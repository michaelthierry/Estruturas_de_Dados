/**
 * @file main.c
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Lista Dinamica Duplamente Encadeada
 * @version 0.1
 * @date 2023-01-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* lista_criar(){
    //Aloca a lista
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    //Se a foi criada
    if(lista != NULL){
        lista->inicio = NULL;
    }
    //retorna 
    return lista;
}

void lista_destruir(Lista *lista){
    //Se a lista existe
    if(lista != NULL){
        //Cria um ponteiro para a um elemento auxiliar
        Elemento* auxiliar;
        //Precorre a lista
        while(lista->inicio != NULL){
            auxiliar = lista->inicio;
            lista->inicio = lista->inicio->proximo;
            free(auxiliar);
        }
        //Libera a
        free(lista);
    }
}

int lista_tamanho(Lista *lista){
    //Se a lista existir
    if(lista == NULL){
        return -1;
    }
    // Criar auxiliar
    Elemento *auxiliar;
    //auxiliar recebe o inicio da lista
    auxiliar = lista->inicio;
    //cria contador
    int contador = 0;
    //Percorre até o fim da lista
    while(auxiliar != NULL){
        contador++;
        auxiliar = auxiliar->proximo;
    }
    //Retorna o valor
    return contador;
}

int lista_cheia(Lista *lista){
    return 0;
}

int lista_vazia(Lista *lista){
    //Se a lista não existe
    if(lista == NULL){
        return -1;
    }
    //Se o inicio for vazio
    if(lista->inicio == NULL){
        return 1;
    }
    //Caso não
    return 0;
}

int lista_mostrar(Lista *lista){
    if(lista == NULL){
        return 0;
    }
    //Cria ponteiro auxiliar
    Elemento *auxiliar;
    auxiliar = lista->inicio;
    printf("|->Lista\n");
    while(auxiliar != NULL){
        printf("|%i|\n", auxiliar->elemento.valor);
        auxiliar = auxiliar->proximo;
    }
    //status ok
    return 1;
}

int lista_inserir_inicio(Lista *lista, Dado elemento){
    //verifica se existe
    if(lista == NULL){
        return -1;
    }
    //Cria um novo elemento
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    //Verifica se o novo elemento foi alocado
    if(novo == NULL){
        return -1;
    }
    //Novo elemento recebe os dados
    novo->elemento = elemento;
    novo->proximo = lista->inicio;
    novo->anterior = NULL;
    //Se a lista não vazia
    if(lista->inicio != NULL){
        lista->inicio->anterior = novo;
    }
    //Inicio recebe o novo
    lista->inicio = novo;
    //Status de sucesso
    return 1;
}

int lista_inserir_ordenado(Lista *lista, Dado elemento){
    //Verifica se a lista existe
    if(lista == NULL){
        return -1;
    }
    //Cria um novo elemento
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    //Verifica se o novo elemento foi criado
    if(novo == NULL){
        return -1;
    }
    //Novo recebe o elemento
    novo->elemento = elemento;
    //Se a lista estiver vazia
    if(lista_vazia(lista)){
        novo->proximo = NULL;
        novo->anterior = NULL;
        lista->inicio = novo;
        return 1;
    }else{
        //Cria elementos auxiliares
        Elemento *anterior, *atual = lista->inicio;
        while((atual != NULL) && (atual->elemento.valor < elemento.valor)){
            anterior = atual;
            atual = atual->proximo;
        }
        //se o atual for o inicio
        if(atual == lista->inicio){
            novo->anterior = NULL;
            lista->inicio->anterior = novo;
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }else{
            novo->proximo = anterior->proximo;
            novo->anterior = anterior;
            anterior->proximo = novo;
            if(atual != NULL){
                atual->anterior = novo;
            }
        }
    }
    return 1;
}

int lista_inserir_fim(Lista *lista, Dado elemento){
    //Se existe
    if(lista == NULL){
        return -1;
    }
    //Criar um novo elemento
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    //verifica se o novo elemento foi alocado
    if(novo == NULL){
        return 0;
    }
    //Novo elemento recebe os dados
    novo->elemento = elemento;
    novo->proximo = NULL;
    //Se a lista for nula
    if(lista_vazia(lista)){
        lista->inicio = novo;
    }else{
        //Cria um auxiliar
        Elemento *auxiliar = lista->inicio;
        //Percore a lista ate o fim
        while(auxiliar->proximo != NULL){
            auxiliar = auxiliar->proximo;
        }
        //adiciona o elemento no fim
        auxiliar->proximo = novo;
        novo->anterior = auxiliar;
    }
    //Retorna sucesso
    return 1;
}

int lista_remover_inicio(Lista *lista){
    //Verifica se a lista esta vazia
    if(lista == NULL || lista_vazia(lista)){
        return -1;
    }
    //Se a lista estiver vazia
    if(lista_vazia(lista)){
        return 0;
    }
    //Cria um elemento auxiliar
    Elemento *auxiliar = lista->inicio;
    lista->inicio = auxiliar->proximo;
    if(auxiliar->proximo != NULL){
        auxiliar->proximo->anterior = NULL;
    }
    free(auxiliar);
    return 1;

}

int lista_remover_elemento(Lista *lista, Dado elemento){
    //Se existir
    if(lista == NULL || lista_vazia(lista)){
        return -1;
    }
    //Cria um auxiliar
    Elemento *auxiliar = lista->inicio;
    //Percorre a lista até encontra
    while((auxiliar != NULL) && (auxiliar->elemento.valor != elemento.valor)){
        auxiliar = auxiliar->proximo;
    }
    //Se o auxiliar é nulo
    if(auxiliar == NULL){
        return 0;
    }
    //se for o inicio
    if(auxiliar->anterior == NULL){
        lista->inicio = auxiliar->proximo;
    }else{
        auxiliar->anterior->proximo = auxiliar->proximo;
    }
    free(auxiliar);
    return 1;
}

int lista_remover_fim(Lista *lista){
    //Se existe
    if(lista == NULL || lista_vazia(lista)){
        return -1;
    }
    //Declara um auxiliar
    Elemento *auxiliar = lista->inicio;
    //Percore a lista
    while(auxiliar->proximo != NULL){
        auxiliar = auxiliar->proximo;
    }
    //Se for o primeiro
    if(auxiliar->anterior == NULL){
        lista->inicio = auxiliar->proximo;
    }else{
        auxiliar->anterior->proximo = NULL;
    }
    free(auxiliar);
    //Retorna sucesso
    return 1;
}

int lista_buscar_elemento(Lista *lista, int valor, Dado *elemento){
    //se existir
    if(lista == NULL){
        return -1;
    }
    //Cria um auxiliar
    Elemento *auxiliar = lista->inicio;
    //Percorre a lista
    while((auxiliar != NULL) && (auxiliar->elemento.valor != valor)){
        auxiliar = auxiliar->proximo;
    }
    //Se for nulo
    if(auxiliar == NULL){
        return 0;
    }else{
        *elemento = auxiliar->elemento;
        return 1;
    }
}

int lista_buscar_posicao(Lista *lista, int indice, Dado *elemento){
    //Se existe
    if(lista == NULL || indice <= 0){
        return -1;
    }
    //Cria auxiliar
    Elemento *auxiliar = lista->inicio;
    int iterador = 1;
    //Percorre a lista até encontrar a posição
    while((auxiliar != NULL) && (iterador < indice)){
        auxiliar = auxiliar->proximo;
        iterador++;
    }
    //Verifica o auxiliar
    if(auxiliar == NULL){
        return 0;
    }else{
        *elemento = auxiliar->elemento;
        return 1;
    }
}
