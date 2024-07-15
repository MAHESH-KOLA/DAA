#include<bits/stdc++.h>
using namespace std;

int mcc(int coins[],int n,int s,vector< vector<int> > &dp){
	if(n==0)
	  return dp[n][s]=0;
	if(s==0)
	 return dp[n][s]=1;
	 if(dp[n][s]!=-1)
	  return dp[n][s];
	if(coins[n-1]<=s)
	  return dp[n][s]=(mcc(coins,n-1,s-coins[n-1],dp) + mcc(coins,n-1,s,dp));
	else
	  return dp[n][s]=mcc(coins,n-1,s,dp); 
}


int main(){
	int n;
	cout<<"enter no. of coins: ";
	cin>>n;
	int coins[n];
	cout<<"enter coins: ";
	for(int i=0;i<n;i++)
	   cin>>coins[i];
	int s;
	cout<<"enter sum to make: ";
	cin>>s;
	vector< vector<int> > dp(n+1,vector<int>(s+1,-1));
	int res=mcc(coins,n,s,dp);
	cout<<res;
}
