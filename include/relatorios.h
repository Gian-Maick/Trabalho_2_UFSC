#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "types.h"

void mostrar_jogador(no_jogadores_t* dado);
void mostrar_todos_jogadores(no_jogadores_t* ptr_lista);
void mostrar_jogo(no_jogos_t* dado);
void mostrar_todos_jogos(no_jogos_t* ptr_lista)
void faixa_etaria(no_jogos_t* lista, int min, int max);
void jogadores_vendidos(string motivo);
void mostrar_resultado_jogos();
void mostrar_valor_time();
void mostrar_aproveitamento();

#endif