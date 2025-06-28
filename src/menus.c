#include "../include/menus.h"


int menu_principal()
{
    int opcao;

    limpar_tela();

    printf("| MENU PRINCIPAL |\n");
    printf("*******************\n");
    printf("1.Cadastros\n");
    printf("2.Relatorios\n");
    printf("3.Buscas\n");
    printf("4.Arquivos\n");
    printf("0.Sair do programa\n");
    printf("::: ");
    scanf("%i", &opcao);

    return opcao;
}

int menu_cadastros()
{
    int opcao;
   
    limpar_tela();

    printf("| MENU DE CADASTROS |\n");
    printf("*******************\n");
    printf("1.Cadastrar jogador\n");
    printf("2.Cadastrar jogo\n");
    printf("3.Recadastrar jogador\n");
    printf("0.Voltar ao menu principal\n");
    printf("::: ");
    scanf("%i", &opcao);
    getchar();

    return opcao;
}

int menu_relatorios()
{
    int opcao;

    limpar_tela();

    printf("| MENU DE RELATORIOS |\n");
    printf("*******************\n");
    printf("1.Todos os jogadores\n");
    printf("2.Todos os jogos\n");
    printf("3.Relatorio de jogadores por faixa etaria\n");
    printf("4.Relatorio de jogadores vendidos\n");
    printf("5.Relatorio de resultado de jogos\n");
    printf("6.Valor do time\n");
    printf("7.Relatorio de aproveitamento\n");
    printf("0.Voltar ao menu principal\n");
    printf("::: ");
    scanf("%i", &opcao);
    getchar();

    return opcao;
}

int menu_buscas()
{
    int opcao;

    limpar_tela();

    printf("| MENU DE BUSCAS |\n");
    printf("*******************\n");
    printf("1.Buscar jogador por nome\n");
    printf("2.Buscar jogador por posicao\n");
    printf("3.Buscar jogador com maior salario\n");
    printf("4.Buscar jogador com menor salario\n");
    printf("5.Buscar jogador por faixa salarial\n");
    printf("6.Buscar jogos contra rival\n");
    printf("0.Voltar ao menu principal\n");
    printf("::: ");
    scanf("%i", &opcao);
    getchar();

    return opcao;
}