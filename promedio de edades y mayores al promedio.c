#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define tope 100
int validadato(int,int,int);
float promedio(int[],int);
void main()
{
setlocale(LC_CTYPE,"Spanish");
int cant,edad,i,suma,vec[tope],cont;
float pr;
do
    {
    printf("\n Ingrese la cantidad de alumnos del curso:\n máximo 100 alumnos \n\n\t");
    scanf("%d",&cant);
    }
while(!validadato(cant,1,100));
suma=0;
for(i=1;i<=cant;i++)
    {
    printf("\n\n Ingrese una edad:\n\n\t");
    scanf("%d",&edad);
    suma+=edad;
    vec[i-1]=edad;
    }
pr=promedio(vec,cant);
cont=0;
for(i=0;i<cant;i++)
    if(vec[i]>pr)
        cont++;
printf("\n\n El promedio de las %d edades ingresadas es %f y \n %d personas superan la edad promedio\n\n",cant,pr,cont);
getch();
}
int validadato(int x,int li,int ls)
{
if(x>=li && x<=ls)
    return 1;
else
    return 0;
}
float promedio(int vec[],int ce)
{
int i,acum,prom;
acum=0;
for(i=0;i<ce;i++)
    acum+=vec[i];
prom=acum/ce;
return prom;
}
