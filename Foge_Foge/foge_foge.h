#ifndef FOGE_FOGE_H_INCLUDED
#define FOGE_FOGE_H_INCLUDED

/*  Constantes */
//  Menu
#define RODAR_JOGO 1
#define EXIBIR_RANK 2
#define SAIR_JOGO 0
//  Personagem
#define CIMA_PERSONAGEM 'w'
#define BAIXO_PERSONAGEM 's'
#define DIREITA_PERSONAGEM 'd'
#define ESQUERDA_PERSONAGEM 'a'
//  Fantasmas
#define FANTASMA_MOVIMENTOS 4
#define CIMA_FANTASMA 0
#define BAIXO_FANTASMA 1
#define DIREITA_FANTASMA 2
#define ESQUERDA_FANTASMA 3
//  Leveis
#define LEVEL_1 1
#define LEVEL_2 2
#define LEVEL_3 3
#define ZEROU_JOGO 4

/*  Struct */
//  Personagem
struct dados_personagem
{
    int x;
    int y;
};
typedef struct dados_personagem personagem;
//  inimigo
struct dados_fantasmas
{
    int x;
    int y;
};
typedef struct dados_fantasmas inimigo;

/*  Funcoes */
int imprimir_menu(int opcao);
int verificar_opcao(int opcao);
void localizar_personagem(void);
void movimentar_personagem(char comando);
int verificar_movimento_personagem(int x, int y);
void atualizar_personagem(int x, int y);
void localizar_fantasmas(void);
void movimentar_fantasmas(int indice);
int verificar_movimento_fantasmas(int x, int y);
void atualizar_fantasmas(int indice, int x, int y);
int completar_level(int level);
int verificar_gameover(int level);
void liberar_memoria_fantasmas(void);

#endif // FOGE_FOGE_H_INCLUDED