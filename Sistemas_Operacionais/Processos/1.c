/*Faça um programa que crie um processo filho. 
Este processo filho deverá realizar a multiplicação de dois vetores de dimensão N (informada pelo usuário) e com valores aleatoriamente gerados. 
Garanta que o processo pai somente vai encerrar após o término dos cálculos pelo processo filho. 
Dica: utilize a função sleep() no processo filho para retardar a execução de cálculos e também mensagens de print no processo pai para indicar 
o que está acontecendo.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main()
{
    pid_t newPid,x;
    int status, n_vetor;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%i",&n_vetor);

    int vetor1[n_vetor], vetor2[n_vetor], vetor_resultado[n_vetor];
    
    newPid = fork();

    if (newPid != 0){
        //Pai
        printf("Esperando filho pid %d\n", newPid);
        x = waitpid(newPid, &status, 0);
        printf("\nFilho %d terminou\n", x);
    }
    else{
        //Filho
        printf("Sou o filho\n");
        
        srand(time(NULL));

        for (int i = 0; i < n_vetor; i++) {
            vetor1[i] = rand() % 10;
            vetor2[i] = rand() % 10;
            vetor_resultado[i] = vetor1[i] * vetor2[i];
        }

        printf("Vetor 1: ");
        for (int i = 0; i < n_vetor; i++) {
            printf("%d ", vetor1[i]);
        }

        printf("\nVetor 2: ");
        for (int i = 0; i < n_vetor; i++) {
            printf("%d ", vetor2[i]);
        }

        printf("\nResultado: ");
        for (int i = 0; i < n_vetor; i++) {
            printf("%d ", vetor_resultado[i]);
        }

        sleep(3);
        printf("\nSaindo do filho!");
    }

    return 0;
}