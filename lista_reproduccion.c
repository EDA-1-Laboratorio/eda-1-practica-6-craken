/* Rutinas básicas */
#include "lista_reproduccion.h"

void initialize(queue *q)
{
    q -> cnt = 0;  // La cuenta de una cola comienza en 0.
    q -> head = NULL; // La cabeza de la cola comienza en Nulo.
    q -> tail = NULL; // La parte trasera de la cola comienza en Nulo.
}

data dequeue(queue *q)
{
    data d;
    elem *p;

    d = q -> head -> d; // El dato es el que está almacenado en la cabeza de la cola.
    p = q -> head; // El elemento p es la cabeza de la cola.
    q -> head = q -> head -> next; //Cuando desencolamos la cabeza, la nueva cabeza debe ser el siguiente elemento en la cola al que apuntaba la cabeza que desencolamos.
    
    if(q->head != NULL){
        q->head->anterior=NULL;
    }else{
        q->tail=NULL;
    }
    
    q -> cnt--; //Bajamos el contador de la cola una unidad.
    free(p); //Liberamos el espacio ocupado por la cabeza desencolada.
    return d; //Vamos a ver lo que estaba guardado en la cabeza desencolada.
}

void enqueue(data d, queue *q)
{
    elem *p;    // Declaramos un apuntador a un espacio donde reservar un objeto de tipo "elem" (elemento de una cola)

    p = malloc(sizeof(elem)); // Encontramos una ubicación en la memoria con suficiente espacio para almacenar un objeto de tipo "elemento" y se la pasamos al apuntador p.

    p -> d = d; // El dato d (una de las componentes del elemento apuntado por p) lo rellenamos con el dato que tenemos en los argumentos de la función "enqueue".

    p -> next = NULL; // El apuntador al "siguiente elemento de la cola" lo iniciamos en nulo, porque en este momento no sabemos si la cola está vacía o no.

    if (!empty(q)) {
        p->anterior=q->tail; 
        
        q -> tail -> next = p; // Si la cola no estaba vacía, entonces hacemos que su último elemento antes de encolar ahora apunte como "siguiente" al nuevo elemento que estamos encolando.

        q -> tail = p; // Actualizamos el apuntador al último elemento de la cola.
    } 
    else {
        p->anterior=NULL;
        
        q -> head = q -> tail = p; // Si la cola está vacía, ambos apuntadores head y tail adoptan lo que el apuntador p contiene.
    }
    q -> cnt++; //Aumentamos la cuenta del apuntador
}
//agregar canciones al inicio
void enqueuehead(data d, queue *q){
    elem *p=malloc(sizeof(elem));
    p->d=d;
    p->anterior=NULL;
    if(!empty(q)){
        p->next=q->head;
        q->head->anterior=p;
        q->head=p;
    }else{
        p->next=NULL;
        q->head=q->tail=p;
    }
    q->cnt++;
}

data head(const queue *q)
{
    return(q->head->d);// <- Completa esta función
}

boolean empty(const queue *q)
{
    return ((boolean) (q -> cnt == EMPTY));
}

boolean full(const queue *q)
{
    return(boolean)(q->cnt==FULL); // <- Completa esta función
}

int main(void)
{
    int c;
    data cancion;
    queue reproduccion;
    initialize(&reproduccion);
    
    printf("Lista de reproduccion, ¿Que desea hacer?\n");
    printf("1)Agregar una cancion al principio\n");
    printf("2)Agregar una cancion al final\n");
    printf("Salir del menu y ver lista de reproduccion, Ctrl+D\n");
    while((c=getchar()) !=EOF){
        switch(c){
            case '1':
            printf("Identificador de la cancion: ");
            scanf("%u", &cancion.ident);
            while(getchar() != '\n');
            
            printf("Nombre de la cancion: ");
            scanf("%[^\n]", &cancion.nombre);
            while(getchar() != '\n');
            
            if(!full(&reproduccion)){
                enqueuehead(cancion, &reproduccion);
                printf("Se ha agregado la cancion con exito\n");
            }
            break;
            
            case '2':
            printf("Identificador de la cancion: ");
            scanf("%u", &cancion.ident);
            while(getchar() != '\n');
            
            printf("Nombre de la cancion: ");
            scanf("%[^\n]", &cancion.nombre);
            while(getchar() != '\n');
            
            if(!full(&reproduccion)){
                enqueue(cancion, &reproduccion);
                printf("Se ha agregado la cancion con exito\n");
            }
            break;
            default:
            printf("Debes seleccionar alguna de las opciones\n");
        }   
        printf("\n1)Agregar una cancion al principio\n");
        printf("2)Agregar una cancion al final\n");
        printf("Salir del menu y ver lista de reproduccion, Ctrl+D\n");
        
    }
    printf("\nLista de reproduccion\n");
    if(empty(&reproduccion)) {
        printf("No se agregado nada a la lista.\n");
    }

    while(!empty(&reproduccion)) {
        cancion = dequeue(&reproduccion);
        printf("Reproduciendo: [%u] %s\n", cancion.ident, cancion.nombre);
    }
    return 0;
}
