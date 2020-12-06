/******************************************************/
/*  Instituto Federal do Maranhao                     */
/*  Data: 01/12/2020                                  */
/*  Disciplina: Linguagem de Programacao I            */
/*  Professora: Evaldinolia Gilbertoni Moreira        */
/*  Nome: Marcelo Jhones e Julio Evencio              */
/*  Foge Foge  -versao 1.0                            */
/******************************************************/

//  Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "foge_foge.h"
#include "foge_foge.c"
#include "mapa/mapa.h"
#include "mapa/mapa.c"

int main()
{
    //  Definindo semente para a funcao rand
    srand(time(NULL));

    //  Variavel que controla o menu
    int menu;

    do
    {
        //  Imprimindo menu
        menu = imprimir_menu(menu);

        //  Verificando qual opcao foi escolhida
        switch(menu)
        {
            case(RODAR_JOGO):
                printf("Iniciando jogo! \n");
                break;
            case(EXIBIR_RANK):
                printf("EM BREVE! \n");
                break;
            case(SAIR_JOGO):
                menu = SAIR_JOGO;
                break;
            default:
                printf("Opcao invalida! \n");
                break;
        }
    
        //  Loop do jogo
        while(menu == RODAR_JOGO)
        {
            //  Leitura do mapa na matriz
            ler_mapa(&m, MAPA_LEVEL_1);

            //  Identificando os elementos no mapa
            identificar_elementos(&m);

            //  Localizando personagem
            localizar_personagem();

            //  Localizando fantasmas
            localizar_fantasmas();

            //  Zerando level
            m.level = LEVEL_1;

            //  Loop da fase
            do
            {
                //  Limpando a tela
                system("clear");
                //  Imprimindo mapa na tela
                imprimir_mapa(&m);
                //  Variavel do comando do usuario
                char comando;
                //  Leitura do comando do usuario
                scanf(" %c", &comando);
                //  Movimentando personagem
                movimentar_personagem(comando);
                //  Movimento dos fantasmas
                movimentar_fantasmas(0);
                //  Verificando se o usuaio passou de level
                m.level = completar_level(m.level);

            }while(verificar_gameover(m.level));

            //  Liberando espaco na memoria antes de encerra o programa
            liberar_matriz(&m);
        }

    }while(menu != 0);

    return 0;
}