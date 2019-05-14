#include <iostream>
#include <vector>
#include <algorithm> // Para la función swap
using namespace std;

class QuickSort{
public:
    vector <int> arr; // se utiliza un vector para que no se restringa el funcionamiento a un solo tamaño
    void quickSort(int lo, int hi);
    int particion(int lo,int hi);
    const void printArray(int size);
};

const void QuickSort::printArray(int size) {
    for (int i = 0; i <size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void QuickSort::quickSort(int lo, int hi)
{
    if(hi<=lo)
        return;
    int j = particion(lo,hi);
    quickSort(lo,j-1);
    quickSort(j+1,hi);
}

int QuickSort::particion(int lo,int hi)
{
    int pivote=arr[lo];
    int i = lo+1;
    int j = hi;

    while(true)
    {
        while(true)
        {
            if(arr[i]<pivote)
            i++;
            else
                break;
        }
        while(true)
        {
        if(arr[j]>pivote)
            j--;
        else
            break;
        }

     if(i>=j)
         break;
    else
        swap(arr[j],arr[i]);
    }
    swap(arr[j],arr[lo]); // el pivote lo pone en la posición excata
                          // en donde va en el arreglo ordenado
    return j;
}

int main()
{
    QuickSort qSort;
    int array [] = { 3,2,90,7,68,0,100,28,200 };
    int n = sizeof(array) / sizeof(array[0]);

    vector<int> arr(array, array + n);
    qSort.arr = arr;
    cout << "The unsorted array is:" << endl;
    qSort.printArray(n);
    cout << "---------------------------------------------"<< endl;
    qSort.quickSort(0,n-1);
    cout << "The sorted array using QUICK SORT is:" << endl;
    qSort.printArray(n);

}