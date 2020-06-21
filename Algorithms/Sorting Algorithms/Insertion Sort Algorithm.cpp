//By Aid
//https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/tutorial/

#include <iostream>
using namespace std;

int main(){
    int n, i, j, k;
    cin >> n;
    int arr[n], arrC[n];
    //Input
    for(i = 0; i < n; ++i){
        cin >> arr[i];
        arrC[i] = arr[i];
    }
    //Process (Insertion sort)
    for(i = 1; i < n; ++i){
        k = i;
        for(j = i-1; j >= 0; --j){
            if(arr[k] < arr[j]){
                swap(arr[k], arr[j]);
                k -= 1;
            }
        }
    }
    //Output
    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            if(arrC[i] == arr[j]) cout << j+1 << " ";
        }
    }
    return 0;
}
