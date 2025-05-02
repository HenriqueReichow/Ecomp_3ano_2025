/*Exercícios 2
Seja a seguinte struct que é utilizada para descrever os produtos que estão no estoque de uma
loja:
struct Produto {
 char nome[30]; //Nome do produto 
 int codigo; //Codigo do produto 
 double preco; //Preco do produto 
};
Faça um programa que gerencie uma lista de produtos (dinâmica) com as opções (menu) de
adicionar, exibir lista (todos), busca por nome (exibição de um produto) e sair. Quando a opção
de saída for selecionada toda a alocação dinâmica efetuada deve ser liberada.
Exemplo de criação de nó de lista:
typedef struct node {
 struct Produto produto;
 struct node* next;
 } Node;*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char nome[30];
    int codigo;
    double preco;
};

typedef struct node {
    struct Produto produto;
    struct node* next;
} Node;

Node* adicionar_item(Node* inicio){
    Node* novo = (Node*) malloc(sizeof(Node));
    printf("\n -Digite o nome do produto: ");
    while (getchar() != '\n');
    fgets(novo->produto.nome, sizeof(novo->produto.nome), stdin);
    novo->produto.nome[strcspn(novo->produto.nome, "\n")] = '\0';

    printf("\n -Digite o codigo do produto: ");
    scanf("%i", &novo->produto.codigo);
    printf("\n -Digite o preço do produto: ");
    scanf("%lf", &novo->produto.preco);

    novo->next = NULL;

    if (inicio == NULL) {
        return novo;
    } else {
        Node* atual = inicio;
        while (atual->next != NULL){
            atual = atual->next;
        }
        atual->next = novo;
        return inicio;
    }
}

void exibir_lista(Node* inicio){
    if (inicio == NULL){
        printf("\nLista vazia!");
        return;
    }

    while (inicio != NULL){
        printf("\nNome: %s | Código: %d | Preço: R$ %.2lf", inicio->produto.nome, inicio->produto.codigo, inicio->produto.preco);
        inicio = inicio->next;
    }
}

void buscar_item(char name[30], Node* inicio){
    while (inicio != NULL){
        if (strcmp(inicio->produto.nome, name) == 0){
            printf("\nEsse produto está na lista:");
            printf("\nNome: %s | Código: %d | Preço: R$ %.2lf\n", inicio->produto.nome, inicio->produto.codigo, inicio->produto.preco);
            return;
        }
        inicio = inicio->next;
    }
    printf("\n\nO produto digitado não se encontra na lista.");
}

void liberar_mem(Node* inicio){
    Node* temp;
    while (inicio != NULL){
        temp = inicio;
        inicio = inicio->next;
        free(temp);
    }
}

int main(){
    Node* lista = NULL;
    int option;
    int sair = 0;
    printf("#----------------------------------------#\n");
    printf("#  Seja bem-vindo ao reicho atacadista!  #\n");
    printf("#----------------------------------------#");
    while (!sair){
        printf("\n\nSelecione uma das opções abaixo:\n");
        printf("#      1 - Adicionar item      #\n");
        printf("#      2 - Exibir lista        #\n");
        printf("#      3 - Buscar item         #\n");
        printf("#      4 - Sair                #\n");
        printf("################################\n");
        printf("\n -Digite sua opção: ");
        scanf("%d", &option);

        if (option == 1){
            lista = adicionar_item(lista);

        } else if (option == 2){
            exibir_lista(lista);

        } else if (option == 3){
            char nome_busca[30];
            while (getchar() != '\n');

            printf("\n -Digite o nome do item desejado para a consulta: ");
            fgets(nome_busca, sizeof(nome_busca), stdin);
            nome_busca[strcspn(nome_busca, "\n")] = '\0';
            buscar_item(nome_busca, lista);

        } else if (option == 4){
            liberar_mem(lista);
            sair = 1;
            printf("\nEncerrando o programa. Memória liberada com sucesso.\n");

        } else {
            printf("Opção inválida! Tente novamente.");
        }
    }

    return 0;
}
