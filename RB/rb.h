#ifndef BST_H 
#define BST_H

// Nodos VERMELHOS são iguais a 1
// Nodos PRETOS são iguais a 0

// - root_t: Utilizada como sentinela e como a própria raiz da árvore RB
//      - root: É o nodo que contém o valor da raiz e seus ponteiros 
//      - nil : É um sentinela que será utilizado no lugar do NULL, 
//              a fim de poder classificar os ponteiros para NULL como PRETOS.
//              Seus ponteiros apontam para si mesmo, a fim de evitar erros.
struct root_t {
    struct node_t *root;
    struct node_t *nil;
};

// - node_t: Utilizada como os nós da árvore RB
struct node_t {
    int key;
    char color;
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;
};

// Inicializa uma árvore RB com um valor k
// Essa função já é responsavel por criar a sentinela nil
struct root_t *create_rb(int k);

// Cria e retorna um nodo para a árvore RB
// A cor padrão de criação de um nodo é VERMELHA
// Seus nodos filhos apontam para nil
struct node_t *create_rb_node(struct root_t *tree, struct node_t *parent_node, int k);

// Realiza uma busca binária
// Caso a chave exista na árvore retorna o seu nodo
// Caso contrário, retorna nil
struct node_t *rb_search(struct root_t *tree, struct node_t *node, int key);

// Realiza a rotação para a esquerda no nodo passado
void rb_left_rotation(struct root_t *tree, struct node_t *target);

// Realiza a rotação para a direita no nodo passado
void rb_right_rotation(struct root_t *tree, struct node_t *target);

// Insere um nodo na árvore RB
// Utiliza-se da função rb_insert_fixup para consertar as cores e a estrutura da árvore
void rb_insert(struct root_t *tree, struct node_t *new);

// Realiza recoloração e rotações a fim de balancear a árvore RB
void rb_insert_fixup(struct root_t *tree, struct node_t *new);

// Imprime a árvore RB "in-order"
// Cada nodo é impresso em uma linha seguinte maneira: (Valor,Nível,Cor)
// Sendo que a raiz da árvore possuí "Nível" igual a 0
void rb_print(struct root_t *tree, struct node_t *node, int counter);

// Encontra o maior valor de uma sub-arvore
struct node_t *find_max(struct root_t *tree, struct node_t *node);

// Realiza a opreação de transplante na árvore RB
void rb_transplant(struct root_t *tree, struct node_t *removing, struct node_t *new_sub_root);

// Deleta um nodo da árvore RB
// O ANTECESSOR é utilizada como substituto ao nodo deletado
// A memória do nodo deletado já é liberada pela função
// Utiliza-se da função rb_delete_fixup para consertar as cores e a estrutura da árvore
void rb_delete(struct root_t *tree, struct node_t *removing);

// Realiza recoloração e rotações a fim de balancear a árvore RB
void rb_delete_fixup(struct root_t *tree, struct node_t *removing);

// Libera a memória, destruindo a árvore e seus nodos
void rb_destroy(struct root_t *tree);

#endif
