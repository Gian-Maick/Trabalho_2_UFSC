#ifndef CADASTROS_H
#define CADASTROS_H

#include "utils.h"
bool lista_jogadores_vazia(no_jogadores_t* lista);
bool lista_jogos_vazia(no_jogos_t* lista);
no_jogadores_t *cadastrar_jogador();
void insere_cadastro_inicio_jogadores(no_jogadores_t *novo, lista_jogadores_t *lista_rh);
void recadrastrar_jogador(no_jogadores_t* lista, string nome);
no_jogos_t *cadastrar_jogo();
void insere_cadastro_inicio_jogos(no_jogos_t *novo, lista_jogos_t *lista_rh);


#endif