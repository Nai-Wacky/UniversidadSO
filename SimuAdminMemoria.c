#include <stdio.h>
#include <stdlib.h>

#define MAX 128

typedef struct {
    int id;
    int size;
} Particion;

int main(int argc, char const *argv[])
{
    int size;
    int NumParti;
    Particion particiones[MAX]; //128 KB
    int totalSizePart = 0;
    int op;

    printf("Ingrese el tamaño de la memoria: ");
    scanf("%d", &size);

    printf("Ingrese el numero de particiones (Max:%d): ",MAX);
    scanf("%d", &NumParti);

    if (NumParti>MAX)
    {
        printf("El numero de particiones es mayor al limite propuesto");
        return 1;
    }

    for (int i = 0; i < NumParti; i++)
    {
        printf("Ingrese el tamaño de la particion %d: ", i+1);
        scanf("%d", &particiones[i].size);
        totalSizePart += particiones[i].size;
        particiones[i].id = 0;

        if (totalSizePart > size)
        {
            printf("El tamaño de las particiones es mayor al tamaño de memoria (%d)", totalSizePart);
            return 1;
        }
    }

    do
    {
        int processSize;
        int processID;
        int flag = 0;

        printf("\n   MENU DE OPCIONES   \n");
        printf("1. Asignar proceso\n");
        printf("2. Liberar proceso\n");
        printf("3. Mostrar estado de la memoria\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                printf("\nIngrese id del proceso: ");
                scanf("%d", &processID);

                printf("\nIngrese el tamaño de la memoria: ");
                scanf("%d", &processSize);

                for (int i = 0; i < NumParti && flag != 1; i++)
                {
                    if (processSize < particiones[i].size && particiones[i].id == 0)
                    {
                        particiones[i].id = processID;
                        flag = 1;
                    }
                }

                if (flag = 0)
                {
                    printf("\nTodos los particiones ya estan ocupadas o el tamaño del proceso es mas grande que la particion\n");
                }

                flag = 0;

                break;
            case 2:
                printf("\nIngrese id del proceso a liberar: ");
                scanf("%d", &processID);

                for (int i = 0; i < NumParti; i++)
                {
                    if (processID == particiones[i].id)
                    {
                        particiones[i].id = 0;
                        flag = 1;
                    }
                    
                }

                if (flag = 0)
                {
                    printf("\nNo se encontro el proceso\n");
                }

                flag = 0;

                break;
            case 3:
                for (int i = 0; i < NumParti; i++)
                {
                    if (particiones[i].id != 0)
                    {
                        printf("Particion: %d Espacio: %d (Ocupado)\n", i+1, particiones[i].size);
                    }
                    else if (particiones[i].id == 0)
                    {
                        printf("Particion: %d Espacio: %d (Libre)\n", i+1, particiones[i].size);
                    }
                }
                
                break;
            case 4:
                printf("\nSaliendo...\n");
                return 1;
                break;
            default:
                printf("\nOpcion no valida\n");
                break;
        }
    } while (op != 4);
    
    


    return 0;
}
