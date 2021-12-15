#include<stdlib.h>
#include<iostream>
//Autor parcial del codigo: Julian Esteban Collazos Toro
#include "MPilas.h";
using namespace std;

struct Nodo
{
    int Nro;
    struct Nodo *Sgte;
};
typedef struct Nodo *Tlista;
//------------------------------------------------------------------------------//
/*Nombre del proceso:InsertarInicio(Tlista &Lista,int Valor)
Objetivo:       Ingresa un valor al inicio de la lista
Parametros:     Tlista &Lista, la lista en la que queremos ingresar un elemento
                int valor, es el valor que vamos a enlistar
Retorna:        La lista con el nuevo valor
Ejemplo:        q={2,7,4}
                X=9
                InsertarInicio(q, X)
                q={2,7,4,9}
*/
void InsertarInicio(Tlista &Lista,int Valor)
{
    Tlista q;
    q=new(struct Nodo);
    q->Nro=Valor;
    q->Sgte=Lista;
    Lista=q;
}
//------------------------------------------------------------------------------//
/*Nombre del proceso:InsertarFinal(Tlista &Lista,int Valor)
Objetivo:       Ingresa un valor al final de la lista
Parametros:     Tlista &Lista, la lista en la que queremos ingresar un elemento
                int valor, es el valor que vamos a enlistar
Retorna:        La lista con el nuevo valor
Ejemplo:        q={2,7,4}
                X=9
                InsertarFinal(q, X)
                q={9,2,7,4}
*/
void InsertarFinal(Tlista &Lista, int Valor)
{
    Tlista t, q=new(struct Nodo);
    q->Nro = Valor;
    q->Sgte = NULL;
    if(Lista == NULL){
        Lista = q;
    }
    else{
        t = Lista;
        while(t->Sgte != NULL){
            t = t->Sgte;
        }
        t->Sgte = q;
    }
}
//------------------------------------------------------------------------------//
/*Nombre de la funcion:InsertarAntesDespues()
Objetivo:       Confirmar si desea ingresar antes o despues de la posicion
Parametros:     Ninguno
Retorna:        int band, -1 antes, 0 despues
Ejemplo:        (Usuario ingresa 2)
                _op = 2
                band = 0
                (retorna 0)
*/
int InsertarAntesDespues()
{
    int _op,band;
    cout<<endl;
    cout<<"\t1. Antes de la posicion"<<endl;
    cout<<"\t2. Despues de la posicion"<<endl;
    cout<<"\tOpcion: ";cin>> _op;
    if(_op == 1)
        band = -1;
    else
        band = 0;
    return band;
}
//------------------------------------------------------------------------------//
/*Nombre del proceso:InsertarElemento(Tlista &Lista,int Valor, int Pos)
Objetivo:       Ingresa un valor en una posicion de la lista
Parametros:     Tlista &Lista, la lista en la que queremos ingresar un elemento
                int valor, es el valor que vamos a enlistar
                int Pos, es la posicion que se tomara de referencia para ingresar el elemento
Retorna:        La lista con el nuevo valor
Ejemplo:        q={2,7,4}
                X=9
                P=2
                InsertarElemento(q, X)
                (internamente llama a InsertarAntesDespues)
                (Usuario ingresa 2)
                band = 0; (Inserta despues de la posicion de referencia)
                q={2,7,9,4}
*/
void InsertarElemento(Tlista &Lista, int Valor, int Pos)
{
    Tlista q, t;
    int i;
    q = new(struct Nodo);
    q->Nro = Valor;
    if(Pos == 1){
        q->Sgte = Lista;
        Lista = q;
    }
    else{
        int x = InsertarAntesDespues();
        t = Lista;
        for(i = 1; t != NULL; i++){
            if(i == Pos+x){
                q->Sgte = t->Sgte;
                t->Sgte = q;
                return;
            }
            t = t->Sgte;
        }
    }
    cout<<"\tError... Posicion no encontrada..!"<<endl;
}
//------------------------------------------------------------------------------//
/*Nombre del proceso: BuscarElemento(Tlista Lista, int Valor)
Objetivo:       Revisa si un elemento x se encuentra en la lista
Parametros:     Tlista Lista, la lista en la que queremos buscar el elemento
                int Valor, elemento que queremos buscar en la lista
Retorna:        Muestra en pantalla, si encuentra el elemento, la posicion en la que esta
Ejemplo:        q={2,7,4,2}
                x=2
                BuscarElemento(q,x)
                (Muestra en pantalla)
                Encontrada en posicion 1
                Encontrada en posicion 4
*/
void BuscarElemento(Tlista Lista, int Valor)
{
    Tlista q = Lista;
    int i = 1, band = 0;
    while (q != NULL){
        if(q->Nro == Valor){
            cout<<endl<<" Encontrada en posicion "<<i<<endl;
            band = 1;
        }
        q = q->Sgte;
        i++;
    }
    if(band == 0)
        cout<<"\n\nNumero no encontrado..!"<<endl;
}
//------------------------------------------------------------------------------//
/*Nombre del proceso: MostrarLista(Tlista Lista)
Objetivo:       Imprime en pantalla los datos dentro de una lista
Parametros:     Tlista Lista, la lista que queremos mostrar en pantalla
Retorna:        Muestra en pantalla todos los datos que se encuentran en una lista
Ejemplo:        q={2,7,4,20,15)
                (Muestra en pantalla)
                2 7 4 20 15
*/
void MostrarLista(Tlista Lista)
{
    int i = 0;
    while(Lista != NULL){
        cout<<Lista->Nro<<"\t";
        Lista = Lista->Sgte;
        i++;
    }
    cout<<endl;
}
//------------------------------------------------------------------------------//
/*Nombre del proceso: EliminarElementoLista(Tlista &Lista, int valor)
Objetivo:       Buscar un elemento x en la lista y eliminar el primero que halle
Parametros:     Tlista Lista, la lista de la que queremos eliminar el elemento
                int Valor, elemento que queremos eliminar en la lista
Retorna:        La lista sin el elemento a eliminar
Ejemplo:        q={2,7,4,2}
                x=2
                EliminarElementoLista(q,x)
                q={7,4,2}
*/
void EliminarElementoLista(Tlista &Lista, int valor)
{
    Tlista p, ant;
    p = Lista;
    if(Lista != NULL){
        while(p != NULL){
            if(p->Nro == valor){
                if(p == Lista)
                    Lista = Lista->Sgte;
                else
                    ant->Sgte = p->Sgte;
                delete(p);
                return;
            }
            ant = p;
            p = p->Sgte;
        }
        cout<<"Numero no encontrado"<<endl;
    }
    else
        cout<<"  Lista vacia...!"<<endl;
}
//------------------------------------------------------------------------------//
/*Nombre del proceso: EliminaRepetidos(Tlista &Lista, int valor)
Objetivo:       Buscar un elemento x en la lista y eliminarlo cada vez que aparezca
Parametros:     Tlista Lista, la lista de la que queremos eliminar el elemento
                int Valor, elemento que queremos eliminar en la lista
Retorna:        La lista sin el elemento a eliminar
Ejemplo:        q={2,7,4,2}
                x=2
                EliminaRepetidos(q,x)
                q={7,4}
*/
void EliminaRepetidos(Tlista &Lista, int Valor)
{
    Tlista q, ant;
    int found;
    q = Lista;
    ant = Lista;
    while(q != NULL){
        if(q->Nro == Valor){
            found = 1;
            if(q == Lista){
                Lista = Lista->Sgte;
                delete(q);
                q = Lista;
            }
            else{
                ant->Sgte = q->Sgte;
                delete(q);
                q = ant->Sgte;
            }
        }
        else{
            found = 0;
            ant = q;
            q = ant->Sgte;
        }
    }
    if(found)
        cout<<"\n\n Valores eliminados..!"<<endl;
    else
        cout<<"\n\nValor no encontrado..!"<<endl;
}
//------------------------------------------------------------------------------//
/*
Nombre de la funcion: CuantasVecesEsta(Tlista Lista, int Valor)
Objetivo:       Cuenta cuantos elementos X hay en la lista
Parametros:     Tlista Lista, la lista en la que queremos contar la cantidad de elementos x que hay
                int Valor, Es el elemento X que queremos contar cuantas veces esta en la lista
Retorna:        int cont, Las veces que aparece dicho elemento
Ejemplo:        q={2,7,4,2}
                CuantasVecesEsta(q,2)=2
*/
int CuantasVecesEsta(Tlista Lista, int Valor)
{
    Tlista q = Lista;
    int cont = 0;
    while (q != NULL){
        if(q->Nro == Valor){
            cont++;
        }
        q = q->Sgte;
    }
    return cont;
}
//------------------------------------------------------------------------------//
/*Nombre del proceso: InvertirLista(Tlista &Lista)
Objetivo:       Invertir la posicion de todos los elementos de una lista
Parametros:     Tlista Lista, la lista que queremos invertir
Retorna:        La lista con los elementos en las posiciones invertidas
Ejemplo:        q={2,7,4}
                InvertirLista(q)
                q={4,7,2}
*/
void InvertirLista(Tlista &Lista)
{
    PtrPila Pl=NULL;
    Tlista q = Lista;
    int num;
    while(q != NULL){
        num = q->Nro;
        Push(Pl, num);
        q = q->Sgte;
    }
    while(Pl != NULL){
        num=Pop(Pl);
        InsertarFinal(q,num);
    }
    Lista = q;
}
//------------------------------------------------------------------------------//
/*
Nombre de la funcion: PromedioValoresLista(Tlista Lista)
Objetivo:       Devolver el promedio de los valores en una lista
Parametros:     Tlista Lista, la lista en la que estan los elementos que vamos a promediar
Retorna:        int prom, el promedio de todos los valores de la lista
Ejemplo:        q={2,7,4,2}
                PromedioValoresLista(q)=15/4=3.75;
*/
float PromedioValoresLista(Tlista Lista)
{
    Tlista q = Lista;
    float c = 0.0,sum = 0.0,prom;
    while(q != NULL){
        sum = sum + q->Nro;
        c++;
        q = q->Sgte;
    }
    prom=sum/c;
    return prom;
}
//------------------------------------------------------------------------------//
/*
Nombre de la funcion: MayorValor(Tlista Lista)
Objetivo:       Devolver el elemento de la lista con mayor valor
Parametros:     Tlista Lista, la lista en la que se busca el elemento con el mayor valor
Retorna:        int may, el mayor valor
Ejemplo:        q={2,7,4,2}
                MayorValor(q)=7
*/
int MayorValor(Tlista Lista)
{
    Tlista Aux=Lista;
    int may;
    while(Aux->Sgte != NULL){
        if(Aux->Nro >= Aux->Sgte->Nro)
            may = Aux->Nro;
        else
            may = Aux->Sgte->Nro;
        Aux = Aux->Sgte;
    }
    return may;
}
//------------------------------------------------------------------------------//
/*
Nombre de la funcion: OrdenadaAscendente(Tlista Lista)
Objetivo:       Revisa si una lista esta ordenada ascendentemente
Parametros:     Tlista Lista, la lista que queremos revisar si esta ordenada ascendentemente
Retorna:        Un booleano, true si la lista esta ordenada ascendentemente, false si no lo esta
Ejemplo:        q={2,7,4}
                Informar(q,x)=false
*/
bool OrdenadaAscendente(Tlista Lista)
{
    Tlista Aux=Lista;
    bool estaOrdenada = 1;
    while(Aux->Sgte != NULL && estaOrdenada == 1){
        if(Aux->Nro <= Aux->Sgte->Nro)
            Aux = Aux->Sgte;
        else
            estaOrdenada = 0;
    }
    return estaOrdenada;
}
//------------------------------------------------------------------------------//
/*Nombre del proceso: Menu()
Objetivo:       Mostrar el menu principal,
Parametros:     Ninguno
Retorna:        Muestra en pantalla el menu principal
*/
void Menu()
{
    cout<<"\n\n\tLista enlazada simple\n\n";
    cout<<"1.  Insertar al inicio"<<endl;
    cout<<"2.  Insertar al final"<<endl;
    cout<<"3.  Insertar en una posicion"<<endl;
    cout<<"4.  Mostrar lista"<<endl;
    cout<<"5.  Buscar elemento"<<endl;
    cout<<"6.  Eliminar elemento 'V'"<<endl;
    cout<<"7.  Eliminar elementos con valor 'V'"<<endl;
    cout<<"8.  Revisar cuantas veces esta el elemento con valor 'V'"<<endl;
    cout<<"9.  Invertir Lista"<<endl;
    cout<<"10. Calcular el promedio de los valores de la lista"<<endl;
    cout<<"11. Encontrar el mayor valor"<<endl;
    cout<<"12. Revisar si la lista esta ordenada ascendentemente"<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"Ingrese opcion: ";
}
int main()
{
    Tlista Lista = NULL;
    int op, pos;
    int _dato;
    float prome;
    system("color 0b");
    do{
        Menu();cin>>op;
        switch(op)
        {
            case 1:
                cout<<"\nNumero a insertar: ";cin>>_dato;
                InsertarFinal(Lista,_dato);
                break;
            case 2:
                cout<<"\nNumero a insertar: ";cin>>_dato;
                InsertarInicio(Lista,_dato);
                break;
            case 3:
                cout<<"Numero a insertar: ";cin>>_dato;
                cout<<"Posicion: ";cin>>pos;
                InsertarElemento(Lista, _dato, pos);
                break;
            case 4:
                cout<<"\nMostrando lista"<<endl;
                MostrarLista(Lista);
                break;
            case 5:
                cout<<"\nValor a buscar: ";cin>>_dato;
                BuscarElemento(Lista, _dato);
                break;
            case 6:
                cout<<"\n Valor a eliminar: ";cin>>_dato;
                EliminarElementoLista(Lista, _dato);
                break;
            case 7:
                cout<<"\n Valor repetido a eliminar: ";cin>>_dato;
                EliminaRepetidos(Lista, _dato);
                break;
            case 8:
                cout<<"\n Valor repetido a buscar: ";cin>>_dato;
                cout<<endl<<"El valor está "<<CuantasVecesEsta(Lista, _dato)<<" veces..!"<<endl;
                break;
            case 9:
                cout<<"Lista inicial: "<<endl;
                MostrarLista(Lista);
                InvertirLista(Lista);
                cout<<"Lista invertida: "<<endl;
                MostrarLista(Lista);
                break;
            case 10:
                prome = PromedioValoresLista(Lista);
                cout<<"El promedio de los valores de la lista es: "<<prome<<endl;
                break;
            case 11:
                _dato = MayorValor(Lista);
                cout<<" El mayor valor existente es: "<<_dato;
                break;
            case 12:
                if(OrdenadaAscendente(Lista))
                    cout<<"La lista esta ordenada ascendentemente..! =D"<<endl;
                else
                    cout<<"La lista no esta ordenada ascendentemente..! =("<<endl;
                break;
        }
        cout<<endl<<endl;
        system("pause");
        system("cls");
    }while(op != 0);
    return 0;
}
