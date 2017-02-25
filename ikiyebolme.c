// fonksiyon=(x^10)-1
#include <stdio.h>
#include <math.h>

void hesap( int s, float xa, float xu )
{
	int i;
	float fa;
	float fu;
	float xr;
	float fr;
	float carpim;
	float xreski;
	float ea;
	for( i=0; i<s; i++ )
	{
		fa = pow(xa,10)-1;
		fu = pow(xu,10)-1;
		xr = (xa+xu)/2;
		fr = pow(xr,10)-1;
		carpim = fa*fr;	
		if ( i != 0 )
		{
			ea = ((xreski-xr)/xr)*100;
			if ( ea < 0 )
			{
				ea*=-1;
			}
		}
		if( carpim < 0 )
		{
			xu=xr;
		}
		else if( carpim > 0 )
		{
			xa=xr;
		}
		xreski=xr;
		printf("%5d \t %11.4f \t %.4f \t %.4f \t %.4f \t %.4f \t %.4f \t %5.4f \n", i+1, xa, xu, xr, fa, fu, fr, ea);
	}
}

int main( void )
{
	float alt;
	float us;
	int iterasyon;
	printf("iterasyon sayısı giriniz");
	scanf("%d", &iterasyon);
	printf("alt sınır ve üst sınır giriniz");
	scanf("%f %f", &alt, &us);
	printf("iterasyon \t xa \t xü \t \t xr \t \t f(xa) \t \t f(xü) \t  \t f(xr) \t \t  Ea(%) \n");
	hesap(iterasyon, alt, us);	
}

