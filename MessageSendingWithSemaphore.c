#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZEOFMESSAGE 50
#define NUMBEROFTHREADS 8

sem_t* semaphores;
char* globalMessages[ NUMBEROFTHREADS ];

void* threadFunction( void* rank );

int main( void )
{
	semaphores = ( sem_t* )malloc( NUMBEROFTHREADS * sizeof( sem_t ) );
	for( long semaphoreIndex = 0; semaphoreIndex < NUMBEROFTHREADS; semaphoreIndex++ )
	{
		sem_init( ( semaphores + semaphoreIndex ), 0, 0 );
	}
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
	long sourceThreadRank = ( threadRank + NUMBEROFTHREADS - 1 ) % NUMBEROFTHREADS;
	char* threadMessage = ( char* )malloc( SIZEOFMESSAGE * sizeof( char ) );
	sprintf( threadMessage, "hello to thread %ld from thread %ld", destinationThreadRank, threadRank );
	globalMessages[ destinationThreadRank ] = threadMessage;
	sem_post( &semaphores[ destinationThreadRank ] );
	sem_wait( &semaphores[ threadRank ] );
	if( globalMessages[ threadRank ] != NULL )
	{
		printf( "thread %ld -> %s \n", threadRank, globalMessages[ threadRank ] );
	}
	else
	{
		printf( "thread %ld -> No message from thread %ld \n", threadRank, sourceThreadRank );
	}
	return NULL;
}
