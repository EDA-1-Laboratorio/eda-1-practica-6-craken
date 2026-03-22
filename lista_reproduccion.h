/* Una implementación de cola mediante una lista ligada */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define    EMPTY    0
#define    FULL     10000

typedef    enum {FALSO, VERDERO}   boolean;

struct data{
    char nombre[100];
    unsigned int ident;
};
typedef struct data            data;

struct elem {          // Un elemento en la cola.
    data         d;
    struct elem  *next;
    struct elem *anterior;
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
void        enqueue(data d, queue *q);          // Encolar (agregar) un elemento (por tail).
data        deque(queue *q);                    // Desencolar (quitar) un elemento (por head). Lo que se devuelve es el elemento apuntado por 'head'.
data        head(const queue *q);               // ¿Cuál es el elemento al inicio de la cola?
data        tail(const queue *q);               // ¿Cuál es el elemento al final de la cola?
boolean     empty(const queue *q);              // ¿La cola está vacía?
boolean     full(const queue *q);               // ¿La cola está llena (10000 elementos)?
void enqueuehead(data d, queue *q);    //mover al principio una cancion
