#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int threadCount;
void* hello( void* rank );

int main( int argc, char* argv [] ) 
{
	long thread;
	pthread_t* threadHandles;
	threadCount = strtol( argv[ 1 ], NULL, 10 );
	threadHandles = ( pthread_t* )malloc( threadCount * sizeof( pthread_t ) ) ;
	for( thread = 0; thread< threadCount; thread++ )
		pthread_create( &threadHandles[ thread ], NULL, hello, ( void* ) thread );
	printf( "Hello from the main thread\n" );
	for( thread = 0; thread< threadCount; thread++ )
		pthread_join( threadHandles[ thread], NULL);
	free( threadHandles );
	return 0;
}

void* hello( void* rank )
{
	long my_rank = ( long ) rank;
	printf( "Hello from thread %d.\n", my_rank ) ;
	return NULL ;
}
