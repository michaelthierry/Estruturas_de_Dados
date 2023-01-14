/**
 * @file main.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Programa Principal
 * @version 0.1
 * @date 2023-01-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/*Incluindo Biblioteca*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*Programa Principal*/
int main(){
    //Criando variaveis
    Lista *lista;
    Dado elemento;
    //Mensagem para usuario
    printf("@> Criando a lista\n");
    //tenta alocar memoria para a lista
    lista = lista_criar();
    //Verifica se a lista foi criada
    if(lista != NULL){
        //Mostrando informações da lista
        printf("@> Lista criada\n"
               "@> Tipo: Lista Linear Estatica\n"
               "@> Tamanho: %d\n", MAX);
        //Variavel de opção
        int opcao;
        do{
            //Mostrando as opções 
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
            //lendo do usuario
            scanf("%i", &opcao);
            //Avaliando a opção
            switch(opcao){
            int valida;
            case 0:
                break;
            case 1:
                //Pegando informação
                printf("@> Digite o valor:\n");
                scanf("%i", &elemento.valor);
                //chamando a inserção
                valida = lista_inserir_inicio(lista, elemento);
                //Verificando
                if(valida > 0){
                    printf("@> Sucesso: Inserido no Inicio\n");
                }else{
                    printf("@> Falha: Ao inserir no inicio\n");
                }
                break;
            case 2:
                //Pegando informação
                printf("@> Digite o valor:\n");
                scanf("%i", &elemento.valor);
                //chamando a inserção
                valida = lista_inserir_ordenado(lista, elemento);
                //Verificando
                if(valida > 0){
                    printf("@> Sucesso: Inserido no meio\n");
                }else{
                    printf("@> Falha: Ao inserir no meio\n");
                }
                break;
            case 3:
                //Pegando informação
                printf("@> Digite o valor:\n");
                scanf("%i", &elemento.valor);
                //chamando a inserção
                valida = lista_inserir_fim(lista, elemento);
                //Verificando
                if(valida > 0){
                    printf("@> Sucesso: Inserido no fim\n");
                }else{
                    printf("@> Falha: Ao inserir no fim\n");
                }
                break;
            case 4:
                //chamando a remoção
                valida = lista_remover_inicio(lista);
                //Verificando
                if(valida > 0){
                    printf("@> Sucesso: Removido do inicio\n");
                }else{
                    printf("@> Falha: Ao remover do inicio\n");
                }
                break;
            case 5:
                //Pegando informação
                printf("@> Digite o valor a ser removido:\n");
                scanf("%i", &elemento.valor);
                //chamando a remoção
                valida = lista_remover_elemento(lista, elemento);
                //Verificando
                if(valida > 0){
                    printf("@> Sucesso: Removido do meio\n");
                }else{
                    printf("@> Falha: Ao remover do meio\n");
                }
                break;
            case 6:
                //chamando a remoção
                valida = lista_remover_fim(lista);
                //Verificando
                if(valida > 0){
                    printf("@> Sucesso: Removido do fim\n");
                }else{
                    printf("@> Falha: Ao remover do fim\n");
                }
                break;
            case 7:
                lista_mostrar(lista);
                printf("@> Lista mostrada\n");
                break;       
            default:
                printf("@> Opção Invalida!\n");
                break;
            }

        }while(opcao != 0);
        
    }else{
        printf("@> Erro ao criar a lista\n");
    }
    //Destruindo a lista
    lista_destruir(lista);
    printf("@> Lista destruida\n");
    return 0;
}