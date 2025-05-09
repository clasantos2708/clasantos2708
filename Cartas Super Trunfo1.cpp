#include <stdio.h>

int main() {
    char nomeCidade1[50];
    char EstadoA;
    char codigodacarta1;
    int Populacao1;
    float Area1, PIB1;
    int Numerodepontosturisticos1;
    char nomeCidade2[50];
    char EstadoB;
    char codigodacarta2;
    int Populacao2;
    float Area2, PIB2;
    int Numerodepontosturisticos2;
    
    
    

    // Entrada para EstadoA e codigodacarta1
    printf("Estado A (letra): ");
    scanf(" %c ", &EstadoA);  

    printf("Codigo da carta1 (letra): ");
    scanf(" %c ", &codigodacarta1);

    printf("Nome da cidade1: ");
    scanf(" %49s ", nomeCidade1);  
		
    printf("Populacao1: ");
    scanf(" %d ", &Populacao1);
	 
    printf("Area1: ");
    scanf(" %f ", &Area1);
	 
    printf("PIB1: ");
    scanf(" %f ", &PIB1);
	 
    printf("Numero de pontos turisticos1: ");
    scanf(" %d ", &Numerodepontosturisticos1);
	 
    // EXIBIÇÃO DE DADOS CARTA 1
    printf("\n--- Carta1 ---\n");
    printf("Nome do estado A: %c\n ", EstadoA);
    printf("Codigo da carta1: %c\n ", codigodacarta1);
    printf("Nome da cidade1: %s\n ", nomeCidade1);
    printf("População: %d\n ", Populacao1);
    printf("Área1: %.2f\n ", Area1);
    printf("PIB1: %.2f\n ", PIB1);
    printf("Número de pontos turísticos1: %d\n ", Numerodepontosturisticos1);



    // Entrada para EstadoB e codigodacarta2
    printf("Estado B (letra): ");
    scanf(" %c ", &EstadoB);  

    printf("Codigo da carta2 (letra): ");
    scanf(" %c ", &codigodacarta2);

    printf("Nome da cidade2: ");
    scanf(" %49s ", nomeCidade2);  
		
    printf("Populacao2: ");
    scanf(" %d ", &Populacao2);
	 
    printf("Area2: ");
    scanf(" %f ", &Area2);
	 
    printf("PIB2: ");
    scanf(" %f ", &PIB2);
	 
    printf("Numero de pontos turisticos2: ");
    scanf(" %d ", &Numerodepontosturisticos2);
	 
    // EXIBIÇÃO DE DADOS CARTA 2
    printf("\n--- Carta2 ---\n");
    printf("Nome do estado B: %c\n ", EstadoB);
    printf("Codigo da carta2: %c\n ", codigodacarta2);
    printf("Nome da cidade2: %s\n ", nomeCidade2);
    printf("População2: %d\n ", Populacao2);
    printf("Área2: %.2f\n ", Area2);
    printf("PIB2: %.2f\n ", PIB2);
    printf("Número de pontos turísticos2: %d\n ", Numerodepontosturisticos2);

    return 0;
}

  

	

