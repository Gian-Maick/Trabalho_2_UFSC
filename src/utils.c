#include "../include/types.h"

void apaga_enter(string str) {
    str[strlen(str)- 1] = '\0';
}

void limpar_tela()
{
    system("clear");
}
void msg_apertar_enter()
{
    printf("\n-----------------------------------------------\n");
    printf("Pressione ENTER para retornar ao MENU\n");
    getchar();
}