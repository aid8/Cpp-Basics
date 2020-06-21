//By Aid
//https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/tutorial/

#include <iostream>
using namespace std;

int main()
{
    int size, steps, i, j, min, stepCount = 0;
    cin >> size >> steps;
    int nArray[size];
    for(i = 0; i < size; ++i) cin >> nArray[i];
    for(i = 0; i < size-1; ++i)
    {
        min = i;
        for(j = i+1; j < size; ++j) if(nArray[j] < nArray[min]) min = j;
        swap (nArray[min], nArray[i]) ;
        stepCount++;
        if(stepCount >= steps) break;
    }
    for(i = 0; i < size; ++i) cout << nArray[i] << " ";
    return 0;
}
