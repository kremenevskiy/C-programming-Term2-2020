#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int L = 3;
const int M = 3;
const int N = 3;

int *** create_3D(int *** ptr, int X_size, int Y_size, int Z_size);
void fillRand_3D(int ***ptr, int X_size, int Y_size, int Z_size);
int ** create_2D(int X_size, int Y_size);
void show_2D(int ** array, int x, int y);


int main() {

    int *** XYZ = NULL;
    XYZ = create_3D(XYZ, L, M, N);

    // Автозакраску лучше не использовать, тк почти все проекции будут закрашены
    // fillRand_3D(XYZ, L, M, N);

    int **XY = create_2D(L, M);
    int **XZ = create_2D(L, N);
    int **YZ = create_2D(M, N);


    // Выбрать точку для закраки

    XYZ[0][0][0] = 1;
    XYZ[1][1][0] = 1;
    XYZ[0][2][1] = 1;
    XYZ[2][1][0] = 1;


    int i, j, k;
    for(i = 0; i < L; i++){
        for(j = 0; j < M; j++){
            for(k = 0; k < L; k++){

                if (XYZ[i][j][k] == 0){
                    continue;
                }

                if (XY[i][j] == 0) XY[i][j] = 1;
                if (XZ[i][k] == 0) XZ[i][k] = 1;
                if (YZ[j][k] == 0) YZ[j][k] = 1;

            }
        }
    }

    printf("XY projection (X down, Y right)\n");
    show_2D(XY, L, M);

    printf("\n\nXZ projection (X down, Z right)\n");
    show_2D(XZ, L, N);

    printf("\n\nYZ projection (Y down, Z right)\n");
    show_2D(YZ, M, N);

    return 0;
}


int *** create_3D(int *** ptr, int X_size, int Y_size, int Z_size){

    ptr = (int***) malloc(X_size * sizeof(int**));
    int i, j, k;

    for(i = 0; i < X_size; i++){
        *(ptr + i) = (int **) malloc(Y_size * sizeof(int *));
        for(j = 0; j < Y_size; j++){
            ptr[i][j] = (int *) malloc(Z_size * sizeof(int));
        }
    }

    return ptr;
}


void fillRand_3D(int ***ptr, int X_size, int Y_size, int Z_size){

    int i, j, k;

    for(i = 0; i < X_size; i++){
        for(j = 0; j < Y_size; j++){
            for(k = 0; k < Z_size; k++){
                ptr[i][j][k] = rand() % 2 ;

                printf("%i ", ptr[i][j][k]);
            }
        }
    }
}


int ** create_2D(int x, int y){

    int ** array_2D = (int **) malloc(x * sizeof(int *));

    int i;
    for(i = 0; i < x; i++){
        array_2D[i] = (int*) malloc (y * sizeof(int));
    }

    return array_2D;
}


void show_2D(int ** array, int x, int y){

    int i, j;
    for(i = 0; i < x; i++){

        for(j = 0; j < y; j++){
            printf("%i ", array[i][j]);
        }
        printf("\n");
    }
}