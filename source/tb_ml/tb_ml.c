#define BASE_IMPLEMENTATION
#include "../base/base_include.h"

#ifdef BTREE_IMPLEMENTATION
internal void
btree_collect(btree_node *node, (void *) *keys, (void *) array *) {

    if (!n) return;

    for (s32 index = 0; index < node->count; ++index)
    {
        TODO(nasr): traverse the tree to use the tree as training data
    }
}
#endif


/**
* calculating a derviate requires a building an algebraic system
* so we do a dump approximation of what the derivative could be
* we want this to be able to normalize the data which is necessary for proper training
**/
#if 1
internal f32
internal training_sample_data
normalize_training_data_btree(btree *btree) {



}

#endif


// using gradient descent
internal void
train(f32 *weights, b_tree, s32 learning_rate) {

    btree_collect(btree_node *node, (void *) *keys, (void *) array *);

    for (s32 epoch = 0; epoch < learning_rate; ++epoch)
    {

    }

}

internal f32
predict(f32 b1, f32 b2) {
    return b1 + (b2 * log(b1)) + M_E;
}

//- dataset is an implementation of the btree
int main(void) {

    for (s32 index = 0; index < 10; ++index)
    {
        printf("value [%4.f]\n",predict(10, 10));
    }

    return 0;
}
