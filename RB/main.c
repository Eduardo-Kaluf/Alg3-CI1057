#include "rb.h"
#include <stdio.h>
#include <stdlib.h>


int main() {

    struct root_t *tree = create_rb(4);

    rb_insert(tree, 12);
    rb_insert(tree, 18);
    rb_insert(tree, 1);
    rb_insert(tree, 2);
    rb_insert(tree, 7);
    rb_insert(tree, 3);
    rb_insert(tree, 5);

    print_tree(tree, tree->root, 0);

    return 0;
}
