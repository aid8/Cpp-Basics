#include<iostream>
using namespace std;

int main(){
	
	int arr[5] = {3,-2,1,-2,5};
	int i, m, ans = -9999999, size = 5;
	for(i = 0; i < size; ++i){
	    if(i == 0) m = arr[i];
	    else m = max(arr[i], m+arr[i]);
	    ans = max(ans, m);
	}
	cout << "Maximum subarray sum is " << ans << "\n";
	return 0;
}
