#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <stdbool.h>
#define Maxpilha 30

typedef struct {
    int dados[Maxpilha];
    int topo;
} Pilha;

Pilha pilha;

void IniciarPilha() {
    pilha.topo = -1;
}

bool PilhaCheia() {
    return pilha.topo == Maxpilha - 1;
}

bool PilhaVazia() {
    return pilha.topo == -1;
}

void Empilhar(int item) {
    if (PilhaCheia()) {
        printf("Erro: a pilha esta cheia.\n");
        return;
    }
    pilha.dados[++pilha.topo] = item;
    printf("Elemento %d empilhado com sucesso!\n", item);
}

void Desempilhar() {
    if (PilhaVazia()) {
        printf("Erro: a pilha esta vazia.\n");
        return;
    }
    int item = pilha.dados[pilha.topo--];
    printf("Elemento %d desempilhado com sucesso!\n", item);
}

void Topo() {
    if (PilhaVazia()) {
        printf("Erro: a pilha esta vazia.\n");
        return;
    }
    printf("Topo da pilha: %d\n", pilha.dados[pilha.topo]);
}

void Limpar() {
    if (PilhaVazia()) {
        printf("Erro: a pilha ja esta vazia.\n");
        return;
    }
    IniciarPilha();
    printf("Pilha limpa com sucesso!\n");
}

int main() {
    IniciarPilha();
    int opcao, elemento;
    
    while (true) {
        printf("\nMenu:\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Limpar\n");
        printf("4. Mostrar pilha\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser empilhado: ");
                scanf("%d", &elemento);
                Empilhar(elemento);
                break;
            case 2:
                Desempilhar();
                break;
            case 3:
                Limpar();
                break;
            case 4:
                if (PilhaVazia()) {
                    printf("A pilha esta vazia.\n");
                } else {
                    printf("Elementos da pilha:\n");
                    for (int i = 0; i <= pilha.topo; i++) {
                        printf("Posicao %2d: %d\n", i, pilha.topo);
                    }
                    Topo();
                }
                break;
            case 5:
                printf("Programa encerrado.\n");
                return 0;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }
}
