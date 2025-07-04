#ifndef CADASTROS_H
#define CADASTROS_H

#include "utils.h"
bool lista_jogadores_vazia(no_jogadores_t* lista);
bool lista_jogos_vazia(no_jogos_t* lista);
void inicializa_lista_jogadores(lista_jogadores_t *lista);
void inicializa_lista_jogos(lista_jogos_t *lista);
no_jogadores_t *acha_ultimo_jogadores(no_jogadores_t* lista);
no_jogos_t *acha_ultimo_jogos(no_jogos_t* lista);
no_jogadores_t *cadastrar_jogador();
void insere_cadastro_fim_jogadores(no_jogadores_t *novo, lista_jogadores_t *lista);
no_jogadores_t *recadastrar_jogador(no_jogadores_t* cadastro, int codigo);
no_jogadores_t *mudar_atividade_jogador(no_jogadores_t *cadastro, int codigo);
no_jogos_t *cadastrar_jogo(no_jogadores_t *cadastro);
void insere_cadastro_fim_jogos(no_jogos_t *novo, lista_jogos_t *lista);
void excluir_jogador(no_jogadores_t* lista, int codigo);
void excluir_jogo(no_jogos_t *lista, int codigo);


#endif