#include <stdio.h>
#include <string.h>
#include "funciones.h"

float validarFloatRango(float a, float b){
    float num;
    int val;
    do
    {
        val = scanf("%f",&num);
        while((getchar())!='\n');
        if (num < a || num > b || val != 1)
        {
            printf("Error: valor ingresado invalido\n");
        }
        
    } while (num < a || num > b || val != 1);
    return num;
}

void leerCadena(char *cadena, int n){
    fgets(cadena,n,stdin);
    int len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

void registrarLibro(int *id, char titulos[][100], 
                        char autores[][50], int *anio, int *estado, int *contL){
    printf("Ingrese los datos del libro %d:\n",*contL);
    id[*contL] = *contL;
    printf("Titulo: ");
    leerCadena(titulos[*contL],100);
    printf("Autor: ");
    leerCadena(autores[*contL],50);
    printf("Anio: ");
    anio[*contL] = validarFloatRango(1990,2026);
    estado[*contL] = 0;
    (*contL)++;
}

void mostrarLibros(int *id, char titulos[][100], 
                        char autores[][50], int *anio, int *estado, int n, int contL){
    printf("ID\t\tTitulo\t\tAutor\t\tAnio\t\tEstado\n");
    for (int i = n; i < contL; i++)
    {
        printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\n",id[i],
                                                titulos[i],
                                                autores[i],
                                                anio[i],
                                                (estado[i]==0 ? "Disponible" : "Prestado"));
    }
}

int buscarLibro(int *id, char titulos[][100], 
                        char autores[][50], int *anio, int *estado, int contL){

   printf("Buscar por 1.ID/2.Titulo: ");
   int opc = validarFloatRango(1,2);
   int indice = -1;
   switch (opc)
   {
   case 1:
        printf("Ingrese ID de libro 0-%d: ",contL);
        int indice = validarFloatRango(0,contL);
        mostrarLibros(id,titulos,autores,anio,estado,indice,indice+1);
    case 2:
        printf("Ingrese Titulo: ");
        char titulo[100];
        leerCadena(titulo,100);
        for (int i = 0; i < contL; i++)
        {
            if (strcasecmp(titulo,titulos[i])==0)
            {
                mostrarLibros(id,titulos,autores,anio,estado,i,i+1);
                indice = i;
                break;
            }
            
        }
        break;
   default:
        printf("Error: no existe la opcion\n");
    break;
   }
   return indice;                  
}
