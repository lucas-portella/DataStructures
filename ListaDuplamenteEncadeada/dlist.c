#include <stdlib.h>
#include "dlist.h"

DList* dlist_init ( void (*destroy)(void *data) ) {
	DList *dlist;
	
	if (!(dlist = (DList*) malloc (sizeof (DList))))
		return NULL;

	dlist->head = NULL;
	dlist->tail = NULL;
	dlist->size = 0;
	dlist->destroy = destroy;

	return dlist;
}

void dlist_destroy ( DList *dlist ) {
	
	if (!dlist)
		return;

	/* recuperando o primeiro elemento da lista : */
	DListElem *elem = dlist_head (dlist);

	/* Enquanto houver elementos na lista, destroi os nodos */
	while (elem) {
		DListElem *aux = dlist_next(elem);

		if (dlist->destroy) 
			dlist->destroy(elem->data);

		/*	aterramento de ponteiros e liberacao de memoria */
		elem->next = elem->prev = NULL;
		free(elem);
		elem = aux;
	}

	/*	aterramento de ponteiros e liberacao de memoria */
	dlist->head = dlist->tail = NULL;
	dlist->destroy = NULL;
	free(dlist);
	return;
}

int dlist_ins_next ( DList *dlist, DListElem *elem, void *data ) {
	DListElem *new_elem;
	
	if (!dlist)
		return -1;

	if (!(new_elem = (DListElem*) malloc (sizeof(DListElem))))
		return -1;

	new_elem->data = data;
	
	/* caso de insercao no comeco da lista */
	if (!elem) {
		/* caso lista vazia */
		if (dlist_size (dlist) == 0) {
			new_elem->next = NULL;
			dlist->tail = new_elem;
		}	

		else {
			new_elem->next = dlist_head (dlist);
			new_elem->next->prev = new_elem;	
		}

		new_elem->prev = NULL;
		dlist->head = new_elem;
	}
	
	else {
		elem->next = new_elem;
		new_elem->prev = elem;
		new_elem->next = elem->next;
	}

	dlist->size ++;
	return 0;
}

int dlist_ins_prev ( DList *dlist, DListElem *elem, void *data ) {
	DListElem *new_elem;

	if (!dlist)
		return -1;

	if (!(new_elem = (DListElem*) malloc (sizeof(DListElem))))
		return -1;

	new_elem->data = data;

	/* caso de insercao no final da lista */
	if (!elem) {
		/* caso lista vazia */
		if (dlist_size (dlist) == 0) {
			dlist->head = new_elem;
			new_elem->prev = NULL;
		}

		else {
			dlist_tail(dlist)->next = new_elem;
			new_elem->prev = dlist_tail(dlist);
		}

		dlist->tail = new_elem;
		new_elem->next = NULL;

	}

	else {
		
		/* caso de insercao no comeco da lista */
		if (dlist_is_head (dlist,elem)) 
			dlist->head = new_elem;

		elem->prev = new_elem;
		new_elem->next = elem;
		new_elem->prev = elem->prev;
	}

	dlist->size ++;
	return 0;
}

int dlist_remove ( DList *dlist, DListElem *elem, void **data ) {

	if (!dlist || !elem || dlist_size(dlist) == 0) 
		return -1;

	/* recuperacao dos dados contidos no nodo : */
	*data = elem->data;

	if (dlist_head(dlist) == elem)
		dlist->head = elem->next;

	if (dlist_tail(dlist) == elem)
		dlist->tail = elem->prev;
	
	if (elem->prev != NULL) 
		elem->prev->next = elem->next;
	
	if (elem->next != NULL)
		elem->next->prev = elem->prev;

	/* aterramento de ponteiros */
	elem->data = NULL;
	elem->prev = NULL;
	elem->next = NULL;

	free(elem);
	dlist->size--;
	
	return 0;
}
