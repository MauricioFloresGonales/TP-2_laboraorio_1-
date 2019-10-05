#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "funcionesAux.h"


void harcodeo(eEmployee lista[],int len)
{
    int i;

    int id[]={1,2,3,4,5};

    char name[][51]={"a","c","d","b","e"};//{"ana","juan","pepe","laura","mauricio"};
    char lastName[][51] = {"catunta","grillo","argento","cordoba","gonzales"};
    float salary[] = {100,200,300,400,500};
    int sector[] = {1,2,3,1,2};
    int isEmpty[] = {0,0,0,0,0};

    for(i=0;i<len;i++)
    {
        //lista[i].id = autoId(lista,len);


        lista[i].id=id[i];

        strcpy(lista[i].name,name[i]);
        strcpy(lista[i].lastName,lastName[i]);
        lista[i].salary = salary[i];
        lista[i].sector = sector[i];
        lista[i].isEmpty = isEmpty[i];
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------

int espacioLibre(eEmployee lista[], int len)
{
    int index;
    int i;
    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty == EMPTY)
        {
            index = i;
            break;

        }else{

            index = -1;
        }//if
    }//for
    return index;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int autoId(eEmployee lista[],int tam)
{
    int retorno;
    int idMayor;

    idMayor=buscarIdMayor(lista,tam);


    if(idMayor!=-1)
    {
        retorno=idMayor+1;
    }else{
        retorno=1;
    }

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int buscarIdMayor(eEmployee lista[],int tam)
{
    int retorno=-1;
    int i;
    int flag=0;
    int mayor;

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==EMPTY)
        {
            if(lista[i].id>mayor || flag==0)
            {
                mayor=lista[i].id;
                flag=1;
            }
        }
    }
    if(flag!=0)
    {
        retorno=mayor;
    }
    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int initEmployees(eEmployee list[], int len)
{
    int i;
    int retorno;

    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(i==1)
            {
                list[i].id = 1;
            }
            list[i].isEmpty = EMPTY;
        }
        retorno = 0;
    }else{
        retorno = -1;
    }

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int agragarEmpleado(eEmployee* lista,int len)
{
    int retorno;
    int index;

    index = espacioLibre(lista,len);

    if(index>-1)
    {
        retorno = addEmployee(lista,len,&lista[index].id,lista[index].name,lista[index].lastName,&lista[index].salary,&lista[index].sector);
        lista[index].isEmpty = NOT_EMPTY;
    }

    return retorno;
}



//----------------------------------------------------------------------------------------------------------------------------------------

