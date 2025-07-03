#include "../include/buscas.h"

void busca_nome(no_jogadores_t* lista, string nome)
{
    int achou = 0;
    printf("\n");
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
        }
        lista = lista->proximo;
    }
    if (achou == 0) {
        printf("Nao ha nenhum jogador com este nome\n\n");
    }

    msg_apertar_enter();
}

void busca_posicao(no_jogadores_t* lista, string posicao)
{
    int achou = 0;
    printf("\n");
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
        }
        lista = lista->proximo;

    }
    if (achou == 0) {
        printf("Nao ha nenhum jogador jogando nesta posicao\n\n");
    }

    msg_apertar_enter();
}

void maior_salario(no_jogadores_t* lista)
{
    if(lista==NULL || lista->proximo==NULL) return;
    printf("\n");
    no_jogadores_t *maior = lista;
    no_jogadores_t *aux = lista->proximo;
    while (aux) {

        if (aux->jogador.salario > maior->jogador.salario) {
            maior = aux;
        }

        aux = aux->proximo;
    }

    printf("Codigo do jogador...............: %i\n", maior->jogador.codigo);
    printf("Jogador.........................: %s\n", maior->jogador.nome);
    printf("Idade...........................: %i\n", maior->jogador.idade);
    printf("Altura..........................: %.2f\n", maior->jogador.altura);
    printf("Peso............................: %.2f\n", maior->jogador.peso);
    printf("Posicao(oes)....................: %s\n", maior->jogador.posicao);
    printf("Valor de venda..................: %.2f\n", maior->jogador.valor_passe);
    printf("Valor de aquisicao..............: %.2f\n", maior->jogador.aquisicao);
    printf("Salario.........................: %.2f\n", maior->jogador.salario);
    printf("Estado..........................: %d\n", maior->jogador.atividade);
    printf("Motivo da inativiade............: %s\n", maior->jogador.motivo);
    printf("\n");

    msg_apertar_enter();
}

void menor_salario(no_jogadores_t* lista)
{
    if(lista==NULL || lista->proximo==NULL) return;
    printf("\n");
    no_jogadores_t *menor = lista;
    no_jogadores_t *aux = lista->proximo;
    while (aux) {

        if (aux->jogador.salario < menor->jogador.salario) {
            menor = aux;
        }

        aux = aux->proximo;
    }

    printf("Codigo do jogador...............: %i\n", menor->jogador.codigo);
    printf("Jogador.........................: %s\n", menor->jogador.nome);
    printf("Idade...........................: %i\n", menor->jogador.idade);
    printf("Altura..........................: %.2f\n", menor->jogador.altura);
    printf("Peso............................: %.2f\n", menor->jogador.peso);
    printf("Posicao(oes)....................: %s\n", menor->jogador.posicao);
    printf("Valor de venda..................: %.2f\n", menor->jogador.valor_passe);
    printf("Valor de aquisicao..............: %.2f\n", menor->jogador.aquisicao);
    printf("Salario.........................: %.2f\n", menor->jogador.salario);
    printf("Estado..........................: %d\n", menor->jogador.atividade);
    printf("Motivo da inativiade............: %s\n", menor->jogador.motivo);
    printf("\n");

    msg_apertar_enter();
}

void faixa_salarial(no_jogadores_t* lista, float min, float max)
{
    int achou = 0;
    printf("\n");
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
        }

        lista = lista->proximo;
    }

    if (achou == 0) {
        printf("Nenhum jogador nessa faixa salarial\n\n");
    }

    msg_apertar_enter();
}

void mostrar_confrontos(no_jogos_t* lista, string nome)
{
    int achou = 0;

    printf("\n");
    printf("Confrontos contra %s\n", nome);
    while(lista) { 
        if(strcasecmp(lista->jogo.time_adv, nome) == 0) { //compara as strings
            printf("Data: %s | Resultado: %d X %d\n", lista->jogo.data_jogo, lista->jogo.resultado, lista->jogo.resultado_adv);
            achou = 1;
        }
        lista = lista->proximo;
    }
     if (achou == 0) {
        printf("Nenhum jogo contra o time registrado\n\n");
    }
    printf("\n");
    
    msg_apertar_enter();
}