#include<bits/stdc++.h>
using namespace std;
struct item{
	int value;
	int weight;
};

float ks(item item[10], int n, int w,vector<vector<int>>& dp){
	if(n==0 || w==0) return dp[n][w]=0;
	else if(dp[n][w]!=-1) return dp[n][w];
	else{
	if(item[n-1].weight<=w)
	  return dp[n][w]=max(item[n-1].value+ks(item,n-1,w-item[n-1].weight,dp),ks(item,n-1,w,dp));
	else
	  return dp[n][w] = ks(item,n-1,w,dp);
}
}
int main(){
	int n;
	cin>>n;
	item item[n];
	for(int i=0;i<n;i++)
	   cin>>item[i].value>>item[i].weight;
	int w;
	cin>>w;
	vector<vector<int>> dp(n,vector<int>(n,-1));
	float res=ks(item,n,w,dp);
	cout<<"max profit: "<<dp[n][w];
	return 0;
}