// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
// Nível: NOVATO
// 
// OBJETIVOS:
// 
// Criar a base de territórios do jogo War
// Definir struct Território
// Permitir o cadastro de 5 territórios com nome, cor do exercito e quantidade de tropas
// Após cadastro, listar os territórios cadastrados, estado atual das tropas

// Inclusão das bibliotecas utilizadas
#include <stdio.h>
#include <string.h>

// Definir struct Territorio
struct Territorio {
    char nome[30]; // Nome do territorio
    char cor[10]; // Cor do exército
    int tropas; // Quantidade de tropas alocadas no território
};

// Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Definindo a constante fora da função
#define MAX_TERRITORIOS 5

// --- Função Principal (main) ---
int main() {
    // Declaração do vetor de structs DENTRO da função principal (escopo local)
    struct Territorio mapa[MAX_TERRITORIOS];
    int totalTerritorios = 0;

    printf("==============================\n");
    printf("BEM VINDO AO JOGO WAR!\n");
    printf("==============================\n");
    printf("Vamos cadastrar os territorios do nosso mapa.\n");
    printf("==============================\n"); 
    
    for (int i = 0; i < MAX_TERRITORIOS; i++) {   

        printf("\nTerritório %d:\n", i + 1);
        
        // 1. Nome do Território
        printf("Digite o nome do território: ");
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = 0;  // Remover nova linha

        // 2. Cor do Exército
        printf("Digite a cor do exército: "); // Mudei a mensagem para refletir a struct
        fgets(mapa[i].cor, sizeof(mapa[i].cor), stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = 0;  // Remover nova linha
        
        // 3. Número de Tropas
        printf("Digite o número de tropas do território: "); // Corrigi o acento
        scanf("%d", &mapa[i].tropas);

        // A limpeza do buffer é crucial após o scanf para o próximo fgets funcionar
        limparBufferEntrada(); 
        totalTerritorios++;
    }

    // Lista dos territórios cadastrados
    printf("\n\n==============================\n");
    printf("Territórios Cadastrados: \n");
    printf("==============================\n");


    // Exibição dos dados
    printf("\n=== Estado Atual do Mapa ===\n");
    for (int i = 0; i < totalTerritorios; i++) { // Usei totalTerritorios para maior segurança
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do exército: %s\n", mapa[i].cor);
        printf("Tropas: %d\n\n", mapa[i].tropas);
    }

    return 0;
}