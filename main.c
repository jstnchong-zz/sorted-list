/*
 * sorted-list.c
 */

#include 	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"sorted-list.h"

int CompareInt( void * a, void * b)
{	//evaluates it for the second parameter
	//if b is greater return 1 etc.
    int* i = (int*) a;
    int* j = (int*) b;
    if((*i)>(*j)){
        return -1;
    }
    else if((*i)<(*j)){
        return 1;
    }
    else{
        return 0;
    }
}

void DestructInt( void * a)
{
    int* i =(int*) a;
    free(i);
}




int main(){
    int *num = (int*) malloc(sizeof(int)); //interger object to be added to list
    int* obj; //interger object that is returned after being sorted
    obj = malloc(sizeof(int));
    int count; //count is a flag that indicates whether a a integer is inputted by user
    SortedListPtr list = SLCreate(CompareInt, DestructInt); //sorted list object
    SortedListIteratorPtr iterator;
    printf("Enter value here: \n");
    count = scanf("%d",num);
    if (count != 1) {
        printf("\nThis is the sorted-list:\n");
        printf("The list is empty\n");
        SLDestroy(list);
        return 0;
    }
    SLInsert(list, num);

    while(count==1) {
        SLInsert(list, num);
        num++;//careful
        num = (int*) malloc(sizeof(int));
        printf("Enter value here: \n");
        count = scanf("%d",num);
    }
    
    int* r1 = (int*)malloc(sizeof(int));
    *r1 = 6;
    SLRemove(list,(void*)r1);
    int* r2 = (int*)malloc(sizeof(int));
    *r2 = 7;
    SLRemove(list,(void*)r2);
    int* r3 = (int*)malloc(sizeof(int));
    *r3 = 8;
    SLRemove(list,(void*)r3);
    
    
    iterator = SLCreateIterator(list);
	obj = SLGetItem(iterator);
	if(list->ls == 0){
        printf("\nThis is the sorted-list:\n");
		printf("The list is empty\n");
        SLDestroy(list);
        return 0;
	}
	else{
        printf("\nThis is the sorted-list:\n");
		printf("%d\n", *obj);
		while(1) {
			obj = SLNextItem(iterator);
			if(obj == 0) {
				break;
			}
			printf("%d\n",*obj);
		}
	}

    free(r1);
    free(r2);
    free(r3);
    
    SLDestroyIterator(iterator);
    SLDestroy(list);

    return 0;
}






/*
 * sorted-list.c
 

#include	<string.h>
#include "sorted-list.h"

SortedListIteratorPtr iterInd[100];

int CompareInt( void * a, void * b){
	int* i = (int*) a;
	int* j = (int*) b;
	if(i<j){
		return -1;
	}
	else if(i>j){
		return 1;
	}
	else{
		return 0;
	}


}
int DestructInt( void * a){
	int* i =(int*) a;
	free(i);
}




void shiftLeft(int index, int end)
{
    int prev;
    int ptr;
    
    if(iterInd[0] == NULL){
        return;
    }
    
    prev = index;
    ptr = index+1;
    
    while(ptr<end)
    {
        iterInd[prev] = iterInd[ptr];
        prev = ptr;
        ptr++;
    }
    
    free(iterInd[end]);
}




main(int argc, char ** argv){
	int (*cf)(void *, void *);
	int (*df)(void *);
	cf = &CompareInt;
	df = &DestructInt;
	char command;
	SortedListPtr LL = SLCreate(cf, df);
	int *data = malloc(sizeof(int));
	int arrayEnd=0;
	int counter =0;
	do{
		printf("Enter a command. Type h for list of commands\n");
       		scanf("%c\n", &command);//(char) getchar();
		switch(command){
				case('i'):printf("Enter an integer you wish to insert as a node.\n");
                		scanf("%d\n", data);//(*data) = getchar();
					SLInsert(LL, data);
                		printf("The value: %d was inserted successfully", (*data));
					break;

			case('r'):printf("Enter an integer you wish to remove from the list.\n");
					scanf("%d\n", data);//(*data) = getchar();
					SLRemove(LL, data);
					break;

			case('c'):if(arrayEnd>=100){
					printf("There can only be a maximum of 100 iterators. Please delete one and try again.\n");
					break;
				  }
					iterInd[arrayEnd] = SLCreateIterator(LL);
					arrayEnd++;
					printf("The iterator is created.\n");
					break;

			case('d'):printf("Enter the iterator's index number.\n");
					scanf("%d\n", data); //(*data) = getchar();
					if((*data)>=arrayEnd){
						printf("The iterator at index %d does not exist.\n", (*data));
						break;
					}
					SLDestroyIterator(iterInd[(*data)]);
					arrayEnd--;
					shiftLeft((*data), arrayEnd);
					printf("The iterator is removed. Note that the indices of all iterators after the inputted index were decreased by 1.\n");
					break;

			case('g'):printf("Enter the iterator's index number.");
					scanf("%d\n", data); //(*data) = getchar();
					if((*data)>=arrayEnd){
						printf("The iterator at index %d does not exist.\n", (*data));
						break;
					}
					data = (int *) SLGetItem(iterInd[(*data)]);
					printf("The value is: %d\n", (*data));
					break;

			case('n'):printf("Enter the iterator's index number.");
					scanf("%d\n", data); //(*data) = getchar();
					if((*data)>=arrayEnd){
						printf("The iterator at index %d does not exist.\n", (*data));
						break;
					}
					data= (int *)SLNextItem(iterInd[(*data)]);
					printf("The value of the next node is: %d\n", (*data));
					break;

			case('h'): printf("Entering i inserts a integer node into the linked list.\n"
					"Entering r removes a integer node from the linked list.\n"
					"Entering c creates an iterator to traverse the linked list.\n"
					"Entering d destroys an iterator.\n"
					"Entering g gets the value of an iterator's node.\n"
					"Entering n gets moves an iterator to the next node, then returns the value of that next node.\n");
                    			break;
	
			case('q'): printf("Program terminated."); break;

			default: printf("Input is invalid, please try again.\n");





		}
	

	}while(command!='q');
	free(data);
	SLDestroy(LL);
	while(iterInd[counter]!=NULL){
		SLDestroyIterator(iterInd[counter]);
		counter++;
	}
}
*/

