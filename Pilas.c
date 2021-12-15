#include<stdlib.h>
#include<stdio.h>
#include<iostream>

struct Nodo{
    int Nro;
    struct Nodo* Sgte;
};
typedef struct Nodo *PtrPila;

//Metodo Apilar
void Push(PtrPila p, int Valor)
{
    PtrPila Aux;
    Aux= new(struct Nodo);
    Aux->Nro=Valor;
    Aux->Sgte=p;
    p=Aux;
}

//Mostrar Pila
void Mostrar(PtrPila p)
{
    PtrPila Aux;
    Aux=p;
    while(Aux != NULL)
    {
        printf("\t%i\n",Aux->Nro);
        Aux=Aux->Sgte;
    }
}

int main()
{
    PtrPila p = NULL;
    Push(p,5);
    Push(p,7);
    Push(p,9);
    Push(p,11);
    Mostrar(p);

    do{
    	menu(); cin>>op;
    	switch(op)
    	{
    		case 1:
    			cout<<"\n Numero a apilar: "; cin>>dato;
    			Push(p,dato);
    			cout<<"\n\n\tNUmero "<<dato<<" apilado...\n\n";
    			break;
    		case 2:
    			x=Pop(p);
    			cout<<"\n\n\tNumero "<<x<<" desapilado...\n\n";
    			break;
    		case 3:
    			cout<<"\n\nMostrando Pila\n\n";
    			if(p != NULL)
    				Mostrar(p);
    			else
    				cout<<"\n\n\tPila vacia...!"<<endl;
    			break;
    		case 4:
    			DestruirPila(p);
    			cout<<"\n\n\tPila eliminada...\n";
    			break;
		}
		cout<<endl;
		system("pause"); system("cls");
	}while(op!=5);

    return 0;
}
