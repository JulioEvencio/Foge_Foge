#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

/*  Constantes */
//  Mapa
#define MAPA_PERSONAGEM '@'
#define MAPA_FANTASMA 'F'
#define MAPA_OBETIVO 'O'
#define MAPA_CAMINHO '.'
#define MAPA_PAREDE '|'
#define MAPA_LEVEL_1 "mapa/level_1.txt"
#define MAPA_LEVEL_2 "mapa/level_2.txt"
#define MAPA_LEVEL_3 "mapa/level_3.txt"
//  Desenho
#define DESENHO_LINHA 4
#define DESENHO_COLUNA 7

/*  Structs */
//  Mapa
struct dados_mapa
{
    char **matriz;
    int linha;
    int coluna;
    int level;
    int objetivo;
    char fantasmas;
};
typedef struct dados_mapa Mapa;

/*  Matrizes */
//  Personagem
char desenho_personagem[DESENHO_LINHA][DESENHO_COLUNA] =
{
    {" .--. "},
    {"/ _.-'"},
    {"\\ '-. "},
    {" '--' "}
};
//  Fantasmas
char desenho_fantasma[DESENHO_LINHA][DESENHO_COLUNA] =
{
    {" .-.  "},
    {"| OO| "},
    {"|   | "},
    {"'^^^' "}
};
//  Parede
char desenho_parede[DESENHO_LINHA][DESENHO_COLUNA] =
{
    {"......"},
    {"......"},
    {"......"},
    {"......"}
};
//  Caminho
char desenho_caminho[DESENHO_LINHA][DESENHO_COLUNA] =
{
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};
//  Objetivo
char desenho_objetivo[DESENHO_LINHA][DESENHO_COLUNA] =
{
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

/*  Funcoes */
void gerar_matriz(Mapa *m);
void ler_mapa(Mapa *m, char level[]);
void imprimir_mapa(Mapa *m);
void desenhar_tela(char desenho, int parte);
void identificar_elementos(Mapa *mapa);
void liberar_matriz(Mapa *m);

#endif // MAPA_H_INCLUDED