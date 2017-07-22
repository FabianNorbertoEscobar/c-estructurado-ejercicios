#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define tope 100
int leeyvalida(void);
int cargarvector(int[],int);
void inicializar(int[],int);
void seleccionconorden(int[],int[],int);
void listar2vectores(int[],int[],int);
void ordeningresomaximos(int[],int[],int,int);
void main()
{
setlocale(LC_CTYPE,"Spanish");
int vec[tope],ord[tope],ce,max;
printf("\n ORDENAMIENTO POR SELECCIÓN ACARREANDO EL ORDEN \n");
printf("\n Ingrese la cantidad de números que desea ingresar: \n (máximo 100 números)\n\n\t\t");
ce=leeyvalida();
printf("\n Usted puede ingresar %d valores enteros\n",ce);
cargarvector(vec,ce);
inicializar(ord,ce);
seleccionconorden(vec,ord,ce);
printf("\n Valores ordenados en forma creciente \n");
printf("\n \t Valor \t Orden de ingreso \n");
listar2vectores(vec,ord,ce);
max=vec[ce-1];
printf("\n El valor máximo que se ha ingresado es %d \n",max);
printf("\n El orden de ingreso de los máximos es:\n");
ordeningresomaximos(vec,ord,ce,max);
getch();
}
int leeyvalida(void)
{
int x;
do
    scanf("%d",&x);
while(x<1||x>tope);
}
int cargarvector(int v[],int ce)
{
int dat,i;
for(i=0;i<ce;i++)
    {
    printf("\n Ingrese el %d%c valor: \t",i+1,248);
    scanf("%d",&dat);
    v[i]=dat;
    }
}
void inicializar(int v[],int ce)
{
int i;
for(i=0;i<ce;i++)
    v[i]=i+1;
}
void seleccionconorden(int v[],int o[],int ce)
{
int j,i,pm,aux,ord;
for(j=1;j<ce;j++)
    {
    pm=j-1;
    for(i=j;i<ce;i++)
        {
        if(v[i]<v[pm])
        pm=i;
        }
    aux=v[pm];
    v[pm]=v[j-1];
    v[j-1]=aux;
    ord=o[pm];
    o[pm]=o[j-1];
    o[j-1]=ord;
    }
}
void listar2vectores(int v[],int o[],int ce)
{
int i;
for(i=0;i<ce;i++)
    printf("\n \t %d \t %d \n",v[i],o[i]);
}
void ordeningresomaximos(int v[],int o[],int ce,int max)
{
int i;
for(i=0;i<ce;i++)
    if(v[i]==max)
        printf("\n\n\t %d \n",o[i]);
}
