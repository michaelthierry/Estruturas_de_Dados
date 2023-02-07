/**
 * @file lista.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Lista Dinamica Duplamente Encadeada
 * @version 0.1
 * @date 2022-12-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "lista.h"

int main(){
    //Cria um ponteiro para lista
    Lista *lista;
    Dado elemento;
    //Mensagem para o usuário
    printf("@> Criando lista\n");
    //tenta alocar memoria para a lista
    lista = lista_criar();

    if(lista != NULL){
        //varivel de opção
        int opcao;
        //informações iniciais da lista
        printf("@> Lista criada\n"
               "@> Tipo: Lista Duplamente Encadeada\n");
        //Menu
        do{
            printf("+------------------------------------------+\n"
                   "|               OPERACOES                  |\n"
                   "+------------------------------------------+\n"
                   "|[1] Inserir no inicio da lista            |\n"
                   "|[2] Inserir no meio da lista (ordenado)   |\n"
                   "|[3] Inserir no fim da lista               |\n"
                   "|[4] Remover do inicio da lista            |\n"
                   "|[5] Remover do meio (por valor)           |\n"
                   "|[6] Remover do fim da lista               |\n"
                   "|[7] Mostrar lista                         |\n"
                   "|[8] Consulta (por posição)                |\n"
                   "|[9] Consulta (por valor)                  |\n"
                   "|[0] Sair                                  |\n"
                   "+------------[Inserira-sua-opção]----------+\n");
            //Le a opção do usuario
            scanf("%i", &opcao);
            //Avalia a opção
            switch(opcao){

                int valida_operacao, valor, indice;
                
                case 0:
                    break;
                case 1:

                    printf("@> Digite o valor:\n");

                    scanf("%i", &elemento.valor);

                    valida_operacao = lista_inserir_inicio(lista, elemento);

                    if(valida_operacao == 1){
                        printf("@> Inserido no inicio\n");
                    }else{
                        printf("@> Erro na operação[%d]\n", valida_operacao);
                    }

                    break;
                case 2:

                    printf("@> Digite o valor:\n");

                    scanf("%i", &elemento.valor);

                    valida_operacao = lista_inserir_ordem(lista, elemento);

                    if(valida_operacao == 1){
                        printf("@> Inserido no meio\n");
                    }else{
                        printf("@> Erro na operação[%d]\n", valida_operacao);
                    }

                    break;
                case 3:
                    
                    printf("@> Digite o valor:\n");

                    scanf("%i", &elemento.valor);

                    valida_operacao = lista_inserir_fim(lista, elemento);

                    if(valida_operacao == 1){
                        printf("@> Inserido no fim\n");
                    }else{
                        printf("@> Erro na operação\n");
                    }

                    break;
                
                case 4:
                    
                    valida_operacao = lista_remover_inicio(lista);

                    if(valida_operacao == 1){
                        printf("@> Removido do inicio\n");
                    }else{
                        printf("@> Erro na operação\n");
                    }

                    break;
                case 5:
                    
                    printf("@> Digite o valor a ser removido:\n");
                    scanf("%i", &elemento.valor);
                    
                    valida_operacao = lista_remover_meio(lista, elemento);

                    if(valida_operacao == 1){
                        printf("@> Removido do meio\n");
                    }else{
                        printf("@> Erro na operação\n");
                    }                    
                    break;
                case 6:
                   
                    valida_operacao = lista_remover_fim(lista);

                    if(valida_operacao == 1){
                        printf("@> Removido do fim\n");
                    }else{
                        printf("@> Erro na operação\n");
                    }
                    break;
                
                case 7:
                    lista_mostrar(lista);
                    printf("@> Lista mostrada\n");
                    break;
                case 8:
                    printf("Digite a posição:\n");
                    scanf("%d", &indice);
                    valida_operacao = lista_buscar_posicao(lista, indice, &elemento);
                    if(valida_operacao <= 0){
                        printf("Operação não pode ser concluída\n");
                        break;
                    }
                    printf("ENCONTRADO\n");
                    printf("Elemento: |%d|\n", elemento.valor);
                    break;
                case 9:
                    printf("Digite o valor:\n");
                    scanf("%d", &valor);
                    valida_operacao = lista_buscar_valor(lista, valor, &elemento);
                    if(valida_operacao <= 0){
                        printf("Não foi possivel fazer a busca\n");
                        break;
                    }
                    printf("ENCONTRADO\n");
                    printf("Elemento: |%d|\n", elemento.valor);
                    break;
                default:
                    printf("@> Opção invalida!\n");
                    break;
            }
        }while(opcao != 0);
    }else{
        printf("@> Erro ao criar a lista\n");
    }
    lista_destruir(lista);
    printf("@> Lista destruida\n");
    return 0 ;
}