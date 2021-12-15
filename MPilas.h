#include<iostream>
#include<stdlib.h>

using namespace std;

struct NodoPila{
    int Nro;
    struct NodoPila* Sgte;
};
typedef NodoPila *PtrPila;

//------------------------------------------------------------------------------//
/*Nombre del proceso: Push(PtrPila &p, int Valor)
Objetivo:       Ingresa un valor en la cima en una pila
Parametros:     PtrPila &p, la pila en la que queremos ingresar un elemento
                int valor, es el valor que vamos a apilar
Retorna:        La pila con el nuevo valor
Ejemplo:        p=  2
                    5
                valor=9
                Push(p, valor)
                p=  9
                    2
                    5
*/
void Push(PtrPila &p, int Valor)
{
    PtrPila Aux;
    Aux= new(NodoPila);
    Aux->Nro=Valor;
    Aux->Sgte=p;
    p=Aux;
}

//------------------------------------------------------------------------------//
/*Nombre del proceso: Mostrar(PtrPila p)
Objetivo:       Imprime en pantalla los datos dentro de una pila
Parametros:     PtrPila p, la pila que queremos mostrar en pantalla
Retorna:        Muestra en pantalla todos los datos que se encuentran en una pila
Ejemplo:        p=  2
                    5
                (Muestra en pantalla)
                    2
                    5
*/
void Mostrar(PtrPila p)
{
    PtrPila Aux;
    Aux=p;
    while(Aux != NULL)
    {
        cout<<"\t"<<Aux->Nro<<endl;
        Aux=Aux->Sgte;
    }
}
//------------------------------------------------------------------------------//
/*Nombre de la funcion: Pop(PtrPila &p)
Objetivo:       Sacar el valor de la cima de una pila
Parametros:     PtrPila &p, la pila a la que queremos sacar el elemento de la cima
Retorna:        int Num con el valor de la cima. (Deja a la pila sin este valor)
Ejemplo:        p=  7
                    2
                    5
                Pop(p)
                p=  2
                    5
*/
int Pop(PtrPila &p)
{
	int Num;
	PtrPila Aux;
	Aux = p;
	Num = Aux->Nro;
	p = Aux->Sgte;
	delete(Aux);

	return Num;
}
//------------------------------------------------------------------------------//
/*Nombre del proceso: DestruirPila(PtrPila &p)
Objetivo:       Eliminar todos los elementos de una pila
Parametros:     PtrPila &p, la pila a la que queremos eliminar todos los elementos
Retorna:        La pila sin ningun valor
Ejemplo:        p=  7
                    2
                    5
                VaciarCola(q)
                p=
*/
void DestruirPila(PtrPila &p)
{
	PtrPila Aux;
	while(p != NULL)
	{
		Aux = p;
		p = Aux->Sgte;
		delete(Aux);
	}
}
