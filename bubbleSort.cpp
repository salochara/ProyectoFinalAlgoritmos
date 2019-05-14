//
// Created by Salomón Charabati on 5/13/19.
//
#include <iostream>
#include <vector>
using namespace std;

class BubbleSort{
public:
    vector <int> bubbleVector;
    BubbleSort();
    void bSort();
    void initializeVectorWithRandomNumbers(vector<int> & vector);
    const void printVector();
};

void BubbleSort::initializeVectorWithRandomNumbers(vector<int> & vector) {
    // Inicializa un vector con 10 números aleatrorios entre el 0 y 99
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        vector.push_back(rand() % 100);
    }
}
BubbleSort::BubbleSort() {}

const void BubbleSort::printVector()
{
    // Para imprimir el vector "bubbleVector" de la clase Bubble Sort
    for (int i = 0; i < bubbleVector.size(); ++i) {
        cout << bubbleVector[i] << " ";
    }
    cout << endl;
}

void BubbleSort::bSort()
{
    // El método de ordenamiento Bubble Sort. Se trabaja con el atributo "bubbleVector" de la clase Bubble Sort
    for (unsigned int i = 0; i < bubbleVector.size() ; ++i)
    {
        for (int j = 0; j < bubbleVector.size() - 1; ++j)
        {
            if(bubbleVector[j] > bubbleVector[j+1])
                swap(bubbleVector[j], bubbleVector[j+1]);
        }
    }
}

int main()
{
  // Se inicializa el objeto "bubbleSort" de la clase Bubble Sort
  BubbleSort bubbleSort;

  // Se inicializa el "bubbleVector" con 10 números aleatorios
  bubbleSort.initializeVectorWithRandomNumbers(bubbleSort.bubbleVector);

  // Se imprime a pantalla el vector original
  cout << "The original vector is: " << endl;
  bubbleSort.printVector();
  cout << "----------------------------" << endl;

  // Se aplica el algoritmo de ordenamiento Bubble Sort
  bubbleSort.bSort();

  // Se imprime el vector despues de aplicar BUBBLE SORT
  cout << "The sorted vector after applying BUBBLE SORT is: " << endl;
  bubbleSort.printVector();
}

