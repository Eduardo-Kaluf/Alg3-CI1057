#include <stdio.h>

#include "hashtable.h"


int main() {
    char instruction;
    int key;
	
    struct hashtable *hashtable = create_hashtable();
	
    while (scanf("%c", &instruction) != EOF) {
        scanf("%d", &key);
	
        if (instruction == 'i') {
	
        }
        else if (instruction == 'r') {
	
        }
	
        getchar();
    }
	
    if (hashtable != NULL) {
        hashtable_print();
	
        hashtable_destroy();
    }
	

    return 0;
}