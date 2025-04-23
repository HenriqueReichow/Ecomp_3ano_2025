//3. Dado um número inteiro positivo n, imprimir os n primeiros naturais ímpares.
#include <stdio.h>
int main()
{
    int N;
    int cont = 1;
    printf("Digite um inteiro N: ");
    scanf("%i", &N);
   
    if(N <= 0){
        printf("Digite um valor válido, positivo!");
        return 0;
    }
    while (cont<=N){
        printf("%i ",cont);
        cont += 2;
    }

    return 0;
}