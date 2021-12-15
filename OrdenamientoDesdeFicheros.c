#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Autor del codigo: Julian Esteban Collazos Toro

void leerArchivo(long *vect, long n);
void mostrar(long *a, long n);
void hall(long *v, long n, short mode);
void ordInsercion (long  *a, long n);
void ordBurbuja (long *a, int n);
void quicksort(long *a, int primero, int ultimo);
void ordenacionShell(long *a, int n);
int get_max (long *a, long n);
void radix_sort (long *a, long n);
int min(long *arr, int len);
void bucketsort(long *a, long n);
int revisarOtroMetodo();
/*------------------------------------------------------------*/
/*Nombre de la funcion: revisarOtroMetodo()
Objetivo:       Regresar al menu principal, o salir del programa
Parametros:     Ninguno
Retorna:        opc, un entero corto, 1 en caso de que quiera volver al menú, 0 en caso de que quiera salir del programa
Ejemplo:        (Se imprime en pantalla)
                Desea revisar otro metodo de ordenamiento?
                1. Si
                0. No
                (Se ingresa por teclado 1)
                opc=1
                (Se dirige al menu principal)
*/
int revisarOtroMetodo()
{
    short opc;
    do{
        printf("\n\nDesea revisar otro metodo de ordenamiento?\n1. Si\n0. No\n>> ");
        scanf("%hi", &opc);
    }while(opc<0 || opc >1);

    return opc;
}
/*Nombre del proceso: hall(long *v, long n, short mode)
Objetivo:       Es el menu principal, redirige a cualquiera de los metodos de ordenamiento
Parametros:     long *v, puntero a vector con los datos a organizar
                long n, cantidad de datos a organizar
                short mode, es el valor que retorna la funcion revisarOtroMetodo, valida si presentar el menu o no.
Retorna:        Llama a la funcion correspondiente al metodo de ordenamiento seleccionado

*/
void hall(long *v, long n, short mode)
{
    if(mode == 1){
        system("cls");
        leerArchivo(v,n);
        short opc;
        float tiempo;
        clock_t inicio, fin;
        printf("\nVector sin ordenar: \n");
        //mostrar(v, n);
        printf("\n\nIngrese el metodo para organizar: \n");
        printf("1. Metodo Insercion directa.\n2. Metodo Burbuja.\n");
        printf("3. Metodo quicksort\n4. Metodo Shell.\n5. Metodo Radixsort.\n6. Metodo binsort.\n>> ");
        scanf("%hi", &opc);
        switch(opc){
            case 1:
                ordInsercion(v, n);
                break;
            case 2:
                ordBurbuja(v, n);
                break;
            case 3:
                inicio=clock();
                quicksort(v, 0, n);
                fin=clock();
                tiempo=(double)(fin-inicio)/CLOCKS_PER_SEC;
                printf("Tiempo: %f\nVector ordenado: \n", tiempo);
                //mostrar(v, n);
                hall(v, n, revisarOtroMetodo());
                break;
            case 4:
                ordenacionShell(v, n);
                break;
            case 5:
                printf("\nMetodo Radixsort: \n");
                radix_sort (v, n);
                printf ("Sorted items : \n");
                //mostrar(v, n);
                hall(v, n, revisarOtroMetodo());
                break;
            case 6:
                printf("\nMetodo Binsort: \n");
                bucketsort(v, n);
                //mostrar(v, n);
                hall(v, n, revisarOtroMetodo());
        }
    }
}
/*Nombre del proceso: ordInsercion (long  *a, long n)
Objetivo:       Ordena los datos de un vector numerico
Parametros:     long *a, puntero al vector a ordenar
                long n, cantidad de datos a ordenar
Retorna:        Ordena los datos en el vector dado e imprime en pantalla el tiempo que se demora en organizarlos
Ejemplo:        long a={2,7,4,20,15)
                Despues de la ejecucion
                long a={2,4,7,15,20}
                (Se imprime en pantalla)
                Tiempo 0,00000
*/
void ordInsercion (long  *a, long n)
{
    long i, j;
    int aux;
    float tiempo;
    clock_t inicio, fin;
    inicio=clock();
    for (i = 1; i < n; i++)
    {
        j = i;
        aux = *(a + i);
        while (j > 0 && aux < a[j-1])
        {
            *(a+j) = *(a+j-1);
            j--;
        }
            *(a+j) = aux;
    }
    fin=clock();
    tiempo=(double)(fin-inicio)/CLOCKS_PER_SEC;
    printf("Tiempo: %f\nVector ordenado: \n", tiempo);
    //mostrar(a,n);
    hall(a, n, revisarOtroMetodo());
}
/*Nombre del proceso: ordBurbuja (long *a, int n)
Objetivo:       Ordena los datos de un vector numerico
Parametros:     long *a, puntero al vector a ordenar
                long n, cantidad de datos a ordenar
Retorna:        Ordena los datos en el vector dado e imprime en pantalla el tiempo que se demora en organizarlos
Ejemplo:        long a={2,7,4,20,15)
                Despues de la ejecucion
                long a={2,4,7,15,20}
                (Se imprime en pantalla)
                Tiempo 0,00000
*/
void ordBurbuja (long *a, int n)
{
    int interruptor = 1;
    long pasada, j;
    float tiempo;
    clock_t inicio, fin;
    inicio=clock();
    for (pasada = 0; pasada < n-1 && interruptor; pasada++)
    {
        interruptor = 0;
        for (j = 0; j < n-pasada-1; j++)
            if (*(a+j) > *(a+j+1))
            {
                long aux;
                interruptor = 1;
                aux = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = aux;
            }
    }
    fin=clock();
    tiempo=(double)(fin-inicio)/CLOCKS_PER_SEC;
    printf("Tiempo: %f\nVector ordenado: \n", tiempo);
    //mostrar(a, n);
    hall(a, n, revisarOtroMetodo());
}
/*Nombre del proceso: quicksort(long *a, int primero, int ultimo)
Objetivo:       Ordena los datos de un vector numerico
Parametros:     long *a, puntero al vector a ordenar
                long n, cantidad de datos a ordenar
Retorna:        Ordena los datos en el vector dado e imprime en pantalla el tiempo que se demora en organizarlos
Ejemplo:        long a={2,7,4,20,15)
                Despues de la ejecucion
                long a={2,4,7,15,20}
                (Se imprime en pantalla)
                Tiempo 0,00000
*/
void quicksort(long *a, int primero, int ultimo)
{
    long i, j, central;
    double pivote;
    central = (primero + ultimo)/2;
    pivote = *(a+central);
    i = primero;
    j = ultimo;
    do {
        while (*(a+i) < pivote) i++;
        while (*(a+j) > pivote) j--;
        if (i<=j)
        {
            long tmp;
            tmp = *(a+i);
            *(a+i) = *(a+j);
            *(a+j) = tmp; /* intercambia a[i] con a[j] */
            i++;
            j--;
        }
    }while (i <= j);
    if (primero < j)
        quicksort(a, primero, j);/* mismo proceso con sublista izqda */
    if (i < ultimo)
        quicksort(a, i, ultimo); /* mismo proceso con sublista drcha */
}
/*Nombre del proceso: ordenacionShell(long *a, int n)
Objetivo:       Ordena los datos de un vector numerico
Parametros:     long *a, puntero al vector a ordenar
                long n, cantidad de datos a ordenar
Retorna:        Ordena los datos en el vector dado e imprime en pantalla el tiempo que se demora en organizarlos
Ejemplo:        long a={2,7,4,20,15)
                Despues de la ejecucion
                long a={2,4,7,15,20}
                (Se imprime en pantalla)
                Tiempo 0,00000
*/
void ordenacionShell(long *a, int n)
{
    int intervalo, i, j, k;
    float tiempo;
    clock_t inicio, fin;
    inicio=clock();
    intervalo = n / 2;
    while (intervalo > 0)
    {
        for (i = intervalo; i < n; i++)
        {
            j=i- intervalo;
            while (j >= 0)
            {
                k=j+ intervalo;
                if (*(a+j) <= *(a+k))
                    j = -1; /* así termina el bucle, par ordenado */
                else
                {
                    double temp;
                    temp = *(a+j);
                    *(a+j) = *(a+k);
                    *(a+k) = temp;
                    j -= intervalo;
                }
            }
        }
    intervalo = intervalo / 2;
    }
    fin=clock();
    tiempo=(double)(fin-inicio)/CLOCKS_PER_SEC;
    printf("Tiempo: %f\nVector ordenado: \n", tiempo);
    //mostrar(a,n);
    hall(a, n, revisarOtroMetodo());
}
/*Nombre del proceso: get_max (long *a, long n)
Objetivo:       Busca el valor maximo dentro de un vector numerico
Parametros:     Parametros:     long *a, puntero al vector
                long n, cantidad de datos dentro de los que se busca el mayor
Retorna:        int max, un entero con el dato de mayor valor
Ejemplo:        long a={2,7,4,20,15)
                max=20
*/
int get_max (long *a, long n)
{
   int max = *a;
   for (long i = 1; i < n; i++)
      if (*(a+i) > max)
         max = *(a+i);
   return max;
}
/*Nombre del proceso: radix_sort (long *a, long n)
Objetivo:       Ordena los datos de un vector numerico
Parametros:     long *a, puntero al vector a ordenar
                long n, cantidad de datos a ordenar
Retorna:        Ordena los datos en el vector dado e imprime en pantalla el tiempo que se demora en organizarlos
Ejemplo:        long a={2,7,4,20,15)
                Despues de la ejecucion
                long a={2,4,7,15,20}
                (Se imprime en pantalla)
                Tiempo 0,00000
*/
void radix_sort (long *a, long n){
   long bucket[1000][100], bucket_cnt[10];
   long i, j, k, r, NOP = 0, divisor = 1, pass;
   int lar;
   float tiempo;
   clock_t inicio, fin;
   inicio=clock();
   lar = get_max (a, n);
   while (lar > 0){
      NOP++;
      lar /= 10;
   }
   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < n; i++){
         r = (*(a+i) / divisor) % 10;
         bucket[r][bucket_cnt[r]] = *(a+i);
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            *(a+i) = bucket[k][j];
            i++;
         }
      }
      divisor *= 10;
