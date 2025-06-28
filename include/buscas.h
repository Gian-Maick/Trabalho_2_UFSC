#ifndef BUSCAS_H
#define BUSCAS_H

#include "utils.h"

void busca_nome(no_jogadores_t* lista, string nome);
void busca_posicao(no_jogadores_t* lista, string posicao);
void maior_salario(no_jogadores_t* lista);
void menor_salario(no_jogadores_t* lista);
void faixa_salarial(no_jogadores_t* lista, float min, float max);
void mostrar_confrontos(no_jogos_t* lista, string nome);

#endif