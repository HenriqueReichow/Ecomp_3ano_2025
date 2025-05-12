/*5) Manipulação de arquivos

Faça um programa que, dado um diretório com arquivos de texto no formato .txt, 
calcule as seguintes estatísticas para cada arquivo. 
Número de palavras, número de vogais, número de consoantes, palavra que apareceu mais vezes no arquivo, 
vogal mais frequente, consoante mais frequente. 
Além disso, para cada arquivo do diretório, o programa deverá gerar um novo arquivo, 
contendo o conteúdo do arquivo original escrito em letras maiúsculas.*/

#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main() {
    DIR *diretorio;
    struct dirent *entry;

    diretorio = opendir("/mnt/c/Users/reich/OneDrive/Área de Trabalho/Ecomp_3ano_2025/Sistemas_Operacionais/Threads/teste_exerc5");
 
    while ((entry = readdir(diretorio)) != NULL) {
        if (strstr(entry->d_name, ".txt")) {
            printf("Lendo arquivo: %s\n", entry->d_name);
            char caminho_completo[1024];
            snprintf(caminho_completo, sizeof(caminho_completo),
            "/mnt/c/Users/reich/OneDrive/Área de Trabalho/Ecomp_3ano_2025/Sistemas_Operacionais/Threads/teste_exerc5/%s",
            entry->d_name);

            FILE *arquivo = fopen(caminho_completo, "r");

            if (arquivo) {
                int dentro_palavra = 0;
                int c, espacos =0, palavras=0, letras=0;

                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                    letras++;
                    dentro_palavra = 1;

                } else if (c == ' ' || c == '\n' || c == '\t') {
                    espacos++;
                    if (dentro_palavra) {
                        palavras++;
                        dentro_palavra = 0;
                    }
                }

                if (dentro_palavra) {
                    palavras++;
                }
                fclose(arquivo);
                printf("\n");
                printf("Espaços: %d\n", espacos);
                printf("Palavras: %d\n", palavras);
                printf("Letras: %d\n", letras);

            } else {
                printf("Erro ao abrir %s\n", entry->d_name);
            }
        }
    }

    closedir(diretorio);
    return 0;
}