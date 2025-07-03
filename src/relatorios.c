#include "../include/relatorios.h"

void mostrar_jogador(no_jogadores_t* dado)
{

    printf("Codigo do jogador...............: %i\n", dado->jogador.codigo);
    printf("Jogador.........................: %s\n", dado->jogador.nome);
    printf("Idade...........................: %i\n", dado->jogador.idade);
    printf("Altura..........................: %.2f\n", dado->jogador.altura);
    printf("Peso............................: %.2f\n", dado->jogador.peso);
    printf("Posicao(oes)....................: %s\n", dado->jogador.posicao);
    printf("Valor de venda..................: %.2f\n", dado->jogador.valor_passe);
    printf("Valor de aquisicao..............: %.2f\n", dado->jogador.aquisicao);
    printf("Salario.........................: %.2f\n", dado->jogador.salario);
    printf("Atividade.......................: %d\n", dado->jogador.atividade);
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
    
    printf("\n--- Jogo %d ---\n", dado->jogo.codigo);
    printf("Adversario...: %s\n", dado->jogo.time_adv);
    printf("Data.........: %s\n", dado->jogo.data_jogo);
    printf("Local........: %s\n", dado->jogo.local);
    printf("Resultado....: %d X %d\n", dado->jogo.resultado, dado->jogo.resultado_adv);
    printf("Escalados....: %s\n", dado->jogo.time_escalado);
    printf("Substituicoes: %d\n", dado->jogo.substituicoes);
    
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
    printf("\n");
    while(lista) {
        
        if(lista->jogador.idade >= min && lista->jogador.idade <= max) {
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
        printf("Nenhum jogador nessa faixa etaria\n\n");
    }
    
    msg_apertar_enter();
}

void jogadores_vendidos(no_jogadores_t* lista)
{
    int qtd_vendidos = 0;
    printf("\n");
    while(lista) {
        if(strcasecmp(lista->jogador.motivo, "vendido") == 0) {
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
            qtd_vendidos++;
        }
        lista = lista->proximo;
    }
    printf("Quantidade de jogadores vendidos: %d\n\n", qtd_vendidos);

    msg_apertar_enter();
}

void mostrar_resultado_jogos(no_jogos_t* lista)
{
    printf("\n");
    //Mostra todos o resultados dos jogos
    printf("Resultados dos Jogos\n");
    while (lista) {
        printf("%s: %d X %d\n", lista->jogo.time_adv, lista->jogo.resultado, lista->jogo.resultado_adv);
        lista = lista->proximo;
    }
    printf("\n");

    msg_apertar_enter();
}

void mostrar_valor_time(no_jogadores_t* lista)
{
    float total = 0;
    int ativos = 0, vendidos = 0;
    printf("\n");
    
    while (lista) {
        if (lista->jogador.atividade == 1) {
            total += lista->jogador.valor_passe;
            ativos++;
        } else if (lista->jogador.atividade == 0 && strcasecmp(lista->jogador.motivo, "Vendido") == 0) {
            total += lista->jogador.valor_passe;
            vendidos++;
        }
        lista = lista->proximo;
    }

    printf("\n--- Valor do Time ---\n");
    printf("Jogadores Ativos..: %d\n", ativos);
    printf("Jogadores Vendidos: %d\n", vendidos);
    printf("Valor Total.......: R$ %.2f\n\n", total);

    msg_apertar_enter();
}

void mostrar_aproveitamento(no_jogos_t* lista, lista_jogos_t* ptr_lista)
{
    int vitoria = 0;
    int derrota = 0;
    int empate = 0;
    float result;
    printf("\n");

    while (lista) {
        if(lista->jogo.resultado > lista->jogo.resultado_adv){
            vitoria++;
        }
        else if(lista->jogo.resultado < lista->jogo.resultado_adv){
                derrota++;
            }   
        else{
            empate++;
        }
        
        lista = lista->proximo;
    }
    result = ((float)vitoria / ptr_lista->qtd_nos) * 100;    
    printf("Vitorias: %d\n", vitoria);
    printf("Empates: %d\n", empate);
    printf("Derrotas: %d\n", derrota);
    printf("Aproveitamento do time: %.2f%%\n", result);
    printf("\n");

    msg_apertar_enter();
}