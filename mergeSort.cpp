#include <iostream>
using namespace std;

class MergeSort{
public:
    MergeSort();
    void merge(int arr [],int low,int mid,int high);
    void sort(int arr [], int low, int high);
    void printArray(int array [], int size);
};

MergeSort::MergeSort() {}

void MergeSort::merge(int arr [],int low,int mid,int high)
{
    int h,i,j,k;
    int aux [10]; //declaración de arreglo auxuliar. Se utiliza un arreglo auxiliar en memoria por
    // el funcionamiento del Merge Sort
    h=low;
    i=low;
    j=mid+1;

    while(h<=mid && j<=high) //mientras que h sea menor que mid (mitad izquierda) y j sea menor a high (mitad derecha)
    {
        if(arr[h]<=arr[j]){ //condiciones para comparación de valores
            aux[i]=arr[h];
            h++; //aumenta en h (del lado izquierdo del arreglo)
        }
        else {
            aux[i]=arr[j]; //condiciones para comparación de valores
            j++; //aumenta en j (del lado derecho del arreglo)
        }
        i++;
    }
    if(h>mid){ // sobrantes en h o j; que se copien al arreglo auxiliar
        for(k=j;k<=high;k++){
            aux[i]=arr[k];
            i++;
        }
    }
    else{
        for(k=h;k<=mid;k++){
            aux[i]=arr[k];
            i++;
        }
    }
    for(k=low;k<=high;k++){
        arr[k]=aux[k]; //en este for se copian todos los valores del arreglo auxiliar al arreglo oiginal
    }

}
void MergeSort::sort(int arr [], int low, int high)
{
    if(high<=low)
        return;
    int mid = low +(high-low)/2; //calcula el mid
    sort(arr,low,mid); // ordena la miad izquierda del arreglo
    sort(arr,mid+1,high); //ordena la mitad derecha del areglo
    merge(arr,low,mid,high); //merge las dos mitades
}

void MergeSort::printArray(int array [], int size)
{
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Inicialización del objeto "mergeSort" de la clase MergeSort
    MergeSort mergeSort;

    // Declaración de arreglo original
    int arr [10] = {22,8,24,9,1,12,3,80,100,5};
    int sizeOfArray = sizeof(arr) / sizeof(*arr);

    // Impresión del arreglo original
    cout << "The original array is: " << endl;
    mergeSort.printArray(arr, sizeOfArray);

    // Llamada a la función sort
    mergeSort.sort(arr,0,sizeOfArray - 1);

    // Impresión del array después de aplicar el algoritmo de ordenamiento Merge Sort
    cout << "The sorted array after applying MERGE SORT is: " << endl;
    mergeSort.printArray(arr, sizeOfArray);

}

