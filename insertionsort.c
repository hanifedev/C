#include <stdio.h>
#define SIZE 10

void insertionSort( int dizi[], int n )
{
	int i;
	int j;
	int gecici;
	int min;
	for ( i = 1; i < SIZE; i++ )
	{
		gecici = dizi[i];
		j = i;
		while (j > 0 && gecici < dizi[j-1])
		{
			dizi[j] = dizi[j-1];
			j--;
		}
		dizi[j] = gecici;	
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
	insertionSort(dizi,SIZE);
	printf("sıralı dizi\n");
	for ( i = 0; i< SIZE; i++ )
	{
		printf("%d \t", dizi[i]);
	}
}
