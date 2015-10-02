#include "sorted-list.h"

#include <stddef.h>





//DONE

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df){

	SortedListPtr list = (SortedListPtr)malloc(sizeof(struct SortedList));

	

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

    Node* temp =(Node*)malloc(sizeof(struct Node)); //NEW NODE TO BE ADDED TO LIST

    temp->data = newObj;

    temp->next = NULL;

    temp->refs = 0;

    temp->alive = 0;

    Node* prev = list->front;	

    Node* ptr = prev->next; //POINTER TO ITERATE THROUGH THE LIST

    

    while(ptr!=NULL){


	//CHECKS FRONT OF LIST

        if((list->cf)(ptr->data, newObj) == 0) //ITEM IS ALREADY IN LIST

        {

            (list->df)(temp->data); //Are we supposed to free this?

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



int SLRemove(SortedListPtr list, void *newObj){

    if(list->front->next == NULL) //LIST IS EMPTY NOTHING TO REMOVE

    {

        return 0;

    }

    

    if(list->front->next->next == NULL) //LIST ONLY HAS ONE ITEM

    {

        if((list->cf)(list->front->next->data, newObj) == 0))

        {

            list->front->next->alive = 0;

            list->front->next->refs--;

            list->front->next = NULL;

            return 1;

            

        }

        else //ITEM IS NOT IN LIST

            return 0;

    }

    

    else

        Node* temp = list->front->next;

        

        //CHECKS FRONT OF LIST

        if((list->cf)(temp->data, newObj) == 0) //ITEM FOUND!

        {

            temp->alive = 0;

            temp->refs--;

            list->front->next = temp->next;

            //NOT SURE IF I SHOULD FREE TEMP

            return 1;

        }

    

        else

            Node* prev= temp; //PREVIOUS NODE USED TO REMOVE NODE

            temp = temp->next;

    

            while(temp->next!=NULL) 

            {

                if((list->cf)(temp->data, newObj) == 0) //ITEM FOUND!

                {

                    temp->alive = 0;

                    temp->refs--;

                    prev->next = temp->next;

                    //NOT SURE IF I SHOULD FREE TEMP

                    return 1;

                }

                else

                    prev = temp;

                    temp= temp->next;

            }

    

    if((list->cf)(temp->data, newObj) == 0) //ITEM FOUND!

    {

        temp->alive = 0;

        temp->refs--;

        prev->next = temp->next;

        //NOT SURE IF I SHOULD FREE TEMP

        return 1;

    }

    

    //free temp and prev?

    return 0; //WE HAVE REACHED THE END OF OUR LIST AND ITEM WAS NOT FOUND

	

}



SortedListIteratorPtr SLCreateIterator(SortedListPtr list){

	SortedListIteratorPtr iter = (SortedListIteratorPtr)malloc(sizeof(struct SortedListIterator));

	

	if(iter != NULL) //checks if malloc succeeds

	{

	iter->current = list->front->next; //initializes current node of iterator to front

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











