#include<stdlib.h>
#include<iostream>

using namespace std;

struct Nodo
{
    int Nro;
    struct Nodo *Sgte;
};
struct Cola
{
    Nodo *Delante;
    Nodo *Atras;
};
//------------------------------------------------------------------------------//
/*Nombre del proceso: Encolar(struct Cola &q, int valor)
Objetivo:       Ingresa un valor a lo ultimo en una cola
Parametros:     struct Cola &q, la cola en la que queremos ingresar un elemento
                int valor, es el valor que vamos a encolar
Retorna:        La cola con el nuevo valor
Ejemplo:        q={2,7,4}
                valor=9
                Encolar(q, valor)
                q={2,7,4,9}
*/
void Encolar(struct Cola &q, int valor)
{
    struct Nodo *Aux= new(struct Nodo);
    Aux->Nro = valor;
    Aux->Sgte=NULL;
    if(q.Delante == NULL)
        q.Delante=Aux;
    else
        (q.Atras)->Sgte=Aux;
    q.Atras=Aux;
}
//------------------------------------------------------------------------------//
/*Nombre de la funcion: Desencolar(struct Cola &q)
Objetivo:       Sacar el primer valor de una cola
Parametros:     struct Cola &q, la cola a la que queremos sacar el primer elemento
Retorna:        int num con el primer valor. (Deja a la cola sin este valor)
Ejemplo:        q={2,7,4}
                Desencolar(q)
                q={7,4}
*/
int Desencolar(struct Cola &q)
{
    int num;
    struct Nodo *Aux;

    Aux=q.Delante;
    num=Aux->Nro;
    q.Delante=(q.Delante)->Sgte;
    delete(Aux);
    return num;
}

//------------------------------------------------------------------------------//
/*Nombre del proceso: MostrarCola(struct Cola q)
Objetivo:       Imprime en pantalla los datos dentro de una cola
Parametros:     struct Cola q, la cola que queremos mostrar en pantalla
Retorna:        Muestra en pantalla todos los datos que se encuentran en una cola
Ejemplo:        q={2,7,4,20,15)
                (Muestra en pantalla)
                2 7 4 20 15
*/
void MostrarCola(struct Cola q)
{
    struct Nodo *Aux;
    Aux=q.Delante;
    while(Aux!=NULL)
    {
        cout<<"     "<<Aux->Nro;
        Aux=Aux->Sgte;
    }
}
//------------------------------------------------------------------------------//
/*Nombre del proceso: VaciarCola(struct Cola &q)
Objetivo:       Eliminar todos los elementos de una cola
Parametros:     struct Cola &q, la cola a la que queremos eliminar todos los elementos
Retorna:        La cola sin ningun valor
Ejemplo:        q={2,7,4}
                VaciarCola(q)
                q={}
*/
void VaciarCola(struct Cola &q)
{
    struct Nodo *Aux;
    while(q.Delante!=NULL)
    {
        Aux=q.Delante;
        q.Delante=Aux->Sgte;
        delete(Aux);
    }
    q.Delante = NULL;
    q.Atras = NULL;
}
//------------------------------------------------------------------------------//
/*Nombre de la funcion: Contar(struct Cola q)
Objetivo:       Cuenta cuantos elementos tiene la cola
Parametros:     struct Cola &q, la cola a la que queremos contar la cantidad de elementos
Retorna:        int num, con el numero de elementos que tiene la cola
Ejemplo:        q={2,7,4}
                Contar(q)=3
*/

int Contar(struct Cola q)
{
    int num;
    struct Nodo *Aux;
    Aux=q.Delante;
    for(num=0; Aux!= NULL; num++)
        Aux=Aux->Sgte;
    return num;
}
