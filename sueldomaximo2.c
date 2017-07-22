#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define tope 100
int cargarvectores(float[],int[]);
float maximo(float[],int);
int validadato(int,int,int);
void mostrarmaximos2(float[],int[],int,float);
void main()
{
setlocale(LC_CTYPE,"Spanish");
int legajos[tope],ce;
float sueldos[tope],max;
printf("\n Ingrese los sueldos y los legajos (números de 4 cifras) \n de los empleados (máximo %d empleados) \n para determinar el sueldo máximo y quiénes lo poseen. \n Finalizar con legajo igual a cero \n",tope);
ce=cargarvectores(sueldos,legajos);
if(ce!=0)
    {
    max=maximo(sueldos,ce);
    printf("\n El máximo sueldo es de %f pesos \n",max);
    printf("\n Los legajos con sueldo máximo son: \n\n\t");
    mostrarmaximos2(sueldos,legajos,ce,max);
    }
else
    printf("\n No hay ningún legajo \n\n");
getch();
}
int cargarvectores(float s[],int l[])
{
int legajo,i;
float sueldo;
i=0;
do
    {
    printf("\n\t Ingrese el legajo número %d: \t",i+1);
    scanf("%d",&legajo);
    printf("\n\t Ingrese el sueldo número %d: \t",i+1);
    scanf("%f",&sueldo);
    }
while(!(sueldo>0&&validadato(legajo,1111,9999))&&legajo!=0);
while(i<tope&&legajo!=0)
    {
    s[i]=sueldo;
    l[i]=legajo;
    i++;
    do
        {
        printf("\n\t Ingrese el legajo número %d: \t",i+1);
        scanf("%d",&legajo);
        printf("\n\t Ingrese el sueldo número %d: \t",i+1);
        scanf("%f",&sueldo);
        }
    while(!(sueldo>0&&validadato(legajo,1111,9999))&&legajo!=0);
    }
return i;
}
float maximo(float v[],int ce)
{
int i;
float max;
for(i=0;i<ce;1)
    if(i==0||v[i]>max)
        max=v[i];
return max;
}
int validadato(int x,int li,int ls)
{
if(x>=li&&x<=ls)
    return 1;
else
    return 0;
}
void mostrarmaximos2(float s[],int l[],int ce,float max)
{
int i;
for(i=0;i<ce;i++)
    if(s[i]==max)
        printf("%d \n\n\t",l[i]);
}
