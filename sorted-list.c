#include "sorted-list.h"
#include <stddef.h>



SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df){
	SortedListPtr list = malloc(sizeof(struct SortedList));
	memset(list,0,sizeof(struct SortedList));
	list->cf = cf;
	list->df = df;

	return list;

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
	SortedListIteratorPtr sli = malloc(sizeof(struct SortedListIterator));
	memset(sli, 0, sizeof(struct SortedListIterator));
	return sli;
	
	
	
	
	
}
void SLDestroyIterator(SortedListIteratorPtr iter){
	free(iter);
	
	
	
	
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






