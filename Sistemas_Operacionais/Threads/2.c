/*2) Somando matrizes

Faça um programa que receba como entrada duas matrizes de inteiros A e B de tamanho MxN e realize a sua soma. 
A saída deverá ser armazenada em uma matriz C. 
O tamanho da matriz e o número de threads devem ser informados pelo usuário. 
Os elementos da matriz devem ser gerados de forma aleatória pelo programa. 
O programa deverá imprimir na tela as matrizes de entrada e a matriz de saída.*/
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

struct Dados {
    int* A, *B, *C;
    int ini, fim;
};

int* gerar_matriz(int M, int N) {
    int* matriz = malloc(M * N * sizeof(int));
    for (int i = 0; i < M * N; i++) {
        matriz[i] = rand() % 30;
    }
    return matriz;
}

void print_matriz(int M,int N, int* matriz) {
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            printf("%2d ", matriz[i * N + j]);
        }
        printf("\n");
    }
}

void* soma(void* arg){
    struct Dados* dados = (struct Dados*) arg;
    for (int i = dados->ini; i < dados->fim; i++) {
        dados->C[i] = dados->A[i] + dados->B[i];
        printf("\nVetor_c[%i] = %i\n",i,dados->C[i]);
    }
    return NULL;
}

int main(){
    int M,N,n_threads;
    printf("Digite as dimensões da matriz (MxN)\n");
    printf("Dimensão M: \n");
    scanf("%i",&M);
    printf("Dimensão N: \n");
    scanf("%i",&N);

    printf("Digite o nro de Threads que deseja usar na soma: \n");
    scanf("%i",&n_threads);

    int* matrizA = gerar_matriz(M,N);
    int* matrizB = gerar_matriz(M,N);
    int* matrizC = malloc(M * N * sizeof(int));

    printf("\nMatriz A:\n");
    print_matriz(M,N,matrizA);

    printf("\nMatriz B:\n");
    print_matriz(M,N,matrizB);

    int pos = (M*N) / n_threads;
    pthread_t vetor_thread[n_threads];
    struct Dados dados[n_threads];

    for (int i=0; i<n_threads;i++){
        dados[i].A = matrizA;
        dados[i].B = matrizB;
        dados[i].C = matrizC;
        dados[i].ini = i * pos;
        
        if (i == n_threads - 1){
            dados[i].fim = M*N;
        } else {
            dados[i].fim = (i + 1) * pos;
        }
        
        pthread_create(&vetor_thread[i], NULL, soma, (void*) &dados[i]);
    }

    for (int i = 0; i < n_threads; i++) {
        pthread_join(vetor_thread[i], NULL);
    }

    //printf("\nMatriz C (soma):\n");
    //print_matriz(M, N, matrizC);


    return 0;
}