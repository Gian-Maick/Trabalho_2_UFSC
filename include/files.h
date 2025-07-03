#ifndef FILES_H
#define FILES_H
#include "utils.h"

//Prototipo JOGADORES
void salvar_jogadores_arquivo_bin(string nome_arq, no_jogadores_t *registro_jogadores);
void ler_jogadores_arquivo_binario(string nome_arq, no_jogadores_t *lista_jogadores, lista_jogadores_t* lista);
void exportar_Jogadores_arquivo_html(string nome_arq, no_jogadores_t *lista_jogadores);
void exportar_arquivo_jogadores_txt(string nome_arq, no_jogadores_t *lista_jogadores);
void exportar_dados_para_arquivo_csv_jogadores(string nome_arq, no_jogadores_t *lista_jogadores);
void exportar_faixa_etaria_csv_jogadores(string nome_arq, no_jogadores_t *lista_jogadores, int min, int max);
void exportar_jogadores_vendidos_csv(string nome_arq, no_jogadores_t *lista_jogadores);
void exportar_dados_valor_time_csv(string nome_arq, no_jogadores_t *lista_jogadores);

//Pototipo JOGOS
void salvar_jogos_arquivo_bin(string nome_arq, no_jogos_t *registro_jogos);
void ler_jogos_arquivo_binario(string nome_arq, no_jogos_t *lista_jogos, lista_jogos_t *lista);
void exportar_Jogos_arquivo_html(string nome_arq, no_jogos_t *lista_jogos);
void exportar_arquivo_jogos_txt(string nome_arq, no_jogos_t *lista_jogos);
void exportar_dados_para_arquivo_csv_jogos(string nome_arq, no_jogos_t *lista_jogos);
void exportar_dados_resultados_csv_jogos(string nome_arq, no_jogos_t *lista_jogos);
void exportar_dados_aproveitamento_csv_jogos(string nome_arq, no_jogos_t *lista_jogos, lista_jogos_t* ptr_lista);

#endif