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
#define CSV_IMPLEMENTATION
#define CSV_DEBUG
#include "../../third_party/btree_impl.h"
#include "../../third_party/csv_decoder.h"
///////////////////////////////////////////////////////////////////////////////

// TODO(nasr): add these functions to the btree implementation later

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

    assert_msg(bt->root != NULL, "null root");

    btree_node *current_node = bt->root;
    s32 kc = current_node->key_count;

    for (s32 index = 0; index < kc; ++index) {
        for (s32 index = 0; index < kc; ++index) {
            sample.w += current_node->keys[index].header_index;
            sample.y += current_node->keys[index].row_index;
        }
        current_node = current_node->children[index];
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
train(ts s, s32 learning_rate, f32 expected, f32 order) {

    model m = {0};
    //- cost function
    f32 delta = -99999;

    for (s32 epoch = 0; epoch < learning_rate; ++epoch)
    {
        m.value = predict(s.y, s.y);
        delta = (1/ (2 * order)) * ((expected - delta) * (expected - delta));
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
    csv_token_list *token_list = PushStructZero(global_arena, csv_token_list);


    {
#if 1
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
    ts sample = normalize_training_data_btree(bt);
    arena_clear(global_arena);

    model m = train(sample, epochs, 0.5, BTREE_ORDER);

    _log("trained value :: %f", m.value);

    btree_node_traverse(bt->root);


    return 0;
}
