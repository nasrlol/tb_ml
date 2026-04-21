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

internal ts *
normalize_training_data_btree(btree *bt) {

    unused(bt);
    return NULL;
}

#endif


internal f32
predict(f32 b1, f32 b2) {
    return b1 + (b2 * log(b1)) + M_E;
}


/**
* using gradient descent
*  btree order
**/
internal model
train(ts *s, s32 learning_rate, f32 expected, f32 order) {

    model m = {0};
    //- cost function
    f32 delta = -99999;

    for (s32 epoch = 0; epoch < learning_rate; ++epoch)
    {
        m.value = predict(s->y, s->y);
        delta = (1/ (2 * order)) * ((expected - delta) * (expected - delta));
    }

    return m;
}

//- dataset is an implementation of the btree
int main(int count, char **value) {


    mem_arena *global_arena = arena_create(GiB(1));

    const char *path = PushStruct(global_arena, char);
    if(count > 2) path = value[2];

    path = "./test/data.csv";

    unused(count);
    unused(value);


    string8 buffer = file_load(global_arena, path);

    csv_table      *table      = PushStructZero(global_arena, csv_table);
    csv_token_list *token_list = PushStructZero(global_arena, csv_token_list);

    token_list->start_token = &nil_csv_token;
    token_list->end_token   = &nil_csv_token;

    csv_token *tokens = tokenize_csv(buffer, global_arena, table, token_list);
    assert_msg(tokens != NULL, "tokens are null");

    btree *bt = btree_parse_csv(global_arena, token_list, table);

    ts *sample = normalize_training_data_btree(bt);
    arena_clear(global_arena);

#if 0
    model m = train(sample, epochs, 0.5, BTREE_ORDER);
#endif

    btree_node_traverse(bt->root);


    return 0;
}
