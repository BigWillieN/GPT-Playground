#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invertString(char *s1, char **s2);


void invertString(char *s1, char **s2){
    
    int len = strlen(s1);
    *s2 = (char*)malloc((len) * sizeof(char));
    int start = 0;
    int end = 0;
    int index = 0;
    while (end < len){
        printf("%d%d\n", end, len);
        while(s1[end]<s1[end+1])
            end++;
        for (int i=end;i>=start;i--){
            (*s2)[index]=s1[i];
            index++;
            }
        end++;
        start = end;
        while(s1[end]>=s1[end+1]){
            (*s2)[index]=s1[end];
            index++;
            end++;
            start = end;
            
            
        }
    }
    (*s2)[index] = '\0';
}

int main() {
    char s1[] = "ABCDDDDZYXWEFG";
    char *s2 = NULL;

    invertString(s1, &s2);

    printf("Input string: %s\n", s1);
    printf("Output string: %s\n", s2);

    free(s2);
    return 0;
}
