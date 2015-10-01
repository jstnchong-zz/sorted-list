#include "sorted-list.h"
#include <stddef.h>


//DONE
SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df){
	SortedListPtr list = (SortedListPtr)malloc(sizeof(struct SortedList));
	
	if(list != NULL) //checks if the malloc succeeds
	{
		list->front = (Node *) malloc(sizeof(struct Node));
		list->cf = cf;
		list->df = df;
		list->front->refs = 1;
		list->front->alive = -1;

		return list;
	}

	return NULL; //returns NULL if the function does not succeed
}
//DONE
void SLDestroy(SortedListPtr list){
	Node * temp;

	while(list->front->next!=NULL){
		if(list->front->next->alive ==1 && list->front->next->ptrs ==1){
			temp = list->front->next;
			list->front->next = list->front->next->next;
			list->df(temp->data);
			free(temp);
		}
		else if(list->front->next->alive == 1 && list->front->next->ptrs >1){
			list->front->next->refs--;
			list->front->next = list->front->next->next;
		}
	}
	free(list->front);
	free(list);
	
	
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
		list->df(iter->current->data);
		free(iter->current);
		free(iter);
		return;
	}
	else{
		iter->current->refs--;
		free(iter);
		return;
	}
		
}
//Might Need Adjustment
void * SLNextItem(SortedListIteratorPtr iter){
	if(iter==null){
		return NULL;
	}
	else if(iter->current==null){
		return null;
	}
	else if(iter->current->alive==0 && iter->current->refs == 1){
		Node* temp = iter;
		iter = iter->current->next;
		free(temp);
		return iter;
	}
	else if(iter->current->alive==0 && iter->current0->refs >1){
		iter->current->refs--;
		iter->current->next;
		return iter;
	}
	else {
		iter->current = iter->current->next;
		return iter;
	}
	
	
	
}
//DONE
void * SLGetItem( SortedListIteratorPtr iter ){
	if(iter==null){
		return NULL;
	}
	else if(iter->current==null){
		return NULL;
	}
	else{
		return iter->current->data;
	}
}






