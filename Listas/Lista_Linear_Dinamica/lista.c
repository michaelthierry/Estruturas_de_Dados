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

int lista_cheia(Lista *lista){
    //Nunca estará cheia (até a memoria acabar)
    return 0;
}

int lista_vazia(Lista *lista){
    //se existe
    if(lista == NULL){
        return -1;
    }
    //Se esta vazia
    if(lista->inicio == NULL){
        return 1;
    }
    //Caso nao
    return 0;
}

int lista_tamanho(Lista *lista){
    //Se existe
    if(lista == NULL){
        return -1;
    }
    //Elemento auxiliar
    Elemento *auxiliar;
    //Contador
    int contador = 0;
    //Percore a lista
    while(auxiliar != NULL){
        contador++;
        auxiliar = auxiliar->proximo;
    }
    //Retorna a qunatidade;
    return contador;
}

int lista_mostrar(Lista *lista){
    //Se existe
    if(lista == NULL){
        return 0;
    }
    //Cria um auxiliar
    Elemento *auxiliar;
    auxiliar = lista->inicio;
    //Mostra a lista
    printf("|>Lista\n");
    //Percore a lista mostrando os elementos
    while(auxiliar != NULL){
        printf("|%d|\n", auxiliar->elemento.valor);
        auxiliar = auxiliar->proximo;
    }
    //retorna sucesso
    return 1;
}

int lista_inserir_inicio(Lista *lista, Dado elemento){
    //Se existe
    if(lista == NULL){
        return -1;
    }
    //Cria um novo elemento
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    //Verifica se foi alocado
    if(novo == NULL){
        return -1;
    }
    //Insere o elemento
    novo->elemento = elemento;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    //status ok
    return 1;

}

int lista_inserir_ordenado(Lista *lista, Dado elemento){
    //Se existe
    if(lista == NULL){
        return -1;
    }
    //Cria um novo elemento
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    //Verifica se foi alocado
    if(novo == NULL){
        return -1;
    }
    
    novo->elemento = elemento;
    //se lista vazia
    if(lista_vazia(lista)){
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }else{
        //Cria auxiliares
        Elemento *anterior, *atual;
        atual = lista->inicio;
        //Perco a lista procurado o local correto para inserir
        while((atual != NULL) && (atual->elemento.valor < elemento.valor)){
            anterior = atual;
            atual = atual->proximo;
        }
        //Se o atual for igual ao inicio
        if(atual == lista->inicio){
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }else{
            novo->proximo = anterior->proximo;
            anterior->proximo = novo;
        }
        //Status de sucesso
        return 1;
    }
}

int lista_inserir_fim(Lista *lista, Dado elemento){
    //Se existe
    if(lista == NULL){
        return -1;
    }
    //Cria um novo elemento
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    //Se foi alocado
    if(novo == NULL){
        return -1;
    }
    //Faz o elemento receber os dados
    novo->elemento = elemento;
    novo->proximo = NULL;
    //Se o inicio for nulo
    if(lista->inicio == NULL){
        lista->inicio = novo;
    }else{
        //Cria um auxiliar
        Elemento *auxiliar;
        auxiliar = lista->inicio;
        //Percore a lista até o fim 
        while(auxiliar->proximo != NULL){
            auxiliar = auxiliar->proximo;
        }
        //Elemento insere no fim
        auxiliar->proximo = novo;
    }
    //Status ok
    return 1;
}

int lista_remover_inicio(Lista *lista){
    //Se existe
    if(lista == NULL){
        return -1;
    }
    //Verifica se esta vazia
    if(lista_vazia(lista)){
        return -1;
    }
    //Cria um elemento 
    Elemento *auxiliar;
    //removendo o elemento do inicio
    auxiliar = lista->inicio;
    lista->inicio = auxiliar->proximo;
    //Libera o auxiliar
    free(auxiliar);
    //Status ok
    return 1;
}

int lista_remover_elemento(Lista *lista, Dado elemento){
    //Se a lista existe
    if(lista == NULL){
        return -1;
    }
    //Verifica se esta vazia
    if(lista_vazia(lista)){
        return -1;
    }
    //Cria auxiliares
    Elemento *anterior, *atual;
    atual = lista->inicio;
    //Encontra o elemento
    while((atual != NULL) && (atual->elemento.valor != elemento.valor)){
        anterior = atual;
        atual = atual->proximo;
    }
    //verifica se esta nulo
    if(atual == NULL){
        return 0;
    }
    //Remove o elemento
    Elemento *remover;
    remover = atual;
    anterior->proximo = remover->proximo;
    free(remover);
    //Status ok
    return 1;
}

int lista_remover_fim(Lista *lista){
    //Se a lista existe
    if(lista == NULL){
        return -1;
    }
    //Se a lista esta vazia
    if(lista_vazia(lista)){
        return -1;
    }
    //Cria auxiliares
    Elemento *anterior, *atual;
    atual = lista->inicio;
    //Percorre a lista
    while(atual->proximo != NULL){
        anterior = atual;
        atual = atual->proximo;
    }
    //Se estiver removendo o primeiro
    if(atual == lista->inicio){
        lista->inicio = atual->proximo;
    }else{
        anterior->proximo = atual->proximo;
    }
    //Libera o atual
    free(atual);
    //Status ok
    return 1;
}

int lista_buscar_posicao(Lista *lista, int posicao, Dado *elemento){
    //Se a lista existir
    if(lista == NULL){
        return -1;
    }
    //Se a lista não estiver vazia
    if(lista_vazia(lista) || posicao <= 0){
        return 0;
    }
    //Criar auxiliar
    Elemento *auxiliar;
    int indice = 1;
    auxiliar = lista->inicio;
    //faz a busca
    while((auxiliar != NULL) && (indice < posicao)){
        auxiliar = auxiliar->proximo;
        indice++;
    }
    //Se não encontrou
    if(auxiliar == NULL){
        return 0;
    }
    //Se sim 
    *elemento = auxiliar->elemento;
    //Status
    return 1;
}

int lista_buscar_elemento(Lista *lista, int valor, Dado *elemento){
    //se existir
    if(lista == NULL){
        return -1;
    }
    //Se nao estiver vazia
    if(lista_vazia(lista)){
        return 0;
    }
    //Criando um ponteiro
    Elemento *auxiliar = lista->inicio;
    //Procura pelo elemento
    while((auxiliar != NULL) && (auxiliar->elemento.valor != valor)){
        auxiliar = auxiliar->proximo;
    }
    //Confere se encontrou
    if(auxiliar == NULL){
        return 0;
    }
    *elemento = auxiliar->elemento;
    //Status ok
    return 1;
}
