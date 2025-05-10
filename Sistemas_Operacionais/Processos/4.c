/*4.Faça um programa que crie um processo filho. Este processo filho, 
ao invés de executar o mesmo código definido pelo pai, deve executar um processo informado pelo usuário. 
Para isso sugere-se utilizar a função execl() (em C).*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main(){
    srand(time(NULL));

    pid_t newPid,x;
    int status;

    newPid = fork();
    
    if(newPid==0){
        printf("Filho está pensando...\n");
        execl("./other_process", "other_process", NULL);
    }
    else{
        printf("Pai pergunta: Qual o resultado de 50 - 8?\n");
        x = waitpid(-1,&status,0);
        printf("\nPai aqui para encerrar o processo!\n");
    }
}