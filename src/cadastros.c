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
    printf("\n");
    printf("Digite a idade do jogador: ");
    scanf("%d", &novo->jogador.idade);
    printf("\n");
    printf("Digite a altura do jogador: ");
    scanf("%f", &novo->jogador.altura);
    printf("\n");
    printf("Digite o peso do jogador: ");
    scanf("%f", &novo->jogador.peso);
    getchar();
    printf("\n");
    printf("Digite a posicao do jogador: ");
    fgets(novo->jogador.posicao, TM, stdin);
    apaga_enter(novo->jogador.posicao);
    printf("\n");
    printf("Digite o valor de venda jogador: ");
    scanf("%f", &novo->jogador.valor_passe);
    printf("\n");
    printf("Digite o valor de aquisicao do jogador: ");
    scanf("%f", &novo->jogador.aquisicao);
    printf("\n");
    printf("Digite o salario do jogador: ");
    scanf("%f", &novo->jogador.salario);
    novo->jogador.atividade = ATIVO;
    printf("\n");
    if (novo->jogador.atividade == ATIVO) {
        strcpy(novo->jogador.motivo, "Jogador ativo");
    }

    return novo;
}

void insere_cadastro_fim_jogadores(no_jogadores_t *novo, lista_jogadores_t *lista)
{
    no_jogadores_t *ultimo;
    lista->qtd_nos++;
    // Define o codigo
    novo->jogador.codigo = lista->qtd_nos;
    novo->proximo = NULL;

    if (lista_jogadores_vazia(lista->cabeca)) {
        lista->cabeca = novo;
        return;
    }
    ultimo = acha_ultimo_jogadores(lista->cabeca);
    ultimo->proximo = novo;
}

no_jogadores_t *recadastrar_jogador(no_jogadores_t* cadastro, int codigo)
{
    int achou = 0;
    string recadastrar;
    no_jogadores_t* novo = cadastro;

    while (novo) {
        if (codigo == novo->jogador.codigo) {
            printf("\n");
            mostrar_jogador(novo);
            printf("Deseja recadastrar este jogador (Sim ou Nao)? \n");
            fgets(recadastrar, TM, stdin);
            apaga_enter(recadastrar);

            if (strcasecmp(recadastrar, "Sim") == 0 || strcasecmp(recadastrar, "S") == 0) {
                printf("\n");
                printf("Nome original: %s\n", cadastro->jogador.nome);
                printf("Digite o nome do jogador: ");
                fgets(novo->jogador.nome, TM, stdin);
                apaga_enter(novo->jogador.nome);
                printf("\n");

                printf("Idade original: %d\n", cadastro->jogador.idade);
                printf("Digite a idade do jogador: ");
                scanf("%d", &novo->jogador.idade);
                printf("\n");

                printf("Altura original: %.2f\n", cadastro->jogador.altura);
                printf("Digite a altura do jogador: ");
                scanf("%f", &novo->jogador.altura);
                printf("\n");

                printf("Peso original: %.2f\n", cadastro->jogador.peso);
                printf("Digite o peso do jogador: ");
                scanf("%f", &novo->jogador.peso);
                getchar();
                printf("\n");

                printf("Posicao original: %s\n", cadastro->jogador.posicao);
                printf("Digite a posicao do jogador: ");
                fgets(novo->jogador.posicao, TM, stdin);
                apaga_enter(novo->jogador.posicao);
                printf("\n");

                printf("Valor original: %.2f\n", cadastro->jogador.valor_passe);
                printf("Digite o valor de venda jogador: ");
                scanf("%f", &novo->jogador.valor_passe);
                printf("\n");

                printf("Valor original: %.2f\n", cadastro->jogador.salario);
                printf("Digite o salario do jogador: ");
                scanf("%f", &novo->jogador.salario);
                printf("\n");

                printf("Atividade original: %d\n", cadastro->jogador.atividade);
                printf("Digite a atividade do jogador (ativo = 1 ou inativo = 0): ");
                scanf("%d", &novo->jogador.atividade);
                getchar();
                printf("\n");
                if (novo->jogador.atividade == ATIVO) {
                    strcpy(novo->jogador.motivo, "Jogador ativo");
                }
                else {
                    printf("Qual o motivo da inatividade (lesionado ou vendido)? \n");
                    fgets(novo->jogador.motivo, TM, stdin);
                    apaga_enter(novo->jogador.motivo);
                }
                achou = 1;
                return cadastro;
            }
            else {
                msg_apertar_enter();

                return cadastro;
            }
            
        }

        novo = novo->proximo;
    }

    if (achou == 0) {
        printf("Nenhum jogador com este codigo encontrado\n\n");
    }
    msg_apertar_enter();
}

