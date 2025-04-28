#ifndef BST_H 
#define BST_H

#define PRETO 0
#define VERMELHO 1


// - root_t: Utilizada como sentinela para a árvore RB
//      - root: Nodo que contém o valor da raiz e seus ponteiros 
//      - nil:  É um sentinela que será utilizado no lugar do NULL, 
//              a fim de poder classificar os ponteiros para NULL como PRETOS.
//              Seus ponteiros apontam para si mesmo, evitando erros.
struct root_t {
    struct node_t *root;
    struct node_t *nil;
};

// - node_t: Utilizada como os nós da árvore RB
//      - key:    Chave guardada pelo nodo;
//      - color:  Bit utilizado para definir a cor do nodo;
//      - left:   Ponteiro para o filho da esquerda;
//      - right:  Ponteiro para o filho da direita;
//      - parent: Ponteira para o pai do nodo;
struct node_t {
    int key;
    char color;
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;
};

// Inicializa uma árvore RB com um valor k
// Parametros:
//      - key: Chave que será guardada na raiz;
// Retorno:
//      - Ponteiro para a raiz da árvore;
struct root_t *create_rb(int key);

// Cria um nodo para a árvore RB 
// Parametros:
//      - tree: Ponteiro para a raiz da árvore;
//      - parent_node: Nodo pai do novo nó;
//      - key: Chave que será guardada pelo nó;
// Retorno:
//      - Ponteiro para o novo nó criado com a cor vermelha e ponteiros filhos para nil
struct node_t *create_rb_node(struct root_t *tree, struct node_t *parent_node, int key);

// Realiza uma busca binária na árvore
// Parametros:
//      - tree: Ponteiro para a raiz da árvore;
//      - node: Nodo de começo da busca;
//      - key: Chave que será buscada;
// Retorno:
//      - Caso a chave exista na árvore retorna o seu nodo, caso contrário retorna nil 
struct node_t *rb_search(struct root_t *tree, struct node_t *node, int key);

// Realiza a rotação para a esquerda no nodo passado
// Parametros:
//      - tree: Ponteiro para a raiz da árvore;
//      - target: Nodo que sofrerá a rotação;
void rb_left_rotation(struct root_t *tree, struct node_t *target);

// Realiza a rotação para a direita no nodo passado
// Parametros:
//      - tree: Ponteiro para a raiz da árvore;
//      - target: Nodo que sofrerá a rotação;
void rb_right_rotation(struct root_t *tree, struct node_t *target);

// Insere um nodo na árvore RB mantendo suas características
// Parametros:
//      - tree: Ponteiro para a raiz da árvore;
//      - new: Nodo que será inserido;
void rb_insert(struct root_t *tree, struct node_t *new);

// Realiza recoloração e rotações a fim de balancear a árvore RB, deve ser utilizado apenas pela função rb_insert
// Parametros:
//      - tree: Ponteiro para a raiz da árvore;
//      - new: Nodo que foi inserido;
void rb_insert_fixup(struct root_t *tree, struct node_t *new);

// Imprime a árvore RB "in-order"
// Cada nodo é impresso ordenado, respectivamente, da seguinte maneira: (Valor,Nível,Cor)
// Sendo que a raiz da árvore possuí "Nível" igual a 0
// Parametros:
//      - tree: Ponteiro para a raiz da árvore;
//      - node: A partir de qual nodo será impresso;
//      - nivel: Qual nível o nodo se encontra;
void rb_print(struct root_t *tree, struct node_t *node, int nivel);

// Encontra o maior valor de uma sub-arvore
// Parametros:
//      - tree: Ponteiro para a raiz da árvore;
//      - node: A partir de qual nó o valor máximo será procurado;
// Retorno:
//      - Um ponteiro para o nodo com o maior valor encontrado;
struct node_t *find_max(struct root_t *tree, struct node_t *node);

// Realiza a opreação de transplante na árvore RB
// Parametros:
//      - tree: Ponteiro para a raiz da árvore;
//      - removing: Nodo que está sendo removido;
//      - new_sub_root: Nodo que será transplantado;
void rb_transplant(struct root_t *tree, struct node_t *removing, struct node_t *new_sub_root);

// Deleta um nodo da árvore RB
// O ANTECESSOR é utilizada como substituto ao nodo deletado
// A memória do nodo deletado já é liberada pela função
// Parametros:
//      - tree: Ponteiro para a raiz da árvore;
//      - removing: Nodo que será removido;
void rb_delete(struct root_t *tree, struct node_t *removing);

// Realiza recoloração e rotações a fim de balancear a árvore RB, deve ser utilizado apenas pela função rb_delete
// Parametros:
//      - tree: Ponteiro para a raiz da árvore;
//      - removing: Nodo que foi removido;
void rb_delete_fixup(struct root_t *tree, struct node_t *removing);

// Libera a memória, destruindo a árvore e seus nodos
// Parametros:
//      - tree: Ponteiro para a raiz da árvore;
void rb_destroy(struct root_t *tree);

#endif
