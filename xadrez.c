#include <stdio.h>

/* ===============================
   FUNÇÕES RECURSIVAS
   =============================== */

/* ----------- TORRE -----------
   Move-se em linha reta horizontalmente.
   Recursão: cada chamada representa uma casa à direita.
*/
void moverTorre(int casas, int atual) {
    if (atual > casas) return; // caso base: parando a recursão
    printf("Torre -> Direita (%d casa)\n", atual);
    moverTorre(casas, atual + 1); // chamada recursiva para a próxima casa
}

/* ----------- BISPO -----------
   Move-se na diagonal (Cima + Direita).
   Recursão + loops aninhados: o loop externo representa
   o movimento vertical e o interno o movimento horizontal.
*/
void moverBispo(int casas, int atual) {
    if (atual > casas) return; // caso base

    // loops aninhados apenas para mostrar interação entre movimentos verticais e horizontais
    for (int vertical = 1; vertical <= 1; vertical++) { // vertical: 1 passo por vez
        for (int horizontal = 1; horizontal <= 1; horizontal++) { // horizontal: 1 passo por vez
            printf("Bispo -> Cima, Direita (%d casa)\n", atual);
        }
    }

    moverBispo(casas, atual + 1); // próxima chamada recursiva
}

/* ----------- RAINHA -----------
   Move-se em qualquer direção.
   Aqui simulamos movimento contínuo para a Esquerda.
   Recursão simples.
*/
void moverRainha(int casas, int atual) {
    if (atual > casas) return; // caso base
    printf("Rainha -> Esquerda (%d casa)\n", atual);
    moverRainha(casas, atual + 1);
}

/* ===============================
   LOOPS COMPLEXOS: CAVALO
   =============================== */

/* ----------- CAVALO -----------
   Move-se em "L": duas casas para cima e uma para a direita.
   Usa loops aninhados com múltiplas variáveis e controle de fluxo.
*/
void moverCavalo() {
    printf("=== Movimento do Cavalo ===\n");

    // as variáveis simulam as posições no tabuleiro
    for (int cima = 1; cima <= 2; cima++) {       // duas casas para cima
        for (int direita = 1; direita <= 2; direita++) { // duas tentativas para direita
            if (cima == 2 && direita == 1) {
                // movimento válido do cavalo (duas pra cima e uma pra direita)
                printf("Cavalo -> Cima (%d), Direita (%d)\n", cima, direita);
                break; // sai do loop interno após o movimento em "L"
            }

            // ignora movimentos que não formam o "L"
            if (cima == direita) continue;
        }
    }

    printf("\n");
}

/* ===============================
   FUNÇÃO PRINCIPAL
   =============================== */
int main() {
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    printf("=== MOVIMENTOS COMPLEXOS NO XADREZ ===\n\n");

    // ---------------- TORRE ----------------
    printf("=== Movimento da Torre (Recursivo) ===\n");
    moverTorre(casasTorre, 1);
    printf("\n");

    // ---------------- BISPO ----------------
    printf("=== Movimento do Bispo (Recursivo + Loops Aninhados) ===\n");
    moverBispo(casasBispo, 1);
    printf("\n");

    // ---------------- RAINHA ----------------
    printf("=== Movimento da Rainha (Recursivo) ===\n");
    moverRainha(casasRainha, 1);
    printf("\n");

    // ---------------- CAVALO ----------------
    moverCavalo();

    printf("Simulação finalizada com sucesso!\n");

    return 0;
}
