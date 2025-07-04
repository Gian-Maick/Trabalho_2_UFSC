#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"

void apaga_enter(string str);
void limpar_tela();
void msg_apertar_enter();
void enter_continuar();
void abre_arquivo_csv(string nome_arq);
void abre_arquivo_txt(string nome_arq);
void abre_arquivo_html(string nome_arq);
void apagar_lista_jogadores();
void apagar_lista_jogos();


#endif