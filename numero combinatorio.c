#include<stdio.h>
#include<conio.h>
#include<locale.h>
int factorial(int);
void main()
{
setlocale(LC_CTYPE,"Spanish");
int m,n,fm,fn,fnm,comb;
printf("\n \t\t CÁLCULO DEL NÚMERO COMBINATORIO C ( m ; n )\n");
printf("\n m debe ser mayor o igual a n por definición del número combinatorio");
do
    {
    do
        {
        printf("\n\n Ingrese el número m entero no negativo:\n\n\t\t");
        scanf("%d",&m);
        }
    while(m<0);
    do
        {
        printf("\n\n Ingrese el número n entero no negativo:\n\n\t\t");
        scanf("%d",&n);
        }
    while(n<0);
    }
while(m<n);
fm=factorial(m);
fn=factorial(n);
fnm=factorial(m-n);
comb=fm/(fn*fnm);
printf("\n\n El número combinatorio C ( %d ; %d ) es %d \n\n",m,n,comb);
getch();
}
int factorial(int x)
{
int f,i;
f=1;
for(i=1;i<=x;i++)
    f*=i;
return f;
}
