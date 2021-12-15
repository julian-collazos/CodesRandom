
#include <cstdlib>
#include <iostream>

#define TRUE 1
#define FALSE 0

using namespace std;

struct NodoAVL{
       int nro;
       int FE;
       struct NodoAVL *der;
       struct NodoAVL *izq;
       struct NodoAVL *padre;
       };

typedef struct NodoAVL *AVL; //Puntero de tipo nodoAVL

void VerArbolAVL(AVL arbol, int n)
{
     if(arbol==NULL)
        return;
     VerArbolAVL(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro<<endl;

     VerArbolAVL(arbol->izq, n+1);
}


void RDD(AVL &r, AVL nodoAVL) //Rotaci�n doble derecha
{
   AVL padre = nodoAVL->padre;
   AVL A = nodoAVL;     //nodoAVL desequilibrado
   AVL B = A->izq;   //Hijo izq del nodoAVL desequilibrado
   AVL C = B->der;   //Hijo der de B
   AVL CI = C->izq;  //Hijo izq de C
   AVL CD = C->der;  //Hijo der de C
   if(padre){//Si no es la ra�z
            if(padre->der == A)
                padre->der = C;
            else
                 padre->izq = C;
            }
   else r = C; //Si es ra�z

   //ROTAR
   B->der = CI;
   A->izq = CD;
   C->izq = B;
   C->der = A;
   C->padre = padre;
   A->padre = B->padre = C;
   if(CI)
     CI->padre = B;
   if(CD)
     CD->padre = A;

  //ACTUALIZAR FACTORES DE EQUILIBRIO
  switch(C->FE)
  {
      case -1: B->FE = 0;
               A->FE = 1;
               break;

      case 0:  B->FE = 0;
               A->FE = 0;
               break;

      case 1:  B->FE = -1;
               A->FE = 0;
               break;
  }
   C->FE = 0;
}

void RDI(AVL &r, AVL nodoAVL) //Rotaci�n doble izquierda
{
   AVL padre = nodoAVL->padre;
   AVL A = nodoAVL;
   AVL B = A->der;
   AVL C = B->izq;
   AVL CI = C->izq;
   AVL CD = C->der;
   if(padre)
            if(padre->der == A)
                 padre->der = C;
            else
                 padre->izq = C;
   else r = C;

   //ROTAR
   A->der = CI;
   B->izq = CD;
   C->izq = A;
   C->der = B;
   C->padre = padre;
   A->padre = B->padre = C;
   if(CI)
     CI->padre = A;
   if(CD)
     CD->padre = B;

   //ACTUALIZAR FACTORES DE EQUILIBRIO
   switch(C->FE)
    {
      case -1: A->FE = 0;
               B->FE = 1;
               break;

      case 0:  A->FE = 0;
               B->FE = 0;
               break;

      case 1:  A->FE = -1;
               B->FE = 0;
               break;
   }
   C->FE = 0;
}

void RSD(AVL &r, AVL nodoAVL) //Rotaci�n simple derecha
{
   AVL padre = nodoAVL->padre;
   AVL A = nodoAVL;
   AVL B = A->izq;
   AVL C = B->der;
   if(padre)
       if(padre->der == A)
             padre->der = B;
       else
             padre->izq = B;
   else
       r = B;
   //ROTAR
   A->izq = C;
   B->der = A;
   A->padre = B;
   if(C)
     C->padre = A;

   B->padre = padre;
   //ACTUALIZAR FACTORES DE EQUILIBRIO
   A->FE = 0;
   B->FE = 0;
}

void RSI(AVL &r, AVL nodoAVL)
{
   AVL padre = nodoAVL->padre;
   AVL A = nodoAVL;
   AVL B = A->der;
   AVL C = B->izq;
   if(padre){
        if(padre->der == A)
            padre->der = B;
        else
            padre->izq = B;
   }
   else
      r = B;
   //ROTAR
   A->der = C;
   B->izq = A;
   A->padre = B;
   if(C)
      C->padre = A;
   B->padre = padre;
   //ACTUALIZAR FACTORES DE EQUILIBRIO
   A->FE = 0;
   B->FE = 0;
}

int esHoja(AVL nodoAVL)
{
   return !nodoAVL->der && !nodoAVL->izq;
}


int Altura(AVL arbol)
{
    if(arbol==NULL) return 0;
    else{
         if (arbol->izq==NULL && arbol->der==NULL) return 1;
         int altIzq=0;
         int altDer=0;
         if(arbol->izq) altIzq=Altura(arbol->izq);
         if(arbol->der) altDer=Altura(arbol->der);

         if(altIzq>altDer)
               return altIzq+1;
         else
               return altDer+1;
         }
}

void Equilibrar(AVL &r, AVL &nodoAVL)
{
   int salir = FALSE;

   while(nodoAVL && salir!=TRUE)
   {
    nodoAVL->FE=Altura(nodoAVL->der)-Altura(nodoAVL->izq);
   //COMPROBAR FACTOR DQUILIBRIO DE LOS nodoAVLS
   if(nodoAVL->FE == 0) salir = TRUE;
   else
       if(nodoAVL->FE == -2) {
                   if(nodoAVL->izq->FE == 1) RDD(r, nodoAVL);
                   else RSD(r, nodoAVL);
                   salir = TRUE;
                   }
       else if(nodoAVL->FE == 2){
                   if(nodoAVL->der->FE == -1)RDI(r, nodoAVL);
                   else RSI(r, nodoAVL);
                   salir = TRUE;
                   }
     nodoAVL = nodoAVL->padre; //Avanzar hacia arriba del arbol comprobando el factor equilibrio
   }
}


void EliminarNodo(AVL &n, int dato)
{
   AVL padre = NULL;
   AVL actual;
   AVL nodoAVL;

   int aux;
   actual = n;

   while(actual!=NULL)
   {
      if(dato == actual->nro)
      {
         if(esHoja(actual)) //Si el nodoAVL actual es hoja, eliminar directamente
         {
             if(padre==NULL){//Eliminar la ra�z cuando es hoja
                    n=NULL;
                    return;
             }
            if(padre){ //Si no es la ra�z
                       if(padre->der == actual)
                                padre->der = NULL;
                       else
                           if(padre->izq == actual)
                                 padre->izq = NULL;
                       }
            free(actual);
            actual= NULL;

            if((padre->der == actual && padre->FE == 1) || (padre->izq == actual && padre->FE == -1)) //El nodoAVL a eliminar es el �nico hijo del padre
            {
               padre->FE = 0;
               actual = padre;
               padre = actual->padre;
            }
            if(padre)
                           Equilibrar(n, padre);
            cout<<"\n\n\tARBOL ACTUALIZADO\n";
            VerArbolAVL(n, 0);
            return;
         }else{ //Si no es hoja el nodoAVL a eliminar
                  padre = actual;
                  if(actual->der)
                  {
                       nodoAVL = actual->der;
                       while(nodoAVL->izq){
                                        padre = nodoAVL;
                                        nodoAVL = nodoAVL->izq;
                                        }
                  }
                  else{
                       nodoAVL = actual->izq;
                       while(nodoAVL->der){
                                        padre = nodoAVL;
                                        nodoAVL = nodoAVL->der;
                                        }
                       }
                  aux = actual->nro;
                  actual->nro = nodoAVL->nro;
                  nodoAVL->nro = aux;
                  actual = nodoAVL;
                  }

         }else{//Si dato no es igual al n�mero actual
                padre = actual;
                if(dato > actual->nro) actual = actual->der;
                else if(dato < actual->nro) actual = actual->izq;
                }
   }//While
}


void InsertarAVL(AVL &nodoAVL, int dato)
{
   AVL padre = NULL;
   AVL actual = nodoAVL;
   while(actual!=NULL && dato!=actual->nro)
   {
      padre=actual;

      if(dato < actual->nro) actual = actual->izq;
      else if(dato > actual->nro) actual = actual->der;
   }
   if(actual!=NULL) return; //Actual ya apunta a un nro, salimos

  if(padre==NULL) //El nro a insertar sera la raiz
  {
      nodoAVL = (AVL)malloc(sizeof(struct NodoAVL));
      nodoAVL->nro = dato;
      nodoAVL->izq = nodoAVL->der = NULL;
      nodoAVL->padre = NULL;
      nodoAVL->FE = 0;
  }

  else if(dato < padre->nro)
       {
            actual=(AVL)malloc(sizeof(struct NodoAVL));
            padre->izq = actual;
            actual->nro = dato;
            actual->izq=actual->der = NULL;
            actual->padre = padre;
            actual->FE = 0;
            Equilibrar(nodoAVL, padre);
       }else{
              if(dato > padre->nro)
              {
                    actual = (AVL)malloc(sizeof(struct NodoAVL));
                    padre->der = actual;
                    actual->nro = dato;
                    actual->izq = actual->der = NULL;
                    actual->padre = padre;
                    actual->FE = 0;
                    Equilibrar(nodoAVL, padre);
              }
              }
   cout<<"\n\n\tEl numero ha sido insertado\n\n";
}

AVL BuscarAVL(AVL nodoAVL, int dato)
{
   AVL actual = nodoAVL;
   if(nodoAVL==NULL){
    cout<<"\n\t El arbol esta vacio "<<endl<<endl;
    return NULL;
   }
   while(actual!= NULL)
   {
      if(dato == actual->nro)
      {
        cout<<"\n\tEl numero "<<dato<<" existe en el arbol\n";
        return actual;
      }
      else if(dato < actual->nro)
         actual = actual->izq;
      else if(dato > actual->nro)
         actual = actual->der;
   }
   cout<<"\n\tEl numero "<<dato<<" NO existe en el arbol\n";
   return NULL;
}
