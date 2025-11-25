#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// --- DEFINIÇÕES E CONSTANTES ---
#define MAX_MESAS 10

// Definição dos Status da Mesa (Melhora a leitura do código)
typedef enum { LIVRE, RESERVADA } Status;

// --- ESTRUTURA HETEROGÊNEA (TAD) ---
typedef struct {
    int numero;             // Inteiro
    int capacidade;         // Inteiro (2, 4, 6, 8 lugares)
    Status status;          // Enum (Dado customizado)
    char nome_cliente[50];  // String (Vetor de char)
} Mesa;

// Variável Global (Vetor de Estruturas)
Mesa restaurante[MAX_MESAS];

// --- PROTÓTIPOS DAS FUNÇÕES ---
void inicializarRestaurante();
void exibirMenu();
void listarMesas();
void fazerReserva();
// void cancelarReserva(); // Implementar depois

// --- FUNÇÃO MAIN ---
int main() {
    setlocale(LC_ALL, "Portuguese"); // Para aceitar acentos
    int opcao;

 
    inicializarRestaurante();

    do {
        exibirMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch(opcao) {
            case 1:
                listarMesas();
                break;
            case 2:
                fazerReserva();
                break;
            case 3:
                printf("\nFunção de cancelamento ainda não implementada.\n");
                break;
            case 0:
                printf("\nEncerrando sistema...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
        
        printf("\nPressione Enter para continuar...");
        getchar();
      
        
    } while (opcao != 0);

    return 0;
}




void inicializarRestaurante() {
    for(int i = 0; i < MAX_MESAS; i++) {
        restaurante[i].numero = i + 1;
        restaurante[i].status = LIVRE;
        strcpy(restaurante[i].nome_cliente, ""); 
        
       
        if(i < 4) {
            restaurante[i].capacidade = 2; 
        } else if (i < 8) {
            restaurante[i].capacidade = 4; 
        } else {
            restaurante[i].capacidade = 8; 
        }
    }
}

void exibirMenu() {
    printf("\n=== GESTÃO DE RESTAURANTE ===\n");
    printf("1. Visualizar Mapa de Mesas\n");
    printf("2. Realizar Nova Reserva\n");
    printf("3. Cancelar Reserva\n");
    printf("0. Sair\n");
    printf("=============================\n");
}

void listarMesas() {
    printf("\n--- STATUS DO SALÃO ---\n");
    for(int i = 0; i < MAX_MESAS; i++) {
        printf("Mesa %02d [%d lug] - ", restaurante[i].numero, restaurante[i].capacidade);
        
        if(restaurante[i].status == LIVRE) {
            printf("[ LIVRE ]\n");
        } else {
            printf("[ RESERVADA: %s ]\n", restaurante[i].nome_cliente);
        }
    }
}

void fazerReserva() {
   
    printf("\n--- NOVA RESERVA ---\n");
    printf("Implemente a lógica de busca e inserção aqui...\n");
}