#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> lis(vector<int> a){
	int l = a.size(), i, j, ans, pos = 0;
	vector<int> dp(l,1), ps(l,-1), ansVec;
	//build table
	for(i = 0; i < l; ++i){
		for(j = 0; j < i; ++j){
			if(a[i] > a[j] && dp[i] < dp[j] + 1){
				dp[i] = dp[j]+1;
				ps[i] = j;
			}
		}
	}
	ans = dp[0];
	for(i = 1; i < l; ++i){
		if(dp[i] > ans){
			ans = dp[i];
			pos = i;
		}
	}
	
	while(pos != -1){ ansVec.push_back(a[pos]); pos = ps[pos]; }
	reverse(ansVec.begin(), ansVec.end());
	return ansVec;
}
//just knowing the size
int lis2(vector<int> a){
	int l = a.size(), i, j, ans = 0;
	vector<int> dp(l,1), ps(l,-1);
	for(i = 0; i < l; ++i){
		for(j = 0; j < i; ++j){
			if(a[j] >= a[i] && dp[i] < dp[j] + 1){
				dp[i] = dp[j]+1;
			}
		}
	}
	for(i = 0; i < l; ++i) ans = max(ans,dp[i]);
	return ans;
}


int main(){
	vector<int> arr = {1,2,3,8,8,6}, ans;
	ans = lis(arr);
	cout << "The longest increasing subsequence is: \n";
	for(auto it : ans) cout << it << " ";
	return 0;
}
