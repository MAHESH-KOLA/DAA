#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
	int ks(vector<int>& wt, vector<int>& values, int n,int s,vector<vector<int>> &dp){
		if(s==0 || n==0)
		  return dp[n][s]=0;
		else if(dp[n][s]!=-1) return dp[n][s];
		else{
			if(wt[n-1]<=s)
			return dp[n][s]=max(values[n-1]+ks(wt,values,n-1,s-wt[n-1],dp),ks(wt,values,n-1,s,dp));
			else
			 return dp[n][s]=ks(wt,values,n-1,s,dp);
		}
	}
};
int main(){
	int n,s;
	cout<<"enter n: ";
	cin>>n;
	cout<<"enter s: ";
	cin>>s;
	Solution sol;
	vector<int> wt;
	vector<int> values;
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		wt.push_back(a);
		cin>>a;
		values.push_back(a);
		}
		vector<vector<int>> dp(n,vector<int>(n,-1));
  int res=sol.ks(wt,values,n,s,dp);
  cout<<res;
  return 0;
}
