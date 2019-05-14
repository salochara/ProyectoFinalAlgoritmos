//
// Created by Salomón Charabati on 5/13/19.
//
#include <iostream>
#include <queue>
#include <vector>
#include <time.h>
using namespace std;

class RadixSort {
public:
    RadixSort();
    void distributeToDigitQueue(const vector <int> & vector , queue <int> digitQueue[], int power);
    void collect(queue <int> digitQueue [], vector <int> & vector);
    void radixSort(vector <int> & v, int maxDigits);
    void initializeVectorWithRandomNumbers(vector <int> &);
    void printVector(const vector <int> &);
    int maxDigitNumber(const vector <int> &);
};

RadixSort::RadixSort(){}

void RadixSort::distributeToDigitQueue(const vector<int> & vector, queue<int> digitQueue [] , int power)
{
    // Distribuye en el digitQueue[n] los valores correspondientes. Es decir, mete los valores en los 10 queues que hay (de 0 a 9)
    // El power es para el digito que se esta analizando
    // i.e. con power = 1000, 78654/1000 = 78, 78 % 10 = 8. Por lo tanto, va al queue [8]
    for (int i = 0; i < vector.size() ; ++i) {
        digitQueue[(vector[i] / power) % 10 ].push(vector[i]);
    }
}

void RadixSort::collect(queue<int> digitQueue [], vector<int> & vector)
{
    // Saca los valores de todos los queueues (desde el 0 al 9) y los copiarlos al vector que recibe por referencia.
    // Se usa la función front() para tomar el primer elemento y pop() para sacar el primer elemento del queue.
    int i = 0;
    for (int digit = 0; digit < 10 ; ++digit)
    {
        while(!digitQueue[digit].empty())
        {
            vector[i] = digitQueue[digit].front();
            digitQueue[digit].pop();
            ++i;
        }
    }
}

void RadixSort::radixSort(vector<int> & vector, int maxDigits)
{
    // implementación del método radixSort en donde se declara un array de 10 queues para utilizarlos como "buckets" del 0 al 9.
    // se inicializa power en 10 para empezar por el dígito 1, leyendo de derecha a izquierda
    int power = 10;
    queue <int> digitQueue[10];

    for (int i = 0; i < maxDigits; ++i)
    {
        distributeToDigitQueue(vector, digitQueue, power);
        collect(digitQueue, vector);
        power *= 10;
    }
}

void RadixSort::initializeVectorWithRandomNumbers(vector<int> & vector)
{
    // Inicializa un vector con 10 números aleatrorios entre el 0 y 9,999
    srand( time(NULL) );
    for (int i = 0; i < 10; ++i)
    {
        vector.push_back(rand() % 10000);
    }
}

void RadixSort::printVector(const vector<int> & vec)
{
    // Para imprimir un vector secuencialmente
    for(int i = 0; i <  vec.size(); ++i){
        cout << vec[i] << " ";
    }
    cout << endl;
}

int RadixSort::maxDigitNumber(const vector<int> & vec)
{
    // Para determinar cual es el número con más digitos dentro de todo el vector.
    // Regresa el número de dígitos.
    vector <int> copyVector = vec;
    // Se hace una copia del vector original para no afectar al vector original.
    int digits = 0;

    for (int i = 0; i < copyVector.size(); ++i)
    {
        int tmp = 0;
        while(copyVector[i]) // mientras siga siendo un número entero
        {
            tmp++;
            copyVector[i] /= 10;
            if(tmp > digits) digits = tmp;
        }
    }
    return digits;
}

int main()
{
    // Se inicializa un vector.
    vector <int> radixVector;

    // Se inicializa una objeto r1 de la clase Radix Sort.
    RadixSort r1;

    // Se le meten valores aleatorios a radixVector. Los valores cambian con cada invocación de la función porque es una "semilla" diferente.
    r1.initializeVectorWithRandomNumbers(radixVector);

    // Se imprime el radixVector, antes de aplicarle Radix Sort
    cout << "The original vector is: " << endl;
    r1.printVector(radixVector);
    cout << "---------------------------------------------"<< endl;

    // Se determina el mayor número de dígitos dentro de "radixVector"
    int maxDigits = r1.maxDigitNumber(radixVector);

    // Se aplica el algoritmo de ordenamiento Radix Sort a radixVector
    r1.radixSort(radixVector, maxDigits);

    // Se imprime el vector ordenado después de aplicar Radix Sort
    cout << "The ordered vector after using RADIX SORT is: " << endl;
    r1.printVector(radixVector);

}