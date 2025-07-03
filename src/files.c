#include "../include/files.h"
#include "../include/cadastros.h"

//Implementação JOGADORES
void salvar_jogadores_arquivo_bin(string nome_arq, no_jogadores_t *registro_jogadores)
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
    while (registro_jogadores) {
        fwrite(registro_jogadores, sizeof(no_jogadores_t), 1, fp);
        registro_jogadores = registro_jogadores->proximo;
    }

    // Fechar o arquivo
    fclose(fp);
}

void ler_jogadores_arquivo_binario(string nome_arq, no_jogadores_t *lista_jogadores, lista_jogadores_t *lista)
{
    FILE *fp;

    fp = fopen(nome_arq, "rb");

    if(!fp) {
        printf("Falha ao abrir o arquivo!\n");
        return;
    }

    while(!feof(fp)) {
        no_jogadores_t *aux = (no_jogadores_t*)malloc(sizeof(no_jogadores_t));
        fread(aux, sizeof(no_jogadores_t), 1, fp);
        if (!feof(fp)) { 
            aux->proximo = NULL;
            insere_cadastro_fim_jogadores(aux, lista);
        }
        else {
            free(aux);
        }
    }

    fclose(fp);
    
}

void exportar_Jogadores_arquivo_html(string nome_arq, no_jogadores_t *lista_jogadores)
{
    FILE *fp = fopen(nome_arq , "w");
    if(!fp){
        printf("Arquivo html nao encontrado");
        return;
    }
    fprintf(fp , "<html> <body> <table> <tr> <td><h1>Codigo do Jogador</h1></td> <td><h1>Nome do Jogador</h1></td> </tr>\n");
    while(lista_jogadores){
        fprintf(fp , "<tr> <td><p>%d</p></td> <td><p>%s</p></td> </tr>\n", lista_jogadores->jogador.codigo , lista_jogadores->jogador.nome);
        lista_jogadores = lista_jogadores->proximo;

    }
    fprintf(fp , "</table> </body> </html>");

    fclose(fp);
}

void exportar_arquivo_jogadores_txt(string nome_arq, no_jogadores_t *lista_jogadores)
{
    FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("Erro ao tentar abrir o arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "Lista de Jogadores\n");
    fprintf(fp, "----------------\n\n");

    while(lista_jogadores) {
       
        
        
        fprintf(fp, "\n");
        
        lista_jogadores = lista_jogadores->proximo;
    }    

    fclose(fp); 
}

void exportar_dados_para_arquivo_csv_jogadores(string nome_arq, no_jogadores_t *lista_jogadores)
{
    FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "CODIGO;NOME;IDADE;ALTURA;PESO;POSICAO;VALOR VENDA;VALOR AQUISICAO;SALARIO;ATIVIDADE;MOTIVO\n");

    while(lista_jogadores) {
        fprintf(fp, "%i;", lista_jogadores->jogador.codigo);
        fprintf(fp, "%s;", lista_jogadores->jogador.nome);
        fprintf(fp, "%d;", lista_jogadores->jogador.idade);
        fprintf(fp, "%f;", lista_jogadores->jogador.altura);
        fprintf(fp, "%f;", lista_jogadores->jogador.peso);
        fprintf(fp, "%s;", lista_jogadores->jogador.posicao);
        fprintf(fp, "%f;", lista_jogadores->jogador.valor_passe);
        fprintf(fp, "%f;", lista_jogadores->jogador.aquisicao);
        fprintf(fp, "%f;", lista_jogadores->jogador.salario);
        fprintf(fp, "%d;", lista_jogadores->jogador.atividade);
        fprintf(fp, "%s;", lista_jogadores->jogador.motivo);
       
        
        lista_jogadores = lista_jogadores->proximo;
    }    

    fclose(fp); 

}

//Implementação JOGOS

void salvar_jogos_arquivo_bin(string nome_arq, no_jogos_t *registro_jogos)
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
    while (registro_jogos) {
        fwrite(registro_jogos, sizeof(no_jogos_t), 1, fp);
        registro_jogos = registro_jogos->proximo;
    }

    // Fechar o arquivo
    fclose(fp);
}

void ler_jogos_arquivo_binario(string nome_arq, no_jogos_t *lista_jogos, lista_jogos_t *lista)
{
   FILE *fp;

    fp = fopen(nome_arq, "rb");

    if(!fp) {
        printf("Falha ao abrir o arquivo!\n");
        return;
    }

    while(!feof(fp)) {
        no_jogos_t *aux = (no_jogos_t*)malloc(sizeof(no_jogos_t));
        fread(aux, sizeof(no_jogos_t), 1, fp);
        if (!feof(fp)) { 
            aux->proximo = NULL;
            insere_cadastro_fim_jogos(aux, lista);
        }
        else {
            free(aux);
        }
    }

    fclose(fp);
}

/*void exportar_Jogos_arquivo_html(string nome_arq, no_jogos_t *lista_jogos)
{
     FILE *fp = fopen(nome_arq , "w");
    if(!fp){
        printf("Arquivo html nao encontrado");
        return;
    }
    fprintf(fp , "<html> <body> <table> <tr> <td><h1>Codigo da partida</h1></td> <td><h1>Time adversario</h1></td> </tr>\n");
    while(lista_jogos){
        fprintf(fp , "<tr> <td><p>%d</p></td> <td><p>%s</p></td> </tr>\n", lista_jogos->jogo.codigo , lista_jogos->jogo.time_adv);
        lista_jogos = lista_jogos->proximo;

    }
    fprintf(fp , "</table> </body> </html>");

    fclose(fp);
}
*/
void exportar_arquivo_jogos_txt(string nome_arq, no_jogos_t *lista_jogos)
{
    FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("Erro ao tentar abrir o arquivo %s\n", nome_arq);
        return;
    }

    fprintf(fp, "Lista de Partidas\n");
    fprintf(fp, "-------------------\n\n");

    while(lista_jogos) {
       
        
        fprintf(fp, "\n");
        
        lista_jogos= lista_jogos->proximo;
    }    

    fclose(fp); 
}

void exportar_dados_para_arquivo_csv_jogos(string nome_arq, no_jogos_t *lista_jogos)
{
    FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "CODIGO;TIME ADVERSARIO;DATA;LOCAL;GOLS FEITOS;GOLS TOMADOS;TIME ESCALADO;SUBSTITUICOES;\n");

    while(lista_jogos) {
        fprintf(fp, "%i;", lista_jogos->jogo.codigo);
        fprintf(fp, "%s;", lista_jogos->jogo.time_adv);
        fprintf(fp, "%s;", lista_jogos->jogo.data_jogo);
        fprintf(fp, "%s;", lista_jogos->jogo.local);
        fprintf(fp, "%i;", lista_jogos->jogo.resultado);
        fprintf(fp, "%i;", lista_jogos->jogo.resultado_adv);
        fprintf(fp, "%s;", lista_jogos->jogo.time_escalado);
        fprintf(fp, "%i;", lista_jogos->jogo.substituicoes);
        
        lista_jogos = lista_jogos->proximo;
    }    

    fclose(fp); 

}

