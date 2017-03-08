#include <stdio.h>
#define SIZE 10

void selectionSort( int dizi[], int n )
{
	int gecici;
	int min;
	int i;
	int j;
	for ( i = 0; i < n-1; i++ )
	{
		min = i;
		for ( j = i; j < n; j++ )
		{
			if ( dizi[j] < dizi[min] )
			{
				min = j;
			}
		}
		gecici = dizi[i];
		dizi[i] = dizi[min];
		dizi[min] = gecici; 
	}
}

int main( void )
{
	int i;
	int dizi[ SIZE ];
	printf("dizinin elemanlarini giriniz\n");
	for ( i = 0; i < SIZE; i++ )
	{
		scanf("%d", &dizi[i]);
	}
	selectionSort(dizi,SIZE);
	printf("sıralı dizi\n");
	for ( i = 0; i< SIZE; i++ )
	{
		printf("%d \t", dizi[i]);
	}
}
