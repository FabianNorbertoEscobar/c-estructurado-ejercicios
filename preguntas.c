#include <stdio.h>
#include <conio.h>
#include <locale.h>
void main()
{
 setlocale(LC_CTYPE,"Spanish");
 int i,x,c=0;
 for(i=1;i<6;i++)
   {
    printf("\n\t\t %d P R E G U N T A \n",i);
    switch (i)
      {
       case 1:printf("\t\n Quién creó la Bandera?");
              printf("\n\t\t\t\t  1- José de San Martín");
              printf("\n\t\t\t\t  2- Manuel Belgrano   ");
              printf("\n\t\t\t\t  3- Jorge Banderas    ");
              printf("\n\t\t\t\t  4- Faustino Sarmiento\n");
              break;
       case 2:printf("\t\n Qué día se festeja la Independencia Nacional?");
              printf("\n\t\t\t\t  1- 25 de Mayo        ");
              printf("\n\t\t\t\t  2-  1 de Mayo        ");
              printf("\n\t\t\t\t  3- 12 de Octubre     ");
              printf("\n\t\t\t\t  4-  9 de Julio\n");
              break;

       case 3:printf("\t\n Un triángulo Equilatero tiene:");
              printf("\n\t\t\t\t  1- Sus tres lados distintos      ");
              printf("\n\t\t\t\t  2- Sus dos iguales y uno distinto");
              printf("\n\t\t\t\t  3- Sus tres lados iguales        ");
              printf("\n\t\t\t\t  4- La suma de lados es igual 180 grados \n");
              break;
       case 4:printf("\t\n La Universidad de La Matanza se encuentra:");
              printf("\n\t\t\t\t  1- San Justo         ");
              printf("\n\t\t\t\t  2- Ramos Mejía       ");
              printf("\n\t\t\t\t  3- Morón             ");
              printf("\n\t\t\t\t  4- Ciudad Autónoma\n");
              break;
       case 5:printf("\t\n Quién escribió el Quijote de la Mancha?");
              printf("\n\t\t\t\t  1- José Luis Borges            ");
              printf("\n\t\t\t\t  2- Miguel de Cervantes Saavedra");
              printf("\n\t\t\t\t  3- Juana Molina                ");
              printf("\n\t\t\t\t  4- Ernesto Sábato\n");
              break;
      }

    printf("\n \t Ingrese correcta:");
    scanf("%d",&x);
    if(i==1&&x==2) c++;
    if(i==2&&x==4) c++;
    if(i==3&&x==3) c++;
    if(i==4&&x==1) c++;
    if(i==5&&x==2) c++;
   }
   switch (c)
    {
     case 0:printf("\n\n Ud debería comenzar la primaria nuevamente   ");break;
     case 1:printf("\n\n Ud debería hacer mas lectura y estudiar mucho");break;
     case 2:printf("\n\n Ud debería hacer mas lectura                 ");break;
     case 3:printf("\n\n Ud se nota que algo sabe                     ");break;
     case 4:printf("\n\n Ud la tiene clara, lástima que no recordo una ");break;
     case 5:printf("\n\n Ud es un genio,  cometa cósmico");
    }
    return 0;
}
