#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<math.h>
#define Pi 3.14
float hipotenusa(float,float);
float longcirc(float);
float areacirc(float);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    float a,b,hip,longi,area;
    do
        {
        printf("\n Ingrese la longitud de los catetos, de a uno, \n y confirmando cada uno con enter");
        printf("\n (La carga de datos finaliza con dos catetos nulos) \n\n");
        scanf("%f%f",&a,&b);
        }
    while(a<0||b<0);
    while(a!=0&&b!=0)
        {
        hip=hipotenusa(a,b);
        if(hip<150)
            {
            longi=longcirc(hip);
            printf("\n La longitud de la circunferencia de diámetro %.2f es %.2f \n\n",hip,longi);
            }
        else
            {
            area=areacirc(hip/2);
            printf("\n El área de la circunferencia de radio %.2f es %.2f \n\n",hip/2,area);
            }
        do
            {
            printf("\n Ingrese la longitud de los catetos, de a uno, \n y confirmando cada uno con enter");
            printf("\n (La carga de datos finaliza con dos catetos nulos) \n\n");
            scanf("%f%f",&a,&b);
            }
        while(a<0||b<0);
        }
    getch();
    }
float hipotenusa(float a,float b)
    {
    float h;
    h=sqrt(a*a+b*b);
    return h;
    }
float longcirc(float d)
    {
    float longi;
    longi=Pi*d;
    return longi;
    }
float areacirc(float r)
    {
    float ar;
    ar=Pi*r*r;
    return ar;
    }
