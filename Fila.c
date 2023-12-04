#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Maxfila 100
#define TamanhoString 40

typedef char ElementoDaFila[TamanhoString];

typedef struct {
    ElementoDaFila elementos[Maxfila];
    int primeiro;
    int ultimo;
    int quantidade;
} Fila;

Fila fila;

void inicializarFila() {
    fila.primeiro = 0;
    fila.ultimo = -1;
    fila.quantidade = 0;
}

int filaEstaCheia() {
    return (fila.quantidade == Maxfila);
}

int filaEstaVazia() {
    return (fila.quantidade == 0);
}

void enfileirar(ElementoDaFila elemento) {
    if (filaEstaCheia()) {
        printf("A fila esta cheia.\n");
        return;
    }

    fila.ultimo = (fila.ultimo + 1) % Maxfila;
    strcpy(fila.elementos[fila.ultimo], elemento);
    fila.quantidade++;
}

void desenfileirar(ElementoDaFila elemento) {
    if (filaEstaVazia()) {
        printf("A fila esta vazia.\n");
        strcpy(elemento, "");  // Retornar uma string vazia em caso de fila vazia
    } else {
        strcpy(elemento, fila.elementos[fila.primeiro]);
        fila.primeiro = (fila.primeiro + 1) % Maxfila;
        fila.quantidade--;
    }
}

void limparFila() {
    inicializarFila();
    printf("A fila foi limpa.\n");
}

void mostrarFila() {
    if (filaEstaVazia()) {
        printf("A fila esta vazia.\n");
    } else {
        printf("Elementos da fila:\n");
        int i;
        for (i = 0; i < fila.quantidade; i++) {
            printf("%s\n", fila.elementos[(fila.primeiro + i) % Maxfila]);
        }
    }
}

int main() {
    inicializarFila();
    int opcao;
    ElementoDaFila elemento;

	while (1) {
		
    printf("\nMenu:\n");
    printf("1. Enfileirar\n");
    printf("2. Desenfileirar\n");
    printf("3. Limpar fila\n");
    printf("4. Mostrar fila\n");
    printf("5. Sair do programa\n");

   
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser enfileirado: ");
                scanf("%s", elemento);
                enfileirar(elemento);
                break;
            case 2:
                desenfileirar(elemento);
                printf("Desenfileirado: %s\n", elemento);
                break;
            case 3:
                limparFila();
                break;
            case 4:
                mostrarFila();
                break;
            case 5:
                printf("Encerrando o programa.\n");
                return 0;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }

    return 0;
}
