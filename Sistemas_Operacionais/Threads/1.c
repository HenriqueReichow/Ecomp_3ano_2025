/*Multiplicando vetores (produto vetorial)

Faça um programa que receba como entrada dois vetores de inteiros A e B de tamanho N e realize o seu produto vetorial. 
A saída deverá ser armazenada em um vetor C. O tamanho do vetor e o número de threads devem ser informados pelo usuário. Os elementos do vetor devem ser gerados de forma aleatória pelo programa. 
O programa deverá imprimir na tela os vetores de entrada e o vetor de saída.*/

#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

struct Dados {
    int *A,*B,*C;
    int ini, fim;
};

void* soma(void* arg){
    struct Dados* dados = (struct Dados*) arg;
    for (int i = dados->ini; i < dados->fim; i++) {
        dados->C[i] = dados->A[i] + dados->B[i];
        //printf("\nVetor_c[%i] = %i\n",i,dados->C[i]);
    }
    return NULL;
}

int main(){
    int N, number_th;
    
    printf("Digite o tamanho esperado do vetor: ");
    scanf("%i",&N);
    printf("Digite a quantidade de Threads que deseja usar: ");
    scanf("%i",&number_th);

    if (number_th>N){
        number_th = N;
    }

    int vetor_A[N], vetor_B[N], vetor_C[N];
    for (int i = 0; i < N; i++){
        vetor_A[i] = rand() % 30;
        vetor_B[i] = rand() % 30;
    }

    pthread_t vetor_thread[number_th];
    struct Dados dados[number_th];

    int pos = N/number_th;

    for (int i=0; i<number_th;i++){
        dados[i].A = vetor_A;
        dados[i].B = vetor_B;
        dados[i].C = vetor_C;
        dados[i].ini = i * pos;
        
        if (i == number_th - 1){
            dados[i].fim = N;
        } else {
            dados[i].fim = (i + 1) * pos;
        }
        
        pthread_create(&vetor_thread[i], NULL, soma, (void*) &dados[i]);
    }

    for (int i = 0; i < number_th; i++) {
        pthread_join(vetor_thread[i], NULL);
    }

    printf("\nVetor A: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", vetor_A[i]);
    }

    printf("\nVetor B: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", vetor_B[i]);
    }

    printf("\nVetor C (soma): ");
    for (int i = 0; i < N; i++) {
        printf("%d ", vetor_C[i]);
    }
    printf("\n");

    return 0;
}