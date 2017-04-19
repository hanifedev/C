#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int threadCount;
void* hesapla( void* thread );
void factoriyel( long sayi );

int main( int argc, char* argv [] ) 
{
	long thread;
	pthread_t* threadHandles;
	threadCount = strtol( argv[ 1 ], NULL, 10 );
	threadHandles = ( pthread_t* )malloc( threadCount * sizeof( pthread_t ) ) ;
	for( thread = 0; thread< threadCount; thread++ )
	{
			pthread_create( &threadHandles[ thread ], NULL, hesapla, ( void* ) thread);
	}
	printf( "Hello from the main thread\n" );
	for( thread = 0; thread< threadCount; thread++ )
		pthread_join( threadHandles[ thread ], NULL);
	free( threadHandles );
	return 0;
}

void* hesapla( void* thread)
{
	long my_thread = ( long )thread;
	printf( "hello from %ld thread", my_thread );
	if ( my_thread % 2 == 0)
	{
		factoriyel( 10 );
	}
	else
	{
		factoriyel( 19 );
	}
	return NULL ;
}

void factoriyel( long sayi )
{
	long f = 1;
	for ( long i = 1; i < sayi; i++ )
	{
		f *= i;
	}
	printf( " %ld! = %ld \n", sayi, f );
}
