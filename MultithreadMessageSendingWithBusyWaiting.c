#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZEOFMESSAGE 50
#define NUMBEROFTHREADS 4

char* globalMessages[ NUMBEROFTHREADS ];

void* threadFunction( void* rank );

int main( void )
{
	pthread_t* threadHandles = ( pthread_t* )malloc( NUMBEROFTHREADS * sizeof( pthread_t ) );
	for( long threadIndex = 0; threadIndex < NUMBEROFTHREADS; threadIndex++ )
	{
		pthread_create( ( threadHandles + threadIndex ), NULL, threadFunction, ( void* )threadIndex );
	}
	for( long threadIndex = 0; threadIndex < NUMBEROFTHREADS; threadIndex++ )
	{
		pthread_join( *( threadHandles + threadIndex ), NULL );
	}
	for( int messageIndex = 0; messageIndex < NUMBEROFTHREADS; messageIndex++ )
	{
		free( globalMessages[ messageIndex ] );
	}
}

void* threadFunction( void* rank )
{
	long threadRank = ( long ) rank;
	long destinationThreadRank = ( threadRank + 1 ) % NUMBEROFTHREADS;
	long sourceThreadRank = ( threadRank + NUMBEROFTHREADS -1 ) % NUMBEROFTHREADS;
	char* threadMessage = ( char* )malloc( SIZEOFMESSAGE * sizeof( char ));
	sprintf( threadMessage, "Hello to Thread %ld from Thread %dld.", destinationThreadRank, threadRank );
	globalMessages[ destinationThreadRank ] = threadMessage;
	while( globalMessages[ threadRank ] == NULL );
	if( globalMessages[ threadRank ] != NULL  )
	{
		printf( "thread %ld->%s\n", threadRank, globalMessages[ threadRank ] );
	}
	else
	{
		printf( "thread %ld->No message from thread %ld\n", threadRank, sourceThreadRank );
	}
	return NULL;
}
