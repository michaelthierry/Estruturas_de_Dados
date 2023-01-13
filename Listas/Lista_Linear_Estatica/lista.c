/**
 * @file lista.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Lista Linear Estatica
 * @version 0.1
 * @date 2023-01-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//Incluindo bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* lista_criar(){
    //Declara ponterio do tipo lista
    Lista *lista;
    //Tenta alocar memoria
    lista = (Lista*) malloc(sizeof(Lista));
    //Verifica se foi alocado 
    if(lista != NULL){
        lista->quantidade = 0;
    }
    //Retorna o ponteiro
    return lista;
}

void lista_destruir(Lista *lista){
    //Libera a memoria alocado para a lista
    free(lista);
}

int lista_cheia(Lista *lista){
    //Se a lista existir
    if(lista == NULL){
        return -1;
    }
    //Verifica se esta cheia
    return (lista->quantidade == MAX);
}

int lista_vazia(Lista *lista){
    //se a lista existir
    if(lista == NULL){
        return -1;
    }
    return (lista->quantidade == 0);
}

int lista_tamanho(Lista *lista){
    //se a lista existe 
    if(lista == NULL){
        return -1;
    }
    //se e existir retorna a quantidade
    return lista->quantidade;
}

int lista_mostrar(Lista *lista){
    //se a lista existe
    if(lista == NULL){
        return -1;
    }
    //Mostra a lista 
    int iterador = 0;
    printf("|->LISTA<-|");
    while(iterador < lista->quantidade){
        printf("|[%i]|\n", lista->elementos[iterador].valor);
        iterador++;
    }
    printf("\n");
    //retorna sucesso
    return 1;
}