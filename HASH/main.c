#include <stdio.h>
#include <string.h>

#include "hashtable.h"


int main(int argc, char **argv) {

    if (argc == 2) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
            printf("Nome: Eduardo Kaluf\nGRR: GRR20241770\nlogin: ek24\nNome: Sergio Sivonei de Sant'ana Filho\nGRR: GRR20242337\nlogin: sssaf24\n");
        return 0;
    }

    char instruction;
    int key;

    struct hashtable *hashtable = create_hashtable(SIZE);
	
    while (scanf("%c", &instruction) != EOF) {
        scanf("%d", &key);
	
        if (instruction == 'i') {
            insert_hashtable(hashtable, key);
        }
        else if (instruction == 'r') {
            remove_hashtable(hashtable, key);
        }
	
        getchar();
    }
	
    if (hashtable != NULL) {
        print_hashtable(hashtable);
	
        destroy_hashtable(hashtable);
    }
	

    return 0;
}