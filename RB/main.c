#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rb.h"


int main() {
    char instruction;
    int key;

    struct root_t *tree = NULL;

    while (scanf("%c", &instruction) != EOF) {
        scanf("%d", &key);
        
        if (instruction == 'i') {

            if (tree == NULL)
                tree = create_rb(key);
            else
                rb_insert(tree, create_rb_node(tree, tree->nil, key));
        }
        else if (instruction == 'r') {

            if (tree != NULL)
                rb_delete(tree, rb_search(tree, tree->root, key));
        }

        getchar();
    }

    if (tree != NULL) {
        rb_print(tree, tree->root, 0);

        rb_destroy(tree);
    }

    return 0;
}
