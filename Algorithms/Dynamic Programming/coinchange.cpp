#include<iostream>
#include<vector>
using namespace std;

int coinChange(vector<int> coins, int amt){
	int l = coins.size(), i, j, x, y;
	int dp[l+1][amt+1];
	
	for(i = 0; i <= l; ++i) dp[i][0] = 1;
	for(i = 1; i <= amt; ++i) dp[0][i] = 0;
	
	for(i = 1; i <= l; ++i){
		for(j = 1; j <= amt; ++j){
			x = (j-coins[i-1] < 0) ? 0 : dp[i][j-coins[i-1]];
			dp[i][j] = x + dp[i-1][j];
		}
	}
	return dp[l][amt];
}

int main(){
	vector<int> vi = {1,2,5,3};
	int amount = 5;
	cout << coinChange(vi, amount) << "\n";
	return 0;
}
