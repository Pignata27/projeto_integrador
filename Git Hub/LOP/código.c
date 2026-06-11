#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
    int codigo;
    char modelo[50];
    char categoria[30];
    char situacao[20];
} Veiculo;

Veiculo veiculos[MAX];
int total = 0;

// Cadastro
void cadastrar() {
    if (total >= MAX) {
        printf("\nLimite de veiculos atingido!\n");
        return;
    }

    printf("\n=== CADASTRO DE VEICULO ===\n");

    printf("Codigo: ");
    scanf("%d", &veiculos[total].codigo);

    printf("Modelo: ");
    scanf(" %[^\n]", veiculos[total].modelo);

    printf("Categoria: ");
    scanf(" %[^\n]", veiculos[total].categoria);

    printf("Situacao (Disponivel/Alugado/Manutencao): ");
    scanf(" %[^\n]", veiculos[total].situacao);

    total++;

    printf("\nVeiculo cadastrado com sucesso!\n");
}

// Consulta
void consultar() {
    int i;

    if (total == 0) {
        printf("\nNenhum veiculo cadastrado!\n");
        return;
    }

    printf("\n=== LISTA DE VEICULOS ===\n");

    for (i = 0; i < total; i++) {
        printf("\nCodigo: %d", veiculos[i].codigo);
        printf("\nModelo: %s", veiculos[i].modelo);
        printf("\nCategoria: %s", veiculos[i].categoria);
        printf("\nSituacao: %s\n", veiculos[i].situacao);
    }
}

// Alteração
void alterar() {
    int codigo, i, encontrado = 0;

    printf("\nDigite o codigo do veiculo: ");
    scanf("%d", &codigo);

    for (i = 0; i < total; i++) {
        if (veiculos[i].codigo == codigo) {

            printf("\nNovo modelo: ");
            scanf(" %[^\n]", veiculos[i].modelo);

            printf("Nova categoria: ");
            scanf(" %[^\n]", veiculos[i].categoria);

            printf("Nova situacao: ");
            scanf(" %[^\n]", veiculos[i].situacao);

            encontrado = 1;

            printf("\nVeiculo alterado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nVeiculo nao encontrado!\n");
    }
}

// Exclusão
void excluir() {
    int codigo, i, j, encontrado = 0;

    printf("\nDigite o codigo do veiculo: ");
    scanf("%d", &codigo);

    for (i = 0; i < total; i++) {
        if (veiculos[i].codigo == codigo) {

            for (j = i; j < total - 1; j++) {
                veiculos[j] = veiculos[j + 1];
            }

            total--;
            encontrado = 1;

            printf("\nVeiculo excluido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nVeiculo nao encontrado!\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\n==============================");
        printf("\n LOCADORA ROTA LIVRE");
        printf("\n==============================");
        printf("\n1 - Cadastrar Veiculo");
        printf("\n2 - Consultar Veiculos");
        printf("\n3 - Alterar Veiculo");
        printf("\n4 - Excluir Veiculo");
        printf("\n5 - Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar();
                break;

            case 2:
                consultar();
                break;

            case 3:
                alterar();
                break;

            case 4:
                excluir();
                break;

            case 5:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 5);

    return 0;
}