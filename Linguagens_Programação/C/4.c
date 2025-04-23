/*4. Escreva um programa que converta temperaturas de Fahrenheit para Celsus,
seguindo a equação 𝐶 = (𝐹−32)×5/9*/
#include <stdio.h>
int main()
{
    int temp_F,temp_C;

    printf("Digite uma temperatura em Fahrenheit: ");
    scanf("%i",&temp_F);
   
    temp_C = ((temp_F-32)*5)/9;
    printf("A temperatura %i em Fahrenheit equivale a %i graus em Celsius!",temp_F,temp_C);

    return 0;
}