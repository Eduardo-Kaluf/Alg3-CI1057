#include <stdio.h>

#include "hashtable.h"


int main() {
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