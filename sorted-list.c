#include "sorted-list.h"
#include <stddef.h>



SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df){
	SortedListPtr list = (SortedListPtr)malloc(sizeof(struct SortedList));
	
	if(list != NULL) //checks if the malloc succeeds
	{
	list->front = NULL;
	list->cf = cf;
	list->df = df;
	list->numItems = 0;

	return list;
	}

	return NULL; //returns NULL if the function does not succeed
}

void SLDestroy(SortedListPtr list){
	
	free(list); //frees the entire list after indiviual nodes are removed
}

int SLInsert(SortedListPtr list, void *newObj){
	
	
	
	
	
	
}
int SLRemove(SortedListPtr list, void *newObj){
	
	
	
	
}

SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
	SortedListIteratorPtr iter = (SortedListIteratorPtr)malloc(sizeof(struct SortedListIterator));
	
	if(iter != NULL) //checks if malloc succeeds
	{
	iter->current = list->front; //initializes current node of iterator to front
		if(iter->current != NULL)
		{
			list->front->refs++;
		}
		return iter;
	}	

	return NULL; //returns NULL if function does not succeed
}

//DONE
void SLDestroyIterator(SortedListIteratorPtr iter){
	if(iter==NULL){
		return;
	}
	else if(iter->current == NULL){
		return;
	}
	else if(iter->current->alive==0 &&  iter->current->refs==1){
		
		free(iter->curr);
		free(iter);
		return;
	}
	else if(iter->curr->alive==0 && iter->curr->refs>1){
		iter->curr->refs--;
		free(iter);
		return;
	}
	else{
		free(iter);
		return;
	}
		
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






