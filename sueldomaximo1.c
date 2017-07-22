#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define tope 100
int cargarsueldos(float[]);
void mostrarmaximos1(float[],int,float);
float maximo(float[],int);
void main()
{
setlocale(LC_CTYPE,"Spanish");
int ce;
float sueldos[tope],max;
printf("\n Ingrese los sueldos de los empleados (máximo %d empleados) \n para encontrar el sueldo máximo y los empleados que lo poseen. \n Finalizar con sueldo igual a cero \n\n\t",tope);
ce=cargarsueldos(sueldos);
if(ce!=0)
    {
    max=maximo(sueldos,ce);
    printf(" \n\n El máximo sueldo es de %f pesos \n",max);
    printf("\n Los legajos con sueldo máximo son: \n\n\t");
    mostrarmaximos1(sueldos,ce,max);
    }
else
    printf(" \n No hay ningún legajo \n\n");
getch();
}
int cargarsueldos(float v[])
{
int i;
float sueldo;
i=0;
do
    {
    printf(" \n\t Ingrese el sueldo número %d: \t",i+1);
    scanf("%f",&sueldo);
    }
while(sueldo<0);
while(i<tope&&sueldo!=0)
    {
    v[i]=sueldo;
    i++;
    do
        {
        printf(" \n\t Ingrese el sueldo número %d: \t",i+1);
        scanf("%f",&sueldo);
        }
    while(sueldo<0);
    }
return i;
}
void mostrarmaximos1(float v[],int ce,float max)
{
int i;
for(i=0;i<ce;i++)
    if(v[i]==max)
        printf("%d \n\n\t",i+1);
}
float maximo(float v[],int ce)
{
int i;
float max;
for(i=0;i<ce;i++)
    if(i==0||v[i]>max)
        max=v[i];
return max;
}
