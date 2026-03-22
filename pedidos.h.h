/* Una implementación de cola mediante una lista ligada */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define    EMPTY    0
#define    FULL     6

typedef enum {SOPA1, SOPA2, CREMA, HAMBURGUESA, FILETE, MILANESA, FRUTA, CUPCAKE, PASTEL, CHEESECAKE}Platillo;
const char *NombresPlatillos[]= {"SOPA1", "SOPA2", "CREMA", "HAMBURGUESA", "FILETE", "MILANESA", "FRUTA", "CUPCAKE", 
"PASTEL","CHEESECAKE"};

typedef    unsigned int         data;
typedef    enum {FALSO, VERDADERO}   boolean;

typedef struct {
    data id_mesa;
    Platillo platillo;
} Pedido;

struct elem {          // Un elemento en la cola.
    Pedido info;
    struct elem  *next;
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
void        enqueue(Pedido d, queue *q);          // Encolar (agregar) un elemento (por tail).
Pedido       dequeue(queue *q);                    // Desencolar (quitar) un elemento (por head). Lo que se devuelve es el elemento apuntado por 'head'.
Pedido       head(const queue *q);               // ¿Cuál es el elemento al inicio de la cola?
Pedido        tail(const queue *q);               // ¿Cuál es el elemento al final de la cola?
boolean     empty(const queue *q);              // ¿La cola está vacía?
boolean     full(const queue *q);               // ¿La cola está llena (10000 elementos)?
