#ifndef LIST_H
#define LIST_H
	
#include <stdlib.h>

	typedef struct ListElem_ {

		void *data;

		struct ListElem_ *next;

	} ListElem;

	typedef struct List_ {
		
		int size;

		ListElem *head;

		ListElem *tail;

		void (*destroy) (void *data);

	} List;
	
	/* INTERFACE */

	List *list_init ( void (*destroy) (void *data) );

	void list_destroy ( List *list );

	int list_ins_next ( List *list, ListElem *elem, void *data );

	int list_rem_next ( List *list, ListElem *elem, void **data );

	#define list_size(list) ((list)->size)

	#define list_head(list) ((list)->head)

	#define list_tail(list) ((list)->tail)

	#define list_data(elem) ((elem)->data)

	#define list_next(elem) ((elem)->next)

	#define list_is_head (list, elem) ( (elem) == (list)->head ? 1 : 0 )

	#define list_is_tail (list, elem) ( (elem) == (list)->tail ? 1 : 0 )
	

#endif
