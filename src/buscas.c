#include "../include/buscas.h"

void busca_nome(no_jogadores_t* lista, string nome)
{
     int achou = 0;
    while (lista) {
        if(strcasestr(lista->jogador.nome, nome) != 0) {//Identifica o se há algo dentro de outra string
            printf("Jogador.........................: %s\n", lista->jogador.nome);
            printf("Idade...........................: %i\n", lista->jogador.idade);
            printf("Altura..........................: %.2f\n", lista->jogador.altura);
            printf("Peso............................: %.2f\n", lista->jogador.peso);
            printf("Posicao(oes)....................: %s\n", lista->jogador.posicao);
            printf("Valor de venda..................: %.2f\n", lista->jogador.valor_passe);
            printf("Valor de aquisicao..............: %.2f\n", lista->jogador.aquisicao);
            printf("Salario.........................: %.2f\n", lista->jogador.salario);
            printf("Estado..........................: %d\n", lista->jogador.atividade);
            printf("Motivo da inativiade............: %s\n", lista->jogador.motivo);
            printf("\n");
            achou = 1;
        }
    }
    if (achou == 0) {
        printf("Nao ha nenhum jogador com este nome\n\n");
    }
}

void busca_posicao(no_jogadores_t* lista, string posicao)
{
    int achou = 0;

    while (lista) {

        if(strcasestr(lista->jogador.posicao, posicao) != 0) {
            printf("Jogador.........................: %s\n", lista->jogador.nome);
            printf("Idade...........................: %i\n", lista->jogador.idade);
            printf("Altura..........................: %.2f\n", lista->jogador.altura);
            printf("Peso............................: %.2f\n", lista->jogador.peso);
            printf("Posicao(oes)....................: %s\n", lista->jogador.posicao);
            printf("Valor de venda..................: %.2f\n", lista->jogador.valor_passe);
            printf("Valor de aquisicao..............: %.2f\n", lista->jogador.aquisicao);
            printf("Salario.........................: %.2f\n", lista->jogador.salario);
            printf("Estado..........................: %d\n", lista->jogador.atividade);
            printf("Motivo da inativiade............: %s\n", lista->jogador.motivo);
            printf("\n");
            achou = 1;
        }

    }
    if (achou == 0) {
        printf("Nao ha nenhum jogador jogando nesta posicao\n\n");
    }
}

void maior_salario(no_jogadores_t* lista)
{
    if(lista==NULL || lista->proximo==NULL) return;

    no_jogadores_t * aux = lista;
    aux = (no_jogadores_t*)malloc(sizeof(no_jogadores_t));
    while (aux) {
        aux = lista->proximo;

        if (aux->jogador.salario > lista->jogador.salario) {
            lista = aux;
        }

        lista = lista->proximo;
    }

    printf("Jogador.........................: %s\n", aux->jogadores.jogador.nome);
    printf("Idade...........................: %i\n", aux->jogadores.jogador.idade);
    printf("Altura..........................: %.2f\n", aux->jogadores.jogador.altura);
    printf("Peso............................: %.2f\n", aux->jogadores.jogador.peso);
    printf("Posicao(oes)....................: %s\n", aux->jogadores.jogador.posicao);
    printf("Valor de venda..................: %.2f\n", aux->jogadores.jogador.valor_passe);
    printf("Valor de aquisicao..............: %.2f\n", aux->jogadores.jogador.aquisicao);
    printf("Salario.........................: %.2f\n", aux->jogadores.jogador.salario);
    printf("Estado..........................: %d\n", aux->jogadores.jogador.atividade);
    printf("Motivo da inativiade............: %s\n", aux->jogadores.jogador.motivo);
    printf("\n");
}

void menor_salario(no_jogadores_t* lista)
{
    if(lista==NULL || lista->proximo==NULL) return;

    no_jogadores_t * aux = lista;
    aux = (no_jogadores_t*)malloc(sizeof(no_jogadores_t));
    while (aux) {
        aux = lista->proximo;

        if (aux->jogador.salario < lista->jogador.salario) {
            lista = aux;
        }

        lista = lista->proximo;
    }

    printf("Jogador.........................: %s\n", aux->jogadores.jogador.nome);
    printf("Idade...........................: %i\n", aux->jogadores.jogador.idade);
    printf("Altura..........................: %.2f\n", aux->jogadores.jogador.altura);
    printf("Peso............................: %.2f\n", aux->jogadores.jogador.peso);
    printf("Posicao(oes)....................: %s\n", aux->jogadores.jogador.posicao);
    printf("Valor de venda..................: %.2f\n", aux->jogadores.jogador.valor_passe);
    printf("Valor de aquisicao..............: %.2f\n", aux->jogadores.jogador.aquisicao);
    printf("Salario.........................: %.2f\n", aux->jogadores.jogador.salario);
    printf("Estado..........................: %d\n", aux->jogadores.jogador.atividade);
    printf("Motivo da inativiade............: %s\n", aux->jogadores.jogador.motivo);
    printf("\n");
}

void faixa_salarial(no_jogadores_t* lista, float min, float max)
{
    int achou = 0;

    while (lista) {
        if(lista->jogador.salario >= min && lista->jogador.salario <= max) {
            printf("Jogador.........................: %s\n", lista->jogador.nome);
            printf("Idade...........................: %i\n", lista->jogador.idade);
            printf("Altura..........................: %.2f\n", lista->jogador.altura);
            printf("Peso............................: %.2f\n", lista->jogador.peso);
            printf("Posicao(oes)....................: %s\n", lista->jogador.posicao);
            printf("Valor de venda..................: %.2f\n", lista->jogador.valor_passe);
            printf("Valor de aquisicao..............: %.2f\n", lista->jogador.aquisicao);
            printf("Salario.........................: %.2f\n", lista->jogador.salario);
            printf("Estado..........................: %d\n", lista->jogador.atividade);
            printf("Motivo da inativiade............: %s\n", lista->jogador.motivo);
            printf("\n");
            achou = 1;
        }
    }
    if (achou == 0) {
        printf("Nenhum jogador nessa faixa salarial\n\n");
    }
}

void mostrar_confrontos();