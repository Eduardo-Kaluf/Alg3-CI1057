#include "rb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char instruction;
    int key;

    struct root_t *tree = NULL;

    while (scanf("%c", &instruction) != EOF) {
        if (instruction == 'i') {
            scanf("%d", &key);

            if (tree == NULL)
                tree = create_rb(key);
            else
                rb_insert(tree, create_node(tree, tree->nil, key));
        }
        else if (instruction == 'r') {
            scanf("%d", &key);

            if (tree != NULL)
                rb_delete(tree, rb_search(tree, tree->root, key));
        }

        getchar();
    }

    print_tree(tree, tree->root, 0);

    return 0;
}
