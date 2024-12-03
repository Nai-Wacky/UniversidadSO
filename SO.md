# SO

## Administración de Memoria

 ### 3.1 Política y filosofía
 1. ¿Cuál es la diferencia entre fragmentación interna y externa? Explica
 cómo cada una afecta el rendimiento de la memoria. <br>

 La **fragmentación interna** es cuando dentro de un bloque de memoria hay espacio en el cual no es utilizado, por ejemplo, hay un bloque de memoria de 50 KB y solo se utiliza 40KB. El efecto que tiene es que la memoria es desperdiciada  y no se usa de manera eficiente.<br>
 La **fragmentación externa** es cuando en la memoria los bloques de memoria que se asignan no son contiguos, por ejemplo, a un programa se le asigna los bloques 1, 23, 17, 7, etc. El efecto que este tiene en dispositivos modernos es practicamente insignificante, pero en dispositivos que utilizan discos duros puede a llegar a afectar la rapidez de lectura ya que tendra que hacer muchos movimientos para poder leer todo el programa. <br>

 2. Investiga y explica las políticas de reemplazo de páginas en sistemas
 operativos. ¿Cuál consideras más eficiente y por qué? <br>

 Estos son algoritmos que se usan para decidir que pagina se sacara de la memoria cuando se necesita cargar una nueva.<br>
 * **OPT**: Significa Optimal, lo que significa que la página que no se utilizará durante más tiempo en el futuro es la que se reemplaza.
 * **FIFO**: FIFO significa primero en entrar, primero en salir, lo que significa que la página que ha estado en la memoria por más tiempo es la que se reemplaza.
 * **Segunda opurtinidad**: Funciona mirando al frente de la cola verificando si su bit de referencia está establecido. Si no está configurado, la página se cambia. De lo contrario, se borra el bit referenciado, la página se inserta al final de la cola (como si fuera una página nueva) y se repite este proceso.
 * **NRU**: Este algoritmo favorece a las páginas que fueron usadas recientemente. es un algoritmo que favorece mantener en la memoria las páginas que se han utilizado recientemente.
 * **LRU**: LRU son las siglas de Least-Recently Used, lo que significa que la página a la que se ha accedido menos recientemente es la que se reemplaza.
 * **El mejor**: De manera personal diria que en teoria en OPT , ya que, en teoria suena como el más optimo, pero tiene el gran problema de tener que saber el futuro.

 ### 3.2 Memoria real
 1. Escribe un programa en C o Python que simule la administración de
 memoria mediante particiones fijas. <br>

