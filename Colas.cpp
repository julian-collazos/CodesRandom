//Autor parcial del codigo: Julian Esteban Collazos Toro
#include"MColas.h"
#include"MPilas.h"

//------------------------------------------------------------------------------//
/*Nombre del proceso: InvertirCola(struct Cola &q)
Objetivo:       Invertir la posicion de todos los elementos de una cola
Parametros:     struct Cola &q, la cola que queremos invertir
Retorna:        La cola con los elementos en las posiciones invertidas
Ejemplo:        q={2,7,4}
                InvertirCola(q)
                q={4,7,2}
*/
void InvertirCola(struct Cola &q)
{
    PtrPila Aux=NULL;
    int num;
    while(q.Delante != NULL)
    {
        num=Desencolar(q);
        Push(Aux, num);
    }
    while(Aux != NULL)
    {
        num=Pop(Aux);
        Encolar(q,num);
    }
}
//------------------------------------------------------------------------------//
/*Nombre de la funcion: Informar(struct Cola q, int x)
Objetivo:       Revisa si un elemento x se encuentra en la cola
Parametros:     struct Cola &q, la cola en la que queremos buscar el elemento
                int x, elemento que queremos buscar en la cola
Retorna:        Un booleano, true si encuentra el valor, false si no lo encuentra
Ejemplo:        q={2,7,4}
                x=7
                Informar(q,x)=true
*/
bool Informar(struct Cola q, int x)
{
    struct Nodo *Aux;
    Aux=q.Delante;
    while(Aux != NULL)
    {
        if(Aux->Nro == x)
            return 1;
        else
            Aux=Aux->Sgte;
    }
    return 0;
}
//------------------------------------------------------------------------------//
/*Nombre de la funcion: Ordenup(struct Cola q)
Objetivo:       Revisa si una cola esta ordenada ascendentemente
Parametros:     struct Cola &q, la cola que queremos revisar si esta ordenada ascendentemente
Retorna:        Un booleano, true si la cola esta ordenada ascendentemente, false si no lo esta
Ejemplo:        q={2,7,4}
                Informar(q,x)=false
*/
bool OrdenUp(struct Cola q)
{
    struct Nodo *Aux;
    Aux=q.Delante;
    while(Aux->Sgte != NULL)
    {
        if(Aux->Nro <= Aux->Sgte->Nro)
            Aux=Aux->Sgte;
        else
            return 0;
    }
    return 1;
}
//------------------------------------------------------------------------------//
/*Nombre de la funcion: SonDiferentes(struct Cola q, struct Cola k)
Objetivo:       Revisa si dos colas son iguales, mismos elementos en las mismas posiciones
Parametros:     struct Cola &q, la cola principal, cuenta la cantidad de elementos de esta para pedir al usuario que
                                llene la segunda cola, asegurandose de que las dos tengan la misma cantidad de elementos
                struct Cola &q, cola que se llenara con la misma cantidad de elementos de la cola principal
Retorna:        Un booleano, true si las dos colas son iguales, false si no lo son
Ejemplo:        q={2,7,4}
(El usuario igresa los numeros de la cola)
                k={4,7,2}
                SonDiferentes(q,k)=false
*/
bool SonDiferentes(struct Cola q, struct Cola k)
{
    int num, cant= Contar(q);
    struct Nodo *Aux1;
    struct Nodo *Aux2;
    Aux1=q.Delante;
    while(cant > 0)
    {
        cout<<"Ingrese un numero para la Cola 2: "; cin>>num;
        Encolar(k,num);
        system("pause");
        system("cls");
        cant--;
    }
    Aux2=k.Delante;
    cout<<"Cola 1:"<<endl;
    MostrarCola(q);
    cout<<"\n\nCola 2:"<<endl;
    MostrarCola(k);
    while(Aux1 != NULL)
    {
        if(Aux1->Nro == Aux2->Nro){
            Aux1=Aux1->Sgte;
            Aux2=Aux2->Sgte;
        }
        else
            return 0;
    }
    return 1;
}
//------------------------------------------------------------------------------//
/*Nombre del proceso: AddInPos(struct Cola &p, int pos, int X)
Objetivo:       Ingresa un valor en una posicion 'pos' en una cola
Parametros:     struct Cola &q, la cola en la que queremos ingresar un elemento
                int pos, la posicion en la cola en la que vamos a ingresar el elemento
                int valor, es el valor que vamos a encolar
Retorna:        La cola con el nuevo valor
Ejemplo:        q={2,7,4}
                pos=2;
                X=9
                AddInPos(q, pos, X)
                q={2,9,7,4}
*/
void AddInPos(struct Cola &p, int pos, int X)
{
    struct Cola Aux;
    int dato;
    Aux.Delante=NULL;
    Aux.Atras=NULL;
    if(pos == 1)
        Encolar(p, X);
    else{
        while(pos > 1){
            dato=Desencolar(p);
            Encolar(Aux, dato);
            pos--;
            cout<<"OK"<<endl;
        }
        Encolar(Aux, X);
        while(p.Delante!=NULL)
        {
            dato=Desencolar(p);
            Encolar(Aux, dato);
        }
        p=Aux;
    }

}
//------------------------------------------------------------------------------//
/*Nombre del proceso: Menu()
Objetivo:       Mostrar el menu principal,
Parametros:     Ninguno
Retorna:        Muestra en pantalla el menu principal
*/
void Menu()
{
    cout<<"\n\t Implementacion de Colas en C++\n";
    cout<<"1. EnColar"<<endl;
    cout<<"2. DesenColar"<<endl;
    cout<<"3. Mostrar Cola"<<endl;
    cout<<"4. Vaciar Cola"<<endl;
    cout<<"5. Invertir Cola"<<endl;
    cout<<"6. Informar si un numero se encuentra en la Cola"<<endl;
    cout<<"7. Informar si la Cola esta ordenada ascendentemente"<<endl;
    cout<<"8. Informar si dos Colas son iguales"<<endl;
    cout<<"9. Agregar un dato X en una posicion pos"<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"\nIngrese opcion: ";
}
//------------------------------------------------------------------------------//
int main()
{
    struct Cola q;
    q.Delante =NULL;
    q.Atras=NULL;
    struct Cola k;
    k.Delante=NULL;
    k.Atras=NULL;
    int dato, op, x,pos;
    system("color 0b");
    do{
        Menu(); cin>> op;
        switch(op)
        {
            case 1:
                cout<<"Numero a encolar: "; cin>> dato;
                Encolar(q,dato);
                cout<<"\n\nNumero "<<dato<<" encolado...\n";
                break;
            case 2:
                x= Desencolar(q);
                cout<<"\n\tNumero "<<x<<" desencolado...\n";
                break;
            case 3:
                cout<<"\n\tMostrando Cola\n\n";
                if(q.Delante!=NULL)
                    MostrarCola(q);
                else
                    cout<<"\tCola vacia...!"<<endl;
                break;
            case 4:
                VaciarCola(q);
                cout<<"\tHecho..."<<endl;
                break;
            case 5:
                cout<<"Cola inicial:"<<endl;
                MostrarCola(q);
                InvertirCola(q);
                cout<<"\n\nCola invertida: "<<endl;
                MostrarCola(q);
                break;
            case 6:
                cout<<"Ingrese numero a buscar en la Cola: "; cin>>x;
                if(Informar(q, x))
                    cout<<"\nNumero encontrado... =D"<<endl;
                else
                    cout<<"\nNumero no encontrado... :("<<endl;
                break;
            case 7:
                if(OrdenUp(q))
                    cout<<"\nOrdenada ascendentemente..."<<endl;
                else
                    cout<<"\nNo ordenada ascendentemente..."<<endl;
                break;
            case 8:
                if(SonDiferentes(q,k))
                    cout<<"\nSon iguales..."<<endl;
                else
                    cout<<"\nSon diferentes..."<<endl;
                break;
            case 9:
                cout<<"Ingrese numero a encolar: ";cin>>dato;
                cout<<"Ingrese posicion en la que quiere poner el dato: ";cin>>pos;
                AddInPos(q,pos,dato);
                cout<<"\n\nNumero "<<dato<<" encolado...\n";
                break;


        }
        cout<<endl;
        system("pause"); system("cls");
    }while(op!= 0);

    return 0;
}
