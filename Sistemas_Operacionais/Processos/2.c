/*Faça um programa que crie um processo filho. Este processo filho executará uma tarefa dependendo do seu ID de processo e do ID do seu pai.
Se ambos IDs foram pares, o processo filho deverá multiplicar dois vetores de dimensão N (informada pelo usuário) e com valores aleatoriamente gerados.
Se ambos IDs forem ímpares, o processo filho deverá subtrair os vetores. Se o pai for ímpar e o filho par, deverá realizar a adição dos vetores.
Se o pai for par e o filho ímpar, deverá realizar as três operações. Se o ID do filho for par, o processo pai deve esperar pelo seu encerramento.
Se o ID for ímpar, não precisa esperar pelo filho.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <unistd.h>

void print_vetor(int *vetor, int len_of_vetor){
    for (int i = 0; i < len_of_vetor; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void somar_vetores(int *vetor_1, int *vetor_2, int len_of_vetor){
    int vetor_resultado[len_of_vetor];
    for (int i = 0; i < len_of_vetor; i++){
        vetor_1[i] = rand() % 30;
        vetor_2[i] = rand() % 30;
        vetor_resultado[i] = vetor_1[i] + vetor_2[i];
    }
    printf("Resultado da soma: ");
    print_vetor(vetor_resultado, len_of_vetor);
}

void multiplicar_vetores(int *vetor_1, int *vetor_2, int len_of_vetor){
    int vetor_resultado[len_of_vetor];
    for (int i = 0; i < len_of_vetor; i++){
        vetor_1[i] = rand() % 30;
        vetor_2[i] = rand() % 30;
        vetor_resultado[i] = vetor_1[i] * vetor_2[i];
    }
    printf("Resultado da multiplicação: ");
    print_vetor(vetor_resultado, len_of_vetor);
}

void diminuir_vetores(int *vetor_1, int *vetor_2, int len_of_vetor){
    int vetor_resultado[len_of_vetor];
    for (int i = 0; i < len_of_vetor; i++){
        vetor_1[i] = rand() % 30;
        vetor_2[i] = rand() % 30;
        vetor_resultado[i] = vetor_1[i] - vetor_2[i];
    }
    printf("Resultado da subtração: ");
    print_vetor(vetor_resultado, len_of_vetor);
}

int main(void){
    srand(time(NULL));

    pid_t newPid, me, parent,x;
    int status, n_vetor;
    
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n_vetor);

    int vetor1[n_vetor];
    int vetor2[n_vetor];

    newPid = fork();
    me = getpid();
    parent = getppid();

    if (newPid != 0) {
        printf("\nPID do pai: %d | PID do filho: %d\n", me, newPid);
        
        if (newPid % 2 == 0) {
            printf("PID do filho é par.Pai esperando o filho\n");
            x = waitpid(newPid, &status, 0);
            printf("Filho terminou!\n");
        } else {
            printf("PID do filho é ímpar.Pai não espera!\n");
        }

    } else {
        me = getpid();      
        parent = getppid();

        if (me % 2 == 0 && parent % 2 == 0) {
            printf("Ambos os PIDs são pares. Multiplicando vetores...\n");
            multiplicar_vetores(vetor1, vetor2, n_vetor);

        } else if (me % 2 != 0 && parent % 2 != 0) {
            printf("Ambos os PIDs são ímpares. Subtraindo vetores...\n");
            diminuir_vetores(vetor1, vetor2, n_vetor);

        } else if (parent % 2 != 0 && me % 2 == 0) {
            printf("Pai ímpar e filho par. Somando vetores...\n");
            somar_vetores(vetor1, vetor2, n_vetor);

        } else if (parent % 2 == 0 && me % 2 != 0) {
            printf("Pai par e filho ímpar. Fazendo as três operações...\n");
            somar_vetores(vetor1, vetor2, n_vetor);
            diminuir_vetores(vetor1, vetor2, n_vetor);
            multiplicar_vetores(vetor1, vetor2, n_vetor);
        }
    }

    return 0;
}