#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FilaCircular.h"

// Função para gerar um número aleatório único
static int gerar_numero_aleatorio() {
    return rand() % 100 + 1;
}

// Função para exibir o menu e retornar a opção escolhida
static OpcaoMenu exibir_menu() {
    int opcao;
    printf("Escolha uma opcao:\n");
    printf("1: Adicionar Senha\n");
    printf("2: Retirar Senha\n");
    printf("3: Imprimir Fila\n");
    printf("4: Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    return (OpcaoMenu)opcao;
}

int main() {
    int valor;

    // Inicializa a fila e o gerador de números aleatórios
    inicio = 0;
    fim = 0;
    vazia = true;
    cheia = false;
    srand(time(NULL));

    while (1) {
        // Exibe o menu e obtém a opção escolhida
        switch (exibir_menu()) {
            case OP_ADICIONAR:
                if (cheia) {
                    printf("Fila esta cheia. Nao eh possivel adicionar mais senhas.\n");
                } else {
                    int numero_gerado;
                    do {
                        numero_gerado = gerar_numero_aleatorio();
                    } while (numero_existe(numero_gerado)); // Gera um número até encontrar um único

                    if (adicionar(numero_gerado)) {
                        printf("Senha %d adicionada com sucesso.\n", numero_gerado);
                    } else {
                        printf("Erro ao adicionar a senha %d.\n", numero_gerado);
                    }
                }
                break;

            case OP_RETIRAR:
                if (retirar(&valor)) {
                    printf("Senha %d retirada com sucesso.\n", valor);
                } else {
                    printf("Fila esta vazia. Nenhuma senha para retirar.\n");
                }
                break;

            case OP_IMPRIMIR:
                imprimir();
                break;

            case OP_SAIR:
                printf("Saindo...\n");
                exit(0);

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
