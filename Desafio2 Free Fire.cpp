
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Capacidade máxima da mochila
#define MAX_ITENS 10
#define TAM_NOME 30
#define TAM_TIPO 20

// Estrutura que representa um item no inventário 
typedef struct {
    char nome[TAM_NOME];    // Nome do item (ex: "AK-47", "Kit Médico")
    char tipo[TAM_TIPO];    // Tipo do item (ex: "arma", "cura", "munição")
    int quantidade;         // Quantidade disponível
} Item;

// Vetor global que simula a mochila 
Item mochila[MAX_ITENS];
int totalItens = 0;  // Controla quantos itens estão atualmente na mochila

// Funções
void inserirItem();
void removerItem();
void listarItens();
void buscarItem();
void limparBuffer();

void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("\n[AVISO] Mochila cheia! Remova itens antes de adicionar novos.\n");
        return;
    }

    Item novo;
    
    printf("\n=== CADASTRO DE ITEM ===\n");
    printf("Nome do item (max %d caracteres): ", TAM_NOME - 1);
    limparBuffer(); // Remove resíduos do buffer
    fgets(novo.nome, TAM_NOME, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0'; // Remove \n

    printf("Tipo do item (arma, municao, cura, ferramenta): ");
    fgets(novo.tipo, TAM_TIPO, stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    // Validação básica
    if (novo.quantidade <= 0) {
        printf("[ERRO] Quantidade deve ser maior que zero!\n");
        return;
    }

    // Adiciona na próxima posição livre
    mochila[totalItens] = novo;
    totalItens++;

    printf("[SUCESSO] Item '%s' adicionado com sucesso!\n", novo.nome);
    listarItens();
}

/*
 * Função: removerItem
 * Descrição: Remove um item da mochila pelo nome.
 *            Usa busca sequencial para localizar e desloca os itens restantes.
 */
void removerItem() {
    if (totalItens == 0) {
        printf("\n[AVISO] A mochila está vazia!\n");
        return;
    }

    char nomeBusca[TAM_NOME];
    printf("\n=== REMOÇÃO DE ITEM ===\n");
    printf("Digite o nome do item a remover: ");
    limparBuffer();
    fgets(nomeBusca, TAM_NOME, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("[REMOVIDO] Item '%s' (%dx) removido da mochila.\n", 
                   mochila[i].nome, mochila[i].quantidade);

            // Desloca todos os itens seguintes uma posição para trás
            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            totalItens--;
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("[ERRO] Item '%s' não encontrado na mochila.\n", nomeBusca);
    }

    listarItens();
}

/*
 * Função: listarItens
 * Descrição: Exibe todos os itens atualmente na mochila com formatação clara.
 *            Mostra mensagem se estiver vazia.
 */
void listarItens() {
    printf("\n=== MOCHILA ATUAL (%d/%d) ===\n", totalItens, MAX_ITENS);
    
    if (totalItens == 0) {
        printf("  [Vazia] - Colete itens rapidamente!\n");
    } else {
        printf("  %-25s %-12s %s\n", "NOME", "TIPO", "QTD");
        printf("  %s\n", "------------------------------------------------");
        for (int i = 0; i < totalItens; i++) {
            printf("  %-25s %-12s %d\n", 
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
        }
    }
    printf("================================\n");
}

/*
 * Função: buscarItem
 * Descrição: Realiza busca sequencial pelo nome do item e exibe seus dados.
 */
void buscarItem() {
    if (totalItens == 0) {
        printf("\n[AVISO] A mochila está vazia!\n");
        return;
    }

    char nomeBusca[TAM_NOME];
    printf("\n=== BUSCA DE ITEM ===\n");
    printf("Digite o nome do item: ");
    limparBuffer();
    fgets(nomeBusca, TAM_NOME, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\n[ENCONTRADO]\n");
            printf("  Nome: %s\n", mochila[i].nome);
            printf("  Tipo: %s\n", mochila[i].tipo);
            printf("  Quantidade: %d\n", mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n[NAO ENCONTRADO] Item '%s' não está na mochila.\n", nomeBusca);
    }
}

/*
 * Função: limparBuffer
 * Descrição: Remove caracteres residuais do buffer de entrada (útil após scanf).
 */
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*
 * Função: exibirMenu
 * Descrição: Mostra o menu interativo com opções claras.
 */
void exibirMenu() {
    printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║        SISTEMA DE INVENTÁRIO         ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("  1. Adicionar Item\n");
    printf("  2. Remover Item\n");
    printf("  3. Listar Mochila\n");
    printf("  4. Buscar Item\n");
    printf("  0. Sair do Jogo\n");
    printf("Escolha uma opção: ");
}

/*
 * Função principal
 */
int main() {
    int opcao;

    printf("Bem-vindo ao Sistema de Loot Inicial!\n");
    printf("Colete recursos rapidamente para sobreviver!\n");

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 0:
                printf("\nSaindo... Boa sorte na sobrevivência!\n");
                break;
            default:
                printf("[ERRO] Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
