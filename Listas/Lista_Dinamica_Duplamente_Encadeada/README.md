# Lista Dinamica Duplamente Encadeada
Tipo de lista onde cada elemento possui referencia para o antecessor e sucessor na lista.
Usa um ponteiro especial para o primeiro elemento da lista e uma indicação de final da lista, nos dois sentidos

__Vantagens__:
- Melhor utilização dos recursos de memoria
- Não precisa movimentar os elementos nas operações de inserção e remoção

__Desvantagens__:
- Acesso indireto aos elementos.
- Nescessidade de percorrer a lista para acessar um elemento.

__Quando Utilizar__:
- Não há necessidade de garantir um espaço minimo para a execução do aplicativo
- Inserção / Remoção em lista são operações mais frequentes
- Nescessidade de acessar um elemento antecessor
