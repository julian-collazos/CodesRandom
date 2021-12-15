#include <iostream>
using namespace std;

struct NodoABB{
    int Num;                    //Dato
    struct NodoABB *Izq, *Der;  //Hijo izquierdo e hijo derecho
};
typedef struct NodoABB *ABB;

/*Nombre de la funcion: CrearNodo(int x)
Objetivo:       Crear un nodo donde se puede insertar un dato
Parametros:     int x, Numero que se inserta en el nodo que se crea
Retorna:        El nodo creado
*/
ABB CrearNodo(int x)
{
    ABB NuevoNodo = new(struct NodoABB);
    NuevoNodo->Num = x;
    NuevoNodo->Izq = NULL;
    NuevoNodo->Der = NULL;

    return NuevoNodo;
}
/*Nombre de la funcion: void Insertar(ABB &Arbol, int x)
Objetivo:       Organizar un nodo cumpliendo las reglas de un arbol binario de busqueda
Parametros:     ABB &Arbol, Arbol donde se organizará el nodo creado
                int x, el dato que se guarda en el nodo
Retorna:        El nodo organizado dentro del arbol
*/
void Insertar(ABB &Arbol, int x)
{
    if(Arbol == NULL)
        Arbol = CrearNodo(x);
    else if( x < Arbol->Num)
        Insertar(Arbol->Izq, x);
    else if(x > Arbol->Num)
        Insertar(Arbol->Der, x);
}
/*Nombre de la funcion: void PreOrden(ABB Arbol)
Objetivo:       Mostrar en pantalla los datos del arbol en preorden, es decir
                mostrando primero el padre, luego el nodo izquierdo y por ultimo el
                derecho
Parametros:     ABB Arbol, Arbol que se va a mosrtrar en pantalla
Retorna:        Muestra en pantalla los datos en el arbol

*/
void PreOrden(ABB Arbol)
{
    if(Arbol != NULL){
        cout<<Arbol->Num<<" ";
        PreOrden(Arbol->Izq);
        PreOrden(Arbol->Der);
    }
}
/*Nombre de la funcion: void EnOrden(ABB Arbol)
Objetivo:       Mostrar en pantalla los datos del arbol en inorden, es decir
                mostrando primero el nodo izquierdo, luego el padre y
                finalmente el nodo derecho
Parametros:     ABB Arbol, Arbol que se va a mosrtrar en pantalla
Retorna:        Muestra en pantalla los datos en el arbol

*/
void EnOrden(ABB Arbol)
{
    if(Arbol != NULL){
        EnOrden(Arbol->Izq);
        cout<<Arbol->Num<<" ";
        EnOrden(Arbol->Der);
    }
}
/*Nombre de la funcion: void PostOrden(ABB Arbol)
Objetivo:       Mostrar en pantalla los datos del arbol en postorden, es decir
                mostrando primero el nodo izquierdo, luego el nodo derecho y por
                ultimo el padre
Parametros:     ABB Arbol, Arbol que se va a mosrtrar en pantalla
Retorna:        Muestra en pantalla los datos en el arbol

*/
void PostOrden(ABB Arbol)
{
    if(Arbol != NULL){
        PostOrden(Arbol->Izq);
        PostOrden(Arbol->Der);
        cout<<Arbol->Num<<" ";
    }
}
/*Nombre de la funcion: void VerArbol(ABB Arbol, int n)
Objetivo:       Mostrar en pantalla los datos del arbol de forma que dependiendo del
                nivel se repetira esa cantidad de veces el dato
Parametros:     ABB Arbol, Arbol que se va a mosrtrar en pantalla
                int n, es un contador interno que va registrando el nivel del dato
Retorna:        Muestra en pantalla los datos en el arbol

*/
void VerArbol(ABB Arbol, int n)
{
    if(Arbol==NULL)
        return;
    VerArbol(Arbol->Der, n+1);

    for(int i=0; i<n; i++)
        cout<<Arbol->Num<<endl;

    VerArbol(Arbol->Izq, n+1);
}
/*Nombre de la funcion: void Eliminar(ABB &Arbol,int x)
Objetivo:       Elimina un dato del arbol moviendo los datos para que siga siendo un
                arbol binario de busqueda
Parametros:     ABB Arbol, Arbol del que se va a eliminar el dato
                int x, dato que se va a eliminar
Retorna:        El abol sin el dato eliminado
*/
void Eliminar(ABB &Arbol,int x)
{
    ABB aux1,aux2;
    if(Arbol==NULL) return;

    if(x>Arbol->Num)
        Eliminar(Arbol->Der,x);
    if(x<Arbol->Num)
        Eliminar(Arbol->Izq,x);

    if(x==Arbol->Num){
        if(Arbol->Der==NULL && Arbol->Izq==NULL) //Si el nodo es hoja
        {
            Arbol=NULL;
            return;
        }
        if(Arbol->Der!=NULL && Arbol->Izq==NULL)
        {
            Arbol=Arbol->Der;
            return;
        }
            aux1=Arbol;
            aux2=Arbol->Izq;
            while(aux2->Der!=NULL)
            {
                aux1=aux2;
                aux2=aux2->Der;
            }
            Arbol->Num = aux2->Num;
            if(aux1==Arbol)
                Arbol->Izq = aux2->Izq;
            else
                aux1->Der = aux2->Izq;
    }
}
/*Nombre de la funcion: bool Buscar(ABB Arbol, int Dato)
Objetivo:       Buscar en un arbol un dato
Parametros:     ABB Arbol, Arbol en el que se va a buscar el dato
                int Dato, dato que se va a buscar
Retorna:        un verdadero si esta o un falso si no
*/
bool Buscar(ABB Arbol, int Dato)
{
     int r=0;   // 0 indica que lo encontre

     if(Arbol==NULL)
        return r;

     if(Dato < Arbol->Num)
         r = Buscar(Arbol->Izq, Dato);

     else if(Dato> Arbol->Num)
         r = Buscar(Arbol->Der, Dato);

     else
        r = 1;   // son iguales, lo encontre

     return r;
}
/*Nombre de la funcion: int AlturaAB(ABB Arbol)
Objetivo:       Determinar la altura de un arbol
Parametros:     ABB Arbol, Arbol del que se quiere saber la altura
Retorna:        El nivel mas alto del arbol, lo que seria la altura de este
*/
int AlturaAB(ABB Arbol)
{
    int AltIzq, AltDer;

    if(Arbol==NULL)
        return -1;
    else
    {
        AltIzq = AlturaAB(Arbol->Izq);
        AltDer = AlturaAB(Arbol->Der);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}
/*Nombre de la funcion: int ContarHojas(ABB Arbol)
Objetivo:       Determinar la cantidad de hojas de un arbol
Parametros:     ABB Arbol, Arbol del que se quiere saber la cantidad de hojas
Retorna:        El numero de hojas que tiene el arbol
*/
int ContarHojas(ABB Arbol)
{
    if (Arbol==NULL)
    {
        return 0;
    }
    if ((Arbol->Der ==NULL)&&(Arbol->Izq ==NULL))
    {
        return 1;
    }
    else
    {
        return ContarHojas(Arbol->Izq) + ContarHojas(Arbol->Der);
    }
}
/*Nombre de la funcion: int BuscarPadre(ABB Arbol, int Nodo, int p)
Objetivo:       Determinar el nodo padre de un dato o un nodo
Parametros:     ABB Arbol, Arbol en el que estan el nodo y el nodo padre
                int Nodo, Nodo del que se quiere saber el padre
                int p, auxiliar que lleva el dato del nodo padre
Retorna:        El dato del nodo padre del nodo dado
*/
int BuscarPadre(ABB Arbol, int Nodo, int p)
{
     if(Arbol==NULL)
        return -1;

     if(Nodo < Arbol->Num){
        p = Arbol->Num;
        BuscarPadre(Arbol->Izq, Nodo, p);
     }
     else if(Nodo > Arbol->Num){
        p = Arbol->Num;
        BuscarPadre(Arbol->Der, Nodo, p);
     }
     else
        return p;

}
/*Nombre de la funcion: void auxContador(ABB nodo, int *c)
Objetivo:       Contar nodos, de forma recursiva recorre en preorden, y aumenta el
                contador
Parametros:     ABB nodo, arbol al que se le van a contar los nodos
                int *c, contador para los nodos
Retorna:        Cambia el contador, que al ser paso por referencia, va guardando
                la cantidad de nodos que hay en el arbol
*/
void auxContador(ABB nodo, int *c)
{
   (*c)++; /* Otro nodo */
   /* Continuar recorrido */
   if(nodo->Izq) auxContador(nodo->Izq, c);
   if(nodo->Der)   auxContador(nodo->Der, c);
}
/*Nombre de la funcion: PesoArbol(ABB Arbol, int *Peso)
Objetivo:       Llamar a la funcion que se encarga de contar de forma recursiva los nodos,
                pasandole por referencia el contador que va a retonar con la cantidad
                de nodos del arbol
Parametros:     ABB nodo, arbol al que se le van a contar los nodos
                int *Peso, contador para los nodos y el valor que retorna
Retorna:        int *Peso, Cantidad de nodos del arbol
*/
int PesoArbol(ABB Arbol, int *Peso)
{
    *Peso = 0;
   auxContador(Arbol, Peso); /* Función auxiliar */
   return *Peso;
}
/*Nombre de la funcion: void AuxComp(ABB Arbol, int *May)
Objetivo:       Comparar nodos, de forma recursiva recorre en preorden, modifica la variable
                guarda el dato mayor del arbol
Parametros:     ABB Arbol, arbol al que se le comparan los nodos
                int *May, variable que guarda el dato mayor del arbol
Retorna:        Cambia la variable, que al ser paso por referencia, va guardando
                el dato mayor del arbol
*/
void AuxComp(ABB Arbol, int *May)
{
    if(Arbol->Num > (*May))
        (*May)=Arbol->Num;

    if(Arbol->Izq)
        AuxComp(Arbol->Izq, May);
    if(Arbol->Der)
        AuxComp(Arbol->Der, May);
}
/*Nombre de la funcion: int ElMayor(ABB Arbol, int *May)
Objetivo:       Llamar a la funcion que se encarga de comparar de forma recursiva los
                nodos, pasandole por referencia la variable que va a retornar con el
                mayor dato del arbol
Parametros:     ABB Arbol, arbol del que se quiere saber el mayor dato
                int *May, Variable que guarda el valor mayor
Retorna:        int *May
*/
int ElMayor(ABB Arbol, int *May)
{
    *May = Arbol->Num;
    AuxComp(Arbol, May);
    return *May;
}
/*Nombre de la funcion: bool SonIguales(ABB Arbol1, ABB Arbol2)
Objetivo:       Determinar si dos arboles son iguales
Parametros:     ABB Arbol1, ABB Arbol2, los arboles que se quieren comparar
Retorna:        true si son iguales, false si no lo son
*/
bool SonIguales(ABB Arbol1, ABB Arbol2)
{
    if(Arbol1 != NULL){
        if(Arbol1->Num != Arbol2->Num)
            return false;
        else{
            SonIguales(Arbol1->Der, Arbol2->Der);
            SonIguales(Arbol1->Izq, Arbol2->Izq);
        }
    }
    if(Arbol2 == NULL)
        return true;
    else
        return false;
}
/*Nombre de la funcion: bool SonPrimos(ABB Arbol, int Num1, int Num2)
Objetivo:       Determinar si los padres de dos Nodos son hermanos, lo que haria que
                estos nodos sean primos
Parametros:     ABB Arbol, Arbol donde se encuentran los nodos
                int Num1, int Num2, los nodos de los que se quiere saber si son o no primos
Retorna:        true si son primos, false si no lo son
*/
bool SonPrimos(ABB Arbol, int Num1, int Num2)
{
    int P1, P2, P3, P4;
    P1 = BuscarPadre(Arbol, Num1, 0);
    P2 = BuscarPadre(Arbol, Num2, 0);

    P3 = BuscarPadre(Arbol, P1, 0);
    P4 = BuscarPadre(Arbol, P2, 0);

    if(P3 == P4)
        return true;
    else
        return false;
}
