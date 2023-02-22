#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person *)(0xFFFFFFFFFFFFFFFUL)

typedef struct {
    char name[MAX_NAME];
    int age;
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
        else if(hash_table[i] == DELETED_NODE){
            printf("\t%i\t---<deleted>\n", i);
        } 
        else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
            
    }
        
}


bool hash_table_insert(person *p){
    if (p == NULL) return false;
    int index = hash(p->name);
    for (int i=0; i < TABLE_SIZE; i++){
        int try = (i + index)  % TABLE_SIZE;
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE) 
            {
                hash_table[try] = p;
                return true;
            }
    }
    return false;
}

person *hash_table_lookup (char *name){
    int index = hash(name);
    for (int i= 0; i< TABLE_SIZE; i++){
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL){
            return false;
        }
        if (hash_table[try] == DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0){
            return hash_table[try];    
        } 
    }
    return NULL;
}

person *hash_table_delete(char *name){
    int index = hash(name);
    for (int i= 0; i< TABLE_SIZE; i++){
        int try = (index + i)  % TABLE_SIZE;
         if (hash_table[try] == NULL){
            return NULL;
        }
        if (hash_table[try] == DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0){
            person *temp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return temp;    
        }     
    }
    return DELETED_NODE;
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