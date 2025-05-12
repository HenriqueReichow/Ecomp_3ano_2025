/*3) Matriz transposta

Faça um programa que receba como entrada uma matriz de inteiro A de tamanho MxN e realize a sua transposição. 
A saída deverá ser armazenada em uma matriz B de tamanho NxM. 
O tamanho da matriz e o número de threads devem ser informados pelo usuário. 
Os elementos da matriz devem ser gerados de forma aleatória pelo programa. 
O programa deverá imprimir na tela as matrizes de entrada e de saída.*/

#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

struct Dados {
    int* A, *B;
    int ini, fim, M,N;
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

void* transposta(void* arg){
    struct Dados* dados = (struct Dados*) arg;
    int M = dados->M;
    int N = dados->N;

    for (int i = dados->ini; i < dados->fim; i++) {
        int line = i / N;
        int col = i % N;
        dados->B[col * M + line] = dados->A[line * N + col];
        //printf("\nVetor_c[%i] = %i\n",i,dados->B[i]);
        printf("Thread %lu processando A[%d][%d] -> B[%d][%d] = %d\n", 
            pthread_self(), line, col, col, line, dados->B[col * M + line]);
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

    printf("Digite o nro de Threads que deseja usar: \n");
    scanf("%i",&n_threads);

    int* matrizA = gerar_matriz(M,N);
    int* matrizB = malloc(M * N * sizeof(int));

    printf("\nMatriz A:\n");
    print_matriz(M,N,matrizA);

    int pos = (M*N) / n_threads;
    pthread_t vetor_thread[n_threads];
    struct Dados dados[n_threads];

    for (int i=0; i<n_threads;i++){
        dados[i].A = matrizA;
        dados[i].B = matrizB;
        dados[i].M = M;
        dados[i].N = N;
        dados[i].ini = i * pos;
        
        if (i == n_threads - 1){
            dados[i].fim = M*N;
        } else {
            dados[i].fim = (i + 1) * pos;
        }
        
        pthread_create(&vetor_thread[i], NULL, transposta, (void*) &dados[i]);
    }

    for (int i = 0; i < n_threads; i++) {
        pthread_join(vetor_thread[i], NULL);
    }

    printf("\nMatriz B (Transposta):\n");
    print_matriz(N, M, matrizB);

    free(matrizA);
    free(matrizB);
    return 0;
}