//      printf ("After pass %d : \n", pass + 1);
//      for (i = 0; i < n; i++)
//         printf ("%i ", *(a+i));
//      printf ("\n");
   }
   fin=clock();
   tiempo=(double)(fin-inicio)/CLOCKS_PER_SEC;
   printf("Tiempo: %f\n", tiempo);
}
/*Nombre del proceso: int min(long *arr, int len)
Objetivo:       Busca el valor minimo dentro de un vector numerico
Parametros:     long *arr, puntero al vector
                long len, cantidad de datos dentro de los que se busca el menor
Retorna:        int minimo, un entero con el dato de menor valor
Ejemplo:        long a={2,7,4,20,15)
                minimo=2
*/
int min(long *arr, int len){
	long i=0;
	int minimo = *arr;
	for (i = 0; i < len; i++) {
		if(*(arr+i) < minimo)
			minimo = *(arr+i);
	}
	return minimo;
}
/*Nombre del proceso: bucketsort(long *arreglo, long len)
Objetivo:       Ordena los datos de un vector numerico
Parametros:     long *a, puntero al vector a ordenar
                long n, cantidad de datos a ordenar
Retorna:        Ordena los datos en el vector dado e imprime en pantalla el tiempo que se demora en organizarlos
Ejemplo:        long a={2,7,4,20,15)
                Despues de la ejecucion
                long a={2,4,7,15,20}
                (Se imprime en pantalla)
                Tiempo 0,00000
*/
void bucketsort(long *arreglo, long len){
	long i,j;
	float tiempo;
    clock_t inicio, fin;
    inicio=clock();
	//Definir valor mínimo y máximo dentro del arreglo
	int minimo = min(arreglo, len);
	int maximo = get_max(arreglo, len);
	int tamanio = maximo - minimo +1;

	//Crear casillero con todos los valores inicializados con 0
	int *casillas = (int*)malloc(tamanio * sizeof(int));
	memset(casillas, 0, tamanio*sizeof(int));

	i=j=0;
	//Sumar 1 en el casillero correspondiente al valor del arreglo
	for (i = 0; i < len; i++) {
		casillas[*(arreglo+i) - minimo]++;
	}

	i=0;
	//Recorrer casilleros
	for (j = 0; j < tamanio; j++) {
		//Verificar que el casillero no está vacío
		while(*(casillas+j)>0){
			//Sacar un elemento del casillero
			casillas[j]--;
			//Cargar valor en el arreglo
			*(arreglo+i) = j+minimo;
			i++;
		}
	}
	fin=clock();
    tiempo=(double)(fin-inicio)/CLOCKS_PER_SEC;
    printf("Tiempo: %f\n", tiempo);
}
/*Nombre del proceso: mostrar(long *a, long n)
Objetivo:       Imprime en pantalla los datos dentro de un vector
Parametros:     long *a, puntero al vector
                long n, cantidad de datos a mostrar
Retorna:        Muestra en pantalla todos los datos que se encuentran en un vector
Ejemplo:        long a={2,7,4,20,15)
                (Muestra en pantalla)
                2 7 4 20 15
*/
void mostrar(long *a, long n)
{
    for(long i=0; i<n; i++){
        printf("%i ", *(a+i));
    }
}
/*Nombre del proceso: leerArchivo(long *vect, long n)
Objetivo:       Leer desde un archivo los datos y almacenarlos en un vector
Parametros:     long *vect, puntero al vector donde se almacenan los datos
                long n, cantidad de datos a guardar
Retorna:        Guarda los datos dentro del vector
Ejemplo:        (En el archivo)
                2 7 4 20 15
                (Despues de ejecucion)
                vect={2,7,4,20,15}
*/
void leerArchivo(long *vect, long n)
{
    FILE* archivo=fopen("datos.txt", "r");
    long i;
    char cadena[10];
    if(archivo == NULL){
        printf("El archivo no se pudo abrir...\n");
        system("pause");
    }
    else{
        printf("El archivo fue abierto correctamente...\n");
        i=0;
        while(i<n){
            fscanf(archivo,"%i",&vect[i]);
            i++;
        }
    }
    fclose(archivo);
}

int main()
{
    long n;
    printf("Cuantos datos desea leer del archivo: ");
    scanf("%ld", &n);
    long v[n];
    hall(v, n, 1);
    return 0;
}
