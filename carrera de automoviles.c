#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define tope 60
int cargartiempos(float[],int[]);
int posicionminimo(float[],int);
int posicionmaximo(float[],int);
float promedio(float[],int);
int superanpromedio(float[],int,float);
int autosnoparticipan(int[],int);
void mostrarautosnoparticipan(int[],int);
void main()
{
setlocale(LC_CTYPE,"Spanish");
int ce,posmin,posmax,sup,aux[tope],ceros;
float tiempos[tope],pr;
printf(" \n CARRERA DE AUTOMÓVILES \n");
printf("\n Ingrese los tiempos de clasificación de los automóviles \n (usted puede ingresar los datos de hasta 60 vehículos)");
printf("\n\n Si alguno de los autos no participara de la carrera, \n ingrese un tiempo igual a cero.");
printf("\n Y un tiempo negativo finalizará la carga de datos. \n");
ce=cargartiempos(tiempos,aux);
if(ce!=0)
    {
    posmin=posicionminimo(tiempos,ce);
    printf("\n El ganador de la carrera es el auto número %d \n",posmin+1);
    posmax=posicionmaximo(tiempos,ce);
    printf("\n El peor tiempo de clasificación lo tiene el auto número %d \n",posmax+1);
    pr=promedio(tiempos,ce);
    sup=superanpromedio(tiempos,ce,pr);
    printf("\n %d autos superan el tiempo promedio de clasificación \n",sup);
    ceros=autosnoparticipan(aux,ce);
    if(ceros!=0)
        {
        printf("\n Los autos que no participan de la carrera son: \n");
        mostrarautosnoparticipan(aux,ce);
        }
    else
        printf("\n No hay autos que no hayan participado en la carrera \n \n ");
    }
else
    printf("\n Ningún auto participó de la carrera \n\n");
getch();
}
int cargartiempos(float tmp[],int aux[])
{
int i,band;
float tiempo;
i=0;
band=0;
printf("\n Ingrese el tiempo del auto %d: \n\t",i+1);
scanf("%f",&tiempo);
while(i<tope&&tiempo>=0)
    {
    tmp[i]=tiempo;
    if(tiempo!=0)
        {
        aux[i]=1;
        band=1;
        }
    else
        aux[i]=0;
    i++;
    printf("\n Ingrese el tiempo del auto %d: \n\t",i+1);
    scanf("%f",&tiempo);
    }
if(band!=0)
    return i;
else
    return band;
}
int posicionminimo(float t[],int ce)
{
int band,p,i;
band=0;
for(i=0;i<ce;i++)
    {
    if(band==0)
        {
            if(t[i]>0)
                {
                p=i;
                band=1;
                }
        }
    else
        if(t[i]>0&&t[i]<t[p])
            p=i;
    }
return p;
}
int posicionmaximo(float t[],int ce)
{
int max,i;
max=0;
for(i=0;i<ce;i++)
    if(t[i]>t[max])
        max=i;
return max;
}
float promedio(float t[],int ce)
{
int cont,i;
float acum,pr;
cont=0;
acum=0;
for(i=0;i<ce;i++)
    if(t[i]>0)
        {
        cont++;
        acum+=t[i];
        }
pr=acum/cont;
return pr;
}
int superanpromedio(float t[],int ce,float pr)
{
int i,cont;
cont=0;
for(i=0;i<ce;i++)
    if(t[i]>pr)
        cont++;
return cont;
}
int autosnoparticipan(int v[],int ce)
{
int i,cont;
cont=0;
for(i=0;i<ce;i++)
    if(v[i]==0)
        cont++;
return cont;
}
void mostrarautosnoparticipan(int v[],int ce)
{
int i;
for(i=0;i<ce;i++)
    if(v[i]==0)
        printf("\n\t %d \n",i+1);
}
