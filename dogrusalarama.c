#include <stdio.h>
#define SIZE 100

size_t dogrusalArama( const int dizi[], int anahtar, size_t size );
void diziyiYaz( int dizi[] );

int main( void )
{
	int a[ SIZE ];
	size_t x;
	int aramaAnahtari;
	size_t konum;
	
	for ( x = 0; x < SIZE; x++ )
	{
		a[ x ] = 2 * x;
	}
	
	diziyiYaz( a );
	puts( "tamsayı arama anahtarı giriniz" );
	scanf( "%d", &aramaAnahtari );

	konum = dogrusalArama( a, aramaAnahtari, SIZE );

	if ( konum != -1 )
	{
		printf( "Bulunan değer %d . indistedir \n", konum );
	}
	else
	{
		puts( "değer bulunamadı!" );
	}
}

void diziyiYaz( int dizi[] )
{
	int x;
	for ( x = 0; x < SIZE; x++ )
	{
		printf( "%d elemanın indisi = %d \n", dizi[ x ], x );
	}
}

size_t dogrusalArama( const int dizi[], int anahtar, size_t size )
{
	size_t i;
	
	for ( i = 0; i < size; i++ )
	{
		if ( dizi[ i ] == anahtar )
		{
			return i;
		}
	}
	return -1;
}
