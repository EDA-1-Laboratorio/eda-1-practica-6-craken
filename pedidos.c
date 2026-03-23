/* Rutinas básicas */
#include "pedidos.h.h"

void initialize(queue *q)
{
    q -> cnt = 0;  // La cuenta de una cola comienza en 0.
    q -> head = NULL; // La cabeza de la cola comienza en Nulo.
    q -> tail = NULL; // La parte trasera de la cola comienza en Nulo.
}

Pedido dequeue(queue *q)
{
    Pedido d;
    elem *p;

    d.id_mesa= q->head->info.id_mesa; // El dato es el que está almacenado en la cabeza de la cola.
    d.platillo=q->head->info.platillo;
    p = q -> head; // El elemento p es la cabeza de la cola.
    q -> head = q -> head -> next; //Cuando desencolamos la cabeza, la nueva cabeza debe ser el siguiente elemento en la cola al que apuntaba la cabeza que desencolamos.
    q -> cnt--; //Bajamos el contador de la cola una unidad.
    free(p); //Liberamos el espacio ocupado por la cabeza desencolada.
    return d; //Vamos a ver lo que estaba guardado en la cabeza desencolada.
}

void enqueue(Pedido d, queue *q)
{
    elem *p;    // Declaramos un apuntador a un espacio donde reservar un objeto de tipo "elem" (elemento de una cola)

    p = malloc(sizeof(elem)); // Encontramos una ubicación en la memoria con suficiente espacio para almacenar un objeto de tipo "elemento" y se la pasamos al apuntador p.

    p -> info.id_mesa = d.id_mesa; // El dato d (una de las componentes del elemento apuntado por p) lo rellenamos con el dato que tenemos en los argumentos de la función "enqueue".
	
	p->info.platillo=d.platillo;
	
    p -> next = NULL; // El apuntador al "siguiente elemento de la cola" lo iniciamos en nulo, porque en este momento no sabemos si la cola está vacía o no.

    if (!empty(q)) {
        q -> tail -> next = p; // Si la cola no estaba vacía, entonces hacemos que su último elemento antes de encolar ahora apunte como "siguiente" al nuevo elemento que estamos encolando.

        q -> tail = p; // Actualizamos el apuntador al último elemento de la cola.
    } 
    else {
        q -> head = q -> tail = p; // Si la cola está vacía, ambos apuntadores head y tail adoptan lo que el apuntador p contiene.
    }
    q -> cnt++; //Aumentamos la cuenta del apuntador
}

Pedido head(const queue *q)
{
    Pedido d;
    if (empty(q)){
		printf("No hay más pedidos\n");
		d.id_mesa=0;
		d.platillo=1;
	}
	else {
		d.id_mesa=q->head->info.id_mesa;
		d.platillo=q->head->info.platillo;
	}
	return d; 
}

Pedido tail(const queue *q)
{
    Pedido d;
    if (empty(q)){
		printf("No hay más pedidos\n");
		d.id_mesa=0;
		d.platillo=1;
	}
	else {
		d.id_mesa=q->tail->info.id_mesa;
		d.platillo=q->tail->info.platillo;
	} 
	return d;
}

boolean empty(const queue *q)
{
    return ((boolean) (q -> cnt == EMPTY));
}

boolean full(const queue *q){
    return ((boolean) (q-> cnt==FULL));
}

int main(void)
{
    int c,i,opcion,mesas;
    int cnt_a = 0;
    Pedido nuevo;
    queue a;

    initialize(&a); // Inicializamos la cola a.

   printf("--------------Bienvenidos al restaurante-------------------\n");
	printf("¿Qué vas a hacer?\n 1 recibir pedido \n 2 servir pedido\n 3 ver pedido siguiente \n 4 ver último pedido\n");
   	scanf("%d",&c);
   	do {
		switch(c){
            case 1:  
            while (c==1){
			if(full(&a)){
				printf("La lista de ordenes está llena");
				printf("¿Qué vas a hacer? \n 2 servir pedido\n 3 ver pedido siguiente \n 4 ver último pedido \n 5 salir\n");
				scanf("%d",&c);
			}
			else{
				printf("¿Qué mesa es?\n");
				scanf("%d",&mesas);
				nuevo.id_mesa=mesas;
				printf("¿Qué desea comer hoy?\n");
				for(i=SOPA1;i<=CHEESECAKE;i++){
					printf("%d: %s\n",i+1,NombresPlatillos[i]);
				}
				scanf("%d",&opcion);
				nuevo.platillo= ((Platillo)opcion+1);
            
				if (!full(&a)) {
					enqueue(nuevo, &a); // Encolamos el id del proceso en la cola a.
				}
				printf("¿Qué vas a hacer?\n 1 recibir nuevo pedido \n 2 servir pedido\n 3 ver pedido siguiente \n 4 ver último pedido \n 5 salir\n");
				scanf("%d",&c);
				}
			}
            break;
            case 2:   
            if (!empty(&a)) {
				Pedido o = dequeue(&a); // Desencolamos un id de proceso de la cola a y lo guardamos en pid.
				printf(" La  TAREA %u es de la mesa %d\n", ++cnt_a, o.id_mesa); // Imprimimos el id del proceso desencolado
				printf("El pedido es %s\n", NombresPlatillos[o.platillo-2]);
			}
			else{
			printf("No hay más pedidos\n");
			}
			printf("¿Qué vas a hacer?\n 1 recibir nuevo pedido \n 2 servir pedido\n 3 ver pedido siguiente \n 4 ver último pedido \n 5 salir\n");
			scanf("%d",&c);
			break;
			case 3:
			while (c==3){
			Pedido o = head(&a);
			printf("El siguiente pedido es en la mesa : %d\n", o.id_mesa);
			printf("El pedido es : %s\n", NombresPlatillos[o.platillo-2]);
			printf("¿Qué vas a hacer?\n 1 recibir nuevo pedido \n 2 servir pedido\n 3 ver pedido siguiente \n 4 ver último pedido \n 5 salir\n");
			scanf("%d",&c);
			}
			break;
			case 4:
			while (c==4){
			Pedido o = tail(&a);
			printf("El último pedido es en la mesa : %d\n", o.id_mesa);
			printf("El pedido es : %s\n", NombresPlatillos[o.platillo-2]);
			printf("¿Qué vas a hacer?\n 1 recibir nuevo pedido \n 2 servir pedido\n 3 ver pedido siguiente \n 4 ver último pedido \n 5 salir\n");
			scanf("%d",&c);
			}
			break;
			default:
			printf("Opción inválida\n");
			break;
        }    
	}while (c!=5);
    return 0;
}
