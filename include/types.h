#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TM 200
typedef char string[TM];
typedef enum {ATIVO = 1, INATIVO = 0} status_t;

 //Structs 
typedef struct cadastro_jogador {
    int codigo;
    string nome;                            
    int idade;
    float altura;
    float peso;
    string posicao;
    float valor_passe;
    float aquisicao;
    float salario;
    int atividade;
    string motivo;
} cadastro_jogador_t;

/*typedef struct dados_jogador {
    cadastro_jogador_t jogador[TM];
    int qtd_jogadores;
} dados_jogador_t;*/

typedef struct cadastro_jogos {
    int codigo;
    string time_adv;
    string data_jogo;
    string local;
    int resultado;
    int resultado_adv;
    string time_escalado;
    int substituicoes;
} cadastro_jogos_t;

/*typedef struct dados_jogos {
    cadastro_jogos_t jogo[TM];
    int qtd_jogos;
} dados_jogos_t;*/

typedef struct no_jogadores {
    cadastro_jogador_t jogador;
    struct no_jogadores *proximo;
} no_jogadores_t;

typedef struct no_jogos {
    cadastro_jogos_t jogo;
    struct no_jogos *proximo;
} no_jogos_t;

typedef struct lista_jogadores {
    no_jogadores_t *cabeca;
    int qtd_nos;
} lista_jogadores_t;

typedef struct lista_jogos {
    no_jogos_t *cabeca;
    int qtd_nos;
} lista_jogos_t;




#endif