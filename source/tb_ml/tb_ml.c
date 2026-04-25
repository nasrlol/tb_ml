///////////////////////////////////////////////////////////////////////////////
#define BASE_IMPLEMENTATION
#define BASE_LOGGING
#include "../base/base_include.h"
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
#include "tb_ml.h"
///////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
#define BTREE_IMPLEMENTATION
#define BTREE_DEBUG
#define CSV_IMPLEMENTATION
#define CSV_DEBUG
#include "../../third_party/btree_impl.h"
#include "../../third_party/csv_decoder.h"
///////////////////////////////////////////////////////////////////////////////

// TODO(nasr): add these functions to the btree implementation later
internal void
btree_debug_print(btree *bt) {

#ifdef BTREE_DEBUG

    if (is_nil_btree_node(bt->root)) {
        _log("btree root is nil!\n");
        return;
    }

    btree_node *root = bt->root;

    _log("Root addres: %p | key_count: %d | is_leaf: %d\n", root, root->key_count, root->leaf);

    for(s32 header_index = 0; header_index < root->key_count; ++header_index) {
        _log(" [%d] header_index=%d, row_index=%d, payload=%p\n", header_index, root->keys[header_index].header_index, root->keys[header_index].row_index, root->payload_per_key[header_index]);
    }

    if(!root->leaf) {
        _log("  Children:\n");
        for(s32 children_index = 0; children_index <= root->key_count; ++children_index) {
            if(!is_nil_btree_node(root->children[children_index])) {
                _log("    [%d] @ %p (keys=%d)\n",
                     children_index, root->children[children_index], root->children[children_index]->key_count);
            }
        }
    }

#else
    unused(bt);
#endif

}

#if 1

internal void
btree_node_traverse(btree_node *node) {

    if(is_nil_btree_node(node)) {
        return;
    }

    for (s32 index = 0; index < node->key_count; ++index) {
        _log("Key index: %d, Payload: %p\n", index, node->payload_per_key[index]);
    }
}


#if 0
internal void
btree_traverse_inorder(btree *bt) {


}
#endif

#endif

/**
* calculating a derviate requires a building an algebraic system
* so we do a dump approximation of what the derivative could be
* we want this to be able to normalize the data which is necessary for proper training
**/

#if 1

internal ts
normalize_training_data_btree(btree *bt) {

    ts sample = {0};

#if 0
    assert_msg(bt->root != NULL, "null root");
#endif

/**
* TODO(nasr): sometimes the btree root is initialized as null. i dont know some kind of bug. but will fix this later
* btree->root is sometimes initialized
**/


/**
* TODO(nasr): try disabling this in the base library with some macro.
* source/tb_ml/tb_ml.c|70 col 61 warning| ISO C99 requires at least one argument for the ‘...’ in a variadic macro [-Wpedantic]
* ||    70 |         _log("Warning: empty btree, returning zero sample\n");
*
**/
    if(is_nil_btree_node(bt->root)) {
        _log("Warning: empty btree, returning zero sample\n");
        return sample;
    }

    btree_node *current_node = bt->root;
    s32 kc = current_node->key_count;

    for(s32 index = 0; index < kc; ++index) {

        for(s32 nested_index = 0; nested_index < kc; ++nested_index) {


            sample.w += current_node->keys[nested_index].header_index;
            sample.y += current_node->keys[nested_index].row_index;
        }

        // current_node could be null at some point anyways it segfaulted before this....
        if(is_nil_btree_node(current_node->children[index])) {
            break;
        }

        current_node = current_node->children[index];

    }

// NOTE(nasr): ensure the sample value isnt 0; because it being 0 makes everything 0;
    if(sample.w == 0.0f){
        sample.w = 1.0f;
    }

    if(sample.y == 0.0f){
        sample.y = 1.0f;
    }

    return sample;
}

#endif


internal f32
predict(f32 b1, f32 b2) {
    return b1 + (b2 * log(b1)) + m_e;
}


/**
* using gradient descent
*  btree order
**/
internal model
train(ts s, s32 learning_rate, f32 expected) {
    model m = {0};
    f32 weight = 0.1f;

    for (s32 epoch = 0; epoch < learning_rate; ++epoch) {
        f32 prediction = predict(s.y, weight);
        f32 loss = prediction - expected;
        weight -= 0.01f * loss;
        m.value = prediction;
    }
    return m;
}

//- dataset is an implementation of the btree
int main(int count, char **value) {


    mem_arena *global_arena = arena_create(GiB(1));

    const char *path = "./test/data.csv";
    if(count > 2) {
        path = value[2];
    }


    string8 buffer = file_load(global_arena, path);

    _log("path :: %s\n",path);
    // _logs8(buffer);
    _log("buffer size: %llu\n",buffer.size);

    csv_table      *table      = PushStructZero(global_arena, csv_table);
#if 1
    csv_token_list *token_list = PushStructZero(global_arena, csv_token_list);
#else
    csv_token_list *token_list = NULL;
#endif


    {
#if 0
        token_list->start_token = &nil_csv_token;
        token_list->end_token   = &nil_csv_token;
#else
        token_list->start_token = NULL;
        token_list->end_token   = NULL;
#endif
    }

    assert_msg(buffer.size != 0, "[BEFORE INITIALIZATION] buffer size is 0\n");

    csv_token *tokens = tokenize_csv(buffer, global_arena, table, token_list);
    assert_msg(tokens != NULL, "tokens are null\n");

    _log("First token: %p\n", token_list->start_token);
    _log("Token list is nil: %d\n", is_nil_csv_token(token_list->start_token));

    btree *bt = btree_parse_csv(global_arena, token_list, table);

    assert_msg(bt != NULL, "btree creation failed\n");

    btree_debug_print(bt);
    ts sample = normalize_training_data_btree(bt);
    arena_clear(global_arena);

    model m = train(sample, epochs, 0.5);

    _log("trained value :: %f\n", m.value);

#if 0
    btree_node_traverse(bt->root);
#endif

    // test data specific values;
    {
        s32 new_bedrooms_col = 4;
        s32 new_sqft_col = 5;
        f32 new_bedrooms = 3.0f;
        f32 new_sqft = 2000.0f;
        f32 prediction = predict(new_bedrooms, new_sqft);
        _log("Prediction for new house: %f\n", prediction);
    }

    return 0;
}
