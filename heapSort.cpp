#include <iostream>
#include <vector>
#include <time.h>

using namespace std;


class HeapSort{
public:
    HeapSort();
    void initializeVectorWithRandomNumbers(vector<int>&);
    void printVector(const vector<int>&);
    void heapSort(vector<int> &, int n);
    void maxHeapify(vector<int> &, int, int);
};

HeapSort::HeapSort(){}

void HeapSort::initializeVectorWithRandomNumbers(vector<int> & vector)
{
    // Inicializa un vector con 10 números aleatorios entre el 0 y 9,999
    srand( time(NULL) );
    for (int i = 0; i < 10; ++i)
    {
        vector.push_back(rand() % 10000);
    }
}

void HeapSort::printVector(const vector<int> & vec)
{
    // Para imprimir un vector secuencialmente
    for(int i = 0; i <  vec.size(); ++i){
        cout << vec[i] << " ";
    }
    cout << endl;
}

void HeapSort::heapSort(vector<int> & vector, int n){
    for (int i = n/2 - 1; i >=0; --i) {
        maxHeapify(vector, n,i); //suponemos al principio que el mas grande es el nodo raiz
    }
    for (int j = n-1; j >=0; --j) {
        int tmp = vector[j];
        vector[j] = vector[0];
        vector[0] = tmp;

        maxHeapify(vector, j, 0);
    }
}

void HeapSort::maxHeapify(vector <int> & vector, int n,int root){
    int max = root;
    int left = 2*root+1;
    int right = 2*root+2;

    if(left < n && vector[left]>vector[max]){
        max = left;
    }
    if(right < n && vector[right]>vector[max]){
        max = right;
    }

    if(max != root){
        int tmp = vector[root];
        vector[root] = vector[max];
        vector[max] = tmp;
        maxHeapify(vector, n,max);
    }
}

int main(){
    // Se debe que compilar en gcc ++11. El comando es: g++ -std=c++11 heapSort.cpp
    vector <int> heapVector {7,5,90,32,50};
    HeapSort h1;

    cout << "The original vector is:" << endl;
    h1.printVector(heapVector);
    cout << "--------------------------------------------" << endl;

    h1.heapSort(heapVector, heapVector.size());

    cout << "The ordered vector using Heap Sort is:" << endl;
    h1.printVector(heapVector);

    return 0;
}