#include "../include/buscas.h"

void busca_nome(no_jogadores_t* lista, string nome)
{
     int achou = 0;
    while (lista) {
        if(strcasestr(lista->jogador.nome, nome) != 0) {//Identifica o se há algo dentro de outra string
            printf("Codigo do jogador...............: %i\n", lista->jogador.codigo);
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
            lista = lista->proximo;
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
            printf("Codigo do jogador...............: %i\n", lista->jogador.codigo);
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
            lista = lista->proximo;
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

    printf("Codigo do jogador...............: %i\n", aux->jogador.codigo);
    printf("Jogador.........................: %s\n", aux->jogador.nome);
    printf("Idade...........................: %i\n", aux->jogador.idade);
    printf("Altura..........................: %.2f\n", aux->jogador.altura);
    printf("Peso............................: %.2f\n", aux->jogador.peso);
    printf("Posicao(oes)....................: %s\n", aux->jogador.posicao);
    printf("Valor de venda..................: %.2f\n", aux->jogador.valor_passe);
    printf("Valor de aquisicao..............: %.2f\n", aux->jogador.aquisicao);
    printf("Salario.........................: %.2f\n", aux->jogador.salario);
    printf("Estado..........................: %d\n", aux->jogador.atividade);
    printf("Motivo da inativiade............: %s\n", aux->jogador.motivo);
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

    printf("Codigo do jogador...............: %i\n", aux->jogador.codigo);
    printf("Jogador.........................: %s\n", aux->jogador.nome);
    printf("Idade...........................: %i\n", aux->jogador.idade);
    printf("Altura..........................: %.2f\n", aux->jogador.altura);
    printf("Peso............................: %.2f\n", aux->jogador.peso);
    printf("Posicao(oes)....................: %s\n", aux->jogador.posicao);
    printf("Valor de venda..................: %.2f\n", aux->jogador.valor_passe);
    printf("Valor de aquisicao..............: %.2f\n", aux->jogador.aquisicao);
    printf("Salario.........................: %.2f\n", aux->jogador.salario);
    printf("Estado..........................: %d\n", aux->jogador.atividade);
    printf("Motivo da inativiade............: %s\n", aux->jogador.motivo);
    printf("\n");
}

void faixa_salarial(no_jogadores_t* lista, float min, float max)
{
    int achou = 0;

    while (lista) {
        if(lista->jogador.salario >= min && lista->jogador.salario <= max) {
            printf("Codigo do jogador...............: %i\n", lista->jogador.codigo);
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
            lista = lista->proximo;
        }
    }
    if (achou == 0) {
        printf("Nenhum jogador nessa faixa salarial\n\n");
    }
}

void mostrar_confrontos(no_jogos_t* lista, string nome)
{
    printf("Confrontos contra %s\n", nome);
    while(lista) { 
        if(strcasecmp(lista->jogo.time_adv, nome) == 0) { //compara as strings
            printf("Data: %s | Resultado: %d X %d\n", lista->jogo.data_jogo, lista->jogo.resultado, lista->jogo.resultado_adv);
        }
        lista = lista->proximo;
    }
    printf("\n");
}