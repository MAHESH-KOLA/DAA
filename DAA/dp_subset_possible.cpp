#include<bits/stdc++.h>
using namespace std;

bool ks(vector<int>& v,int n, int w,vector<vector<int>>& dp){
	if(n==0) return dp[n][w]=0;
	if(w==0) return dp[n][w]=1;
	else if(dp[n][w]!=-1) return dp[n][w];
	if(v[n-1]<=w)
	  return dp[n][w]=ks(v,n-1,w-v[n-1],dp) || ks(v,n-1,w,dp);
	else
	  return dp[n][w] = ks(v,n-1,w,dp);
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n,0);
	for(int i=0;i<n;i++){
		int in;
		cin>>in;
	     v[i]=in;
	}
	int w;
	cin>>w;
	vector<vector<int>> dp(n,vector<int>(n,-1));
	cout<<ks(v,n,w,dp);
	return 0;
}