int addEmployee(eEmployee lista[], int len, int* id, char name[],char lastName[],float* salary,int* sector)
{
    int retorno;

    if(lista!=NULL && (espacioLibre(lista,len))>-1)
    {
            *id = autoId(lista,len);
            printf("inngrese el nombre: ");
            fflush(stdin);
            scanf("%s",name);
            printf("ingrese el Apellido: ");
            fflush(stdin);
            scanf("%s",lastName);
            printf("ingrese el Salario: ");
            scanf("%f",salary);
            printf("ingrese el numero del Sector: ");
            scanf("%d",sector);


            retorno = 0;

     }else{

        printf("No hay mas espacio libre\n");
        retorno = -1;

        }

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int findEmployeeById(eEmployee* list, int len,int id)
{
    int index;
    int i;

    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].id == id && list[i].isEmpty == NOT_EMPTY)
            {
                index = i;
                break;

            }else{
                index = -1;
            }//if2
        }//for
    }else{
        index = -1;
    }//if1

    return index;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int removeEmployee(eEmployee* list, int len, int id)
{
    int retorno;
    int i;

    if(list!=NULL || len>0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == NOT_EMPTY && list[i].id == id)
            {
                list[i].isEmpty = EMPTY;
                retorno = 0;
            }else{
                retorno = -1;
            }//if2
        }//for

    }else{
        retorno = -1;
    }//if1

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int sortEmployees(eEmployee* list, int len, int order)
{
    int retorno;

    if(list!=NULL || len>0)
    {
        if(order==0)
        {
            ordenarAfabeticamenteUp(list,len);
            mostrarApellidoSector(list,len);
            retorno = 0;
        }else if(order == 1)
        {
            ordenarAfabeticamenteDown(list,len);
            mostrarApellidoSector(list,len);
            retorno = 0;
        }else{
            printf("No eligio ninguna opcion.\n");
        }
    }else{
        retorno = -1;
    }
   return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

void ordenarAfabeticamenteUp(eEmployee* list, int len)
{
    int i;
    int j;
    eEmployee aux;

    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(stricmp(list[i].lastName,list[j].lastName)<0)
            {
                strcpy(aux.lastName,list[i].lastName);
                strcpy(list[i].lastName,list[j].lastName);
                strcpy(list[j].lastName,aux.lastName);
            }else if(stricmp(list[i].lastName,list[j].lastName)== 0)
            {
                if(list[i].sector<list[j].sector)
                {
                    aux.sector = list[i].sector;
                    list[i].sector = list[j].sector;
                    list[j].sector = aux.sector;
                }

            }
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------

void ordenarAfabeticamenteDown(eEmployee* list, int len)
{
    int i;
    int j;
    eEmployee aux;

    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(stricmp(list[i].lastName,list[j].lastName)>0)
            {
                strcpy(aux.lastName,list[i].lastName);
                strcpy(list[i].lastName,list[j].lastName);
                strcpy(list[j].lastName,aux.lastName);

            }else if(stricmp(list[i].lastName,list[j].lastName)== 0)
                {
                    if(list[i].sector>list[j].sector)
                    {
                        aux.sector = list[i].sector;
                        list[i].sector = list[j].sector;
                        list[j].sector = aux.sector;
                    }

                }
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------

int printEmployees(eEmployee* list, int length)
{
    int retorno;
    int i;

    if(list!=NULL || length>0)
    {
        for(i=0;i<length;i++)
        {
            mostrarUnEmpleado(list,i);
        }
        retorno = 0;
    }else{
        retorno = -1;
    }

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

void mostrarUnEmpleado(eEmployee* list, int index)
{
    if(list[index].isEmpty == NOT_EMPTY)
    {
        printf("%d\t",list[index].id);
        printf("%s\t",list[index].name);
        printf("%s\t",list[index].lastName);
        printf("%f\t",list[index].salary);
        printf("%d\n",list[index].sector);
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------

int  modificarMenu(eEmployee* list, int len)
{

    int opcion;
    int index;
    int id;
    int retorno;
    char auxChar[51];

    if(list!=NULL || len>0)
    {
        retorno = printEmployees(list,len);

        do{
            printf("ingrese un ID a modificar: ");
            scanf("%d",&id);
            index = findEmployeeById(list,len,id);
        }while(index > -1);

        mostrarUnEmpleado(list,index);

        do{
                printf("Que desea modificar:\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n5-Salir.");
                scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:

                printf("ingrese nuevo nombre: ");
                fflush(stdin);
                scanf("%s",auxChar);
                strcpy(list[index].name,auxChar);
                retorno=0;
                break;
            case 2:
                printf("ingrese nuevo Apellido: ");
                fflush(stdin);
                scanf("%s",auxChar);
                strcpy(list[index].lastName,auxChar);
                retorno=0;
                break;
            case 3:
                printf("ingrese nuevo Salario: ");
                scanf("%f", &list[index].salary);
                retorno=0;
                break;
            case 4:
                printf("ingrese nuevo Sector: ");
                scanf("%d",&list[index].sector);
                retorno=0;
                break;
            default:
                printf("SALIR.\n");
                break;
            }
        }while(opcion != 5);
    }else{
        retorno = -1;
    }
    return retorno;
}



//----------------------------------------------------------------------------------------------------------------------------------------

void mostrarApellidoSector(eEmployee* list, int len)
{
    int i;

    if(list!=NULL || len>0)
    {
        printf("\tApellidos:\tSectores:\n");
        for(i=0;i<len-1;i++)
        {

            printf("\t%9s\t%5d\n",list[i].lastName,list[i].sector);
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------

float totalSalarios(eEmployee* list, int len)
{
    int i;
    float contador =0;
    float retorno;

    if(list!=NULL || len>0)
    {
        for(i=0;i<len-1;i++)
        {
            if(list[i].isEmpty ==NOT_EMPTY)
            {
                contador = contador + list[i].salary;
            }
        }
        retorno = contador;
    }else{
        retorno = -1;
    }

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

float promedioDeSalarios(eEmployee* list, int len)
{
    int retorno;
    float total;
    float promedio;
    int contador = 0;
    int i;

    if(list!=NULL || len>0)
    {
        for(i=0;i<len-1;i++)
        {
            if(list[i].isEmpty ==NOT_EMPTY)
            {
                contador ++;
            }
        }

        total = totalSalarios(list,len);

        promedio = total / contador;

        retorno = promedio;

    }else{
        retorno = -1;
    }

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int superanPromedioSalario(eEmployee* list, int len)
{
    int i;
    int contador;
    int retorno;

    if(list!=NULL || len>0)
    {
        for(i=0;i<len-1;i++)
        {
            if(list[i].isEmpty ==NOT_EMPTY)
            {
                if(list[i].salary>promedioDeSalarios(list,len))
                {
                    contador++;
                }
            }
        }
        retorno = contador;
    }else{
        retorno =0;
    }

    return retorno;
}

int informeSalario(eEmployee* list, int len)
{
    float total;
    float promedio;
    int contador;
    int retorno;

    if(list!=NULL || len>0)
    {
        total = totalSalarios(list,len);
        promedio = promedioDeSalarios(list,len);
        contador = superanPromedioSalario(list,len);

        printf("\nSalario total: %f\n",total);
        printf("Salario promedio: %f\n",promedio);
        printf("Num. de empleados que superan el promedio: %d\n\n",contador);
        retorno = 0;
    }else{
        retorno = -1;
    }

    return retorno;

}
