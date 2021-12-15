//Autor del codigo: Julian Esteban Collazos Toro
#include "MPilas.h";

void InvertirPila(PtrPila &p);
bool Revisar(PtrPila p, int X);
bool RevisarOrdenUp(PtrPila p);
bool SonIguales(PtrPila p1, PtrPila &p2);
void SacarElemen(PtrPila &p, int X);
void ContarPos(PtrPila p, int &T);
void AgregarEnPos(PtrPila &p, int pos, int X);
void MayoresMenoresX(PtrPila p, PtrPila &P1, PtrPila &P2, int X);
void menu();

//------------------------------------------------------------------------------//
/*Nombre del proceso: InvertirPila(PtrPila &p)
Objetivo:       Invertir la posicion de todos los elementos de una pila
Parametros:     PtrPila &p, la pila que queremos invertir
Retorna:        La pila con los elementos en las posiciones invertidas
Ejemplo:        p=  2
                    7
                    4
                InvertirPila(p)
                p=  4
                    7
                    2
*/
void InvertirPila(PtrPila &p)
{
    PtrPila Aux;
    int valor;
    Aux=NULL;
    while(p != NULL)
    {
        valor=Pop(p);
        Push(Aux, valor);
    }
    p=Aux;
}
//------------------------------------------------------------------------------//
/*Nombre de la funcion: Revisar(PtrPila p, int X)
Objetivo:       Revisa si un elemento x se encuentra en la pila
Parametros:     PtrPila p, la pila en la que queremos buscar el elemento
                int X, elemento que queremos buscar en la pila
Retorna:        Un booleano, true si encuentra el valor, false si no lo encuentra
Ejemplo:        p=  2
                    7
                    4
                X=7
                Revisar(p,X)=true
*/
bool Revisar(PtrPila p, int X)
{
    PtrPila Aux;
    Aux=p;
    while(Aux != NULL)
    {
        if(Aux->Nro == X)
            return 1;
        Aux=Aux->Sgte;
    }
    return 0;
}
//------------------------------------------------------------------------------//
/*Nombre de la funcion: RevisarOrdenUp(PtrPila p)
Objetivo:       Revisa si una pila esta ordenada ascendentemente
Parametros:     PtrPila p, la pila que queremos revisar si esta ordenada ascendentemente
Retorna:        Un booleano, true si la pila esta ordenada ascendentemente, false si no lo esta
Ejemplo:        p=  2
                    7
                    4
                RevisarOrdenUp(p)=false
*/
bool RevisarOrdenUp(PtrPila p)
{
    PtrPila Aux;
    Aux=p;
    while(Aux->Sgte != NULL)
    {
        if(Aux->Nro >= Aux->Sgte->Nro)
            Aux=Aux->Sgte;
        else
            return false;

    }
    return true;
}
//------------------------------------------------------------------------------//
/*Nombre de la funcion: SonIguales(PtrPila p1, PtrPila &p2)
Objetivo:       Revisa si dos pilas son iguales, mismos elementos en las mismas posiciones
Parametros:     PtrPila p1, la pila principal, se cuenta la cantidad de elementos de esta para pedir al usuario que
                            llene la segunda pila, asegurandose de que las dos tengan la misma cantidad de elementos
                PtrPila &p2, pila que se llenara con la misma cantidad de elementos de la pila principal
Retorna:        Un booleano, true si las dos pilas son iguales, false si no lo son
Ejemplo:        p1= 2
                    7
                    4
(El usuario igresa los numeros de la pila)
                p2= 4
                    7
                    2
                SonIguales(p1,p2)=false
*/
bool SonIguales(PtrPila p1, PtrPila &p2)
{
    PtrPila Aux1, Aux2;
    int cant,dato;
    ContarPos(p1,cant);
    Aux1=p1;
    while(cant > 0)
    {
        cout<<"Ingrese un numero para la pila 2: "; cin>>dato;
        Push(p2,dato);
        system("pause");
        system("cls");
        cant--;
    }
    Aux2=p2;

    cout<<"Cola 1:"<<endl;
    Mostrar(p1);
    cout<<"Pila 2:"<<endl;
    Mostrar(p2);

    while(Aux1!=NULL){
        if(Aux1->Nro == Aux2->Nro){
            Aux1=Aux1->Sgte;
            Aux2=Aux2->Sgte;
        }
        else
            return false;
    }
    return true;
}
//------------------------------------------------------------------------------//
/*Nombre del proceso: SacarElemen(PtrPila &p, int X)
Objetivo:       Saca un elemento 'X' de la pila, si esta
Parametros:     PtrPila &p, la pila de la que queremos sacar el elemento
                int X, es el valor que vamos a sacar
Retorna:        La pila sin el valor 'X', en caso de que se encuentre el valor en la pila
Ejemplo:        p=  2
                    7
                    4

                X=7
                SacarElemen(p, X)
                p=  2
                    4
*/
void SacarElemen(PtrPila &p, int X)
{
    PtrPila Aux;
    int dato, band=0;

    Aux=NULL;
    while(p != NULL)
    {
        if(p->Nro == X){
            p = p->Sgte;
            band = 1;
        }
        else{
            dato=Pop(p);
            Push(Aux, dato);
        }
    }

    InvertirPila(Aux);
    p=Aux;

    if(band)
        cout<<"Eliminado con exito"<<endl;
    else
        cout<<"El elemento no se encuentra en la pila"<<endl;
}
//------------------------------------------------------------------------------//
/*Nombre de la funcion: ContarPos(PtrPila p, int &T)
Objetivo:       Cuenta cuantos elementos tiene la pila
Parametros:     PtrPila p, la pila a la que queremos contar la cantidad de elementos
Retorna:        Coloca en T el numero de elementos que tiene la pila
Ejemplo:        p=  2
                    7
                    4
                ContarPos(p,T)
                T=3
*/
void ContarPos(PtrPila p, int &T)
{
    PtrPila Aux;
    Aux=p;
    while(Aux != NULL){
        T++;
        Aux=Aux->Sgte;
    }
}
//------------------------------------------------------------------------------//
/*Nombre del proceso: AgregarEnPos(PtrPila &p, int pos, int X)
Objetivo:       Ingresa un valor en una posicion 'pos' en una pila
Parametros:     PtrPila &p, la pila en la que queremos ingresar un elemento
                int pos, la posicion en la pila en la que vamos a ingresar el elemento
                int X, es el valor que vamos a apilar
Retorna:        La pila con el nuevo valor
Ejemplo:        p=  2
                    7
                    4

                pos=2;
                X=9
                AddInPos(q, pos, X)
                p=  2
                    7
                    9
                    4
*/
void AgregarEnPos(PtrPila &p, int pos, int X)
{
    PtrPila Aux;
    int dato,total=0;
    ContarPos(p, total);
    Aux=NULL;
    pos=total-pos;
    if(pos < 0){
        cout<<"La pila tiene "<<total<<" posiciones, no puede ingresar un numero mas alto que este."<<endl;
    }
    else{
        while(pos >= 0){
            dato=Pop(p);
            Push(Aux, dato);
            pos--;
        }
        Push(Aux, X);
        while(p!=NULL)
        {
            dato=Pop(p);
            Push(Aux, dato);
        }
        InvertirPila(Aux);
        p=Aux;
    }
}
//------------------------------------------------------------------------------//
/*Nombre del proceso: MayoresMenoresX(PtrPila p, PtrPila &P1, PtrPila &P2, int X)
Objetivo:       De una pila sacar los elementos mayores a 'X' y colocarlos en una pila, el resto en otra pila
Parametros:     PtrPila p, la pila principal cuyos elementos se repartiran en otras dos pila
                PtrPila &P1, la pila en la que van los elementos mayores a X
                PtrPila &P2, la pila en donde van los valores que no son mayores a 'X'
                int X, es el valor que va a servir de referencia para dividir la pila principal
Retorna:        Dos pilas con los valores de la pila principal segun la condicion
Ejemplo:        p=  2
                    5
                    7
                    4
                    8

                X=7
                AddInPos(q, pos, X)
                P1= 8

                P2= 4
                    7
                    5
                    2
*/
void MayoresMenoresX(PtrPila p, PtrPila &P1, PtrPila &P2, int X)
{
    PtrPila Aux;
    int dato;
    Aux=p;
    while(Aux != NULL){
        dato = Pop(Aux);
        if(dato > X){
            Push(P1, dato);
        }
         else{
            Push(P2, dato);
         }
    }
    cout<<"P1:"<<endl;
    Mostrar(P1);
    cout<<"P2:"<<endl;
    Mostrar(P2);
}
//------------------------------------------------------------------------------//
/*Nombre del proceso: MenuPilas()
Objetivo:       Mostrar el menu principal,
Parametros:     Ninguno
Retorna:        Muestra en pantalla el menu principal
*/
void MenuPilas()
{
	cout<<"\n\t Implementacion de pilas en c++\n\n";
	cout<<"1.  Apilar"<<endl;
	cout<<"2.  Desapilar"<<endl;
	cout<<"3.  Mostrar pila"<<endl;
	cout<<"4.  Destruir pila"<<endl;
	cout<<"5.  Invertir pila"<<endl;
	cout<<"6.  Revisar si un elemento esta en la pila"<<endl;
	cout<<"7.  Revisar si la pila esta ordenada ascendentemente"<<endl;
	cout<<"8.  Revisar si dos pilas son iguales"<<endl;
	cout<<"9.  Sacar de la pila el elemento X"<<endl;
	cout<<"10. Agregar elemento en la pila en la posicion X"<<endl;
	cout<<"11. Dividir la pila entre mayores y menores que X"<<endl;
	cout<<"0.Salir"<<endl;
	cout<<"\nIngrese opcion: ";
}
int main()
{
	short op;
	int dato,pos,x;
    PtrPila p = NULL, q=NULL, P1=NULL, P2=NULL;

    do{
        MenuPilas(); cin>> op;
        switch(op)
        {
            case 1:
                cout<<"Numero a apilar: "; cin>> dato;
                Push(p,dato);
                cout<<"\n\nNumero "<<dato<<" apilado...\n";
                break;
            case 2:
                x= Pop(p);
                cout<<"\n\tNumero "<<x<<" desapilado...\n";
                break;
            case 3:
                cout<<"\n\tMostrando Pila\n\n";
                if(p->Nro!=NULL)
                    Mostrar(p);
                else
                    cout<<"\tPila vacia...!"<<endl;
                break;
            case 4:
                DestruirPila(p);
                cout<<"\tHecho..."<<endl;
                break;
            case 5:
                cout<<"Pila inicial:"<<endl;
                Mostrar(p);
                InvertirPila(p);
                cout<<endl<<"Pila invertida:"<<endl;
                Mostrar(p);
                break;
            case 6:
                cout<<"Ingrese numero a buscar en la pila: "; cin>>x;
                if(Revisar(p,x))
                    cout<<"\nNumero encontrado... =D"<<endl;
                else
                    cout<<"\nNumero no encontrado... :("<<endl;
                break;
            case 7:
                if(RevisarOrdenUp(p))
                    cout<<"\nOrdenada ascendentemente..."<<endl;
                else
                    cout<<"\nNo ordenada ascendentemente..."<<endl;
                break;
            case 8:
                if(SonIguales(p,q))
                    cout<<"\nSon iguales..."<<endl;
                else
                    cout<<"\nSon diferentes..."<<endl;
                break;
            case 9:
                cout<<"Ingrese numero a sacar de la pila: ";cin>>dato;
                SacarElemen(p,dato);
                break;
            case 10:
                cout<<"Ingrese numero a ingresar en la pila: ";cin>>dato;
                cout<<"Ingrese posicion en la que quiere poner el dato: ";cin>>pos;
                AgregarEnPos(p,pos,dato);
                cout<<"\n\nNumero "<<dato<<" apilado...\n"<<endl;
                break;
            case 11:
                cout<<"Ingrese el numero X: "; cin>>x;
                MayoresMenoresX(p,P1,P2,x);
                break;
            default:
                cout<<"Opcion no valida, por favor ingrese una opcion nuevamente"<<endl;
        }
        cout<<endl;
        system("pause");
        system("cls");
    }while(op != 0);

}
