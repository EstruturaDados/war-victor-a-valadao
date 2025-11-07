// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
// Nível: NOVATO
// 
// OBJETIVOS:
// 
// Criar a base de territórios do jogo War
// Definir struct Território
// Permitir qo cadastro de 5 territórios com nome, cor do exercito e quantidade de tropas
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

//Declarar vetor de structs mapa, com capacidade para 5 territórios
    #define MAX_TERRITORIOS 5
    struct Territorio mapa[MAX_TERRITORIOS];
    int totalTerritorios = 0;


// --- Função Principal (main) ---
int main() {

        printf("==============================\n");
        printf("BEM VINDO AO JOGO WAR!\n");
        printf("==============================\n");
        printf("Vamos cadastrar os territorios do nosso mapa.\n");
        printf("==============================\n"); 
        
        for (int i = 0; i < MAX_TERRITORIOS; i++) {   

        printf("\nTerritório %d:\n", i + 1);
        printf("Digite o nome do território: ");
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = 0;  // Remover nova linha

        printf("Digite a cor do território: ");
        fgets(mapa[i].cor, sizeof(mapa[i].cor), stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = 0;  // Remover nova linha
        
        printf("Digite o numero de tropas do território: ");
        scanf("%d", &mapa[i].tropas);

        limparBufferEntrada();
        totalTerritorios++;
    }

    // Lista dos territórios cadastrados
    printf("Territórios Cadastrados: \n");

    for (int i = 0; i < totalTerritorios; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do Exército: %s\n", mapa[i].cor);
        printf("Número de Tropas: %d\n", mapa[i].tropas);
        printf("-------------------------\n");
    }
    
        return 0;
};