```c
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

```

 2. Diseña un algoritmo para calcular qué procesos pueden ser asignados
 a un sistema con memoria real limitada utilizando el algoritmo de
 "primera cabida". <br>

    * Leer en tamanño total de la memoria
    * Leer el tamaño total de las particiones
    * Leer el tamaño total de los procesos
    * Buscar la partición con el tamaño correcta para cada proceso
    * Si se encuantra, verficar si la partición esta ocupada o libre
    * Si se encuentra, se asigna el proceso a esa partición y marcar la partición como ocupada, en caso de que no se encuentre una partición indicar que no se pudo cargar el proceso debido a que se encontro una particion

 ### 3.3 Organización de memoria virtual
 1. Investiga y explica el concepto de "paginación" y "segmentación".
 ¿Cuáles son las ventajas y desventajas de cada técnica? <br>

 La paginación y la segmentación son técnicas de gestión de memoria que se diferencian en la forma en que distribuyen el espacio de direccionamiento de un proceso: <br>

 * **Paginación**: En el método de paginación, la memoria principal se divide en pequeños bloques de direcciones físicas de tamaño fijo, que se denominan tramas. 

    * Ventajas:
        * Elimina la fragmetación externa  
        * Fácil de usar 
        * El intercambio es fácil entre páginas y marcos de página del mismo tamaño
    * Desventajas: 
        * Puede causar fragmentación interna 
        * Las tablas de páginas consumen memoria adicional

 * **Segmentación**: es un método de control de memoria utilizado por los sistemas operativos para dividir el área de dirección lógica de un sistema en segmentos de tamaño variable.
    * Ventajas: <br> 
        * Elimina la fragmentación interna
        * Ofrece flexibilidad al programador para organizar el espacio de direcciones
        * Usa menos memoria que la paginación
    * Desventajas: <br> 
        * Puede generar fragmentación externa
        * Esta técnica de administración de memoria es demasiado costosa 

 2. Escribe un programa que simule una tabla de páginas para procesos
 con acceso aleatorio a memoria virtual. <br>

 ```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PAGINAS 20
#define TAM_PAGINA 256
#define MAX_PROCESOS 5

typedef struct {
    int procesoID;
    int paginaID;
} Pagina;

typedef struct {
    int id;
    int numPaginas;
} Proceso;

void inicializarMemoria(Pagina *memoria) {
    for (int i = 0; i < NUM_PAGINAS; i++) {
        memoria[i].procesoID = -1;
        memoria[i].paginaID = -1;
    }
}

void mostrarEstadoMemoria(Pagina *memoria) {
    printf("\nEstado de la memoria:\n");
    printf("Marco\tProceso\tPagina\n");
    for (int i = 0; i < NUM_PAGINAS; i++) {
        if (memoria[i].procesoID == -1) {
            printf("%d\tLibre\t-\n", i);
        } else {
            printf("%d\tP%d\t%d\n", i, memoria[i].procesoID, memoria[i].paginaID);
        }
    }
}

void crearProceso(Proceso *procesos, int *numProcesos) {
    if (*numProcesos >= MAX_PROCESOS) {
        printf("No se pueden crear mas procesos. Limite alcanzado.\n");
        return;
    }

    Proceso nuevoProceso;
    nuevoProceso.id = *numProcesos;
    nuevoProceso.numPaginas = 0;
    procesos[*numProcesos] = nuevoProceso;
    (*numProcesos)++;
    printf("Proceso P%d creado.\n", nuevoProceso.id);
}

void asignarPaginas(Pagina *memoria, Proceso *procesos, int numProcesos) {
    int procesoID, numPaginas;

    printf("Ingrese el ID del proceso: ");
    scanf("%d", &procesoID);

    if (procesoID < 0 || procesoID >= numProcesos) {
        printf("Proceso no valido.\n");
        return;
    }

    printf("Ingrese el numero de paginas a asignar: ");
    scanf("%d", &numPaginas);

    int paginasAsignadas = 0;
    for (int i = 0; i < NUM_PAGINAS && paginasAsignadas < numPaginas; i++) {
        if (memoria[i].procesoID == -1) {
            memoria[i].procesoID = procesoID;
            memoria[i].paginaID = procesos[procesoID].numPaginas++;
            paginasAsignadas++;
        }
    }

    if (paginasAsignadas < numPaginas) {
        printf("No hay suficiente memoria disponible. Solo se asignaron %d paginas.\n", paginasAsignadas);
    } else {
        printf("Se asignaron %d paginas al proceso P%d.\n", paginasAsignadas, procesoID);
    }
}

void liberarPaginas(Pagina *memoria, Proceso *procesos, int numProcesos) {
    int procesoID;

    printf("Ingrese el ID del proceso: ");
    scanf("%d", &procesoID);

    if (procesoID < 0 || procesoID >= numProcesos) {
        printf("Proceso no valido.\n");
        return;
    }

    int paginasLiberadas = 0;
    for (int i = 0; i < NUM_PAGINAS; i++) {
        if (memoria[i].procesoID == procesoID) {
            memoria[i].procesoID = -1;
            memoria[i].paginaID = -1;
            paginasLiberadas++;
        }
    }

    procesos[procesoID].numPaginas = 0;
    printf("Se liberaron %d paginas del proceso P%d.\n", paginasLiberadas, procesoID);
}

int main() {
    Pagina memoria[NUM_PAGINAS];
    Proceso procesos[MAX_PROCESOS];
    int numProcesos = 0;

    inicializarMemoria(memoria);

    int opcion;
    do {
        printf("1. Crear proceso\n");
        printf("2. Asignar paginas a proceso\n");
        printf("3. Liberar paginas de proceso\n");
        printf("4. Mostrar estado de la memoria\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                crearProceso(procesos, &numProcesos);
                break;
            case 2:
                asignarPaginas(memoria, procesos, numProcesos);
                break;
            case 3:
                liberarPaginas(memoria, procesos, numProcesos);
                break;
            case 4:
                mostrarEstadoMemoria(memoria);
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no válida.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}

 ```

 ### 3.4 Administración de memoria virtual
 1. Escribe un código que implemente el algoritmo de reemplazo de página "Least Recently Used" (LRU).

