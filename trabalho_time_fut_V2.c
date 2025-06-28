//Código feito por Gian Maick Perira e Ian Kamphorst Leal
#include "../include/types.h"





int menu();

//Prototipo de carga
/*
void carregar_jogadores_txt(const char *filename); 
void carregar_jogos_txt(const char *filename);
*/
dados_jogador_t jogadores;
dados_jogos_t jogos;



int main()
{
    /*carregar_jogadores_txt("jogadores.txt");
    carregar_jogos_txt("jogos.txt");
    */
    lista_jogadores_t lista_jogadores;
    lista_jogos_t lista_jogos;
    
    int opc, idade_min, idade_max;
    string nome_jogador, posicao_jogador;
    float salario_min, salario_max;

    do {
        opc = menu();
        switch (opc)
        {
                //Parte dos jogadores | Gian
        case 1: //cadastra um jogador
            jogadores.jogador[jogadores.qtd_jogadores++] = cadastrar_jogador();
            printf("\n");
            break;

        case 2: //mostra todos os jogadores
            mostrar_jogador();
            break;
        
        case 3: //mostra jogadores por faixa etaria
            printf("Digite a idade minima: ");
            scanf("%d", &idade_min);
            printf("Digite a idade maxima: ");
            scanf("%d", &idade_max);
            faixa_etaria(idade_min, idade_max);
            break;

        case 4://mostra jogador por nome
            printf("Digite o nome do jogador que deseja encontrar: ");
            fgets(nome_jogador, TM, stdin);
            nome_jogador[strlen(nome_jogador)- 1] = '\0';
            busca_nome(nome_jogador);
            break;

        case 5://mostra jogador por posicao que joga
            printf("Digite a posicao do jogador que deseja encontrar: ");
            fgets(posicao_jogador, TM, stdin);
            posicao_jogador[strlen(posicao_jogador)- 1] = '\0';
            busca_posicao(posicao_jogador);//arrumar dps
            break;

        case 6://Mostrar jogador com maior salario
            printf("Jogador com maior salario: \n");
            maior_salario();
              
            break;

        case 7: //Mostrar jogador com maior salario
            printf("Jogador com menor salario: \n");
            menor_salario();
              
            break;
                
        case 8://mostra jogadores por faixa etaria  
            printf("Digite o salario minimo: ");
            scanf("%f", &salario_min);
            printf("Digite o salario maximo: ");
            scanf("%f", &salario_max);
            faixa_salarial(salario_min, salario_max);
            break;

        case 9://mostra os jogadores vendidos
            jogadores_vendidos(jogadores.jogador[jogadores.qtd_jogadores].motivo);
            break;

            //Parte dos jogos | Ian
        case 10: //Recebe os valores da func Cadastrar jogos
            jogos.jogo[jogos.qtd_jogos++] = cadastrar_jogo();
            break;

        case 11: //Mostra todos os jogos
              mostrar_jogo();
            break;

        case 12: //Mostra todos os confrontos
              mostrar_resultado_jogos();
            break;

        case 13: //Mostrar os confrontos contra um time especifico
              mostrar_confrontos();
            break;

        case 14: //Mostra o valor do time
              mostrar_valor_time();
            break;

        case 15://Mostra a quantidade de jogos vencidos em relação a quantidade de jogos jogados
              mostrar_aproveitamento();
            break;

        case 0: printf("Tchau\n");
            break;
        
        }
        
    } while (opc != 0);

    return 0;
}


//Implementação

void busca_posicao(string posicao)//case 5
{
    
}

void maior_salario()//case 6
{
    int maior, pos_maior;
    maior = jogadores.jogador[0].salario;
    for (size_t i = 1; i < jogadores.qtd_jogadores; i++) {
        if(maior < jogadores.jogador[i].salario) {
            maior = jogadores.jogador[i].salario;
            pos_maior = i;
        }
    }
    printf("Jogador.........................: %s\n", jogadores.jogador[pos_maior].nome);
    printf("Idade...........................: %i\n", jogadores.jogador[pos_maior].idade);
    printf("Altura..........................: %.2f\n", jogadores.jogador[pos_maior].altura);
    printf("Peso............................: %.2f\n", jogadores.jogador[pos_maior].peso);
    printf("Posicao(oes)....................: %s\n", jogadores.jogador[pos_maior].posicao);
    printf("Valor de venda..................: %.2f\n", jogadores.jogador[pos_maior].valor_passe);
    printf("Valor de aquisicao..............: %.2f\n", jogadores.jogador[pos_maior].aquisicao);
    printf("Salario.........................: %.2f\n", jogadores.jogador[pos_maior].salario);
    printf("Estado..........................: %d\n", jogadores.jogador[pos_maior].atividade);
    printf("Motivo da inativiade............: %s\n", jogadores.jogador[pos_maior].motivo);
    printf("\n");
    
}

