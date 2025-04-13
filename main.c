#include "bst.h"
#include <stdio.h>
#include <stdlib.h>


int main() {

    struct node_t *root = binary(NULL, NULL, 5);
    root = binary(root, NULL, 2);
    root = binary(root, NULL, 4);
    root = binary(root, NULL, 3);
    root = binary(root, NULL, 1);
    root = binary(root, NULL, 7);
    postorder(root, 2);

    return 0;
}
