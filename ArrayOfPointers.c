#include <stdio.h>
#include <stdlib.h>

void printArray( const int* array, int numberOfElements );
void printAllArrays( const int** arrayOfPointers, int sizeOfArray, int numberOfElements );

int main( void )
{
	const int* arrayOfPointers [ 3 ] = { NULL };
	int firstArray [ 4 ] = { 10, 20, 30, 40 };
	int secondArray [ 4 ] = { 100, 200, 300, 400 };
	int thirdArray [ 4 ] = { 1000, 2000, 3000, 4000 };
	arrayOfPointers[ 0 ] = firstArray;
	arrayOfPointers[ 1 ] = secondArray;
	arrayOfPointers[ 2 ] = thirdArray;
	for ( int counter = 0; counter < 3; counter++ )
	{
		printArray( arrayOfPointers[ counter ], 4 );
	}
	puts( "" );
	printAllArrays( arrayOfPointers, 3, 4 );
	return 0;
}

void printArray( const int* array, int numberOfElements )
{
	for ( int counter = 0; counter < numberOfElements; counter++ )
	{
		printf( "Value: %d \n", *( array + counter ) );
	}
	puts( "" );
}

void printAllArrays( const int** arrayOfPointers, int sizeOfArray, int numberOfElements )
{
	for ( int counter = 0; counter < numberOfElements; counter++ )
	{
		const int* currentArray = *( arrayOfPointers + counter );
		printArray( currentArray, numberOfElements );
	}
}
