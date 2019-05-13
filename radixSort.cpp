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
    void radixSort(vector <int> & v, int d);
    void initializeVectorWithRandomNumbers(vector <int> &);
    void printVector(const vector <int> &);
    int maxDigitNumber(const vector <int> &);
};


void RadixSort::distributeToDigitQueue(const vector<int> & vector, queue<int> digitQueue [] , int power)
{
    for (int i = 0; i < vector.size() ; ++i) {
        digitQueue[(vector[i] / power) % 10 ].push(vector[i]);
    }
}

void RadixSort::collect(queue<int> digitQueue [], vector<int> & vector)
{
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

void RadixSort::radixSort(vector<int> & vector, int d)
{
    int power = 10;
    queue <int> digitQueue[10];

    for (int i = 0; i < d; ++i) {
        distributeToDigitQueue(vector, digitQueue, power);
        collect(digitQueue, vector);
        power *= 10;
    }
}

RadixSort::RadixSort(){}

void RadixSort::initializeVectorWithRandomNumbers(vector<int> & vector)
{
    srand( time(NULL) );
    // number between 0 and 9999

    for (int i = 0; i < 10; ++i)
    {
        vector.push_back(rand() % 10000);
    }
}

void RadixSort::printVector(const vector<int> & vec)
{
    for(int i = 0; i <  vec.size(); ++i){
        cout << vec[i] << " ";
    }
    cout << endl;
}

int RadixSort::maxDigitNumber(const vector<int> & vec)
{
   vector <int> copyVector = vec;
    int digits = 0;

    for (int i = 0; i < copyVector.size(); ++i)
    {
        int tmp = 0;
        while(copyVector[i])
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
    vector <int> vector;
    RadixSort r1;
    r1.initializeVectorWithRandomNumbers(vector);
    cout << "The original vector is: " << endl;
    r1.printVector(vector);
    cout << "---------------------------------------------"<< endl;
    r1.radixSort(vector, r1.maxDigitNumber(vector));
    cout << "The ordered vector after using RADIX SORT is: " << endl;
    r1.printVector(vector);


}