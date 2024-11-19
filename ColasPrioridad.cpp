#include <iostream>
using namespace std;

struct nodo{
    
    char dato;
    int prio;
    
    struct nodo *sgte;
};

struct cola
{
    nodo *delante;
    nodo *atras;
};

struct nodo *crearNodo(char x, int pr)
{
    struct nodo *nuevoNodo = new(struct nodo);

    nuevoNodo->dato = x;
    nuevoNodo->prio = pr;

    return nuevoNodo;
};

void encolar(struct cola &q, char valor, int prio)
{
    struct nodo *aux = crearNodo(valor, prio);

    aux->sgte = NULL;

    if(q.delante == NULL)
        q.delante = aux;
    else 
        (q.atras)->sgte=aux;
    
    q.atras=aux;
}

void muestraCola(struct cola q)
{
    struct nodo *aux;

    aux=q.delante;

    cout<<"Caracter Prioridad"<<endl;
    cout<<"------------------"<<endl;

    while (aux != aux)
    {
        cout<<" "<<aux->dato<<" | "<<aux->prio<<endl;

        aux = aux->sgte;
    }
    
}

void ordenarPrioridad(struct cola &q)
{
    struct nodo *aux1, *aux2;

    int pAux;
    char cAux;

    aux1 = q.delante;

    while (aux1->sgte != NULL)
    {
        aux2 = aux1->sgte;

        while (aux2 != NULL)
        {
            if(aux1->prio > aux2->prio)
            {
                pAux = aux1->prio;
                cAux = aux1->dato;

                aux1->prio = aux2->prio;
                aux1->dato = aux2->dato;

                aux2->prio = pAux;
                aux2->dato = cAux;
            }

            aux1 = aux2->sgte;
        }
        
        aux1 = aux1->sgte;
    }
    
}

void insertar(struct cola &q, char c, int pr)
{
    encolar(q,c,pr);

    ordenarPrioridad(q);

}

void menu()
{
    cout<<"\n\t COLAS CON PRIORIDAD EN C++ \n\n";
    cout<<" 1. ENCOLAR                          "<<endl;
    cout<<" 2. MOSTRAR                          "<<endl;
    cout<<" 3. SALIR                            "<<endl;

    cout<<"\n Ingrese opción";
}

int main(int argc, char const *argv[])
{
    system("color f1");

    struct cola q;

    q.delante = NULL;
    q.atras = NULL;

    char c;
    int pr, op, x;

    do
    {
        menu();
        cin>>op;

        switch (op)
        {
        case 1:
            cout<<"Ingrese caracter"<<endl;
            cin>>c;
            cout<<"Ingrese prioridad"<<endl;
            cin>>pr;
            
            insertar(q,c,pr);

            break;

        case 2:
            cout<<"Mostrando cola"<<endl;

            if(q.delante == NULL)
                cout<<"Cola vacia"<<endl;
            else
                muestraCola(q);

            break;

        case 3:
            cout<<"Saliendo..."<<endl;
            break;
        
        default:
            break;

        system("pause");
        system("cls");
        }

    } while (op != 3);
    
    return 0;
}
