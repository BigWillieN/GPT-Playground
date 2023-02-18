#include <stdio.h>
#include <stdlib.h>

void generate_helper(FILE *fp, int n, int sum_even, int sum_odd, char *buffer, int index){
    if (index == n){
        if (sum_even == sum_odd){
            fprintf(fp, "%s\n", buffer);
        }
        return;
    }
    //generate even digits for position 0 
    for (int d=2; d<=8; d+=2){
        if (index == 0){
            buffer[index] = '0' + d;
            generate_helper(fp, n, sum_even+d, sum_odd, buffer, index+1);
        }
    }
    //generate even digits for positions with even weight
    for (int d=0; d<=8; d+=2){
        if (index %2 == 0){
            if (index != 0){
                buffer[index]= '0' + d;
                generate_helper(fp, n, sum_even+d, sum_odd, buffer, index+1);
            }
            
        }
    }
    
    //generate odd digits for positions with odd weight
    for (int d=1; d<=9; d+=2){
        if (index %2 == 1){
            buffer[index]= '0' + d;
            generate_helper(fp, n, sum_even, sum_odd+d, buffer, index+1);
        }
    }

}

void generate(char *name, int n) {
    FILE *fp = fopen(name, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", name);
        return;
    }
    
    char buffer[n + 1];
    memset(buffer, 0, sizeof(buffer));
    generate_helper(fp, n, 0, 0, buffer, 0);
    
    fclose(fp);
}