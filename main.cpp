#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <int> RadixSort();
int numDigits(int number);


int main() {

    RadixSort();
    return 0;
}


int numDigits(int number)
{
    int digits = 0;
    if (number < 0) digits = 1; // remove this line if '-' counts as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}


vector <int> RadixSort()
{
    // Hardcoded example
    string a = "45";
    string b = "2";
    string c = "0";
    string d = "12";
    string e = "4";
    string f = "189";
    string g = "901";


    vector <string> input;
    input.push_back(a);
    input.push_back(b);
    input.push_back(c);
    input.push_back(d);
    input.push_back(e);
    input.push_back(f);
    input.push_back(g);

    int largestSize = 0;
    for (int i = 0; i < input.size(); ++i) {
        if(input[i].size() > largestSize){
            largestSize = input[i].size();
        }
    }

    vector <int> arr;

    int amountOfZeros = 0;
    int indexOfNumbers = 0;
    int amountOfZerosLoop = 0;
    for (int j = 0; j < input.size(); ++j) {
        amountOfZeros = largestSize -input[j].size();
        amountOfZerosLoop = amountOfZeros;
        while(amountOfZeros > 0)
        {
            arr.push_back(0);
            amountOfZeros--;
        }
        
    }


    vector <int> tmp;

    /*vector < vector <int> > unorderedVectorofV;

    unorderedVectorofV.push_back(a);
    unorderedVectorofV.push_back(b);
    unorderedVectorofV.push_back(c);
    unorderedVectorofV.push_back(d);
    unorderedVectorofV.push_back(e);
    unorderedVectorofV.push_back(f);
    unorderedVectorofV.push_back(g);*/





    return tmp;
}