#include <stdio.h>
#include <string.h>

int main() {
    // Definição da struct Territorio armazena informações do território
    // A struct agrupa dados diferentes em uma única unidade
    struct Territorio {
        char nome[30];  // Nome do território (string de até 29 caracteres + null terminator)
        char cor[10];   // Cor do exército (string de até 9 caracteres + null terminator)
        int tropas;     // Quantidade de tropas (inteiro)
    };

    // Declaração de um vetor de struct armazena 5 territórios
    // Cria uma "base de dados" simples em memória
    struct Territorio territorios[5]; 

    // Laço para cadastro dos 5 territórios
    // Utilizei um loop for para iterar o vetor e coletar entradas do usuário
    for (int i = 0; i < 5; i++) {
        printf("Cadastro do Territorio %d:\n", i + 1);

        // Entrada do nome do território
        printf("Digite o nome do territorio: ");
        scanf("%29s", territorios[i].nome);  // Limita a leitura para evitar overflow

        // Entrada da cor do exército
        printf("Digite a cor do exercito: ");
        scanf("%9s", territorios[i].cor);   // Limita a leitura para evitar overflow

        // Entrada do número de tropas
        printf("Digite o numero de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");  // Linha em branco para melhor legibilidade
    }

    // Exibe os dados cadastrados
    // Outro laço for para percorrer o vetor e imprime as informações de cada território
    printf("Dados dos Territorios Cadastrados:\n");
    for (int i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exercito: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
        printf("\n");  // Linha em branco para separar os territórios
    }

    return 0;
}

  

	



