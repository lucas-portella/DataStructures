#include <stdio.h>
#include "list.h"

List *list_init (void (*destroy) (void *data) ) {
	List *list;
	
	if ( !(list = (List*) malloc (sizeof (List))) )
		return NULL;

	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;

	return list;
}

void list_destroy ( List *list ) {

	if (!list)
		return;

	ListElem *elem = list->head;

	while (elem) {
		ListElem *aux;
		if (list->destroy)
			list->destroy(elem->data);
		elem->data = NULL;
		aux = elem;
		elem = elem->next;
		free(aux);
		aux = NULL;
	}
	
	free (list);
}

int list_ins_next ( List *list, ListElem *elem, void *data ) {
	ListElem *novo_elem;
	
	if (!list)
		return -1;

	if (!(novo_elem = (ListElem*) malloc (sizeof(ListElem))))
		return -1;

	novo_elem->data = data;

	/* caso elem seja nulo, o inserimos no inicio da lista: */
	if (!elem) {

		/* caso lista vazia: */
		if (list_size(list) == 0) {
			list->tail = novo_elem;
			novo_elem->next = NULL;
		}

		/* caso lista nao vazia: */
		else 
			novo_elem->next = list->head;
		
		
		list->head = novo_elem;

	}

	else {

		if (elem->next == NULL) 
			list->tail = novo_elem;

		novo_elem->next = elem->next;
		elem->next = novo_elem;
	}

	list->size++;
	return 0;
}

int list_rem_next ( List *list, ListElem *elem, void **data ) {
	
	if (!list)
		return -1;

	if (list_size(list) == 0)
		return -1;

	ListElem *aux;
	/* se elem nulo, excluimos o no cabeca */
	if (!elem) {
		aux = list->head;
		list->head = aux->next;
	}
	else {
		aux = elem->next;
		elem->next = elem->next->next;
	}	
		
	/* removendo o no e ajustando ponteiros: */
	*data = aux->data;
	aux->next = NULL;
	aux->data = NULL;
	free(aux);

	list->size--;

	return 0;
}
