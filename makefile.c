#include "sorted-list.h"
#include <stddef.h>





SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df){
	
	
	

}
void SLDestroy(SortedListPtr list){
	
	
	
	
	
	
	
	
	
}
int SLInsert(SortedListPtr list, void *newObj){
	
	
	
	
	
	
}
int SLRemove(SortedListPtr list, void *newObj){
	newObj->prev->next = newObj->next;
	newObj->next->prev = newObj->prev;
	
	list->df(newObj->data);
	free(newObj);
	
	
	
	
}
SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
	
	
	
	
	
	
}
void SLDestroyIterator(SortedListIteratorPtr iter){
	
	
	
	
	
}
void * SLNextItem(SortedListIteratorPtr iter){
	if(iter==null){
		return 0;
	}
	return iter->next->data;
	
	
	
}

void * SLGetItem( SortedListIteratorPtr iter ){
	if(iter==null){
		return NULL;
	}
	return iter->current->data;
}






