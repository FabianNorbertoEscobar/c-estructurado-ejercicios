#include<stdio.h>
#include<conio.h>
#include<locale.h>
int validadato(int,int,int);
void op1(int,int,int);
void op2(int,int,int);
void op3(int,int,int);
void op4(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int band1,band2,band3,band4,a,b,c,op;
    band1=band2=band3=band4=0;
    do
        {
        if(band1==1)
            printf("\n El valor ingresado es incorrecto. Reingréselo: \n");
        printf("\n Ingrese un valor entero (entre -19 y 240): \t");
        scanf("%d",&a);
        band1=1;
        }
    while(!validadato(a,-19,240));
    do
        {
        if(band2==1)
            printf("\n El valor ingresado es incorrecto. Reingréselo: \n");
        printf("\n Ingrese un valor entero (entre -19 y 240): \t");
        scanf("%d",&b);
        band2=1;
        }
    while(!validadato(b,-19,240));
    do
        {
        if(band3==1)
            printf("\n El valor ingresado es incorrecto. Reingréselo: \n");
        printf("\n Ingrese un valor entero (entre -19 y 240): \t");
        scanf("%d",&c);
        band3=1;
        }
    while(!validadato(c,-19,240));
    printf("\n Menú: \n\t\t Elija la opción que desea que se ejecute: \n");
    printf("\n 1-La suma de los valores positivos");
    printf("\n 2-La resta del mayor valor con el menor");
    printf("\n 3-El valor de multiplicar solo los valores pares");
    printf("\n 4-El promedio de los valores negativos");
    do
        {
        if(band4==1)
            printf("\n La opción ingresada no existe. Ingrese una opción válida: \n");
        printf("\n\n Opción: \t\t");
        scanf("%d",&op);
        band4=1;
        }
    while(!validadato(op,1,4));
    switch(op)
        {
        case 1:op1(a,b,c);
            break;
        case 2:op2(a,b,c);
            break;
        case 3:op3(a,b,c);
            break;
        case 4:op4(a,b,c);
            break;
        }
    getch();
    }
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
void op1(int a,int b,int c)
    {
    int sum;
    sum=0;
    if(a>0)
        sum+=a;
    if(b>0)
        sum+=b;
    if(c>0)
        sum+=c;
    printf("\n La suma de los valores positivos es: %d \n\n",sum);
    }
void op2(int a,int b,int c)
    {
    int may,men,res;
    if(a>b)
        {
        may=a;
        men=b;
        }
    else
        {
        may=b;
        men=a;
        }
    if(c>may)
        may=c;
    else
        if(c>men)
            men=c;
    res=may-men;
    printf("\n La resta entre el mayor y el menor valor es: %d \n\n",res);
    }
void op3(int a,int b,int c)
    {
    int pr,band;
    pr=1;
    band=0;
    if(a%2==0)
        {
        pr*=a;
        band=1;
        }
    if(b%2==0)
        {
        pr*=b;
        band=1;
        }
    if(c%2==0)
        {
        pr*=c;
        band=1;
        }
    if(band!=0)
        printf("\n El producto de los valores pares es: %d \n\n",pr);
    else
        printf("\n No se ingresaron valores pares. \n\n");
    }
void op4(int a,int b,int c)
    {
    int acum,cont;
    acum=cont=0;
    if(a<0)
        {
        acum+=a;
        cont++;
        }
    if(b<0)
        {
        acum+=b;
        cont++;
        }
    if(c<0)
        {
        acum+=c;
        cont++;
        }
    if(cont>0)
        printf("\n El promedio de los valores negativos es: %.2f \n\n",(float)acum/cont);
    else
        printf("\n No se ingresaron valores negativos \n\n");
    }
