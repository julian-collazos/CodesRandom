#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;
/*Autores:  Leonardo Trejos Buenaventura
            Julian Esteban Collazos Toro
*/
//---------------------------------
struct Nodo{
	int Nro;
	struct Nodo *Sgte;
};

struct Tlista{
	Nodo *Primero;
	Nodo *Segundo;
};
//------------------------------------------------------
/*
Nombre de la función: InsertarNodo()

Objetivo:   Ingresar a la lista los numeros del 1 al 40

Parámetros: Tlista &lista, la lista de la que vamos a eliminar el numero
			int Dato, Es el numero que se va a ingresar en la lista
retorna =   La lista con el numero ingresado
Ejemplo:    while(i <= 3)
            {
                InsertarNodo(lista,i);
                i++;
            }
            lista = {1,2,3}
*/
void InsertarNodo(Tlista &lista,int Dato){
	Nodo *Aux = new(Nodo);
		Aux->Nro = Dato;
		if(lista.Primero == NULL){
			lista.Primero = Aux;
			(lista.Primero)->Sgte = lista.Primero;
			lista.Segundo = lista.Primero;
		}
		else{
			lista.Segundo->Sgte = Aux;
			Aux->Sgte = lista.Primero;
			lista.Segundo = Aux;
		}
}

//------------------------------------------------------
/*
Nombre de la función: MostrarLista()

Objetivo:   Mostrar los elementos de la lista

Parámetros: Nodo *Aux --> Creamos un nodo el cual se llama Aux
    		Aux=lista.Primero --> Este nodo apuntara a lista.Primero
retorna = lista = {1,2,3,4,5,...,40}
Ejemplo:
		lista = {1,2,3,..,40}
		Aux = Direccion lista.Primero

		 if(Aux!=NULL)
     	{
     		do{
	    		cout<<"  "<<1;
        		Aux = 2;
        		cout<<"  "<<2;
        		Aux = 3;
        		cout<<"  "<<3;
        		Aux = 4;
        		cout<<"  "<<4;
        		Aux = 5;
        		.
        		.
        		.
        		cout<<"  "<<40;
        		Aux = 1;
        	}while(Aux != lista.Primero);
    	}
     	else
        {
			cout<<"\n\n\tLista vacia...!"<<endl;
		}
*/
void MostrarLista(Tlista &lista){
	Nodo *Aux;
    Aux=lista.Primero;
    int i=1;
    if(Aux!=NULL)
     {
     	do{
	    cout<<"  "<<Aux->Nro;
        Aux = Aux->Sgte;
        i++;
        }while(Aux != lista.Primero);
    }
     else
         {
		 cout<<"\n\n\tLista vacia...!"<<endl;
	}
}
//------------------------------------------------------
/*
Nombre de la función: Eliminar()

Objetivo:   Eliminar de la lista el numero en la posicion Num

Parámetros: Tlista &lista, la lista de la que vamos a eliminar el numero
			int Num, Cantidad de posiciones a recorrer en la lista para encontrar al que se quiere eliminar
			int &cont, Variable donde guardamos la posicion en la que quedó despues de haber hecho el recorrido y
                        eliminado el valor.
retorna = La lista sin el valor eliminado
Ejemplo:
    Primer pasada
		lista = {1,2,3,4,5}
		Num= 8
		cont=1;
		Eliminar(lista,Num,Cont)
		lista = {1,2,4,5}
		Cont = 3
    Segunda pasada
        lista = {1,2,4,5}
        Num = 8
		Cont = 3
		Eliminar(lista,Num,Cont)
		lista = {2,4,5}
		Cont = 1

*/
void Eliminar(Tlista &lista, int Num, int &cont){
	Tlista Aux;
	Nodo *Copia;
	Aux.Primero = NULL;
	Aux.Segundo = NULL;
	Copia = lista.Primero;
	Num = Num + cont - 1;
	cont = 0;
    while(Num >= 2){
        if(Copia->Nro != lista.Segundo->Nro){
            InsertarNodo(Aux,Copia->Nro);
            Copia = Copia->Sgte;
            Num--;
            cont++;
        }
        else{
            Num--;
            cont=0;
            Copia = lista.Primero;
            Aux.Primero = NULL;
            Aux.Segundo = NULL;
        }
    }
    Copia = Copia->Sgte;
    cont++;

	while(Copia->Nro != lista.Primero->Nro){
        InsertarNodo(Aux,Copia->Nro);
        Copia = Copia->Sgte;
	}
	lista=Aux;
}
//------------------------------------------------------
/*Nombre del proceso: Menu()
Objetivo:       Mostrar el menu principal,
Parametros:     Ninguno
Retorna:        Muestra en pantalla el menu principal
*/
 void menu(){
 	cout<<"1. Insertar"<<endl;
 	cout<<"2. Mostrar"<<endl;
 	cout<<"3. Eliminar"<<endl;
 	cout<<"7. SALIR";

	cout<<"\n INGRESE UNA OPCION: ";

 }
//-------------------------------------------------------
int main()
{
	Tlista lista;
	lista.Primero=NULL;
	lista.Segundo=NULL;
	srand(time(NULL));
	int i=1;
	int Op;
	int x=1;
	int Pos = 1;
	int X,Num;
	Num=1+rand()%(41-1);
	system("color 0b");
	do{
		menu(); cin>>Op;
		switch(Op)
		{
			case 1:while(i <= 40)
					{
						InsertarNodo(lista,i);
						i++;
					}
					break;
			case 2:MostrarLista(lista);
					break;
			case 3:
			    cout<<"Num: "<<Num<<endl;
                while(x <= 38){
                    Eliminar(lista,Num,Pos);
                    x++;
                }
			    cout<<"Lista despues de Eliminar el "<<Num<<" dato"<<endl;
                MostrarLista(lista);
                break;

		}
		cout<<endl<<endl;
		system("pause");system("cls");
	}while(Op != 7);
}


