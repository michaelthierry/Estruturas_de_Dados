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

//CRIANDO E DESTRUIDO A LISTA

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

//OBTENDO INFORMAÇÃO DA LISTA
/**
 * @brief Informa se a lista passada está cheia
 * 
 * @param lista um ponteiro do tipo lista
 * @return int -1 se a lista não existir  1 se a lista estiver cheia 0 caso não
 */
int lista_cheia(Lista *lista);

/**
 * @brief Informa se a lista esta vazia
 * 
 * @param lista um ponteiro do tipo lista
 * @return int -1 se a lista não existir 1 se estiver vazia e 0 se não
 */
int lista_vazia(Lista *lista);

/**
 * @brief Informa o tamanho da lista 
 * 
 * @param lista um ponterio do tipo lista
 * @return int -1 se a lista não existir ou o tamanho da lista se existir
 */
int lista_tamanho(Lista *lista);

/**
 * @brief Informa os elementos que constitui a lista
 * 
 * @param lista 
 * @return int 
 */
int lista_mostrar(Lista *lista);

//ADICIONANDO ELEMENTO NA LISTA
/**
 * @brief Adiciona um elemento no inicio da lista
 * 
 * @param lista um ponteiro do tipo lista
 * @param elemento uma informação do tipo Dado
 * @return int -1 para erro e 1 para sucesso
 */
int lista_inserir_inicio(Lista *lista, Dado elemento);

/**
 * @brief Adiciona um elemento na lista de forma ordenada
 * 
 * @param lista um ponteiro do tipo lista
 * @param elemento uma informaçao do tipo Dado
 * @return int -1 para erro e 1 para sucesso
 */
int lista_inserir_ordenado(Lista *lista, Dado elemento);

/**
 * @brief Insere um elemento no final da lista
 * 
 * @param lista um ponteiro do tipo lista
 * @param elemento uma informação do tipo Dado
 * @return int -1 para erro 1 para sucesso
 */
int lista_inserir_fim(Lista *lista, Dado elemento);

//REMOVENDO ELEMENTOS DA LISTA
/**
 * @brief Remove um elemento do inicio da lista
 * 
 * @param lista um ponteiro do tipo lista
 * @return int -1 para erro e 1 para sucesso
 */
int lista_remover_inicio(Lista *lista);

/**
 * @brief Remove o elemento da lista se encontrado
 * 
 * @param lista um ponteiro do tipo lista
 * @param elemento elemento que se deseja remover
 * @return int -1 para erro 1 para sucesso
 */
int lista_remover_elemento(Lista *lista, Dado elemento);

/**
 * @brief Remove um elemento do fim da lista
 * 
 * @param lista um ponteiro do tipo lista
 * @return int -1 para erro e 1 para sucesso
 */
int lista_remover_fim(Lista *lista);

//BUSCA NA LISTA
/**
 * @brief Busca o elemento que está na posição passada
 * 
 * @param lista um ponteiro do tipo lista
 * @param posicao posição da lista onde esta o elemento
 * @param elemento ponteiro para o elemento
 * @return int -1  para erro 1 para sucesso
 */
int lista_buscar_posicao(Lista *lista, int posicao, Dado *elemento);

/**
 * @brief Procura o elemento passado na lista 
 * 
 * @param lista um ponteiro do tipo lista
 * @param elemento um ponteiro do tipo Dado
 * @return int -1 para erro 1 para sucesso
 */
int lista_buscar_elemento(Lista *lista, int valor, Dado *elemento);

#endif