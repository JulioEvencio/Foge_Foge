//  Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

//  Funcao que gera uma matriz por alocacao dinamica
void gerar_matriz(Mapa *m)
{
    m->matriz = malloc(sizeof(char*) * m->linha);
    for(int loop = 0; loop < m->linha; loop++)
    {
        m->matriz[loop] = malloc(sizeof(char) * m->coluna + 1);
    }
}

//  Funcao que ler o arquivo mapa.txt e copia na matriz mapa
void ler_mapa(Mapa *m, char level[])
{
    FILE *file;
    file = fopen(level, "r");
    if(file == 0)
    {
        printf("Erro na leitura do mapa! \n");
        exit(1);
    }
    fscanf(file, "%d", &(m->linha));
    fscanf(file, "%d", &(m->coluna));
    gerar_matriz(m);
    for(int linha = 0; linha < m->linha; linha++)
    {
        fscanf(file, "%s", m->matriz[linha]);
    }
    fclose(file);
}

//  Funcao que imprime o mapa na tela
void imprimir_mapa(Mapa *m)
{
    for(int linha = 0; linha < m->linha; linha++)
    {
        for(int parte = 0; parte < DESENHO_LINHA; parte++)
        {
            for(int coluna = 0; coluna < m->coluna; coluna++)
            {
                desenhar_tela(m->matriz[linha][coluna], parte);
            }
            printf("\n");
        }
    }
}

//  Funcao que desenha na tela
void desenhar_tela(char desenho, int parte)
{
    switch(desenho)
    {
        case(MAPA_PERSONAGEM):
            printf("%s", desenho_personagem[parte]);
            break;
        case(MAPA_FANTASMA):
            printf("%s", desenho_fantasma[parte]);
            break;
        case(MAPA_CAMINHO):
            printf("%s", desenho_caminho[parte]);
            break;
        case(MAPA_PAREDE):
            printf("%s", desenho_parede[parte]);
            break;
        case(MAPA_OBETIVO):
            printf("%s", desenho_objetivo[parte]);
            break;
        default:
            printf("Erro ao gerar mapa! \n");
            exit(1);
    }
}

//  Funcao que identifica a quantidade de elementos do mapa
void identificar_elementos(Mapa *m)
{
    m->fantasmas = 0;
    m->objetivo = 0;
    for(int linha = 0; linha < m->linha; linha++)
    {
        for(int coluna = 0; coluna < m->coluna; coluna++)
        {
            if(m->matriz[linha][coluna] == MAPA_FANTASMA)
            {
                m->fantasmas++;
            }
            if(m->matriz[linha][coluna] == MAPA_OBETIVO)
            {
                m->objetivo++;
            }
        }
    }
}

//  Funcao que libera os espacos de memoria da matriz
void liberar_matriz(Mapa *m)
{
    for(int loop = 0; loop < m->linha; loop++)
    {
        free(m->matriz[loop]);
    }
    free(m->matriz);
}