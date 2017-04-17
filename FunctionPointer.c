#include <stdio.h>
#include <stdlib.h>

void printValue( void ( *functionPointer )( int ), int parameter );
void function( int parameter );

int main( void )
{
	void ( *functionPointer )( int ) = function;
	( *functionPointer )( 10 );
	( *functionPointer )( 20 );
	( *functionPointer )( 30 );
	printValue( function, 40 );
	printValue( functionPointer, 50 );
}

void function( int parameter )
{
	printf( "value %d \n", parameter );
}

void printValue( void ( *functionPointer )( int ), int parameter )
{
	( *functionPointer )( parameter );
}
