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
    
    int opc, opc_arq, opc_rela, sub_menu, idade_min, idade_max, codigo_jogador, codigo_jogo;
    string nome_jogador, posicao_jogador, nome_adversario, nome_arq;
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

                        case 5: printf("Digite o codigo do jogador que deseja excluir: \n");
                                scanf("%d", &codigo_jogador);
                                getchar();
                                printf("\n");
                                excluir_jogador(lista_jogadores.cabeca, codigo_jogador);
                                break;

                        case 6: printf("Digite o numero do jogo que deseja excluir: \n");
                                scanf("%d", &codigo_jogo);
                                getchar();
                                printf("\n");
                                excluir_jogo(lista_jogos.cabeca, codigo_jogo);
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
                                        case 1: printf("Qual nome deseja dar ao arquivo?\n");
                                                fgets(nome_arq, TM, stdin);
                                                apaga_enter(nome_arq);
                                                exportar_dados_para_arquivo_csv_jogadores(nome_arq, lista_jogadores.cabeca);
                                                abre_arquivo_csv(nome_arq);
                                                break;

                                        case 2: printf("Qual nome deseja dar ao arquivo?\n");
                                                fgets(nome_arq, TM, stdin);
                                                apaga_enter(nome_arq);
                                                exportar_dados_para_arquivo_csv_jogos(nome_arq, lista_jogos.cabeca);
                                                abre_arquivo_csv(nome_arq);
                                                break;

                                        case 3: printf("Qual nome deseja dar ao arquivo?\n");
                                                fgets(nome_arq, TM, stdin);
                                                apaga_enter(nome_arq);
                                                printf("Digite a idade minima: \n");
                                                scanf("%d", &idade_min);
                                                getchar();
                                                printf("Digite a idade maxima: \n");
                                                scanf("%d", &idade_max);
                                                getchar();
                                                exportar_faixa_etaria_csv_jogadores(nome_arq, lista_jogadores.cabeca, idade_min, idade_max);
                                                abre_arquivo_csv(nome_arq);
                                                break;

                                        case 4: printf("Qual nome deseja dar ao arquivo?\n");
                                                fgets(nome_arq, TM, stdin);
                                                apaga_enter(nome_arq);
                                                exportar_jogadores_vendidos_csv(nome_arq, lista_jogadores.cabeca);
                                                abre_arquivo_csv(nome_arq);
                                                break;

                                        case 5: printf("Qual nome deseja dar ao arquivo?\n");
                                                fgets(nome_arq, TM, stdin);
                                                apaga_enter(nome_arq);
                                                exportar_dados_resultados_csv_jogos(nome_arq, lista_jogos.cabeca);
                                                abre_arquivo_csv(nome_arq);
                                                break;

                                        case 6: printf("Qual nome deseja dar ao arquivo?\n");
                                                fgets(nome_arq, TM, stdin);
                                                apaga_enter(nome_arq);
                                                exportar_dados_valor_time_csv(nome_arq, lista_jogadores.cabeca);
                                                abre_arquivo_csv(nome_arq);
                                                break;

                                        case 7: printf("Qual nome deseja dar ao arquivo?\n");
                                                fgets(nome_arq, TM, stdin);
                                                apaga_enter(nome_arq);
                                                exportar_dados_aproveitamento_csv_jogos(nome_arq, lista_jogos.cabeca, &lista_jogos);
                                                abre_arquivo_csv(nome_arq);
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
                                        case 1: exportar_arquivo_jogadores_txt("jogadores.txt", lista_jogadores.cabeca);
                                                abre_arquivo_txt("jogadores.txt");
                                                break;

                                        case 2: exportar_Jogadores_arquivo_html("jogadores.html", lista_jogadores.cabeca);
                                                abre_arquivo_html("jogadores.html");
                                                break;

                                        case 0:
                                                break;

                                    }


                                } while (opc_arq != 0);
                                    break;
                        
                        case 2: do{
                                    opc_arq = menu_arquivos_jogos();
                                    
                                    switch (opc_arq){
                                        case 1: exportar_arquivo_jogos_txt("jogos.txt", lista_jogos.cabeca);
                                                abre_arquivo_txt("jogos.txt");
                                                break;
                                        case 2: exportar_Jogos_arquivo_html("jogos.html", lista_jogos.cabeca);
                                                abre_arquivo_html("jogos.html");
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

    apagar_lista_jogadores(&lista_jogadores.cabeca);
    apagar_lista_jogos(&lista_jogos.cabeca);

    return 0;
}
