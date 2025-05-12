/*4) Multiplicação de matrizes

Faça um programa que multiplique duas matrizes A e B, cujos dimensões são MxN e NxP, 
onde M pode ou não ser igual a P. 
O tamanho das matrizes e o número de threads devem ser informados pelo usuário. 
Os valores das matrizes devem ser gerados de forma aleatória pelo programa. 
O programa deverá imprimir na tela as matrizes A e B bem como o resultado da sua multiplicação.*/
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

struct Dados {
    int* A, *B, *C;
    int ini, fim, M,N,P;
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

void* multiplyMatrix(void* arg){
    struct Dados* dados = (struct Dados*) arg;
    int M = dados->M;
    int N = dados->N;
    int P = dados->P;
    for (int i = dados->ini; i < dados->fim; i++) {
        for (int j = 0; j < P; j++) {
            int soma = 0;
            for (int k = 0; k < N; k++) {
                soma += dados->A[i * N + k] * dados->B[k * P + j];
            }
            dados->C[i * P + j] = soma;
        }
    }
    return NULL;
}

void main(){
    int M,N,P,n_threads;
    printf("Digite as dimensões da matriz (MxN) e da matriz (NxP)\n");
    printf("Dimensão M: \n");
    scanf("%i",&M);
    printf("Dimensão N: \n");
    scanf("%i",&N);
    printf("Dimensão P: \n");
    scanf("%i",&P);

    printf("Digite o nro de Threads que deseja usar: \n");
    scanf("%i",&n_threads);
    if (n_threads > P){
        n_threads = P;
    }
    pthread_t vetor_thread[n_threads];
    int* matrizA = gerar_matriz(M,N);
    int* matrizB = gerar_matriz(N,P);
    int* matrizC = malloc(N*P*sizeof(int));
    struct Dados dados[n_threads];
    int pos = M / n_threads;

    for (int i=0; i<n_threads;i++){
        dados[i].A = matrizA;
        dados[i].B = matrizB;
        dados[i].C = matrizC;
        dados[i].M = M;
        dados[i].N = N;
        dados[i].P = P;
        dados[i].ini = i * pos;
        
        if (i == n_threads - 1){
            dados[i].fim = M;
        } else {
            dados[i].fim = (i + 1) * pos;
        }
        
        pthread_create(&vetor_thread[i], NULL, multiplyMatrix, (void*) &dados[i]);
    }

    for (int i = 0; i < n_threads; i++) {
        pthread_join(vetor_thread[i], NULL);
    }

    printf("\nMatriz A:\n");
    print_matriz(M, N, matrizA);

    printf("\nMatriz B:\n");
    print_matriz(N, P, matrizB);

    printf("\nMatriz C (Resultado):\n");
    print_matriz(M, P, matrizC);

    free(matrizA);
    free(matrizB);
    free(matrizC);

}