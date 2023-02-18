#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10


typedef struct person {
    char name[MAX_NAME];
    int age;
    struct person *next;
} person;
person * hash_table[TABLE_SIZE];



unsigned int hash(char *name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]  % TABLE_SIZE);
        
    }
    return hash_value;
}

void init_hash_table() {
    for (int i=0; i<TABLE_SIZE; i++) {
        hash_table[i]= NULL;
    }
}

void print_table(){
    for (int i=0; i<TABLE_SIZE; i++){
        if (hash_table[i]==NULL){
            printf("\t%i\t---\n", i);
        } 
        else {
            printf("\t%i\t", i);
            person *tmp = hash_table[i];
            while (tmp != NULL){
                printf("%s -", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
            
    }
        
}


bool hash_table_insert(person *p){
    if (p == NULL) return false;
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

person *hash_table_lookup (char *name){
    int index = hash(name);
    person *tmp = hash_table[index];
    while (tmp!=NULL && strncmp(tmp->name, name, MAX_NAME)!= 0){
        tmp = tmp->next;
    }
    return tmp;
}

person *hash_table_delete(char *name){
    int index = hash(name);
    person *tmp = hash_table[index];
    person *prev = NULL;
    while (tmp!=NULL && strncmp(tmp->name, name, MAX_NAME)!= 0){
        prev = tmp;
        tmp = tmp->next;
        
    }
    if(tmp == NULL) return NULL;
    if (prev == NULL){
        hash_table[index] = tmp->next;
    } else {
        prev->next = tmp->next;
    }
    return tmp;
}


int main(){
    init_hash_table();
    
    person jacob = {.name = "Jacob", .age = 23};
    person kate = {.name = "Kate", .age = 35};
    person berk = {.name = "Berk", .age = 45};
    person summer = {.name = "Summer", .age = 15};
    person kumalala = {.name = "Kumalala", .age = 25};
    person zoomer = {.name = "Zoomer", .age = 35};
    person delealli = {.name = "Dele Alli", .age = 26};
    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&berk);
    hash_table_insert(&zoomer);
    hash_table_insert(&kumalala);
    hash_table_insert(&summer);
    hash_table_insert(&delealli);
    
    print_table();
    return 0;
}