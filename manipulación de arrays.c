#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<locale.h>
float valida(int,int);
void sumarvectores(float[],float[],float[]);
int busquedasecuencial(float[],int,float);
void ordenarmenor(float[],int);//Ordenamiento por selección
float promedio(float[],int);
int cargarsi(float[],int,float[],float);
void mostrar(float[],int);
void listar(float[],float[],float[],float[],int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int i,ord,pos,ce;
    float va[10],vb[10],vc[10],vd[10],ve[10],may,men,n,pr;
    printf("\n MANIPULACIÓN DE ARRAYS \n");
    printf("\n Ingrese diez valores reales para llenar un array \n");
    for(i=0;i<10;i++)
        va[i]=valida(1,100);
    for(i=0;i<10;i++)
        vb[i]=sqrt(va[i]);
    sumarvectores(va,vb,vc);
    for(i=0;i<10;i++)
        vd[9-i]=vc[i];
    for(i=0;i<10;i++)
        if(i==0||va[i]>may)
            {
            may=va[i];
            ord=i+1;
            }
    printf("\n El mayor valor ingresado es %.2f en la posición %d \n\n",may,ord);
    for(i=0;i<10;i++)
        if(i==0||vb[i]<men)
            men=vb[i];
    printf("\n La menor raíz cuadrada de los elementos ingresados es %.2f.Posicion/Posiciones:\n",men);
    for(i=0;i<10;i++)
        if(vb[i]==men)
            printf("\n %d",i+1);
    printf("\n\n Ingrese un valor real para que sea buscado en el array: (entre 1 y 100) \n");
    n=valida(1,100);
    printf("\n Posición del array en que fue encontrado el valor:\n");
    pos=busquedasecuencial(va,10,n);
    if(pos!=-1)
        printf("\n %d",pos+1);
    else
        printf("\n No se encontró el valor ingresado \n\n");
    ordenarmenor(vd,10);
    pr=promedio(vb,10);
    ce=cargarsi(vb,10,ve,pr);
    if(ce>0)
        {
        printf("\n\n Array con los mayores al promedio de la raíz cuadrada del array ingresado: \n");
        mostrar(ve,ce);
        }
    else
        printf("\n No hay mayores al promedio de la raíz cuadrada del array ingresado \n\n");
    ve[ce]=101.5;
    printf("\n\n Array de mayores al promedio de la raíz cuadrada del array ingresado \n + un valor agregado en la última posición: \n");
    mostrar(ve,ce+1);
    printf("\n\n LISTADO DE ARRAYS \n");
    printf("\n Array A \t\t Array B \t\t Array C \t\t Array D \n");
    listar(va,vb,vc,vd,10);
    printf("\n\n");
    getch();
    }
float valida(int li,int ls)
    {
    float n;
    do
        {
        printf("\n Ingrese un número real: (entre 1 y 100) \n\n");
        scanf("%f",&n);
        }
    while(!(n>=1&&n<=100));
    return n;
    }
void sumarvectores(float a[],float b[],float c[])
    {
    int i;
    for(i=0;i<10;i++)
        c[i]=a[i]+b[i];
    }
int busquedasecuencial(float v[],int ce,float x)
    {
    int p,i;
    p=-1;
    i=0;
    while(p==-1&&i<ce)
        {
        if(v[i]==x)
            p=i;
        else
            i++;
        }
    return p;
    }
void ordenarmenor(float v[],int ce)
    {
    int i,j,pm;
    float aux;
    for(j=1;j<ce;j++)
        {
        pm=j-1;
        for(i=j;i<ce;i++)
            if(v[i]<v[pm])
                pm=i;
        aux=v[pm];
        v[pm]=v[j-1];
        v[j-1]=aux;
        }
    }
float promedio(float v[],int ce)
    {
    int i;
    float acum;
    acum=0;
    for(i=0;i<ce;i++)
        acum+=v[i];
    return acum/ce;
    }
int cargarsi(float v1[],int ce,float v2[],float x)
    {
    int j,i;
    j=0;
    for(i=0;i<ce;i++)
        if(v1[i]>x)
            {
            v2[j]=v1[i];
            j++;
            }
    return j;
    }
void mostrar(float v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        printf("\n %.2f",v[i]);
    }
void listar(float a[],float b[],float c[],float d[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        printf("\n %.2f \t\t\t %.2f \t\t\t %.2f \t\t\t %.2f",a[i],b[i],c[i],d[i]);
    }
