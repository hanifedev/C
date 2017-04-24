#include <stdio.h>
#include <stdlib.h>

void* printVariable( void* pointer );

int main( void )
{
	int variable = 10;
	int *variablePointer = &variable;
	void* voidPointer = variablePointer;
	printf( "value of variable %d\n", *variablePointer );
	int *firstVariablePointer = ( int* ) voidPointer;
	printf( "value of variable from firstVariablePointer %d \n", *firstVariablePointer );
	printVariable( voidPointer );
	printf( "value of variable from firstVariablePointer %d \n", *firstVariablePointer );
}

void* printVariable( void* pointer )
{
	int * intPointer = ( int* ) pointer;
	printf( "value of variable from function %d \n", *intPointer );
	*intPointer = *intPointer + 10;
	return NULL;
}
