#include "../include/cadastros.h"

bool lista_jogadores_vazia(no_jogadores_t* lista)
{
    if(lista) return false;

    return true;
}

bool lista_jogos_vazia(no_jogos_t* lista)
{
    if(lista) return false;

    return true;
}

void inicializa_lista_jogadores(lista_jogadores_t *lista)
{
    lista->cabeca = NULL;
    lista->qtd_nos = 0;
}

void inicializa_lista_jogos(lista_jogos_t *lista)
{
    lista->cabeca = NULL;
    lista->qtd_nos = 0;
}

no_jogadores_t *acha_ultimo_jogadores(no_jogadores_t* lista)
{
    while (lista->proximo) {
        lista = lista->proximo;
    }

    return lista;
}

no_jogos_t *acha_ultimo_jogos(no_jogos_t* lista)
{
    while (lista->proximo) {
        lista = lista->proximo;
    }

    return lista;
}

no_jogadores_t *cadastrar_jogador()
{
    //cadastra um jogador
    no_jogadores_t *novo;

    novo = (no_jogadores_t*)malloc(sizeof(no_jogadores_t));

    if (!novo) return NULL;

    novo->jogador.codigo = 0;
    printf("Digite o nome do jogador: ");
    fgets(novo->jogador.nome, TM, stdin);
    apaga_enter(novo->jogador.nome);
    printf("Digite a idade do jogador: ");
    scanf("%d", &novo->jogador.idade);
    printf("Digite a altura do jogador: ");
    scanf("%f", &novo->jogador.altura);
    printf("Digite o peso do jogador: ");
    scanf("%f", &novo->jogador.peso);
    getchar();
    printf("Digite a posicao do jogador: ");
    fgets(novo->jogador.posicao, TM, stdin);
    apaga_enter(novo->jogador.posicao);
    printf("Digite o valor de venda jogador: ");
    scanf("%f", &novo->jogador.valor_passe);
    printf("Digite o valor de aquisicao do jogador: ");
    scanf("%f", &novo->jogador.aquisicao);
    printf("Digite o salario do jogador: ");
    scanf("%f", &novo->jogador.salario);
    novo->jogador.atividade = ATIVO;
    if (novo->jogador.atividade = ATIVO) {
        strcpy(novo->jogador.motivo, "Jogador ativo");
    }
   
    novo->qtd_jogadores++;

    return novo;
}

void insere_cadastro_fim_jogadores(no_jogadores_t *novo, lista_jogadores_t *lista)
{
    no_jogadores_t *ultimo;
    // Define o codigo
    novo->jogador.codigo = ++lista->qtd_nos;

    if (lista_jogadores_vazia(lista->cabeca)) {
        lista->cabeca = novo;
        return;
    }
    ultimo = acha_ultimo_jogadores(lista->cabeca);
    ultimo->proximo = novo;
}

void recadastrar_jogador(no_jogadores_t* lista, int codigo)
{

}

no_jogos_t *cadastrar_jogo()
{
    //Cadastra n jogos
    no_jogos_t *novo; 

    novo = (no_jogos_t*)malloc(sizeof(no_jogos_t));

    if (!novo) return NULL;

    printf("Digite o nome do time adversario: ");
    fgets(novo->jogo.time_adv, TM, stdin);
    apaga_enter(novo->jogo.time_adv);
    printf("Digite a data do jogo (DD/MM/AAAA): ");
    fgets(novo->jogo.data_jogo, TM, stdin);
    apaga_enter(novo->jogo.data_jogo);
    printf("Digite o local do jogo: ");
    fgets(novo->jogo.local, TM, stdin);
    apaga_enter(novo->jogo.local);
    printf("Digite quantos gols o time fez: ");
    scanf("%d", &novo->jogo.resultado);
    printf("Digite quantos gols o time adversario fez: ");
    scanf("%d", &novo->jogo.resultado_adv);
    getchar();
    printf("Digite os nomes dos jogadores escalados: ");
    fgets(novo->jogo.time_escalado, TM, stdin);
    apaga_enter(novo->jogo.time_escalado);
    printf("Digite o numero de substituicoes: ");
    scanf("%d", &novo->jogo.substituicoes);

    return novo;
}

void insere_cadastro_fim_jogos(no_jogos_t *novo, lista_jogos_t *lista)
{
    no_jogos_t *ultimo;
    novo->jogo.codigo = ++lista->qtd_nos;
    novo->qtd_jogos++;

    if (lista_jogos_vazia(lista->cabeca)) {
        lista->cabeca = novo;
        return;
    }

    ultimo = acha_ultimo_jogos(lista->cabeca);
    ultimo->proximo = novo;
    //novo->proximo = lista->cabeca;
    //lista->cabeca = novo;
}

