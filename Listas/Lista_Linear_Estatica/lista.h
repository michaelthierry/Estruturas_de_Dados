/**
 * @file lista.h
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Lista Linear Estática
 * @version 0.1
 * @date 2023-01-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//Defindo as diretivas e as macro das lista
#ifndef LISTA_H
#define LISTA_H

/*Define o tamanho máximo da lista*/
#define MAX 10

/*Tipo de dado que a lista guarda*/
typedef struct dado{
    //Campo que guarda um inteiro
    int valor;
}Dado;

/*Estrutura da Lista Linear Estatica*/
typedef struct lista{
    //Campo que guarda a quantidade de elementos da lista
    int quantidade;
    //Campo para os elementos da lista
    Dado elementos[MAX];
}Lista;

/**
 * @brief Aloca memoria para um ponteiro do tipo Lista
 * 
 * @return Lista* o ponteiro será NULL se a lista não for criada
 */
Lista* lista_criar();

/**
 * @brief Desaloca a memoria alocada para a lista
 * 
 * @param lista recebe um ponteiro do tipo lista
 */
void lista_destruir(Lista *lista);

#endif