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
#include <sys/wait.h>
#include <unistd.h>

void print_collatz(int pid) {
    int x = (pid / 10) % 100;

    printf("Processo %d: %d ", pid, x);
    fflush(stdout);

    while (x != 1) {
        if (x % 2 == 0) {
            x = x / 2;
        } else {
            x = 3 * x + 1;
        }
        printf("%d ", x);
        fflush(stdout);
    }
    printf("\n");
}

int main() {
    int N;
    printf("Digite o número de processos: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Erro ao criar processo");
            exit(1);
        }

        if (pid == 0) {
            int me = getpid();
            print_collatz(me);
            exit(0);
        }
    }

    int status;
    while (waitpid(-1, &status, 0) > 0);

    printf("Todos os processos filhos terminaram.\n");
    return 0;
}
