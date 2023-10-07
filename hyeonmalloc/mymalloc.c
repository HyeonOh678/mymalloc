#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymalloc.h"

#define MEMLENGTH 512
static double memory[MEMLENGTH];


//let's define our linked list structure
struct LinkedList
{
	int isFree; //0 means no and 1 means yes
	size_t  size;
 	struct LinkedList *next;
};

//now we will see how many linked list nodes we can put inside our memory
static const int numNodes = MEMLENGTH/sizeof(struct LinkedList) + 1;
//we will make an array of pointers that will be initialized to 0
//as we traverse through the array
//we will assign each index which is a pointer to an address in memory
//we will want to keep track of the next memory that is not used
static void* nodePtrs[MEMLENGTH/sizeof(struct LinkedList)+1] = {0};



void* mymalloc(size_t size, char* file, int line)
{
	//our first step is to initialize our first chunk 
	static int isInitialized = 0;
	//we will set the copyroot to the next chunk that the first address
	//points to 
	struct LinkedList* copyRoot;
	struct LinkedList* next;
	static struct LinkedList* first;


	if(isInitialized == 0)
	{
		//here we will make our first chunk
		first = (struct LinkedList*) memory; //points to first index
		first -> next = 0;
		first -> isFree = 0; 
		//we will update the size left 
		first -> size = MEMLENGTH - sizeof(struct LinkedList);
	        isInitialized = 1;


	}

}

void myfree(void* ptr, char* file, int line)
{


}

int main()
{
	printf("%d", numNodes);
	

	return 0;
}


