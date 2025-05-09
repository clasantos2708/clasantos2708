#include <stdio.h>

int main() {
    // Simula o movimento da Torre usando estrutura 'for'
    // Torre se move 5 casas para a direita
    int movimentoTorre = 5;
    printf("Movimento da Torre:\n");
    for (int i = 0; i < movimentoTorre; i++) {
        printf("Direita\n");
    }

    printf("\n");

    // Simula o movimento do Bispo usando estrutura 'while'
    // Bispo se move 5 casas na diagonal para cima e à direita
    int movimentoBispo = 5;
    int contadorBispo = 0;
    printf("Movimento do Bispo:\n");
    while (contadorBispo < movimentoBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }

    printf("\n");

    // Simula o movimento da Rainha usando estrutura 'do-while'
    // Rainha se move 8 casas para a esquerda
    int movimentoRainha = 8;
    int contadorRainha = 0;
    printf("Movimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < movimentoRainha);

    return 0;
}

