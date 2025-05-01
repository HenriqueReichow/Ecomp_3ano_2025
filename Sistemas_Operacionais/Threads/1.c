/*Multiplicando vetores (produto vetorial)

Faça um programa que receba como entrada dois vetores de inteiros A e B de tamanho N e realize o seu produto vetorial. 
A saída deverá ser armazenada em um vetor C. O tamanho do vetor e o número de threads devem ser informados pelo usuário. Os elementos do vetor devem ser gerados de forma aleatória pelo programa. 
O programa deverá imprimir na tela os vetores de entrada e o vetor de saída.*/

#include<stdio.h>
#include<pthread.h>
#include <time.h>

void print_vetor(int *vetor, int len_of_vetor){
    for (int i=0; i < len_of_vetor; i++){
        printf("%i ", vetor[i]);
    }
    printf("\n");
}

void *hello(void *i){

    long id;

    id = (long)i;

    printf("Olá, sou a thread %ld\n", id);

    pthread_exit(NULL);

}

int produtoVetor(int *vet1,int *vetb){
   
    return 0;
}

int main(){
    srand(time(NULL));
    int nThreads,lenVetor;
   
    printf("Digite o tamanho do vetor: ");
    scanf("%i",&lenVetor);
    int a[lenVetor], b[lenVetor], c[lenVetor];
   
    printf("Digite o numero de threads: ");
    scanf("%i",&nThreads);

    printf("O vetor A é: ");
    print_vetor(a,lenVetor);
   
    for (int i =0; i<lenVetor; i++){
       
        a[i] = _random(0,20);
        b[i] = _random(0,20);
        c[i] = a[i] + b[i];
    }
   
pthread_t threads[nThreads];
long i;

for(i=0;i<N;i++){
printf("Criando thread %ld\n", i);
pthread_create(&threads[i],NULL,&hello,(void *)i);
}

for(i=0;i<N;i++){
pthread_join(&threads[i],NULL);
}

}
