#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
int cuad,band1,band2,band3,band4,i,cuadmax;
float x,y,norm,max;
printf("\n Ingrese las coordenadas ( x ; y ) de diez puntos,\n utilizando no mas de dos cifras decimales:\n");
cuad=band1=band2=band3=band4=0;
for(i=1;i<=10;i++)
    {
    printf("\n Ingrese la abscisa del punto %d: \n\t",i);
    scanf("%f",&x);
    printf("\n Ingrese la ordenada del punto %d: \n\t",i);
    scanf("%f",&y);
    if(x>0&&y>0)
        {
        cuad=1;
        band1=1;
        }
    else
        if(x<0&&y>0)
            {
            cuad=2;
            band2=1;
            }
        else
            if(x<0&&y<0)
                {
                cuad=3;
                band3=1;
                }
            else
                if(x>0&&y<0)
                    {
                    cuad=4;
                    band4=1;
                    }
                else
                    printf("\n Este punto no tiene cuadrante \n");
    printf("\n Punto: %d \t Coordenadas:( %7.2f ; %7.2f ) \t Cuadrante: %d \n",i,x,y,cuad);
    norm=sqrt(x*x+y*y);
    if(i==1||norm>max)
        {
        max=norm;
        cuadmax=cuad;
        }
    cuad=0;
    }
if(band1==0)
    printf(" \n No hay puntos en el primer cuadrante \n");
if(band2==0)
    printf(" \n No hay puntos en el segundo cuadrante \n");
if(band3==0)
    printf(" \n No hay puntos en el tercer cuadrante \n");
if(band4==0)
    printf(" \n No hay puntos en el cuarto cuadrante \n");
printf("\n El punto que genera entre el origen y el mismo \n el vector con la mayor norma se encuentra en el cuadrante %d \n",cuadmax);
getch();
}
