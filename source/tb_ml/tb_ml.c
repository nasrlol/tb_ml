#define BASE_IMPLEMENTATION
#include "../base/base_include.h"
#include "tb_ml.h"

//
#define BTREE_IMPLEMENTATION
#include "../../third_party/tb_db/source/tb_db/btree_impl.h"



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
internal model
train(btree *bt, s32 learning_rate, f32 expected) {

    model m = {0};
    f32 delta = -99999;
    struct ts *sd = btree_collect(bt);

    for (s32 epoch = 0; epoch < learning_rate; ++epoch)
    {
        m.value = predict(sd->y, sd->y);
        delta = expected - delta;
    }


    return m;
}

//- dataset is an implementation of the btree
int main(void) {

    for (s32 index = 0; index < 10; ++index) printf("value [%4.f]\n", predict(10, 10));

    return 0;
}
