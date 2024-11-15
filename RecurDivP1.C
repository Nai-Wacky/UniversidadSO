#include<stdio.h>

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
    

    int n, div;
    printf("Introduce dos numeros separados por un espacio (divisor dividendo): \n");
    scanf("%d %d", &n, &div);
    printf("El resultado es: %d", division(n, div, 0));
    return 0;
}