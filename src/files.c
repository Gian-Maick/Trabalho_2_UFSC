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
        fprintf(fp, "%i;", lista_jogadores->jogador.codigo);
        fprintf(fp, "%s;", lista_jogadores->jogador.nome);
        fprintf(fp, "%d;", lista_jogadores->jogador.idade);
        fprintf(fp, "%.2f;", lista_jogadores->jogador.altura);
        fprintf(fp, "%.2f;", lista_jogadores->jogador.peso);
        fprintf(fp, "%s;", lista_jogadores->jogador.posicao);
        fprintf(fp, "%.2f;", lista_jogadores->jogador.valor_passe);
        fprintf(fp, "%.2f;", lista_jogadores->jogador.aquisicao);
        fprintf(fp, "%.2f;", lista_jogadores->jogador.salario);
        fprintf(fp, "%d;", lista_jogadores->jogador.atividade);
        fprintf(fp, "%s;", lista_jogadores->jogador.motivo);
        fprintf(fp, "\n");
        
        lista_jogadores = lista_jogadores->proximo;
    }    

    fclose(fp); 
}

void exportar_dados_para_arquivo_csv_jogadores(string nome_arq, no_jogadores_t *lista_jogadores)
{
    strcat(nome_arq, ".csv");
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
        fprintf(fp, "%.2f;", lista_jogadores->jogador.altura);
        fprintf(fp, "%.2f;", lista_jogadores->jogador.peso);
        fprintf(fp, "%s;", lista_jogadores->jogador.posicao);
        fprintf(fp, "R$ %.2f;", lista_jogadores->jogador.valor_passe);
        fprintf(fp, "R$ %.2f;", lista_jogadores->jogador.aquisicao);
        fprintf(fp, "R$ %.2f;", lista_jogadores->jogador.salario);
        fprintf(fp, "%d;", lista_jogadores->jogador.atividade);
        fprintf(fp, "%s;", lista_jogadores->jogador.motivo);
        fprintf(fp, "\n");
       
        
        lista_jogadores = lista_jogadores->proximo;
    }    

    fclose(fp); 

}

void exportar_faixa_etaria_csv_jogadores(string nome_arq, no_jogadores_t *lista_jogadores, int min, int max)
{
    strcat(nome_arq, ".csv");
    FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "CODIGO;NOME;IDADE;ALTURA;PESO;POSICAO;VALOR VENDA;VALOR AQUISICAO;SALARIO;ATIVIDADE;MOTIVO\n");

    while(lista_jogadores) {
        if (lista_jogadores->jogador.idade >= min && lista_jogadores->jogador.idade <= max) {
            fprintf(fp, "%i;", lista_jogadores->jogador.codigo);
            fprintf(fp, "%s;", lista_jogadores->jogador.nome);
            fprintf(fp, "%d;", lista_jogadores->jogador.idade);
            fprintf(fp, "%.2f;", lista_jogadores->jogador.altura);
            fprintf(fp, "%.2f;", lista_jogadores->jogador.peso);
            fprintf(fp, "%s;", lista_jogadores->jogador.posicao);
            fprintf(fp, "R$ %.2f;", lista_jogadores->jogador.valor_passe);
            fprintf(fp, "R$ %.2f;", lista_jogadores->jogador.aquisicao);
            fprintf(fp, "R$ %.2f;", lista_jogadores->jogador.salario);
            fprintf(fp, "%d;", lista_jogadores->jogador.atividade);
            fprintf(fp, "%s;", lista_jogadores->jogador.motivo);
            fprintf(fp, "\n");
        }
        
        lista_jogadores = lista_jogadores->proximo;
    }    

    fclose(fp); 
}

