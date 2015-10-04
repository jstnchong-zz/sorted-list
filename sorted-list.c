#include "sorted-list.h"
#include <stddef.h>


//DONE
SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df){
	SortedListPtr list = (SortedListPtr)malloc(sizeof(struct SortedList));
	if(cf==NULL && df==NULL){
		return NULL;
	}
	if(list != NULL) //checks if the malloc succeeds
	{
		list->front = (Node*)malloc(sizeof(struct Node));
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
		if(list->front->next->alive ==1 && list->front->next->refs ==1){
			temp = list->front->next;
			list->front->next = list->front->next->next;
			list->df(temp->data);
			free(temp);
		}
		else if(list->front->next->alive == 1 && list->front->next->refs >1){
			list->front->next->refs--;
			list->front->next = list->front->next->next;
		}
	}
	free(list->front);
	free(list);
}
//DONE
int SLInsert(SortedListPtr list, void *newObj){
    if(newObj==NULL || list==NULL){
	return 0;
    }
    Node* temp =(Node*)malloc(sizeof(struct Node)); //NEW NODE TO BE ADDED TO LIST
    temp->data = newObj;
    temp->next = NULL;
    temp->refs = 0;
    temp->alive = 0;
    Node* prev = list->front;	
    Node* ptr = prev->next; //POINTER TO ITERATE THROUGH THE LIST
    while(ptr!=NULL){
        if((list->cf)(ptr->data, newObj) == 0) //ITEM IS ALREADY IN LIST
        {
            (list->df)(temp->data);
            free(temp); 
            return 0;
        }
        else if((list->cf)(ptr->data, newObj) < 0) //NODE SHOULD BE BEFORE PTR
        {
            prev->next = temp;
	    temp->next = ptr;
	    temp->refs = 1;
	    temp->alive = 1;
            return 1;
        }
	else{
		prev = prev->next;
		ptr =  ptr->next;
	}
    }
    prev->next = temp;
    temp->next = ptr;
    temp->refs = 1;
    temp->alive = 1;
}
//DONE
int SLRemove(SortedListPtr list, void *newObj){
    if(list==NULL || newObj==NULL)
    {
        return 0;
    }
    if(list->front->next != NULL){
    	Node* ptr = list->front->next;
    	Node* prev = list->front;
    	while(ptr->next!=NULL){
		if((list->cf)(ptr->data, newObj)==0){
			prev->next = prev->next->next;
			ptr->refs--;
			ptr->alive=0;
			if(ptr->refs==0 && ptr->alive==0){
				(list->df)(ptr->data);
				free(ptr);
				return 1;
			}
			else{
				return 1;
			}
		}
		else if((list->cf)(ptr->data, newObj)>0){
			return 0;
    		}
		else{
			prev=prev->next;
			ptr = ptr->next;
        	}
    	}
    }
    return 0; 
}
//DONE
SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
	SortedListIteratorPtr iter = (SortedListIteratorPtr)malloc(sizeof(struct SortedListIterator));
	if(list==NULL){
		return NULL;
	}
	if(iter != NULL) //checks if malloc succeeds
	{
		iter->current = list->front->next; //initializes current node of iterator to front
        	iter->df  = list->df;
		if(iter->current != NULL)
		{
			list->front->next->refs++;
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
        iter->df(iter->current->data);
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

//DONE
void * SLNextItem(SortedListIteratorPtr iter){
	if(iter==NULL){
		return NULL;
	}

	else if(iter->current==NULL){
		return NULL;
	}

	else if(iter->current->alive==0 && iter->current->refs == 1){
		Node* temp = iter;
		iter = iter->current->next;
		free(temp);
		return iter->current->data;
	}
	else if(iter->current->alive==0 && iter->current->refs >1){
		iter->current->refs--;
		iter->current->next;
		if(iter->current == NULL){
			return NULL;
		}
		else{
			return iter->current->data;
		}
		
	}
	else {
		iter->current = iter->current->next;
		if(iter->current == NULL){
			return NULL;
		}
		else{
			return iter->current->data;
		}
	}
}

//DONE
void * SLGetItem( SortedListIteratorPtr iter ){
	if(iter==NULL){
		return NULL;
	}
	else if(iter->current==NULL){
		return NULL;
	}
	else{
		return iter->current->data;
	}
}






