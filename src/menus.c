#include "../include/menus.h"


int menu_principal()
{
    int opcao;

    limpar_tela();

    printf("| MENU PRINCIPAL |\n");
    printf("*******************\n");
    printf("1.Cadastros\n");
    printf("2.Relatorios\n");
    printf("3.Consultas\n");
    printf("4.Arquivos\n");
    printf("0.Sair do programa\n");
    printf("::: ");
    scanf("%i", &opcao);

    return opcao;
}

int menu_cadastro_jogos()
{

}

int menu_cadastro_jogadores()
{
    
}