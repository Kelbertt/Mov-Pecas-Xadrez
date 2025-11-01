#include <stdio.h>
#include <locale.h>
#include <windows.h>

const int MOVIMENTOS_TORRE = 5;
const int MOVIMENTOS_RAINHA = 8;
const int MOVIMENTOS_BISPO = 5;

const int CAVALO_MOVER_VERTICAL = 2;
const int CAVALO_MOVER_HORIZONTAL = 1;

void setup_console() {
    setlocale(LC_ALL, "pt_BR");
    SetConsoleOutputCP(CP_UTF8); 
    SetConsoleCP(CP_UTF8);
}

void simular_torre_recursiva(int casas_restantes) {
    if (casas_restantes == 0) {
        return;
    }

    printf("Direita\n");

    simular_torre_recursiva(casas_restantes - 1);
}

void simular_rainha_recursiva(int casas_restantes) {
    if (casas_restantes == 0) {
        return;
    }

    printf("Esquerda\n");

    simular_rainha_recursiva(casas_restantes - 1);
}

void bispo_passo_diagonal(int passo_atual) {
    for (int i = 0; i < 1; i++) {
        printf("Cima");

        int j = 0;
        while (j < 1) {
            printf(" Direita\n");
            j++;
            break;
        }
    }
}

void simular_bispo_recursivo_e_aninhado(int casas_restantes) {
    if (casas_restantes == 0) {
        return;
    }

    bispo_passo_diagonal(MOVIMENTOS_BISPO - casas_restantes + 1);

    simular_bispo_recursivo_e_aninhado(casas_restantes - 1);
}

void simular_cavalo_complexo() {
    printf("==========================================\n");
    printf("Simulação do Movimento do CAVALO (Loops Aninhados Complexos)\n");
    printf("Movendo %d casas para Cima e %d casa para a Direita (Formando um 'L'):\n",
           CAVALO_MOVER_VERTICAL, CAVALO_MOVER_HORIZONTAL);
    printf("==========================================\n");

    int i = 0;
    int j = 0;

    for (; i < CAVALO_MOVER_VERTICAL; i++) {
        printf("Cima\n");

        if (i < CAVALO_MOVER_VERTICAL - 1) {
            continue;
        }

        while (j < CAVALO_MOVER_HORIZONTAL) {
            printf("Direita\n");
            j++;
            break;
        }

        if (j == CAVALO_MOVER_HORIZONTAL) {
            break;
        }
    }

    printf("\nCavalo finalizou o movimento em 'L' (2 Cima, 1 Direita).\n\n");
}

int main() {
    setup_console();
    
    printf("==========================================\n");
    printf("Simulação da TORRE (RECURSIVIDADE)\n");
    printf("Movendo %d casas para a Direita:\n", MOVIMENTOS_TORRE);
    printf("==========================================\n");
    simular_torre_recursiva(MOVIMENTOS_TORRE);
    printf("\nTorre finalizou o movimento de %d casas.\n\n", MOVIMENTOS_TORRE);

    printf("==========================================\n");
    printf("Simulação da RAINHA (RECURSIVIDADE)\n");
    printf("Movendo %d casas para a Esquerda:\n", MOVIMENTOS_RAINHA);
    printf("==========================================\n");
    simular_rainha_recursiva(MOVIMENTOS_RAINHA);
    printf("\nRainha finalizou o movimento de %d casas.\n\n", MOVIMENTOS_RAINHA);

    printf("==========================================\n");
    printf("Simulação do BISPO (RECURSIVIDADE + LOOPS ANINHADOS)\n");
    printf("Movendo %d casas na diagonal Cima e Direita:\n", MOVIMENTOS_BISPO);
    printf("==========================================\n");
    simular_bispo_recursivo_e_aninhado(MOVIMENTOS_BISPO);
    printf("\nBispo finalizou o movimento de %d casas.\n\n", MOVIMENTOS_BISPO);

    simular_cavalo_complexo();

    return 0;
}
