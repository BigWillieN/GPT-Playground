#include <stdio.h>
#include <stdlib.h>
#define N 8
void knight(int mat[N][N], int *r, int *c);
void knight(int mat[N][N], int *r, int *c){
    int max_sum = -1;
    int dr[8] = {2,1,-1,-2,-2,-1,1,2}; //Knight moves x (order doesn't matter)
    int dc[8] = {1,2,2,1,-1,-2,-2,-1}; //Knight moves y (order doesn't matter)
    for (int i = 0; i<N; i++){
        for (int j=0; j<N; j++){
            int sum = 0;
            for (int k=0;k<8;k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (nr >= 0 && nr < N && nc >=0 && nc<N) {
                    sum += mat[nr][nc];
                }
            }
            if (sum > max_sum) {
                max_sum = sum;
                *r = i;
                *c = j;
            }
        }
    }
}
int main() {
    int mat[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 3, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 9, 1}
    };
    int r, c;
    knight(mat, &r, &c);
     printf("Best place for the knight is at (%d, %d)\n", r, c);
    return 0;
}
