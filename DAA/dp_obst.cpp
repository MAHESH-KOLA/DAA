#include<bits/stdc++.h>
using namespace std;
int frequency(vector<int>&freq, int st,int end){
	int sum=0;
	for(int i=st;i<=end;i++)
		sum=sum+freq[i-1];
	return sum;
}
int obst(vector<int> &v,vector<int>& freq,int st,int end,vector<vector<int>> &dp){
	if(st>end) return 0;
   if(st==end) return freq[st-1];
		int mini=INT_MAX;
		for(int k=st;k<=end;k++){
			int val= obst(v,freq,st,k-1,dp)+ obst(v,freq,k+1,end,dp);
			if(val<mini)
				mini=val;
		}
		return mini+frequency(freq,st,end);
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n,0);
	for(int i=0;i<n;i++){ int input; cin>>input; v[i]=input; }
		for(int i=0;i<n;i++) cout<<v[i]<<" ";
			cout<<endl;
	vector<int> freq(n,0);
	for(int i=0;i<n;i++){ int input; cin>>input; freq[i]=input; }
		cout<<endl;
	for(int i=0;i<n;i++) cout<<freq[i]<<" ";
			cout<<endl;
	vector<vector<int>> dp(n,vector<int>(n,-1));
	cout<<obst(v,freq,1,n,dp);
	}