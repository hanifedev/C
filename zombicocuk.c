#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main( void )
{
	pid_t pid;
	if (!pid)
	{
		char *const argv[] = { "date", NULL };
		int ret;
		ret = execv( "/bin/date", argv );
		if ( ret == -1 )
		{
			perror( "execv" );
			exit( EXIT_FAILURE );
		}
		else if( pid == -1 )
		{
			perror( "fork" );
			exit( EXIT_FAILURE );
		}
		printf( "child %d \n", pid );
		sleep( 10 ); 
		return EXIT_SUCCESS;
	}
}
