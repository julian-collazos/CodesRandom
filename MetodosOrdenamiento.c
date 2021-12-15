#include <stdio.h>
void hall(int ord);
void mostrar(int *a, int n);
void ordInsercion (int  a[], int n);
void ordBurbuja (int *a, int n);
void quicksort(int *a, int primero, int ultimo);
void ordenacionShell(int *a, int n);
int get_max (int *a, int n);
void radix_sort (int *a, int n);
/*------------------------------------------------------------*/
void hall(int ord)
{
    int v[]={15, 10, 4, 14, 8, 12, 20, 6, 13, 9, 3, 7, 2, 6, 11, 5, 16, 1, 18, 17, 19};
    printf("\n\nVector sin ordenar: \n");
    mostrar(v, 21);
    switch(ord){
        case 1:
            ordInsercion(v, 21);
            break;
        case 2:
            ordBurbuja(v, 21);
            break;
        case 3:
            quicksort(v, 0, 20);
            printf("\n\nMetodo Quicksort: \n");
            mostrar(v, 21);
            hall(4);
            break;
        case 4:
            ordenacionShell(v, 21);
            break;
        case 5:
            printf("\n\nMetodo Radixsort: \n");
            radix_sort (v, 21);
            printf ("Sorted items : ");
            mostrar(v, 21);
            break;

    }
}
void mostrar(int *a, int n)
{
    for(int i=0; i<n; i++){
        printf("%i ", *(a+i));
    }
}
void ordInsercion (int  *a, int n)
{
    int i, j;
    int aux;
    for (i = 1; i < n; i++)
    {
    /* índice j explora la sublista a[i-1]..a[0] buscando la
    posición correcta del elemento destino, lo asigna a a[j] */
        j = i;
        aux = *(a + i);
        /* se localiza el punto de inserción explorando hacia abajo */
        while (j > 0 && aux < a[j-1])
        {
            /* desplazar elementos hacia arriba para hacer espacio */
            *(a+j) = *(a+j-1);
            j--;
        }
            *(a+j) = aux;
    }
    printf("\n\nMetodo Insercion directa: \n");
    mostrar(a,21);
    hall(2);
}
void ordBurbuja (int *a, int n)
{
    int interruptor = 1;
    int pasada, j;
    for (pasada = 0; pasada < n-1 && interruptor; pasada++)
    {
        /* bucle externo controla la cantidad de pasadas */
        interruptor = 0;
        for (j = 0; j < n-pasada-1; j++)
            if (*(a+j) > *(a+j+1))
            {
                /* elementos desordenados, es necesario intercambio */
                long aux;
                interruptor = 1;
                aux = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = aux;
            }
    }
    printf("\n\nMetodo La Burbuja: \n");
    mostrar(a,21);
    hall(3);
}
void quicksort(int *a, int primero, int ultimo)
{
    int i, j, central;
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
            int tmp;
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
void ordenacionShell(int *a, int n)
{
    int intervalo, i, j, k;
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
    printf("\n\nMetodo Shell: \n");
    mostrar(a,21);
    hall(5);
}
int get_max (int *a, int n){
   int max = a[0];
   for (int i = 1; i < n; i++)
      if (*(a+i) > max)
         max = *(a+i);
   return max;
}
void radix_sort (int *a, int n){
   int bucket[10][10], bucket_cnt[10];
   int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
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
//      printf ("After pass %d : ", pass + 1);
//      for (i = 0; i < n; i++)
//         printf ("%i ", *(a+i));
//      printf ("\n");
   }
}
int main()
{
    hall(1);

    return 0;
}
