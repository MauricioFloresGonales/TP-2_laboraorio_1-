#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"

#define LEN 5

int main()
{
    eEmployee empleados[LEN];

    int funcionamiento;
    int idAux;
    int order;
    int opcion4;
    int opcion;
    if(initEmployees(empleados,LEN)==0)
    {
        do{
            printf("1- ALTA:\n");
            printf("2- MODIFICAR:\n");
            printf("3- BAJA:\n");
            printf("4- INFORMAR:\n");
            printf("5- SALIR:\n");
            printf("Elija una opcion:\n");
            scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
                harcodeo(empleados,LEN);
                funcionamiento = agragarEmpleado(empleados,LEN);
                funcionamiento = printEmployees(empleados,LEN);
                break;
            case 2:
                funcionamiento = modificarMenu(empleados,LEN);
                funcionamiento = printEmployees(empleados,LEN);

                break;
            case 3:
                    printf("ingrese un ID a modificar: ");
                    scanf("%d",&idAux);
                    if((findEmployeeById(empleados,LEN,idAux)) != -1)
                    {
                        funcionamiento = removeEmployee(empleados,LEN,idAux);
                    }
                    funcionamiento = printEmployees(empleados,LEN);
                break;
            case 4:
                do{
                    printf("1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n");
                    printf("2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
                    printf("3. Salir\n");
                    printf("Opcion: ");
                    scanf("%d",&opcion4);
                    switch(opcion4)
                    {
                        case 1:
                                printf("Ingrese una opcion:\n0-indicate DOWN\n1-indicate UP\n");
                                scanf("%d",&order);
                                funcionamiento = sortEmployees(empleados,LEN,order);
                            break;
                        case 2:
                            funcionamiento = informeSalario(empleados,LEN);
                            break;
                        default:

                        printf("Cancelado\n");
                    }

                }while(opcion4!=3);

                break;

            default:
                printf("SALIR\n");
            }

        system("pause");
        system("cls");

        }while(opcion != 5);
    }

    return 0;
}
