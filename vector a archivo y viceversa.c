#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
struct precios
    {
    float x;
    };
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int i;
    struct precios v[5];
    FILE *pf;
    printf("\n Ingrese los precios de cinco artículos: \n\n");
    pf=fopen("DATOS.dat","wb");
    for(i=0;i<5;i++)
        {
        do
            {
            printf("\n precio %d: \t\t",i+1);
            scanf("%f",&v[i].x);
            }
        while(v[i].x<=0);
        }
    for(i=0;i<5;i++)
        fwrite(&v[i].x,sizeof(struct precios),1,pf);
    fclose(pf);
    pf=fopen("DATOS.dat","rb");
    if(pf==NULL)
        {
        printf("\n Error al abrir el archivo: \n\n");
        exit(0);
        }
    for(i=0;i<5;i++)
        fread(&v[i].x,sizeof(struct precios),1,pf);
    fclose(pf);
    printf("\n Los valores de los precios de los cinco artículos son: \n\n\t");
    for(i=0;i<5;i++)
        printf("%.2f \t",v[i].x);
    printf("\n\n");
    getch();
    }
