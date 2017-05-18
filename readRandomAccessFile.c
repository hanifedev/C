#include <stdio.h>
struct clientData{
	unsigned int acctNum;
	char lastName[ 15 ];
	char firstName[ 10 ];
	double balance;
};

int main( void )
{
	unsigned int i;
	struct clientData client = { 0, "", "", 0.0 };
	FILE *cfPtr;
	int result;
	if( ( cfPtr = fopen( "deneme.dat", "rb" ) ) == NULL )
	{
		puts( "file could not be opened" );
	}
	else
	{
		printf( "%-6s%-16s%-11s%10s\n", "Acct", "LastName", "FirstName", "balance" );
		while( !feof( cfPtr ) )
		{
			result = fread( &client, sizeof( struct clientData ), 1, cfPtr );
			if( result != 0 && client.acctNum != 0 )
			{
				printf( "%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance );
			}
		}
	fclose( cfPtr );
	}
}
