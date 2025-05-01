/*Faça um programa que crie N processos, onde N é um número fornecido pelo usuário. 
Cada processo criado deverá gerar uma sequência de números seguindo a conjectura de Collatz (definida abaixo). 
O número x utilizado por cada processo será indicado pelos dígitos da centena e da dezena do seu ID (ex: ID 12345, 
a entrada será 34). A conjectura de Collatz diz que, dado um número inteiro X positivo, 
se a seguinte regra for aplicada, a sequência eventualmente chegará até o valor 1. 
Garanta que o processo pai somente vai encerrar após o término dos cálculos por TODOS os processos filho.
Definição: x = x/2, se x for par ou 3*x+1 se x for ímpar.
Exemplo considerando x = 35: 35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <unistd.h>

void print_collatz(int id){
    id = (id%1000) - (id%10) / 10;
    
    while (id!=1){
        if(id % 2 == 0){
            id = id/2;
        }
        else{
            id = 3*x+1;
        }
        printf("%i ",id);
    }
}

int main(){
    pid_t newPid, me, parent, x;
    parent = getpid()

    int N,status;
    printf("Digite o número de processos: ");
    scanf("%i",&N);
    int *listProcess = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        vetorProcessos[i] = fork();
        if (vetorProcessos[i] == 0) {
            break;
        }
    }

    me = getpid()

    if (me == parent) {
        x = waitpid(-1, &status, 0);
        printf("Finalizado!\n");
    }
    else {
        _collatz(me);
    }
    return 0;
}