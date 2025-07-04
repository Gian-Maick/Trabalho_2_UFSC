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

void enter_continuar()
{
    printf("\n-----------------------------------------------\n");
    printf("Pressione ENTER para continuar\n");
    getchar(); 
}

void abre_arquivo_csv(string nome_arq)
{
    char abrir[200];
    strcpy(abrir, "libreoffice --calc ");
    strcat(abrir, nome_arq);
    system(abrir);
}

void abre_arquivo_txt(string nome_arq)
{
    char abrir[200];
    strcpy(abrir, "xdg-open ");
    strcat(abrir, nome_arq);
    system(abrir);
}

void abre_arquivo_html(string nome_arq)
{
    char abrir[200];
    strcpy(abrir, "firefox ");
    strcat(abrir, nome_arq);
    system(abrir);
}

void apagar_lista_jogadores(no_jogadores_t **lista)
{
    no_jogadores_t *aux;

    while(*lista != NULL){
        aux = *lista;
        *lista = (*lista)->proximo;
        free(aux);
    }
}
void apagar_lista_jogos(no_jogos_t **lista)
{
    no_jogos_t *aux;

    while(*lista != NULL){
        aux = *lista;
        *lista = (*lista)->proximo;
        free(aux);
    } 
}