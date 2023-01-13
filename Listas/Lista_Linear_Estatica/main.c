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
            case 0:
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