void menor_salario()//case 7
{
    int menor, pos_menor;
    menor = jogadores.jogador[0].salario;
    for (size_t i = 1; i < jogadores.qtd_jogadores; i++) {
        if(menor > jogadores.jogador[i].salario) {
            menor = jogadores.jogador[i].salario;
            pos_menor = i;
        }
    }
    
}

void faixa_salarial(float min, float max)//case 8
{
    
}

void jogadores_vendidos(string motivo)//case 9
{
    int qtd_vendidos = 0;
    for(size_t i = 0; i < jogadores.qtd_jogadores; i++) {
        if(strcasecmp(jogadores.jogador[i].motivo, "vendido") == 0) {
            printf("Jogador.........................: %s\n", jogadores.jogador[i].nome);
            printf("Idade...........................: %i\n", jogadores.jogador[i].idade);
            printf("Altura..........................: %.2f\n", jogadores.jogador[i].altura);
            printf("Peso............................: %.2f\n", jogadores.jogador[i].peso);
            printf("Posicao(oes)....................: %s\n", jogadores.jogador[i].posicao);
            printf("Valor de venda..................: %.2f\n", jogadores.jogador[i].valor_passe);
            printf("Valor de aquisicao..............: %.2f\n", jogadores.jogador[i].aquisicao);
            printf("Salario.........................: %.2f\n", jogadores.jogador[i].salario);
            printf("Estado..........................: %d\n", jogadores.jogador[i].atividade);
            printf("Motivo da inativiade............: %s\n", jogadores.jogador[i].motivo);
            printf("\n");
            qtd_vendidos++;
        }
    }
    printf("Quantidade de jogadores vendidos: %d\n\n", qtd_vendidos);
}
//Parte do Ian, todos o relatorios e busca de jogos


void mostrar_resultado_jogos()//case 12
{   
    //Mostra todos o resultados dos jogos
    printf("Resultados dos Jogos\n");
    for(size_t i = 0; i < jogos.qtd_jogos; i++) {
        printf("%s: %d X %d\n", jogos.jogo[i].time_adv, jogos.jogo[i].resultado, jogos.jogo[i].resultado_adv);
    }
    printf("\n");
}

void mostrar_confrontos()//case 13
{
    string nome;
    printf("Digite o nome do time adversario: ");
    fgets(nome, TM, stdin);
    nome[strlen(nome)- 1] = '\0';

    printf("Confrontos contra %s\n", nome);
    for(size_t i = 0; i < jogos.qtd_jogos; i++) { 
        if(strcasecmp(jogos.jogo[i].time_adv, nome) == 0) { //compara as strings
            printf("Data: %s | Resultado: %d X %d\n", jogos.jogo[i].data_jogo, jogos.jogo[i].resultado, jogos.jogo[i].resultado_adv);
        }
    }
    printf("\n");
}

void mostrar_valor_time()//case 14
{
    float total = 0;
    int ativos = 0, vendidos = 0;
    
    for (size_t i = 0; i < jogadores.qtd_jogadores; i++) {
        if (jogadores.jogador[i].atividade == 1) {
            total += jogadores.jogador[i].valor_passe;
            ativos++;
        } else if (jogadores.jogador[i].atividade == 0 && strcasecmp(jogadores.jogador[i].motivo, "Vendido") == 0) {
            total += jogadores.jogador[i].valor_passe;
            vendidos++;
        }
    }

    printf("\n--- Valor do Time ---\n");
    printf("Jogadores Ativos..: %d\n", ativos);
    printf("Jogadores Vendidos: %d\n", vendidos);
    printf("Valor Total.......: R$ %.2f\n\n", total);
}

