#ifndef BST_H 
#define BST_H

struct root_t {
    struct node_t *root;
    struct node_t *nil;
};

struct node_t {
    int key;
    char color;
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;
};

struct root_t *create_rb(int k);

struct node_t *create_node(struct root_t *tree, struct node_t *parent_node, int k);

struct node_t *rb_search(struct root_t *tree, struct node_t *node, int key);

void left_rotate(struct root_t *tree, struct node_t *target);

void right_rotate(struct root_t *tree, struct node_t *target);

struct node_t *bst_insert(struct root_t *tree, struct node_t *node, struct node_t *parent_node, int k);

void rb_insert(struct root_t *tree, struct node_t *new);

void rb_insert_fixup(struct root_t *tree, struct node_t *new);

void print_tree(struct root_t *tree, struct node_t *node, int counter);

struct node_t *find_max(struct root_t *tree, struct node_t *node);

void rb_transplant(struct root_t *tree, struct node_t *removing, struct node_t *new_sub_root);

void rb_delete_fixup(struct root_t *tree, struct node_t *removing);

void rb_delete(struct root_t *tree, struct node_t *removing);

void delete_tree(struct root_t *tree);

#endif
