#ifndef FILACIRCULAR_FILACIRCULAR_H
#define FILACIRCULAR_FILACIRCULAR_H

#include <stdbool.h>

// Constantes
enum {
    TAMANHO = 5
};

// Enum para as opções do menu
typedef enum {
    OP_ADICIONAR = 1,
    OP_RETIRAR,
    OP_IMPRIMIR,
    OP_SAIR
} OpcaoMenu;

// Variáveis
extern int fila[TAMANHO];
extern int inicio;
extern int fim;
extern bool vazia;
extern bool cheia;

// Protótipos
bool adicionar(int valor);
bool retirar(int *valor);
void imprimir();
bool numero_existe(int valor);

#endif
