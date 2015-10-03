/*
 * sorted-list.c
 */

#include	<string.h>
#include	"sorted-list.h"
#include	<stdin.h>
SortedListIteratorPtr iterInd[100];


main(int argc, char ** argv){
	char command;
	SortedListPtr LL = SLCreate(cf, df);
	int *data = malloc(sizeof(int));
	int arrayEnd=0;
	do{
		printf("Enter a command. Type h for list of commands\n");
		command = (char) getchar();
		switch(command){
			case('i'):printf("Enter an integer you wish to insert as a node.\n");
					(*data) = getchar();
					SLInsert(LL, data);
					break;

			case('r'):printf("Enter an integer you wish to remove from the list.\n");
					(*data) = getchar();
					SLRemove(LL, data);
					break;

			case('c'):if(arrayEnd>=100){
					printf("There can only be a maximum of 100 iterators. Please delete one and try again.\n");
				  }
					iterInd[arrayEnd] = SLCreateIterator(LL);
					arrayEnd++;
					printf("The iterator is created.\n");
					break;

			case('d'):printf("Enter the iterator's index number.\n"){
					(*data) = getchar();
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
					(*data) = getchar();
					if((*data)>=arrayEnd){
						printf("The iterator at index %d does not exist.\n", (*data));
						break;
					}
					data = (int *) SLGetItem(iterInd[(*data)]);
					printf("The value is: %d\n", (*data));
					break;

			case('n'):printf("Enter the iterator's index number.");
					(*data) = getchar();
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
					"Entering g gets the value of an iterator's node.\n");
					"Entering n gets moves an iterator to the next node, then returns the value of that next node.\n");break;
	
			case('q'): printf("Program terminated."); break;

			default: "Input is invalid, please try again. Type h for list of commands"





		}
	

	}while(command!='q');
	free(data);
	SLDestroy(LL);
	while(iterInd[counter]!=NULL){
		SLDestroyIterator(iterInde[counter]);
		counter++;
	}
}
