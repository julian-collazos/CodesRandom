//Problema de Josefo
#include<stdlib.h>
#include<iostream>
using namespace std;

struct NodoCircular
{
    int Nro;
    struct NodoCircular *Sgte;
};
struct ListaCircular
{
    struct NodoCircular *Delante;
    struct NodoCircular *Detras;
};

void Enlistar(struct ListaCircular &q, int valor)
{
    struct NodoCircular *Aux= new(struct NodoCircular);
    Aux->Nro = valor;
    Aux->Sgte = NULL;
    if(q.Delante == NULL)
        q.Delante=Aux;
    else
        (q.Detras)->Sgte=Aux;
    q.Detras=Aux;
}
void MostrarLC(struct ListaCircular c)
{
    struct NodoCircular *aux;
    aux=c.Delante;
    int i=1;

    if(c.Delante != NULL)
     {
          do
          {    cout<<"  "<<aux->Nro;
               aux = aux->Sgte;
               i++;
          }while(i <= 10);
      }
     else
         cout<<"\n\n\tLista vacia...!"<<endl;
}
int main()
{
    struct ListaCircular c;
    c.Delante=NULL;
    c.Detras=NULL;

    Enlistar(c,2);
    Enlistar(c,4);
    Enlistar(c,6);
    Enlistar(c,8);
    Enlistar(c,3);
    Enlistar(c,5);

    MostrarLC(c);
}
