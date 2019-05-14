//
// Created by Salomón Charabati on 5/13/19.
//
#include <iostream>
#include <vector>
using namespace std;
class BubbleSort{
public:
    BubbleSort ();
    void bSort(vector <int> & );
    void printVector(vector <int>);
};

BubbleSort::BubbleSort() {}

void BubbleSort::printVector(vector <int> bubbleVector)
{
    for (int i = 0; i < bubbleVector.size(); ++i) {
        cout << bubbleVector[i] << " ";
    }
    cout << endl;
}

void BubbleSort::bSort(vector <int> & bubbleVector)
{
    for (int i = i; i < bubbleVector.size() ; ++i)
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
  BubbleSort bubbleSort;
  vector <int> bubbleVector;

  int array [] = {6,7,2,100,8,5,1,0,89};
  int sizeOfArray = sizeof(array) / sizeof(array[0]);

  for (int i = 0; i < sizeOfArray; ++i) {
        bubbleVector.push_back(array[i]);
    }

  bubbleSort.bSort(bubbleVector);

   /* for (int i = 0; i < bubbleSort.bubbleVector.size(); ++i) {
        cout << bubbleSort.bubbleVector[i] << " ";
    }
    cout << endl;*/
  bubbleSort.printVector(bubbleVector);
}

