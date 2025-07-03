//Código feito por Gian Maick Perira e Ian Kamphorst Leal
#include "./include/types.h"
#include "./include/buscas.h"
#include "./include/cadastros.h"
#include "./include/relatorios.h"
#include "./include/files.h"
#include "./include/menus.h"





int menu();

//Prototipo de carga
/*
void carregar_jogadores_txt(const char *filename); 
void carregar_jogos_txt(const char *filename);
*/



int main()
{
    /*carregar_jogadores_txt("jogadores.txt");
    carregar_jogos_txt("jogos.txt");
    */
    lista_jogadores_t lista_jogadores;
    lista_jogos_t lista_jogos;
    no_jogadores_t *aux_jogadores;
    no_jogos_t *aux_jogos;
    
    int opc, opc_arq, opc_rela, sub_menu, idade_min, idade_max, codigo_jogador;
    string nome_jogador, posicao_jogador, nome_adversario;
    float salario_min, salario_max;

    inicializa_lista_jogadores(&lista_jogadores);
    inicializa_lista_jogos(&lista_jogos);
    ler_jogadores_arquivo_binario("jogadores.bin", lista_jogadores.cabeca, &lista_jogadores);
    ler_jogos_arquivo_binario("jogos.bin", lista_jogos.cabeca, &lista_jogos);


    do {
        sub_menu = menu_principal();
        switch (sub_menu)
        {
            case 1:
                do {
                    opc = menu_cadastros();

                    switch (opc)
                    {
                        case 1: aux_jogadores = cadastrar_jogador();
                            insere_cadastro_fim_jogadores(aux_jogadores, &lista_jogadores);
                                break;

                        case 2: aux_jogos = cadastrar_jogo(lista_jogadores.cabeca);
                            insere_cadastro_fim_jogos(aux_jogos, &lista_jogos);
                                break;

                        case 3: printf("Digite o codigo do jogador que deseja alterar: \n");
                                scanf("%d", &codigo_jogador);
                                getchar();
                                recadastrar_jogador(lista_jogadores.cabeca, codigo_jogador);
                                break;

                        case 4: printf("Digite o codigo do jogador que deseja alterar: \n");
                                scanf("%d", &codigo_jogador);
                                getchar();
                                mudar_atividade_jogador(lista_jogadores.cabeca, codigo_jogador);
                                break;
                            
                        case 0: break;   

                    } 
                } while (opc != 0);
                    break;

            case 2: 
                do {
                    opc = menu_relatorios_geral();

                    switch (opc)
                    {
                        case 1: do {
                                    opc_rela = menu_relatorios();
                                    
                                    switch (opc_rela) {
                                        case 1: mostrar_todos_jogadores(lista_jogadores.cabeca);
                                                break;

                                        case 2: mostrar_todos_jogos(lista_jogos.cabeca);
                                                break;

                                        case 3: printf("Digite a idade minima: \n");
                                                scanf("%d", &idade_min);
                                                getchar();
                                                printf("Digite a idade maxima: \n");
                                                scanf("%d", &idade_max);
                                                getchar();
                                                faixa_etaria(lista_jogadores.cabeca, idade_min, idade_max);
                                                break;

                                        case 4: jogadores_vendidos(lista_jogadores.cabeca);
                                                break;

                                        case 5: mostrar_resultado_jogos(lista_jogos.cabeca);
                                                break;

                                        case 6: mostrar_valor_time(lista_jogadores.cabeca);
                                                break;

                                        case 7: mostrar_aproveitamento(lista_jogos.cabeca, &lista_jogos);
                                                break;
                                            
                                        case 0: break;      
                                    }
                                } while (opc_rela != 0);
                                break;

                        case 2: do {
                                    opc_rela = menu_relatorios_csv();
                                    switch (opc_rela) {
                                        case 1: mostrar_todos_jogadores(lista_jogadores.cabeca);
                                                break;

                                        case 2: mostrar_todos_jogos(lista_jogos.cabeca);
                                                break;

                                        case 3: printf("Digite a idade minima: \n");
                                                scanf("%d", &idade_min);
                                                getchar();
                                                printf("Digite a idade maxima: \n");
                                                scanf("%d", &idade_max);
                                                getchar();
                                                faixa_etaria(lista_jogadores.cabeca, idade_min, idade_max);
                                                break;

                                        case 4: jogadores_vendidos(lista_jogadores.cabeca);
                                                break;

                                        case 5: mostrar_resultado_jogos(lista_jogos.cabeca);
                                                break;

                                        case 6: mostrar_valor_time(lista_jogadores.cabeca);
                                                break;

                                        case 7: mostrar_aproveitamento(lista_jogos.cabeca, &lista_jogos);
                                                break;
                                            
                                        case 0: break;      
                                    }
                                    
                                } while (opc_rela != 0);
                                    break;

                    }
                } while (opc != 0);

                    break;

            case 3: 
                do {
                    opc = menu_buscas();

                    switch (opc) {
                        case 1: printf("Digite o nome do jogador a ser buscado: \n");
                                fgets(nome_jogador, TM, stdin);
                                apaga_enter(nome_jogador);
                                busca_nome(lista_jogadores.cabeca, nome_jogador);
                                break;

                        case 2: printf("Digite a posicao que deseja buscar: \n");
                                fgets(posicao_jogador, TM, stdin);
                                apaga_enter(posicao_jogador);
                                busca_posicao(lista_jogadores.cabeca, posicao_jogador);
                                break;

                        case 3: maior_salario(lista_jogadores.cabeca);
                                break;

                        case 4: menor_salario(lista_jogadores.cabeca);
                                break;

                        case 5: printf("Digite o salario minimo: \n");
                                scanf("%f", &salario_min);
                                getchar();
                                printf("Digite o salario maximo: \n");
                                scanf("%f", &salario_max);
                                getchar();
                                faixa_salarial(lista_jogadores.cabeca, salario_min, salario_max);
                                break;

                        case 6: printf("Deseja ver os confrontos contra qual time? \n");
                                fgets(nome_adversario, TM, stdin);
                                apaga_enter(nome_adversario);
                                mostrar_confrontos(lista_jogos.cabeca, nome_adversario);
                                break;

                        case 0: break;
                    }

                } while (opc != 0);

                    break;

            case 4: 
                do{
                    opc = menu_arquivos();

                    switch(opc){
                        
                        case 1: do {
                                    opc_arq = menu_arquivos_jogadores();

                                    switch (opc_arq){
                                        case 1:
                                                break;

                                        case 2: exportar_Jogadores_arquivo_html("jogadores.html", lista_jogadores.cabeca);
                                                break;

                                        case 0:
                                                break;

                                    }


                                } while (opc_arq != 0);
                                    break;
                        
                        case 2: do{
                                    opc_arq = menu_arquivos_jogos();
                                    
                                    switch (opc_arq){
                                        case 1: 
                                                break;
                                        case 2: //exportar_Jogos_arquivo_html("jogos.html", lista_jogos.cabeca);
                                                break;
                                        case 0: 
                                                break;
                                    }

                                } while (opc_arq != 0);
                                break;
                    } 
                
                } while (opc != 0);
            case 0: break;
        
        }
        
    } while (sub_menu != 0);


    if (!lista_jogadores_vazia(lista_jogadores.cabeca)) {
        salvar_jogadores_arquivo_bin("jogadores.bin", lista_jogadores.cabeca);
    }

    if (!lista_jogos_vazia(lista_jogos.cabeca)) {
        salvar_jogos_arquivo_bin("jogos.bin", lista_jogos.cabeca);
    }

    return 0;
}


//Implementação

//Parte do Ian, todos o relatorios e busca de jogos





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