/**
 * @file lista.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Lista Linear Dinamica
 * @version 0.1
 * @date 2023-01-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*Inclindo biliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* lista_criar(){
    //Ponteiro do tipo lista
    Lista *lista;
    //Alocando memoria para lista
    lista = (Lista*) malloc(sizeof(Lista));
    //Se a lista for criada
    if(lista != NULL){
        lista->inicio = NULL;
    }
    //retorna a lista
    return lista;
}

void lista_destruir(Lista *lista){
    //Se existe
    if(lista != NULL){
        //cria um ponterio auxiliar
        Elemento *auxiliar;
        //Percore a lista liberando os elementos
        while(lista->inicio != NULL){
            auxiliar = lista->inicio;
            lista->inicio = lista->inicio->proximo;
            free(auxiliar);
        }
        //Libera a lista
        free(lista);
    }
}