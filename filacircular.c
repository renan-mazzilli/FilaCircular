#include <stdio.h>
#include <stdbool.h>
#include "FilaCircular.h"

// Variáveis
int fila[TAMANHO];
int inicio = 0;
int fim = 0;
bool vazia = true;
bool cheia = false;

// Funções auxiliares
bool numero_existe(int valor) { // Remova a palavra-chave static
    int i = inicio;
    while (i != fim) {
        if (fila[i] == valor) {
            return true;
        }
        i = (i + 1) % TAMANHO;
    }
    return false;
}

// Adiciona um valor à fila
bool adicionar(int valor) {
    if (valor <= 0 || cheia || numero_existe(valor)) {
        return false;
    }
    fila[fim] = valor;
    fim = (fim + 1) % TAMANHO;

    if (fim == inicio) {
        cheia = true;
    }
    vazia = false;
    return true;
}

// Retira um valor da fila
bool retirar(int *valor) {
    if (vazia) {
        return false;
    }
    *valor = fila[inicio];
    inicio = (inicio + 1) % TAMANHO;

    if (inicio == fim) {
        vazia = true;
    }
    cheia = false;
    return true;
}

// Imprime a fila
void imprimir() {
    if (vazia) {
        printf("Fila Vazia\n");
        return;
    }

    printf("Fila: ");
    int i = inicio;
    while (true) {
        printf("%d ", fila[i]);
        if (i == (fim - 1 + TAMANHO) % TAMANHO) {
            break;
        }
        i = (i + 1) % TAMANHO;
    }
    printf("\n");
}
