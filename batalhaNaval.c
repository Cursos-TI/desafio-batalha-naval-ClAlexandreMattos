/*#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
*/

#include <stdio.h>

#define LINHA 10
#define COLUNA 10
#define AGUA 0
#define NAVIO 3
#define NavioDiagonal 4
#define Submarino 8
#define Cone 5
#define Cruz 7
#define Octaedro 9

int main() {
    int tabuleiro[LINHA][COLUNA];

    // Inicializa o tabuleiro com agua
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posiciona o navio horizontalmente
    int navioHorizontalLinha = 4;    // Linha onde o navio horizontal começa
    int navioHorizontalColuna = 5;    // Coluna onde o navio horizontal começa
    int tamanhoNavioHorizontal = 3;    // Tamanho do navio horizontal

    for (int j = navioHorizontalColuna; j < navioHorizontalColuna + tamanhoNavioHorizontal; j++) {
        tabuleiro[navioHorizontalLinha][j] = NAVIO;
    }

    // Posiciona o navio verticalmente
    int navioVerticalLinha = 5;      // Linha onde o navio vertical começa
    int navioVerticalColuna = 1;      // Coluna onde o navio vertical começa
    int tamanhoNavioVertical = 3;      // Tamanho do navio vertical

    for (int i = navioVerticalLinha; i < navioVerticalLinha + tamanhoNavioVertical; i++) {
        tabuleiro[i][navioVerticalColuna] = NAVIO;
    }

    //Posiciona o navio na diagonal
    int navioDiagonallLinha = 6;      // Linha onde o navio Diagonal começa
    int navioDiagonalColuna = 4;      // Coluna onde o navio Diagonal começa
    
    // Coloca o navio em diagonal
    for (int i = 0; i < 3; i++) {
        tabuleiro[navioDiagonallLinha + i][navioDiagonalColuna - i] = NavioDiagonal; // 4 representa o navio que está invertido em relação ao outro

    }

    //Posiciona o navio na diagonal2
    int navioDiagonal2lLinha = 0;      // Linha onde o navio Diagonal2 começa
    int navioDiagonal2Coluna = 0;      // Coluna onde o navio Diagonal2  começa
    
    
    // Coloca o navio em diagonal
    for (int i = 0; i < 3; i++) {
        tabuleiro[navioDiagonal2lLinha + i][navioDiagonal2Coluna + i] = NavioDiagonal; // 4 representa o navio
    }

    /*
    //Posiciona o submarino com dois espaços na diagonal **  desconsiderar para exercício  **
    int submarinoDiagonalLinha = 5;      // Linha onde o navio Diagonal começa
    int submarinoDiagonalColuna = 7;      // Coluna onde o navio Diagonal começa
    int tamanhoSubmarinoDiagonal = 2;      // Tamanho do navio diagonal

    // Coloca o submarino em diagonal
    for (int i = 0; i < 2; i++) {
        tabuleiro[submarinoDiagonalLinha + i][submarinoDiagonalColuna + i] = Submarino; // 4 representa o navio

    }*/

    


                        /******* SUPER PODERES *******/


// Posiciona o Cone
int ConeLinha = 3;    // Linha onde o navio horizontal começa
int ConeColuna = 7;    // Coluna onde o navio horizontal começa
int tamanhocone  = 3;    // Tamanho do navio horizontal

for (int i = 0; i < ConeLinha; i++) {
    for (int j = 0;j <= i;j++){
    tabuleiro[ConeLinha - i][ConeColuna -j] = Cone; //Desenho o lado Esquerdo
    tabuleiro[ConeLinha - i][ConeColuna +j] = Cone; //desenho o lado Direito
}
// Posiciona Cruz
int Cruzlinha = 3; 
int CruzColuna = 3;
//Minha duvida sobre como consigo aumentar a cruz em dois espaços para cada lado
if (Cruzlinha >= 0 && Cruzlinha < tabuleiro && CruzColuna >= 0 && CruzColuna < tabuleiro) {
    tabuleiro[Cruzlinha][CruzColuna] = Cruz; // Marca o centro da cruz
    if (Cruzlinha - 1 >= 0) tabuleiro[Cruzlinha - 2][CruzColuna] = Cruz; // Acima
    if (Cruzlinha + 2 < tabuleiro) tabuleiro[Cruzlinha + 2][CruzColuna] = Cruz; // Abaixo
    if (CruzColuna - 2 >= 0) tabuleiro[Cruzlinha][CruzColuna - 2] = Cruz; // Esquerda
    if (CruzColuna + 2 < tabuleiro) tabuleiro[Cruzlinha][CruzColuna + 2] = Cruz; // Direita
}

// Posicionar octaedro 
int octaLinha = 7;
int octaColuna = 7;

if(octaLinha >= 0 && octaLinha < tabuleiro && octaColuna >= 0 && octaColuna < tabuleiro){
// Exemplo de como colocar um octaedro em uma posição (x, y)
// Aqui, estamos apenas marcando a posição central e as adjacentes
tabuleiro[octaLinha][octaColuna] = Octaedro; // Centro do octaedro
tabuleiro[octaLinha-1][octaColuna] = Octaedro; // Cima
tabuleiro[octaLinha+1][octaColuna] = Octaedro; // Baixo
tabuleiro[octaLinha][octaColuna-1] = Octaedro; // Esquerda
tabuleiro[octaLinha][octaColuna+1] = Octaedro; // Direita
}
}

    // Exibe o tabuleiro
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < LINHA; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLUNA; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    return 0;
}