```c

```

 2. Diseña un diagrama que represente el proceso de traducción de direcciones virtuales a físicas en un sistema con memoria virtual. <br>

 [Diagrama de traducción](https://photos.app.goo.gl/XcRAhL3choD3PiXx9)

 ### Integración
 1. Analiza un sistema operativo moderno (por ejemplo, Linux o Windows)
 e identifica cómo administra la memoria virtual.<br>

**Windows**: La memoria virtual vendria ser una parte del almacenamiento que toma windows en caso de que un programa pesado se este corriendo, de esta forma no se consume mucha memoria RAM y permite que el sistema siga funcionando. Windows suele asignar de forma automatica cuanta memoria virtual va a tomar, pero tambien se puede configurar de forma manual. 

 2. Realiza una simulación en cualquier lenguaje de programación que
 emule el swapping de procesos en memoria virtual.<br>

```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANO_MEMORIA 1000
#define TAMANO_DISCO 5000
#define MAX_PROCESOS 10

typedef struct {
    int id;
    int tamano;
    int enMemoria;
} Proceso;

Proceso procesos[MAX_PROCESOS];
int memoriaDisponible = TAMANO_MEMORIA;
int discoDisponible = TAMANO_DISCO;
int numProcesos = 0;

void mostrarEstado() {
    printf("\nEstado del sistema:\n");
    printf("Memoria disponible: %d KB\n", memoriaDisponible);
    printf("Disco disponible: %d KB\n", discoDisponible);
    printf("Procesos en el sistema:\n");
    printf("ID\tTamaño\tUbicacion\n");
    for (int i = 0; i < numProcesos; i++) {
        printf("%d\t%d KB\t%s\n", procesos[i].id, procesos[i].tamano, 
               procesos[i].enMemoria ? "Memoria" : "Disco");
    }
    printf("\n");
}

void agregarProceso() {
    if (numProcesos >= MAX_PROCESOS) {
        printf("Limite alcanzado. No se pueden agregar mas procesos. \n");
        return;
    }

    int tamano;
    printf("Ingrese el tamaño del proceso (KB): ");
    scanf("%d", &tamano);

    if (tamano > memoriaDisponible && tamano > discoDisponible) {
        printf("No hay suficiente espacio para este proceso en memoria ni en disco.\n");
        return;
    }

    procesos[numProcesos].id = numProcesos;
    procesos[numProcesos].tamano = tamano;

    if (tamano <= memoriaDisponible) {
        procesos[numProcesos].enMemoria = 1;
        memoriaDisponible -= tamano;
        printf("Proceso P%d cargado en memoria.\n", numProcesos);
    } else {
        procesos[numProcesos].enMemoria = 0;
        discoDisponible -= tamano;
        printf("Proceso P%d almacenado en disco.\n", numProcesos);
    }

    numProcesos++;
}

void liberarProceso() {
    int id;
    printf("Ingrese el ID del proceso a liberar: ");
    scanf("%d", &id);

    if (id < 0 || id >= numProcesos || procesos[id].tamano == 0) {
        printf("Proceso no valido.\n");
        return;
    }

    if (procesos[id].enMemoria) {
        memoriaDisponible += procesos[id].tamano;
    } else {
        discoDisponible += procesos[id].tamano;
    }

    printf("Proceso P%d liberado.\n", id);
    procesos[id].tamano = 0;
}

void realizarSwapping() {
    for (int i = 0; i < numProcesos; i++) {
        if (!procesos[i].enMemoria && procesos[i].tamano <= memoriaDisponible) {
            memoriaDisponible -= procesos[i].tamano;
            discoDisponible += procesos[i].tamano;
            procesos[i].enMemoria = 1;
            printf("Proceso P%d cargado del disco a memoria.\n", i);
        }
    }
}

int main() {
    int opcion;

    do {
        printf("\nMemoria disponible: %d ;Disco disponible: %d KB\n", memoriaDisponible, discoDisponible);
        printf("1. Agregar proceso\n");
        printf("2. Liberar proceso\n");
        printf("3. Realizar swapping\n");
        printf("4. Mostrar estado del sistema\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarProceso();
                break;
            case 2:
                liberarProceso();
                break;
            case 3:
                realizarSwapping();
                break;
            case 4:
                mostrarEstado();
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no valida.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}

```

 ## Administración de Entrada/Salida

 ### 4.1 Dispositivos y manejadores de dispositivos
 1. Explica la diferencia entre dispositivos de bloque y dispositivos de
 carácter. Da un ejemplo de cada uno. <br>

* **De bloque**: Son aquellos dispositivos que manejan datos en bloques de tamaño fijo, ejemplo, Un disco duro (HDD) o una unidad de estado solido (SSD).
* **De caracter**: Son aquellos que envian datos caracter por caracter, ejemplo, un raton o un teclado.

 2. Diseña un programa que implemente un manejador de dispositivos sencillo para un dispositivo virtual de entrada.<br>

 ```c
 #include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool interrupcion;
} Dispositivo;

typedef struct {
    int estado;
    int parametros;
} TablaEstadosDispositivos;

Dispositivo dispositivoEntrada;
TablaEstadosDispositivos tablaEstados;
bool interrupcionActiva = false;

void operacionES();
void atenderInterrupcion();

void manejadorDispositivo(Dispositivo dispositivo) {
    while (tablaEstados.estado == 1) {
        printf("Dispositivo ocupado\n");
        sleep(1);
        printf("Espere...\n");
        sleep(2);
        tablaEstados.estado = 0;
    }

    if (tablaEstados.estado == 0) {
        tablaEstados.estado = 1;
        printf("Info: dispositivo libre\n");
        operacionES();
        atenderInterrupcion();
    }
}

void operacionES() {
    printf("Iniciando operacion de E/S...\n");
    sleep(2);
    tablaEstados.estado = 2;
    printf("Operacion de E/S cargada en la tabla de estados.\n");
}

void atenderInterrupcion() {
    if (tablaEstados.estado == 2) {
        printf("Interrupcion\n");
        printf("Atendiendo interrupcion\n");
        tablaEstados.estado = 0;
    }
}

int main() {
    dispositivoEntrada.interrupcion = false;
    tablaEstados.estado = 1;
    tablaEstados.parametros = 0;

    while (true) {
        printf("\n");
        manejadorDispositivo(dispositivoEntrada);
        sleep(3);
    }

    return 0;
}

 ```

 ### 4.2 Mecanismos y funciones de los manejadores de dispositivos
 1. Investiga qué es la interrupción por E/S y cómo la administra el sistema operativo. Escribe un ejemplo en pseudocódigo para simular este proceso.<br>

 **Interrupcion por E/S**: Este es un evento en el cual se le avisa al procesador que un dispositivo E/S tiene datos que necesita tratar. <br>
 **Como lo administra el SO**: Estas se manejan de forma que el sistema operativo primero analiza la interrupción para despues ser atendida por la rutina mas adecuada para atenderla. Una vez atendida, se reanuda la ejecución.

 ```
interrupcion_e_s() {
    guardar_estado();
    manejar_solicitud_e_s();
    restaurar_estado();
}

manejar_solicitud_e_s() {
    // Código para atender la E/S
    leer_datos();
    procesar_datos();
    escribir_datos();
}

guardar_estado() {
    // Código para guardar el estado actual del programa
}

restaurar_estado() {
    // Código para restaurar el estado del programa
}

simular_interrupcion() {
    if (dispositivo_e_s_necesita_atencion()) {
        interrupcion_e_s();
    }
}

main() {
    while (true) {
        ejecutar_tarea();
    }
    while (true) {
        simular_interrupcion();
    }
}

 ```

 2. Escribe un programa que utilice el manejo de interrupciones en un sistema básico de simulación.

 ```c
 #include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool interrupcion;
} Dispositivo;

typedef struct {
    int estado; 
    int parametros; 
} TablaEstadosDispositivos;

Dispositivo dispositivoEntrada;
TablaEstadosDispositivos tablaEstados;
bool interrupcionActiva = false;

void operacionES();
void atenderInterrupcion();

void manejadorDispositivo(Dispositivo dispositivo) {
    while (tablaEstados.estado == 1) {
        printf("Dispositivo ocupado\n");
        sleep(1);
        printf("Espere...\n");
        sleep(2);
        tablaEstados.estado = 0;
    }

    if (tablaEstados.estado == 0) {
        tablaEstados.estado = 1;
        printf("Info: dispositivo libre\n");
        operacionES();
        atenderInterrupcion();
    }
}

void operacionES() {
    printf("Iniciando operación de E/S...\n");
    sleep(2);
    tablaEstados.estado = 2;
    printf("Operación de E/S cargada en la tabla de estados.\n");
}

void atenderInterrupcion() {
    if (tablaEstados.estado == 2) {
        printf("Interrupción\n");
        printf("Atendiendo interrupción\n");
        tablaEstados.estado = 0;
    }
}

int main() {
    dispositivoEntrada.interrupcion = false;
    tablaEstados.estado = 1;
    tablaEstados.parametros = 0;

    while (true) {
        printf("\n");
        manejadorDispositivo(dispositivoEntrada);
        sleep(3);
    }

    return 0;
}

 ```

 ### 4.3 Estructuras de datos para manejo de dispositivos
 1. Investiga y explica qué es una cola de E/S. Diseña una simulación de una cola con prioridad.<br>

 **Cola de E/S**: son contenedores para las solicitudes de E/S que recibe un controlador. Cada controlador puede crear una o varias colas de E/S para cada dispositivo. Cada solicitud en la cola representa una operación de E/S que debe realizarse, como leer o escribir datos en un disco duro, enviar datos a una impresora, o recibir datos de un teclado.

 ```c++
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
 ```

 2. Escribe un programa que simule las operaciones de un manejador de dispositivos utilizando una tabla de estructuras.<br>

 ```c
 #include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool interrupcion;
} Dispositivo;

typedef struct {
    int estado;
    int parametros;
} TablaEstadosDispositivos;

Dispositivo dispositivoEntrada;
TablaEstadosDispositivos tablaEstados;
bool interrupcionActiva = false;

void operacionES();
void atenderInterrupcion();

void manejadorDispositivo(Dispositivo dispositivo) {
    while (tablaEstados.estado == 1) {
        printf("Dispositivo ocupado\n");
        sleep(1);
        printf("Espere...\n");
        sleep(2);
        tablaEstados.estado = 0;
    }

    if (tablaEstados.estado == 0) {
        tablaEstados.estado = 1;
        printf("Info: dispositivo libre\n");
        operacionES();
        atenderInterrupcion();
    }
}

void operacionES() {
    printf("Iniciando operacion de E/S...\n");
    sleep(2);
    tablaEstados.estado = 2;
    printf("Operación de E/S cargada en la tabla de estados.\n");
}

void atenderInterrupcion() {
    if (tablaEstados.estado == 2) {
        printf("Interrupcion\n");
        printf("Atendiendo interrupcion\n");
        tablaEstados.estado = 0;
    }
}

int main() {
    dispositivoEntrada.interrupcion = false;
    tablaEstados.estado = 1;
    tablaEstados.parametros = 0;

    while (true) {
        printf("\n");
        manejadorDispositivo(dispositivoEntrada);
        sleep(3);
    }

    return 0;
}

 ```

 ### 4.4 Operaciones de Entrada/Salida
 1. Diseña un flujo que describa el proceso de lectura de un archivo desde un disco magnético. Acompáñalo con un programa básico que simule el proceso.<br>

* El flujo es el siguiente:
    * Envio de la solicitud de lectura.
    * Busqueda del archivo a leer.
    * Posicionar el cabezal.
    * Leer el sector.
    * Tranferir los datos leidos.

```c
 
 #include <stdio.h>
#include <stdlib.h>

#define TAMANO_DISCO 100
#define TAMANO_BLOQUE 512

typedef struct {
    char nombre[50];
    int inicio;
    int tamano;
} Archivo;

Archivo disco[TAMANO_DISCO];

void inicializarDisco() {
    for (int i = 0; i < TAMANO_DISCO; i++) {
        disco[i].inicio = -1;
    }

    strcpy(disco[0].nombre, "archivo1.txt");
    disco[0].inicio = 0;
    disco[0].tamano = 10;

    strcpy(disco[1].nombre, "file.txt");
    disco[1].inicio = 10;
    disco[1].tamano = 15;

    printf("Disco inicializado con archivos de prueba.\n");
}

Archivo* buscarArchivo(const char* nombre) {
    for (int i = 0; i < TAMANO_DISCO; i++) {
        if (disco[i].inicio != -1 && strcmp(disco[i].nombre, nombre) == 0) {
            return &disco[i];
        }
    }
    return NULL;
}

void moverCabezal(int sector) {
    printf("Moviendo cabezal al sector %d...\n", sector);
    usleep(500000);
}

void transferirDatos(int inicio, int tamano) {
    printf("Transfiriendo datos desde el sector %d (tamaño: %d bloques)...\n", inicio, tamano);
    usleep(tamano * 100000); 
    printf("Transferencia completa.\n");
}

void leerArchivo(const char* nombre) {
    Archivo* archivo = buscarArchivo(nombre);
    if (archivo == NULL) {
        printf("Archivo no encontrado.\n");
        return;
    }

    moverCabezal(archivo->inicio);
    transferirDatos(archivo->inicio, archivo->tamano);
    printf("Lectura del archivo '%s' completada.\n", archivo->nombre);
}

int main() {
    int opcion;
    char nombreArchivo[50];

    inicializarDisco();

    do {
        printf("\n----MENU----\n");
        printf("Los unicos dos archivos que estan son archivo1.txt y file.txt\n");
        printf("1. Leer archivo\n");
        printf("2. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                printf("Ingrese el nombre del archivo: ");
                fgets(nombreArchivo, 50, stdin);
                nombreArchivo[strcspn(nombreArchivo, "\n")] = '\0';
                leerArchivo(nombreArchivo);
                break;
            case 2:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 2);

    return 0;
}

 ```

 2. Implementa un programa en Python, C o java que realice operaciones de entrada/salida asíncronas usando archivos.

 ```c
 
 
 ```

 ### Integración
 1. Escribe un programa que implemente el algoritmo de planificación de discos "Elevator (SCAN)".

 ```c
 
 #include <stdio.h>
#include <stdlib.h>

void ordenar(int *array, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void scan(int *solicitudes, int n, int cabezal, int direccion, int limiteDisco) {
    int *izquierda = (int *)malloc(n * sizeof(int));
    int *derecha = (int *)malloc(n * sizeof(int));
    int l = 0, r = 0;

    for (int i = 0; i < n; i++) {
        if (solicitudes[i] < cabezal) {
            izquierda[l++] = solicitudes[i];
        } else {
            derecha[r++] = solicitudes[i];
        }
    }

    ordenar(izquierda, l);
    ordenar(derecha, r);

    printf("\nOrden de acceso a las solicitudes:\n");

    if (direccion == 1) {
        for (int i = 0; i < r; i++) {
            printf("%d -> ", derecha[i]);
            cabezal = derecha[i];
        }
        printf("Fin -> ");

        
        for (int i = l - 1; i >= 0; i--) {
            printf("%d -> ", izquierda[i]);
            cabezal = izquierda[i];
        }
    } else { 
        for (int i = l - 1; i >= 0; i--) {
            printf("%d -> ", izquierda[i]);
            cabezal = izquierda[i];
        }
        printf("Inicio -> ");

        
        for (int i = 0; i < r; i++) {
            printf("%d -> ", derecha[i]);
            cabezal = derecha[i];
        }
    }

    printf("Fin\n");

    free(izquierda);
    free(derecha);
}

int main() {
    int n, cabezal, direccion, limiteDisco;

    printf("Ingrese el número de solicitudes: ");
    scanf("%d", &n);

    int *solicitudes = (int *)malloc(n * sizeof(int));

    printf("Ingrese las posiciones de las solicitudes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &solicitudes[i]);
    }

    printf("Ingrese la posición inicial del cabezal: ");
    scanf("%d", &cabezal);

    printf("Ingrese la dirección del movimiento (1 para derecha (1 -> 2 -> 3), 0 para izquierda (3 -> 2 -> 1)): ");
    scanf("%d", &direccion);

    printf("Ingrese el límite del disco: ");
    scanf("%d", &limiteDisco);

    scan(solicitudes, n, cabezal, direccion, limiteDisco);

    free(solicitudes);

    return 0;
}


 ```

 2. Diseña un sistema que maneje múltiples dispositivos simulados (disco duro, impresora, teclado) y muestra cómo se realiza la comunicación entre ellos.<br>

 ```c
 
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define OPERACION_LECTURA 1
#define OPERACION_ESCRITURA 2
#define OPERACION_IMPRESION 3
#define OPERACION_ENTRADA 4

typedef struct {
    int tipoDispositivo;
    int operacion;
    char datos[256];
} Solicitud;

#define TAMANO_COLA 10
Solicitud cola[TAMANO_COLA];
int inicio = 0, fin = 0;

int esColaLlena() {
    return (fin + 1) % TAMANO_COLA == inicio;
}

int esColaVacia() {
    return inicio == fin;
}

void agregarSolicitud(Solicitud solicitud) {
    if (esColaLlena()) {
        printf("Error: La cola de solicitudes está llena.\n");
        return;
    }
    cola[fin] = solicitud;
    fin = (fin + 1) % TAMANO_COLA;
}

Solicitud obtenerSolicitud() {
    Solicitud solicitud = {0, 0, ""};
    if (esColaVacia()) {
        printf("Error: La cola de solicitudes está vacía.\n");
    } else {
        solicitud = cola[inicio];
        inicio = (inicio + 1) % TAMANO_COLA;
    }
    return solicitud;
}

void manejarDisco(Solicitud solicitud) {
    if (solicitud.operacion == OPERACION_LECTURA) {
        printf("[Disco Duro] Leyendo datos: %s\n", solicitud.datos);
    } else if (solicitud.operacion == OPERACION_ESCRITURA) {
        printf("[Disco Duro] Escribiendo datos: %s\n", solicitud.datos);
    }
}

void manejarImpresora(Solicitud solicitud) {
    if (solicitud.operacion == OPERACION_IMPRESION) {
        printf("[Impresora] Imprimiendo: %s\n", solicitud.datos);
    }
}

void manejarTeclado(Solicitud solicitud) {
    if (solicitud.operacion == OPERACION_ENTRADA) {
        printf("[Teclado] Entrada recibida: %s\n", solicitud.datos);
    }
}

void procesarSolicitudes() {
    while (!esColaVacia()) {
        Solicitud solicitud = obtenerSolicitud();
        switch (solicitud.tipoDispositivo) {
            case 1:
                manejarDisco(solicitud);
                break;
            case 2:
                manejarImpresora(solicitud);
                break;
            case 3:
                manejarTeclado(solicitud);
                break;
            default:
                printf("[Controlador] Dispositivo desconocido.\n");
        }
        sleep(1);
    }
}

int main() {
    int opcion;

    do {
        printf("\n--- MENU---\n");
        printf("1. Agregar solicitud al Disco Duro\n");
        printf("2. Agregar solicitud a la Impresora\n");
        printf("3. Agregar solicitud al Teclado\n");
        printf("4. Procesar solicitudes\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        Solicitud solicitud;
        switch (opcion) {
            case 1:
                solicitud.tipoDispositivo = 1;
                printf("Ingrese operación (1: Leer, 2: Escribir): ");
                scanf("%d", &solicitud.operacion);
                getchar();
                printf("Ingrese datos: ");
                fgets(solicitud.datos, 256, stdin);
                solicitud.datos[strcspn(solicitud.datos, "\n")] = '\0';
                agregarSolicitud(solicitud);
                break;
            case 2:
                solicitud.tipoDispositivo = 2;
                solicitud.operacion = OPERACION_IMPRESION;
                getchar();
                printf("Ingrese datos para imprimir: ");
                fgets(solicitud.datos, 256, stdin);
                solicitud.datos[strcspn(solicitud.datos, "\n")] = '\0';
                agregarSolicitud(solicitud);
                break;
            case 3:
                solicitud.tipoDispositivo = 3;
                solicitud.operacion = OPERACION_ENTRADA;
                getchar();
                printf("Ingrese datos desde el teclado: ");
                fgets(solicitud.datos, 256, stdin);
                solicitud.datos[strcspn(solicitud.datos, "\n")] = '\0';
                agregarSolicitud(solicitud);
                break;
            case 4:
                procesarSolicitudes();
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 5);

    return 0;
}


 ```

 ## Avanzados
 1. Explica cómo los sistemas operativos modernos optimizan las operaciones de entrada/salida con el uso de memoria caché.<br>

La memoria cache es la memoria mas rapida a la que tiene acceso el SO debido a la cercania que esta tiene al procesador. Dentro de estas memorias se suelen almacenar archivos a los que suelen acceder de forma frecuente, de esta forma permite que las solicitudes de escritura se atiendan de forma mas rapida; Esto mejora la eficiencia de las operaciones porque se acceden de forma mas rapida que, por ejemplo, accediendo a los dispositivos de almacenamiento.

--- 

<div align="center">

# Markdown
### Nombre: Ricardo Hernández Urbina 
### Num. Control: 22121304
### Profesor: Jesus Eduardo Alcaraz Chavez