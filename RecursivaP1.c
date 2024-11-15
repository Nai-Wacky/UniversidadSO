#include<stdio.h>

int potencia(int n, int pot)
{
    
    if(pot==0)
    {
        return 1;
    }
    else if (pot==-1)
    {
        return 1;
    }   
    else
    {
        return n + potencia(n+n, pot-1);
    }
}

int division(int n, int div, int cont)
{
    if(n<div)
    {
        return cont;
    }
    else 
    {
        return division(n-div, div, cont+1);
    }
}

int main(int argc, char const *argv[])
{
    int pid = fork();

    if (pid<0)
    {
        perror("Error al crear un proceso");
        return 1;
    }
    else if (pid==0)
    {
        printf("Valor del pid hijo: %d \n", pid);
        int n, div;
        //printf("Introduce dos numeros separados por un espacio (divisor dividendo): \n");
        //scanf("%d %d", &n, &div);
        printf("El resultado de la divicion es: %d", division(10, 5, 0));
    }
    else
    {
        printf("Valor del pid hijo: %d \n", pid);
        int n, pot;
        //printf("Introduce dos numeros separados por un espacio (base potencia): \n");
        //scanf("%d %d", &n, &pot);
        printf("El resultado de la potencia es: %d", (potencia(2, (8-1))+1));
        
    }
    return 0;
    
}