void exportar_jogadores_vendidos_csv(string nome_arq, no_jogadores_t *lista_jogadores)
{
    strcat(nome_arq, ".csv");
    FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "CODIGO;NOME;IDADE;ALTURA;PESO;POSICAO;VALOR VENDA;VALOR AQUISICAO;SALARIO;ATIVIDADE;MOTIVO\n");

    while(lista_jogadores) {
        if (strcasecmp(lista_jogadores->jogador.motivo, "vendido") == 0) {
            fprintf(fp, "%i;", lista_jogadores->jogador.codigo);
            fprintf(fp, "%s;", lista_jogadores->jogador.nome);
            fprintf(fp, "%d;", lista_jogadores->jogador.idade);
            fprintf(fp, "%.2f;", lista_jogadores->jogador.altura);
            fprintf(fp, "%.2f;", lista_jogadores->jogador.peso);
            fprintf(fp, "%s;", lista_jogadores->jogador.posicao);
            fprintf(fp, "R$ %.2f;", lista_jogadores->jogador.valor_passe);
            fprintf(fp, "R$ %.2f;", lista_jogadores->jogador.aquisicao);
            fprintf(fp, "R$ %.2f;", lista_jogadores->jogador.salario);
            fprintf(fp, "%d;", lista_jogadores->jogador.atividade);
            fprintf(fp, "%s;", lista_jogadores->jogador.motivo);
            fprintf(fp, "\n");
        }
        
        lista_jogadores = lista_jogadores->proximo;
    }    

    fclose(fp); 
}

void exportar_dados_valor_time_csv(string nome_arq, no_jogadores_t *lista_jogadores)
{
    strcat(nome_arq, ".csv");
    FILE *fp = fopen(nome_arq, "w");
    float total = 0;
    int ativos = 0, vendidos = 0;

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "ATIVOS;VENDIDOS;VALOR TOTAL;\n");

    while(lista_jogadores) {
        if (lista_jogadores->jogador.atividade == 1) {
            total += lista_jogadores->jogador.valor_passe;
            ativos++;
        } else if (lista_jogadores->jogador.atividade == 0 && strcasecmp(lista_jogadores->jogador.motivo, "Vendido") == 0) {
            total += lista_jogadores->jogador.valor_passe;
            vendidos++;
        }

        lista_jogadores = lista_jogadores->proximo;

    }    
    fprintf(fp, "%d", ativos);
    fprintf(fp, "%d", vendidos);
    fprintf(fp, "R$ %.2f", total);

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
    strcat(nome_arq, ".csv");
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

void exportar_dados_resultados_csv_jogos(string nome_arq, no_jogos_t *lista_jogos)
{
    strcat(nome_arq, ".csv");
    FILE *fp = fopen(nome_arq, "w");

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "TIME ADVERSARIO;GOLS FEITOS;GOLS TOMADOS;\n");

    while(lista_jogos) {
        fprintf(fp, "%s", lista_jogos->jogo.time_adv);
        fprintf(fp, "%d", lista_jogos->jogo.resultado);
        fprintf(fp, "%d", lista_jogos->jogo.resultado_adv);
        
        lista_jogos = lista_jogos->proximo;
    }    

    fclose(fp); 
}

void exportar_dados_aproveitamento_csv_jogos(string nome_arq, no_jogos_t *lista_jogos, lista_jogos_t* ptr_lista)
{
    strcat(nome_arq, ".csv");
    FILE *fp = fopen(nome_arq, "w");
    int vitoria = 0;
    int derrota = 0;
    int empate = 0;
    float result;

    if (fp == NULL){
        printf("erro ao abrir o arquivo %s\n", nome_arq);
        return;
    }
    
    fprintf(fp, "VITORIAS;EMPATES;DERROTAS;APROVEITAMENTO\n");

    while(lista_jogos) {
        if(lista_jogos->jogo.resultado > lista_jogos->jogo.resultado_adv){
            vitoria++;
        }
        else if(lista_jogos->jogo.resultado < lista_jogos->jogo.resultado_adv){
                derrota++;
            }   
        else{
            empate++;
        }
        
        lista_jogos = lista_jogos->proximo;

        result = ((float)vitoria / ptr_lista->qtd_nos) * 100;    
        fprintf(fp, "%d", vitoria);
        fprintf(fp, "%d", empate);
        fprintf(fp, "%d", derrota);
        fprintf(fp, "%.2f%%", result);
    }    

    fclose(fp); 
}