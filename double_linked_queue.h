/* Una implementación de cola mediante una lista ligada */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define    EMPTY    0
#define    FULL     10000

typedef    unsigned int         data;
typedef    enum {FALSO, VERDERO}   boolean;

struct elem {          // Un elemento en la cola.
    data         d;
    struct elem  *next;
    struct elem  *previous;
};

typedef    struct elem           elem;
struct queue {
    int         cnt;                            // Conteo de los elementos de la cola.
    elem        *head;                          // Apuntador al 'head' de la cola.
    elem        *tail;                          // Apuntador al 'tail' de la cola.
};

typedef     struct queue          queue;        // Definimos el tipo de dato cola (queue, se pronuncia "quiu").

/* Operaciones básicas de colas */
void        initialize(queue *q);               // Inicializar una cola.
void        enqueueHead(data d, queue *q);          // Encolar (agregar) un elemento (por tail).
void        enqueueTail(data d, queue *q);
data        dequeueHead(queue *q);
data        dequeueTail(queue *q);                    // Desencolar (quitar) un elemento (por head). Lo que se devuelve es el elemento apuntado por 'head'.
data        head(const queue *q);               // ¿Cuál es el elemento al inicio de la cola?
data        tail(const queue *q);               // ¿Cuál es el elemento al final de la cola?
boolean     empty(const queue *q);              // ¿La cola está vacía?
boolean     full(const queue *q);               // ¿La cola está llena (10000 elementos)?


void initialize(queue *q)
{
    q -> cnt = 0;  // La cuenta de una cola comienza en 0.
    q -> head = NULL; // La cabeza de la cola comienza en Nulo.
    q -> tail = NULL; // La parte trasera de la cola comienza en Nulo.
}

data dequeueHead(queue *q)
{
    data d;
    elem *p;

    d = q -> head -> d; // El dato es el que está almacenado en la cabeza de la cola.
    p = q -> head; // El elemento p es la cabeza de la cola.
    q -> head = q -> head -> next; //Cuando desencolamos la cabeza, la nueva cabeza debe ser el siguiente elemento en la cola al que apuntaba la cabeza que desencolamos.
    q -> cnt--; //Bajamos el contador de la cola una unidad.
    free(p); //Liberamos el espacio ocupado por la cabeza desencolada.
    return d; //Vamos a ver lo que estaba guardado en la cabeza desencolada.
}

data dequeueTail(queue *q) {
    data d;
    elem *p;

    d = q -> tail -> d; 
    p = q -> tail; 
    q -> tail = q -> tail -> previous; 
    q -> cnt--; 
    free(p); 
    return d; 
}

void enqueueTail(data d, queue *q)
{
    elem *p;    // Declaramos un apuntador a un espacio donde reservar un objeto de tipo "elem" (elemento de una cola)

    p = malloc(sizeof(elem)); // Encontramos una ubicación en la memoria con suficiente espacio para almacenar un objeto de tipo "elemento" y se la pasamos al apuntador p.

    p -> d = d; // El dato d (una de las componentes del elemento apuntado por p) lo rellenamos con el dato que tenemos en los argumentos de la función "enqueue".

    p -> next = NULL; // El apuntador al "siguiente elemento de la cola" lo iniciamos en nulo, porque en este momento no sabemos si la cola está vacía o no.
    p -> previous = NULL;
   

    if (!empty(q)) {
        p -> previous = q -> tail;
        q -> tail -> next = p; // Si la cola no estaba vacía, entonces hacemos que su último elemento antes de encolar ahora apunte como "siguiente" al nuevo elemento que estamos encolando.

        q -> tail = p; // Actualizamos el apuntador al último elemento de la cola.
    } 
    else {
        q -> head = q -> tail = p; // Si la cola está vacía, ambos apuntadores head y tail adoptan lo que el apuntador p contiene.
    }
    q -> cnt++; //Aumentamos la cuenta del apuntador
}

void enqueueHead(data d, queue *q)
{
    elem *p;   

    p = malloc(sizeof(elem)); 

    p -> d = d; 

    p -> next = NULL; 
    p -> previous = NULL;
   

    if (!empty(q)) {
        q -> head -> previous = p;
        p -> next = q -> head

        q -> head = p; 
    } 
    else {
        q -> head = q -> tail = p; // Si la cola está vacía, ambos apuntadores head y tail adoptan lo que el apuntador p contiene.
    }
    q -> cnt++; //Aumentamos la cuenta del apuntador
}

data head(const queue *q)
{
     return q -> head -> d; // <- Completa esta función
}

boolean empty(const queue *q)
{
    return ((boolean) (q -> cnt == EMPTY));
}

boolean full(const queue *q)
{
    return ((boolean) (q -> cnt >= FULL)); // <- Completa esta función
}