void mostrar_aproveitamento()//case 15
{   
    int vitoria = 0;
    int derrota = 0;
    int empate = 0;
    float result;

    for (size_t i = 0; i < jogos.qtd_jogos; i++) {
        if(jogos.jogo[i].resultado > jogos.jogo[i].resultado_adv){
            vitoria++;
        }
        else if(jogos.jogo[i].resultado < jogos.jogo[i].resultado_adv){
                derrota++;
            }   
        else{
            empate++;
        }
        
        qtd_partidas++;
    }
    result = ((float)vitoria / jogos.qtd_jogos) * 100;    
    printf("Vitorias: %d\n", vitoria);
    printf("Empates: %d\n", empate);
    printf("Derrotas: %d\n", derrota);
    printf("Aproveitamento do time: %.2f%%\n", result);
    printf("\n");
}

//Aqui é o menu organizado por hora
int menu()
{
    int opcao;
    printf("MENU JOGADORES\n");
    printf("1.Cadastrar jogador:\n");
    printf("2.Mostrar jogadores:\n");
    printf("3.Mostrar jogadores por faixa etaria:\n");
    printf("4.Mostrar jogadores por nome:\n");
    printf("5.Mostrar jogadores por posicao:\n");
    printf("6.Mostrar jogador com maior salario:\n");
    printf("7.Mostrar jogador com menor salario:\n");
    printf("8.Mostrar jogadores por faixa salarial:\n");
    printf("9.Mostrar jogadores vendidos:\n\n");
    printf("MENU JOGOS\n");
    printf("10.Cadastrar jogos:\n");
    printf("11.Mostrar jogos:\n");
    printf("12.Mostrar resultado de jogos:\n");
    printf("13.Mostrar confrontos contra time adversario:\n");
    printf("14.Mostrar valor do time:\n");
    printf("15.Aproveitamento do time:\n");
    printf("0.Sair do programa\n");
    printf("Digite a opcao desejada: \n");
    scanf("%d", &opcao);
    getchar();
    printf("\n");

    return opcao;
}


//Aqui em baixo é só carregamento de dados e lá na func main mostra nas funcs mostrar_jogos e mostrar_jogadores
/*
void carregar_jogadores_txt(const char *filename) 
{
    FILE *file = fopen(filename, "r");
        if (!file) 
        {
            printf("Arquivo %s não encontrado.\n", filename);
            return;
        }
    cadastro_jogador_t temp;
        while(fgets(temp.nome, TM, file) != NULL && jogadores.qtd_jogadores < TM)
        {
            temp.nome[strcspn(temp.nome, "\n")] = '\0';
            fscanf(file, "%i\n", &temp.idade);
            fscanf(file, "%f\n", &temp.altura);
            fscanf(file, "%f\n", &temp.peso);
            fgets(temp.posicao, TM, file); 
            temp.posicao[strcspn(temp.posicao, "\n")] = '\0';
            fscanf(file, "%f\n", &temp.valor_passe);
            fscanf(file, "%f\n", &temp.aquisicao);
            fscanf(file, "%f\n", &temp.salario);
            fscanf(file, "%d\n", &temp.atividade);
            fgets(temp.motivo, TM, file);
            temp.motivo[strcspn(temp.motivo, "\n")] = '\0';
            
            //fgets(temp.atividade, TM, file);
            //temp.atividade[strcspn(temp.atividade, "\n")] = '\0';
            
            jogadores.jogador[jogadores.qtd_jogadores++] = temp;
        }
        fclose(file);
}

void carregar_jogos_txt(const char *filename)
{
    FILE *file = fopen(filename, "r");
        if (!file) 
        {
            printf("Arquivo %s não encontrado.\n", filename);
            return;
        } 
    cadastro_jogos_t temp;
        while (fgets(temp.time_adv, TM, file) != NULL && jogos.qtd_jogos < TM) 
        {
            temp.time_adv[strcspn(temp.time_adv, "\n")] = '\0';
            fgets(temp.data_jogo, TM, file); 
            temp.data_jogo[strcspn(temp.data_jogo, "\n")] = '\0';
            fgets(temp.local, TM, file); 
            temp.local[strcspn(temp.local, "\n")] = '\0';
            fscanf(file, "%d\n", &temp.resultado);
            fscanf(file, "%d\n", &temp.resultado_adv);
            fgets(temp.time_escalado, TM, file); 
            temp.time_escalado[strcspn(temp.time_escalado, "\n")] = '\0';
            fscanf(file, "%d\n", &temp.substituicoes);

            jogos.jogo[jogos.qtd_jogos++] = temp;
        }

        fclose(file);
}
*/