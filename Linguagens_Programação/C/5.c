/*5. Dados dois strings (um contendo uma frase e outro contendo uma palavra), 
determine o número de vezes que a palavra ocorre na frase.
Exemplo:
Para a palavra ANA e a frase : ANA E MARIANA GOSTAM DE BANANA
Resp: Temos que a palavra ANA ocorre 4 vezes na frase*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char name[10] = "ANA";

    char frase[40] = "ANA E MARIANA GOSTAM DE BANANA";
   
    int cont = 0;
   
    for (int i=0; i<= strlen(frase); i++){
        if (frase[i] == name[0] && frase[i+1] == name[1] && frase[i+2] == name[2]){
            cont++;
        }
    }
    printf("%i",cont);
    return 0;
}