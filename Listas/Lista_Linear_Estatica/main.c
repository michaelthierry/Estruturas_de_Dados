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
        printf("@> Lista criada\n"
               "@> Tipo: Lista Linear Estatica\n"
               "@> Tamanho: %d\n", MAX);
        
    }else{
        printf("@> Erro ao criar a lista\n");
    }
    //Destruindo a lista
    lista_destruir(lista);
    printf("@> Lista destruida\n");
    return 0;
}