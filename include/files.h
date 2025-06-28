#ifndef FILES_H
#define FILES_H
#include "types.h"

//Prototipo JOGADORES
salvar_jogadores_arquivo_bin(string nome_arq, no_jogadores_t );
ler_jogadores_arquivo_binario(string nome_arq, no_jogadores_t );
salvar_jogadores_arquivo_html(string nome_arq, no_jogadores_t );
salvar_jogadores_arquivo_txt(string nome_arq, no_jogadores_t );

//Pototipo JOGOS
salvar_jogos_arquivo_bin(string nome_arq, no_jogos_t );
ler_jogos_arquivo_binario(string nome_arq, no_jogos_t );
salvar_jogos_arquivo_html(string nome_arq, no_jogos_t );
salvar_jogos_arquivo_txt(string nome_arq, no_jogos_t );


#endif