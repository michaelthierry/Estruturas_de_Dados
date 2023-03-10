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
    printf("|>LISTA\n");
    while(iterador < lista->quantidade){
        printf("[%i]\n", lista->elementos[iterador].valor);
        iterador++;
    }
    printf("\n");
    //retorna sucesso
    return 1;
}

int lista_inserir_inicio(Lista *lista, Dado elemento){
    //verifica se esta cheia
    if(lista_cheia(lista)){
        return -1;
    }
    //Declara um indice
    int indice; 
    //move todos os elemento uma casa para frente
    for(indice = lista->quantidade - 1; indice >= 0; indice--){
        lista->elementos[indice + 1] = lista->elementos[indice];
    }
    //
    lista->elementos[0] = elemento;
    lista->quantidade++;
    //retorna sucesso 
    return 1;
}

int lista_inserir_ordenado(Lista *lista, Dado elemento){
    //verifica se esta cheia
    if(lista_cheia(lista)){
        return -1;
    }
    //Percore a lista procurando a posi????o certa 
    int posicao, indice = 0;
    while((indice < lista->quantidade) && (lista->elementos[indice].valor < elemento.valor)){
        indice++;
    }
    //Move todos da posi????o encontrada para a direita
    for(posicao = lista->quantidade - 1; posicao >= indice; posicao--){
        lista->elementos[posicao + 1] = lista->elementos[posicao];
    }
    //Insere o elemento na posi????o e incrementa o quantidade
    lista->elementos[indice] = elemento;
    lista->quantidade++;
    //retorna status de sucesso
    return 1;
}

int lista_inserir_fim(Lista *lista, Dado elemento){
    //Verifica se a lista esta cheia
    if(lista_cheia(lista)){
        return -1;
    }
    //Adiciona o elemento na ultima posicao
    lista->elementos[lista->quantidade] = elemento;
    //incrementa a quantidade
    lista->quantidade++;
    //retorna sucesso
    return 1;
}

int lista_remover_inicio(Lista *lista){
    //verifica se esta vazia
    if(lista_vazia(lista)){
        return -1;
    }
    //Declarando indice
    int indice;
    //Move todos um posi????o para esquerda
    for(indice = 0; indice < lista->quantidade - 1; indice++){
        lista->elementos[indice] = lista->elementos[indice + 1];
    }
    //decrementa qunatidade
    lista->quantidade--;
    //retorna sucesso
    return 1;
}

int lista_remover_elemento(Lista *lista, Dado elemento){
    //Verifica se a lista esta vazia
    if(lista_vazia(lista)){
        return -1;
    }
    int posicao, indice = 0;
    //Percorre a lista procurando o elemento
    while((indice < lista->quantidade) && (lista->elementos[indice].valor != elemento.valor)){
        indice++;
    }
    //Verifica se encontrou
    if(indice == lista->quantidade){
        return -1;
    }
    //Move todos a direita do indice uma posi????o para esquerda
    for(posicao = indice; posicao < lista->quantidade-1; posicao++){
        lista->elementos[posicao] = lista->elementos[posicao + 1];
    }
    //Decrementa a quantidade
    lista->quantidade--;
    //Retorna sucesso
    return 1;
}

int lista_remover_fim(Lista *lista){
    //Verifica se esta vazia
    if(lista_vazia(lista)){
        return -1;
    }
    //Apenas decrementa a quantidade
    lista->quantidade--;
    return 1;
}

int lista_buscar_posicao(Lista *lista, int posicao, Dado *elemento){
    //Verifica se a lista existe
    if(lista == NULL){
        return -1;
    }
    //verifica se a busca ?? possivel
    if(posicao <= 0 || posicao > lista->quantidade){
        return -1;
    }
    //Elemento rece o ende??o da posi????o
    *elemento = lista->elementos[posicao - 1];
    //retorna sucesso
    return 1;
}

int lista_buscar_elemento(Lista *lista, int valor, Dado *elemento){
    //Verifica se a lista existe
    if(lista == NULL){
        return -1;
    }
    //Tenta encontrar o elemento
    int indice = 0;
    while((indice < lista->quantidade) && (lista->elementos[indice].valor != valor)){
        indice++;
    }
    //Verifica se encontrou
    if(indice == lista->quantidade){
        return -1;
    }
    //se encontrou
    *elemento = lista->elementos[indice];
    //retorna sucesso
    return 1;
}
