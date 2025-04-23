//2. Dado um inteiro positivo n, verificar se n é primo.
#include <stdio.h>
int main()
{
    int N;
    int cont = 0;
    printf("Digite um inteiro N: ");
    scanf("%i",&N);
   
    for (int i=1; i<=N; i++){
        if (N % i == 0){
            cont++;
        }
    }

    if (cont == 2){
        printf("O número %i é primo!",N);
    }
    else{
        printf("O número %i não é primo!",N);
    }

    return 0;
}