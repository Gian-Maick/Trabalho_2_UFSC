#include "../include/cadastros.h"

no_jogadores_t cadastrar_jogador()
{
    //cadastra um jogador
    no_jogadores_t novo_jogador;

    novo_jogador = (no_jogadores_t*)malloc(sizeof(no_jogadores_t));

     if (!novo_jogador) return NULL;

    printf("Digite o nome do jogador: ");
    fgets(novo_jogador->jogador.nome, TM, stdin);
    apaga_enter(novo_jogador->jogador.nome);
    printf("Digite a idade do jogador: ");
    scanf("%d", &novo_jogador->jogador.idade);
    printf("Digite a altura do jogador: ");
    scanf("%f", &novo_jogador->jogador.altura);
    printf("Digite o peso do jogador: ");
    scanf("%f", &novo_jogador->jogador.peso);
    getchar();
    printf("Digite a posicao do jogador: ");
    fgets(novo_jogador->jogador.posicao, TM, stdin);
    apaga_enter(novo_jogador->jogador.posicao);
    printf("Digite o valor de venda jogador: ");
    scanf("%f", &novo_jogador->jogador.valor_passe);
    printf("Digite o valor de aquisicao do jogador: ");
    scanf("%f", &novo_jogador->jogador.aquisicao);
    printf("Digite o salario do jogador: ");
    scanf("%f", &novo_jogador->jogador.salario);
    novo_jogador->jogador.atividade = ATIVO;
    if (novo_jogador->jogador.atividade = ATIVO) {
        novo_jogador->jogador.motivo = "Jogador ativo";
    }
    novo_jogador->qtd_jogadores++;

    return novo_jogador;
}

void recadrastrar_jogador(no_jogadores_t* lista, string nome)
{

}

no_jogos_t cadastrar_jogo()
{
    //Cadastra n jogos
    no_jogos_t novo_jogo; 

    novo_jogo = (no_jogos_t*)malloc(sizeof(no_jogos_t));

    if (!novo_jogo) return NULL;

    printf("Digite o nome do time adversario: ");
    fgets(novo_jogo->jogo.time_adv, TM, stdin);
    apaga_enter(novo_jogo->jogo.time_adv);
    printf("Digite a data do jogo (DD/MM/AAAA): ");
    fgets(novo_jogo->jogo.data_jogo, TM, stdin);
    apaga_enter(novo_jogo->jogo.data_jogo);
    printf("Digite o local do jogo: ");
    fgets(novo_jogo->jogo.local, TM, stdin);
    apaga_enter(novo_jogo->jogo.local);
    printf("Digite quantos gols o time fez: ");
    scanf("%d", &novo_jogo->jogo.resultado);
    printf("Digite quantos gols o time adversario fez: ");
    scanf("%d", &novo_jogo->jogo.resultado_adv);
    getchar();
    printf("Digite os nomes dos jogadores escalados: ");
    fgets(novo_jogo->jogo.time_escalado, TM, stdin);
    apaga_enter(novo_jogo->jogo.time_escalado);
    printf("Digite o numero de substituicoes: ");
    scanf("%d", &novo_jogo->jogo.substituicoes);

    novo_jogo->qtd_jogos++;

    return novo_jogo;
}

