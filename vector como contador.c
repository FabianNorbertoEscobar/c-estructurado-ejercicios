#include<stdio.h>
#include<conio.h>
#define tope 100
int validadato(int,int,int);
void ponerencero(int[],int);
void main()
{
int mayores65,edad,i,vcont[tope];
ponerencero(vcont,66);
mayores65=0;
printf("\n Ingrese de a una las edades de los habitantes de una ciudad, \n finalizando con la edad -1: \n\n");
do
    {
    printf("\n Ingrese la edad de un habitante de la ciudad:\n\n\t");
    scanf("%d",&edad);
    }
while(!validadato(edad,-1,100));
while(edad!=-1)
    {
    if(edad<=65)
        vcont[edad]++;
    else
        mayores65++;
    do
    {
    printf("\n Ingrese la edad de un habitante de la ciudad:\n\n\t");
    scanf("%d",&edad);
    }
while(!validadato(edad,-1,100));
    }
printf("\n\t Edad \t Cantidad\n");
for(i=0;i<66;i++)
    printf("\n\t %d \t %d \n",i,vcont[i]);
printf("\n \n Mayores de 65: %d \n \n",mayores65);
getch();
}
int validadato(int x,int li,int ls)
{
if(x>=li && x<=ls)
    return 1;
else
    return 0;
}
void ponerencero(int vcont[],int ce)
{
int i;
for(i=0;i<ce;i++)
    vcont[i]=0;
}
