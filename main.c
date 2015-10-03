/*
 * sorted-list.c
 */

#include	<string.h>
#include	"sorted-list.h"
#include	<stdin.h>


main(int argc, char ** argv){
	char command;
	SortedListPtr LL = SLCreate(cf, df);
	SortedListIteratorPtr iterInd[100];
	
	do{
		printf("Enter a command. Type h for list of commands\n");
		command = getchar();
		switch(command){
			case('i'):printf("Enter an integer you wish to insert as a node.");
			case('r'):
			case('c'):
			case('d'):
			case('g'):
			case('h'): printf("Entering i inserts a integer node into the linked list.\n"
					"Entering r removes a integer node from the linked list.\n"
					"Entering c creates an iterator to traverse the linked list.\n"
					"Entering d destroys an iterator.\n"
					"Entering g gets the value of an iterator's node.\n"); break;	
			case('q'): printf("Program terminated."); break;
			default: "Input is invalid, please try again. Type h for list of commands"





		}
	

	}while(command!='q');
	SLDestroy(LL);
	while(iterInd[counter]!=NULL){
		SLDestroyIterator(iterInde[counter]);
		counter++;
	}			
		
	
	












}
