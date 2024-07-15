#include<bits/stdc++.h>
using namespace std;


int mcm(vector<int> &v,int st,int end,vector<vector<int>> &dp){
	if(st==end) return dp[st][end]=0;  
	if(dp[st][end]!=-1) return dp[st][end];
	int mini=INT_MAX;
	for(int k=st;k<end;k++){
		int val=mcm(v,st,k,dp)+mcm(v,k+1,end,dp)+v[st-1]*v[k]*v[end];
		if(val<mini)
			mini=val;
	}
	dp[st][end]=mini;

}
int main(){
	int n;
	cin>>n;
	vector<int> v(n,0);
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n;i++) cout<<v[i]<<" ";
	cout<<endl;
	vector<vector<int>> dp(n,vector<int>(n,-1));
	cout<<mcm(v,1,n-1,dp);
	}