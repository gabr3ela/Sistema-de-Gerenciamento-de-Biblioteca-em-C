#include <stdio.h>
#include <string.h>

#define TAMANHO_ACERVO 20

// Estrutura que representa um livro //
struct Livro {
    int codigo;
    char titulo[50];
    char autor[30];
    char area[30];
    int ano;
    char editora[30];
};

// Funções utilizadas //
void cadastrarLivro(struct Livro acervo[], int *qtde);
void imprimirLivros(struct Livro acervo[], int qtde);
void pesquisarLivro(struct Livro acervo[], int qtde);
void ordenarLivros(struct Livro acervo[], int qtde);
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Função principal //
int main() {
    struct Livro acervo[TAMANHO_ACERVO];
    int qtde = 0;
    int opcao;

    do {
        printf("\n========= MENU =========\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Imprimir todos os livros\n");
        printf("3 - Pesquisar livro por codigo\n");
        printf("4 - Ordenar livros por ano de publicacao\n");
        printf("5 - Sair do programa\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            limparBuffer();
            continue;
        }
        limparBuffer();

        switch (opcao) {
            case 1:
                cadastrarLivro(acervo, &qtde);
                break;
            case 2:
                imprimirLivros(acervo, qtde);
                break;
            case 3:
                pesquisarLivro(acervo, qtde);
                break;
            case 4:
                ordenarLivros(acervo, qtde);
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}

// Cadastro dos livros //
void cadastrarLivro(struct Livro acervo[], int *qtde) {
    if (*qtde >= TAMANHO_ACERVO) {
        printf("Acervo cheio!\n");
        return;
    }

    int i = *qtde;
    printf("\n--- Cadastro do Livro %d ---\n", i + 1);
    printf("Codigo: ");
    while (scanf("%d", &acervo[i].codigo) != 1) {
        printf("Codigo invalido. Digite um numero inteiro: ");
        limparBuffer();
    }
    limparBuffer();

    printf("Titulo: ");
    fgets(acervo[i].titulo, sizeof(acervo[i].titulo), stdin);
    acervo[i].titulo[strcspn(acervo[i].titulo, "\n")] = '\0';

    printf("Autor: ");
    fgets(acervo[i].autor, sizeof(acervo[i].autor), stdin);
    acervo[i].autor[strcspn(acervo[i].autor, "\n")] = '\0';

    printf("Area: ");
    fgets(acervo[i].area, sizeof(acervo[i].area), stdin);
    acervo[i].area[strcspn(acervo[i].area, "\n")] = '\0';

    printf("Ano: ");
    while (scanf("%d", &acervo[i].ano) != 1) {
        printf("Ano invalido. Digite um numero inteiro: ");
        limparBuffer();
    }
    limparBuffer();

    printf("Editora: ");
    fgets(acervo[i].editora, sizeof(acervo[i].editora), stdin);
    acervo[i].editora[strcspn(acervo[i].editora, "\n")] = '\0';

    (*qtde)++;
    printf("Livro cadastrado com sucesso! Total agora: %d\n", *qtde);
}

// Impressão dos livros //
void imprimirLivros(struct Livro acervo[], int qtde) {
    if (qtde == 0) {
        printf("\nNenhum livro cadastrado!\n");
        return;
    }

    printf("\n====== ACERVO DE LIVROS ======\n");
    for (int i = 0; i < qtde; i++) {
        printf("\nLivro %d:\n", i + 1);
        printf("Codigo: %d\n", acervo[i].codigo);
        printf("Titulo: %s\n", acervo[i].titulo);
        printf("Autor: %s\n", acervo[i].autor);
        printf("Area: %s\n", acervo[i].area);
        printf("Ano: %d\n", acervo[i].ano);
        printf("Editora: %s\n", acervo[i].editora);
    }
}

// Pesquisa por código //
void pesquisarLivro(struct Livro acervo[], int qtde) {
    if (qtde == 0) {
        printf("Nenhum livro cadastrado!\n");
        return;
    }

    int codigoBusca;
    printf("Digite o codigo do livro: ");
    while (scanf("%d", &codigoBusca) != 1) {
        printf("Codigo invalido! Digite novamente: ");
        limparBuffer();
    }
    limparBuffer();

    for (int i = 0; i < qtde; i++) {
        if (acervo[i].codigo == codigoBusca) {
            printf("\nLivro encontrado!\n");
            printf("Titulo: %s\n", acervo[i].titulo);
            printf("Autor: %s\n", acervo[i].autor);
            printf("Area: %s\n", acervo[i].area);
            printf("Ano: %d\n", acervo[i].ano);
            printf("Editora: %s\n", acervo[i].editora);
            return;
        }
    }
    printf("\nLivro nao encontrado.\n");
}

// Ordenação dos livros (Bubble Sort) //
void ordenarLivros(struct Livro acervo[], int qtde) {
    if (qtde < 2) {
        printf("Poucos livros para ordenar.\n");
        return;
    }

    struct Livro temp;
    for (int i = 0; i < qtde - 1; i++) {
        for (int j = 0; j < qtde - 1 - i; j++) {
            if (acervo[j].ano > acervo[j + 1].ano) {
                temp = acervo[j];
                acervo[j] = acervo[j + 1];
                acervo[j + 1] = temp;
            }
        }
    }
    printf("Livros ordenados por ano!\n");
}