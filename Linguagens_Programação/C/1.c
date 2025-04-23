//1. Dado um inteiro x, determine 𝑥!
#include <stdio.h>

int main()
{
    int X; 
    int resultado = 1;
    printf("Digite um inteiro, o resultado será o seu fatorial: ");
    scanf("%i", &X);
    for (int i=1; i<=X ; i++){
        resultado = resultado * i;
        
    }
    printf("O resultado de %i fatorial é: %i",X,resultado);
    return 0;
}
