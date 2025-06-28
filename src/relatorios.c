#include "../include/relatorios.h"

void mostrar_jogador(no_jogadores_t* dado)
{
    
       printf("Jogador.........................: %s\n", dado->jogador.nome);
       printf("Idade...........................: %i\n", dado->jogador.idade);
       printf("Altura..........................: %.2f\n", dado->jogador.altura);
       printf("Peso............................: %.2f\n", dado->jogador.peso);
       printf("Posicao(oes)....................: %s\n", dado->jogador.posicao);
       printf("Valor de venda..................: %.2f\n", dado->jogador.valor_passe);
       printf("Valor de aquisicao..............: %.2f\n", dado->jogador.aquisicao);
       printf("Salario.........................: %.2f\n", dado->jogador.salario);
       printf("Estado..........................: %d\n", dado->jogador.atividade);
       printf("Motivo da inativiade............: %s\n", dado->jogador.motivo);
       
       printf("\n");
    
}

void mostrar_todos_jogadores(no_jogadores_t* ptr_lista)
{
    while(ptr_lista) {
        mostrar_jogador(ptr_lista);
        ptr_lista = ptr_lista->proximo;
    }
    msg_apertar_enter();
}

void mostrar_jogo(no_jogos_t* dado)
{
    //Mostra todos os jogos cadastrados
    int i = 0:
    printf("\n--- Jogo %d ---\n", i+1);
    printf("Adversario...: %s\n", dado->jogo.time_adv);
    printf("Data.........: %s\n", dado->jogo.data_jogo);
    printf("Local........: %s\n", dado->jogo.local);
    printf("Resultado....: %d X %d\n", dado->jogo.resultado, dado->jogo.resultado_adv);
    printf("Escalados....: %s\n", dado->jogo.time_escalado);
    printf("Substituicoes: %d\n", dado->jogo.substituicoes);
    i++;
    
    printf("\n");

}

void mostrar_todos_jogos(no_jogos_t* ptr_lista)
{
    while(ptr_lista) {
        mostrar_jogo(ptr_lista);
        ptr_lista = ptr_lista->proximo;
    }
    msg_apertar_enter();
}

void faixa_etaria(no_jogadores_t* lista, int min, int max)
{
    int achou = 0;
    while(lista) {
        
        if(lista->jogador.idade >= min && lista->jogador.idade <= max) {
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
        printf("Nenhum jogador nessa faixa etaria\n\n");
    }
    
}

void jogadores_vendidos(string motivo);
void mostrar_resultado_jogos();
void mostrar_valor_time();
void mostrar_aproveitamento();