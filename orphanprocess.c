#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main( void )
{
	pid_t pid;
	pid = fork();
	if( !pid )
	{
		char *const argv[] = { "sleep", "100", NULL };
		int ret;
		ret = execv( "/bin/sleep", argv );
		if( ret == -1 )
		{
			perror( "execv" );
			exit( EXIT_FAILURE );
		}
	}
	else if( pid == -1 )
	{
		perror( "fork" );
		exit( EXIT_FAILURE );
	}
	return EXIT_SUCCESS;
}
