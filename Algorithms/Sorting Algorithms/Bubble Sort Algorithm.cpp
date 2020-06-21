//By Aid
//Link: https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/tutorial/

#include <iostream>
using namespace std;

int main()
{
    int size, i, j, swaps = 0; cin >> size;
    int nArray[size];
    for(i = 0; i < size; ++i) cin >> nArray[i];
    for(i = 0; i < size-1; ++i){
        for(j = 0; j < size-i-1; ++j){
            if(nArray[j] > nArray[j+1]){
                swap(nArray[j],nArray[j+1]);
                swaps++;
            }
        }
    }
    cout << swaps << endl;
    return 0;
}
