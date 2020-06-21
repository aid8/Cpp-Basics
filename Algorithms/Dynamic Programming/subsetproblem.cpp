#include <iostream>
#include <vector>
using namespace std;

//checks if there is a subset that adds to the total

bool subset(vector<int> nums, int sum){
	int l = nums.size(), i, j;
	bool dp[l+1][sum+1];
	for(i = 0; i <= l; ++i) dp[i][0] = true;
	for(i = 1; i <= sum; ++i) dp[0][i] = false; 
	
	for(i = 1; i <= l; ++i){
		for(j = 1; j <= sum; ++j){
			if(j-nums[i-1] < 0) dp[i][j] = dp[i-1][j];
			else dp[i][j] = (dp[i-1][j-nums[i-1]] || dp[i-1][j]);
		}
	}
	
	return dp[l][sum];
}

int main(){
	vector<int> nums = {3,34,4,12,5,2};
	int sum = 45;
	if(subset(nums, sum)) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}