no_jogadores_t *mudar_atividade_jogador(no_jogadores_t *cadastro, int codigo)
{
    int achou = 0;
    string recadastrar;
    no_jogadores_t* novo = cadastro;

    while (novo) {
        if (codigo == novo->jogador.codigo) {
            printf("\n");
            mostrar_jogador(novo);
            printf("Deseja mudar a atividade deste jogador (Sim ou Nao)? \n");
            fgets(recadastrar, TM, stdin);
            apaga_enter(recadastrar);

            if (strcasecmp(recadastrar, "Sim") == 0 || strcasecmp(recadastrar, "S") == 0) {
                printf("\n");
                printf("Digite a atividade do jogador (ativo = 1 ou inativo = 0): ");
                scanf("%d", &novo->jogador.atividade);
                getchar();
                printf("\n");
                if (novo->jogador.atividade == ATIVO) {
                    strcpy(novo->jogador.motivo, "Jogador ativo");
                }
                else {
                    printf("Qual o motivo da inatividade (lesionado ou vendido)? \n");
                    fgets(novo->jogador.motivo, TM, stdin);
                    apaga_enter(novo->jogador.motivo);
                }
                achou = 1;
                return cadastro;
            }
            else {
                msg_apertar_enter();

                return cadastro;
            }
            
        }

        novo = novo->proximo;
    }

    if (achou == 0) {
        printf("Nenhum jogador com este codigo encontrado\n\n");
    }
    msg_apertar_enter();
}

no_jogos_t *cadastrar_jogo(no_jogadores_t* cadastro)
{
    //Cadastra n jogos
    no_jogos_t *novo; 
    int qtd = 0, codigo, i = 0, achou = 0;
    no_jogadores_t *aux = cadastro;
    no_jogadores_t *mostrar;
    int cadastrado[14];
    
    novo = (no_jogos_t*)malloc(sizeof(no_jogos_t));

    if (!novo) return NULL;

    printf("Digite o nome do time adversario: ");
    fgets(novo->jogo.time_adv, TM, stdin);
    apaga_enter(novo->jogo.time_adv);
    printf("\n");
    printf("Digite a data do jogo (DD/MM/AAAA): ");
    fgets(novo->jogo.data_jogo, TM, stdin);
    apaga_enter(novo->jogo.data_jogo);
    printf("\n");
    printf("Digite o local do jogo: ");
    fgets(novo->jogo.local, TM, stdin);
    apaga_enter(novo->jogo.local);
    printf("\n");
    printf("Digite quantos gols o time fez: ");
    scanf("%d", &novo->jogo.resultado);
    printf("\n");
    printf("Digite quantos gols o time adversario fez: ");
    scanf("%d", &novo->jogo.resultado_adv);
    getchar();
    printf("\n");

    
    while (aux || qtd < 3) {
        limpar_tela();
        mostrar = cadastro;
        while (mostrar) {
            if (mostrar->jogador.atividade == 1) {
                printf("Codigo do jogador...............: %i\n", mostrar->jogador.codigo);
                printf("Jogador.........................: %s\n", mostrar->jogador.nome);
                printf("Posicao(oes)....................: %s\n", mostrar->jogador.posicao);
                printf("Atividade.......................: %d\n", mostrar->jogador.atividade);
                printf("Motivo da inativiade............: %s\n", mostrar->jogador.motivo);
                printf("\n");
            }
            mostrar = mostrar->proximo;
        }
        printf("Jogadores escalados ate agora: %s\n\n", novo->jogo.time_escalado);
        printf("Digite o codigo do jogador a escalar: \n");
        scanf("%d", &codigo);
        getchar();
        

        for (i = 0; i < 7; i++) {
            if (cadastrado[i] == aux->jogador.codigo) {
                printf("jogador ja escalado.\n");
                break;
            }
        }

            if (codigo == aux->jogador.codigo) {
                if (aux->jogador.atividade == 1) {
                    if (strlen(novo->jogo.time_escalado) == 0) {
                        strcpy(novo->jogo.time_escalado, aux->jogador.nome);
                        qtd++;
                        cadastrado[qtd] = aux->jogador.codigo;
                        achou = 1;
                    }
                    else {
                        strcat(novo->jogo.time_escalado, ", ");
                        strcat(novo->jogo.time_escalado, aux->jogador.nome);
                        qtd++;
                        cadastrado[qtd] = aux->jogador.codigo;
                        achou = 1;
                    }
                }
                else {
                    printf("Jogador indisponivel\n");
                }
                
                aux = aux->proximo;
            }
            
        if (achou == 0) {
            printf("Nenhum jogador com este codigo encontrado\n\n");
        }
    
    }
    printf("\n");

    printf("Digite o numero de substituicoes: ");
    scanf("%d", &novo->jogo.substituicoes);
    printf("\n");

    return novo;
}

void insere_cadastro_fim_jogos(no_jogos_t *novo, lista_jogos_t *lista)
{
    no_jogos_t *ultimo;
    lista->qtd_nos++;
    novo->jogo.codigo = lista->qtd_nos;
    novo->proximo = NULL;

    if (lista_jogos_vazia(lista->cabeca)) {
        lista->cabeca = novo;
        return;
    }

    ultimo = acha_ultimo_jogos(lista->cabeca);
    ultimo->proximo = novo;
}

