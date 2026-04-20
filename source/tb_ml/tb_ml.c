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
#include "../../third_party/btree_impl.h"
#include "../../third_party/csv_decoder.h"
///////////////////////////////////////////////////////////////////////////////

internal void
init_tb_db(int count, char **value)
{
    if(count < 2) value[1] = "./test/data.csv";

    local_persist b32 running = 1;

    mem_arena *global_arena = arena_create(GiB(1));

    string8 buffer = file_load(global_arena, value[1]);

    // NOTE(nasr): the use of tables is required for tracking headers etc.
    // i think we can optimize this away in the future but for now its fine
    csv_table      *table      = PushStructZero(global_arena, csv_table);
    csv_token_list *token_list = PushStructZero(global_arena, csv_token_list);

    token_list->start_token = &nil_csv_token;
    token_list->end_token   = &nil_csv_token;

    csv_token *tokens = tokenize_csv(buffer, global_arena, table, token_list);
    assert_msg(tokens != NULL, "tokens are null");

    // NOTE(nasr): token_list is now populated — pass it directly, not a fresh empty list
    btree *bt = btree_parse_csv(global_arena, token_list, table);

    _log("\nDatabase Engine\n");

    for(;;)
    {
        if(running)
        {
            u8  *lbuf     = PushArray(global_arena, u8, 256);
#if 0
            s32  err      = os_read_stderr(lbuf, 256);
#endif
            s32 err = 0;

            if(err < 0)
            {
                _log("error reading from stdin");
            }

            // TODO(nasr): extract this later in the future and make a string copy function/macro
            // @params (s32 lbuf_size, string8 lbuf_stringified)
            // NOTE(nasr): use err (bytes read) not sizeof(lbuf*) — sizeof a pointer is always 8
            s32     lbuf_size       = err;
            string8 lbuf_stringified = PushString8(global_arena, lbuf_size);
            {
                memcpy(lbuf_stringified.data, lbuf, lbuf_size);
                lbuf_stringified.size = lbuf_size;
            }




            // TODO(nasr): dispatch qtl against bt here

            unused(bt);

            sleep(1);
        }
    }

    return;
}


internal struct ts *
btree_collect(btree *bt) {

    if (!bt) return NULL;

    btree_node *node = bt->root;

    for (s32 index = 0; index < node->key_count; ++index)
    {


    }

    // return a sample data where the  weights are are a set of keys adn values
    return NULL;
}

/**
 * calculating a derviate requires a building an algebraic system
 * so we do a dump approximation of what the derivative could be
 * we want this to be able to normalize the data which is necessary for proper training
 **/

#if 1
internal struct ts *
normalize_training_data_btree(btree *bt) {

    unused(bt);

    // TODO(nasr): later

    return NULL;
}

#endif


internal f32
predict(f32 b1, f32 b2) {
    return b1 + (b2 * log(b1)) + M_E;
}


// using gradient descent
// btree order
internal model
train(btree *bt, s32 learning_rate, f32 expected, f32 order) {

    model m = {0};
    //- cost function
    f32 delta = -99999;

    struct ts *sd = btree_collect(bt);

    for (s32 epoch = 0; epoch < learning_rate; ++epoch)
    {
        m.value = predict(sd->y, sd->y);
        delta = (1/ (2 * order)) * ((expected - delta) * (expected - delta));
    }


    return m;
}

//- dataset is an implementation of the btree
int main(void) {

    for (s32 index = 0; index < 10; ++index)
    {

    }

    return 0;
}
