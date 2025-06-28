#include "../include/files.h"

//Implementação JOGADORES
salvar_jogadores_arquivo_bin(string nome_arq, no_jogadores_t )
{
     FILE *fp;

    // Abre arquivo
    fp = fopen(nome_arq, "wb");

    // Verifica se o arquivo foi aberto
    if (!fp) {
        printf("Erro ao tentar abrir o arquivo %s\n", nome_arq);
        return;
    }

    // Salvar dados para o arquivo binário
    while () {
        fwrite(ptr_lista_rh, sizeof(no_jogadores_t), 1, fp);
         = ->proximo;
    }

    // Fechar o arquivo
    fclose(fp);
}

ler_jogadores_arquivo_binario(string nome_arq, no_jogadores_t )
{

}

exportar_Jogadores_arquivo_html(string nome_arq, no_jogadores_t )
{

}

exportar_arquivo_jogadores_txt(string nome_arq, no_jogadores_t )
{
    FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("Erro ao tentar abrir o arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "Lista de Jogos\n");
    fprintf(fp, "----------------\n\n");

    while(lista_rh) {
       
        
        
        fprintf(fp, "\n");
        
        = ->proximo;
    }    

    fclose(fp); 
}

//Implementação JOGOS

salvar_jogos_arquivo_bin(string nome_arq, no_jogos_t)
{
     FILE *fp;

    // Abre arquivo
    fp = fopen(nome_arq, "wb");

    // Verifica se o arquivo foi aberto
    if (!fp) {
        printf("Erro ao tentar abrir o arquivo %s\n", nome_arq);
        return;
    }

    // Salvar dados para o arquivo binário
    while () {
        fwrite(ptr_lista_rh, sizeof(no_jogos_t), 1, fp);
         = ->proximo;
    }

    // Fechar o arquivo
    fclose(fp);
}

ler_jogos_arquivo_binario(string nome_arq, no_jogos_t)
{

}

exportar_Jogos_arquivo_html(string nome_arq, no_jogos_t)
{

}

exportar_arquivo_jogos_txt(string nome_arq, no_jogos_t)
{
    FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("Erro ao tentar abrir o arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "Lista de Jogadores\n");
    fprintf(fp, "-------------------\n\n");

    while(lista_rh) {
       
        
        i
        fprintf(fp, "\n");
        
        = ->proximo;
    }    

    fclose(fp); 
}


