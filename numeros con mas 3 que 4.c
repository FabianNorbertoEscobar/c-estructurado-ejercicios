#include<stdio.h>
#include<conio.h>
#include<locale.h>
int trescuatro(int,int,int,int,int,int);
void main()
{
setlocale(LC_CTYPE,"Spanish");
int cont3,i,c1,c2,c3,c4,c5,tres,cuatro;
cont3=0;
for(i=10001;i<=90009;i++)
    {
    c5=i%10;
    c4=i/10%10;
    c3=i/100%10;
    c2=i/1000%10;
    c1=i/10000;
    if(c1==4||c2==4||c3==4||c4==4||c5==4)
        {
        tres=trescuatro(c1,c2,c3,c4,c5,3);
        cuatro=trescuatro(c1,c2,c3,c4,c5,4);
        if(tres>cuatro)
            cont3++;
        }
    }
printf("\n\n Hay %d números enteros entre 10001 y 90009 que tienen al menos un número 4 y además, tienen mas cifras iguales a 3 que cifras iguales a 4 \n\n",cont3);
getch();
}
int trescuatro(int a ,int b,int c,int d,int e,int x)
{
int cont;
cont=0;
if(a==x)
    cont++;
if(b==x)
    cont++;
if(c==x)
    cont++;
if(d==x)
    cont++;
if(e==x)
    cont++;
return cont;
}
