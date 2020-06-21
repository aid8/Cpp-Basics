#include <iostream>
#include <cmath>
using namespace std;

//knapsack 0/1 problem
//how what is the maximum price that you can get
//if you have a capacity of 8, then 4 items to choose from?

//This solution will use dynamic programming and tabulation method
int main(){
	int cap = 8, items = 4, maximumProfit = 0;
	int price[items] = {1,2,5,6};
	int weight[items] = {2,3,4,5};
	bool toGet[items] = {false};
	//this is where the dp will start
	int dp[items+1][cap+1];
	for(int i = 0; i <= items; ++i){
		//every iteration of the i (items)
		//you are including the items itself and the previous ones
		//you should get the position of the item where you can get the weight
		//then the items beyond the position of the item, 
		//you should consider the previous items as well
		//the formula used for this is:
		//dp[i,j] = max(dp[i-1,j],dp[i-1,j-weight[i]] + price[i])
		for(int j = 0; j <= cap; ++j){
			//i = 0 -> no object included so 0
			//j = 0 -> 0 capacity of bag so 0
			if(i == 0 || j == 0) dp[i][j] = 0;
			else{
				if(j-weight[i-1] < 0) dp[i][j] = dp[i-1][j];
				else dp[i][j] = max(dp[i-1][j], (dp[i-1][j-weight[i-1]] + price[i-1]));
			}
		}
	}
	
	int checker = cap;
	for(int i = items; i >= 1; i--){
		if(dp[i][checker] != dp[i-1][checker]){
			toGet[i-1] = true;
			maximumProfit += price[i-1];
			checker -= weight[i-1];
		}
	}
	
	cout << "DP Table (Computation): \n\n";
	for(int i = 0; i <= items; ++i){
		for(int j = 0; j <= cap; ++j) cout << dp[i][j] << " ";
		cout << "\n";
	}
	cout << "\nIncluded Table:\n";
	for(auto it : toGet) cout << it << " "; cout << "\n";

	cout << "\nMaximum Profit: "<< maximumProfit << "\n";
	return 0;
}
