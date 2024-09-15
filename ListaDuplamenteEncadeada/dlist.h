#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h> 

/*
	Implementação baseada no apresentado em 
	'Dominando Algoritmos com C', de 
	Kyle Loudon.

	@author Lucas Silveira Portella.
*/

/* * * * * * * * * * * * * * *
	
	Estruturação da Lista

 * * * * * * * * * * * * * */

typedef struct DListElem_ {

	void *data;

	struct DListElem_ *prev;

	struct DListElem_ *next;

} DListElem;

typedef struct DList_ {
	
	int size;

	DListElem *head;
	
	DListElem *tail;

	void (*destroy) (void *data);

} DList;

/* * * * * * * * * * * * * * *
	DList * dlist_init: Inicia a lista duplamente encadeada.

	Valor de Retorno: NULL, caso nao seja possivel alocar
	memoria para a lista, ou o ponteiro para a estrutura de
	dados.

	Parâmetros: Deve-se passar o ponteiro para uma funcao
	de liberacao de alocacao de memoria do tipo de dado
	abstrado guardado na lista, ou entao NULL caso os dados
	da lista sejam alocados estaticamente e nao necessitem
	de liberacao de memoria.

 * * * * * * * * * * * * * */

DList *dlist_init ( void (*destroy) (void *data) );


/* * * * * * * * * * * * * * *
	DList dlist_destroy: Destroi a lista duplamente encadeada.

	Valor de retorno: Sem retorno.

	Parâmetros: Ponteiro para a lista.

	Libera a memoria dos tipos de dados abstratos guardados
	na lista, caso tenha sido passado uma funcao responsavel
	por isso na inicializacao da lista.

 * * * * * * * * * * * * * */
void dlist_destroy ( DList *dlist );


/* * * * * * * * * * * * * * *
	int dlist_ins_next: Insere na lista um dado uma posicao
	DEPOIS de certo elemento especificado.

	Valor de retorno: 0 em caso de sucesso e -1 caso contrario.

	Parâmetros: 
					DList *list: Ponteiro para a lista

					DListElem *elem: Ponteiro para o elemento o qual 
					sera inserido o dado logo apos. Caso elem = NULL,
					será inserido no inicio da lista.

					void *data: Ponteiro para o dado que sera guardado
					na lista.

 * * * * * * * * * * * * * */
int dlist_ins_next ( DList *dlist, DListElem *elem, void *data );

/* * * * * * * * * * * * * * *
	int dlist_ins_prev: Insere na lista um dado uma posicao
	ANTES de certo	elemento especificado.

	Valor de retorno: 0 em caso de sucesso e -1 caso contrario.

	Parâmetros: 
					DList *list: Ponteiro para a lista

					DListElem *elem: Ponteiro para o elemento o qual 
					o dado sera inserido logo antes. Caso elem = NULL,
					o elemento será inserido no final da lista.

					void *data: Ponteiro para o dado que sera guardado
					na lista.

 * * * * * * * * * * * * * */
int dlist_ins_prev ( DList *dlist, DListElem *elem, void *data );

/* * * * * * * * * * * * * * *
	int dlist_remove: remove da lista duplamente encadeada um
	elemento especificado.

	Valor de retorno: 0 em caso de sucesso e -1 caso contrario.

	Parâmetros: 
					DList *list: Ponteiro para a lista

					DListElem *elem: Ponteiro para o elemento que sera
					excluido da lista.

					void **data: Endereco de um Ponteiro para o dado que 
					sera recuperado da lista. É dever do usuário tratar
					da liberacao de memoria do dado.

 * * * * * * * * * * * * * */
int dlist_remove ( DList *dlist, DListElem *elem, void **data );

/* * * * * * * * * * * * * * *
	dlist_head: Macro que retorna a head da lista 		
 * * * * * * * * * * * * * * */
#define dlist_head(dlist) ((dlist)->head)

/* * * * * * * * * * * * * * *
	dlist_tail: Macro que retorna a tail da lista
 * * * * * * * * * * * * * * */
#define dlist_tail(dlist) ((dlist)->tail)

/* * * * * * * * * * * * * * *
	dlist_size: Macro que retorna o tamanho da lista
					(numero de elementos).
 * * * * * * * * * * * * * * */
#define dlist_size(dlist) ((dlist)->size)

/* * * * * * * * * * * * * * *
	dlist_is_head: Macro que retorna 1 caso element seja 
					o elemento head da lista e 0 caso contrário.
 * * * * * * * * * * * * * * */
#define dlist_is_head(dlist,element) ((dlist)->head == element ? 1 : 0)

/* * * * * * * * * * * * * * *
	dlist_is_tail: Macro que retorna 1 caso element seja 
						o elemento tail da lista e 0 caso contrário.
 * * * * * * * * * * * * * * */
#define dlist_is_tail(dlist,element) ((dlist)->tail == element ? 1 : 0)

/* * * * * * * * * * * * * * *
	dlist_next: Macro que retorna a o elemento posterior a 'element'
					na lista.
 * * * * * * * * * * * * * * */
#define dlist_next(element) ((element)->next)

/* * * * * * * * * * * * * * *
	dlist_tail: Macro que retorna a o elemento anterior a 'element'
					na lista.
 * * * * * * * * * * * * * * */
#define dlist_prev(element) ((element)->prev)

/* * * * * * * * * * * * * * *
	dlist_tail: Macro que retorna a os dados constidos em 'element'.
 * * * * * * * * * * * * * * */
#define dlist_data(element) ((element)->data)

#endif
