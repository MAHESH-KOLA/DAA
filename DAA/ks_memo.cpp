#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
	int ks(vector<int>& wt, vector<int>& values, int n,int s){
		vector< vector<int> > dp(n+1,vector<int> (s+1)); 
		for(int i=0;i<=n;i++){
			for(int j=0;j<=s;j++){
					if(j==0 || i==0)
		           dp[i][j]=0;
		           else{
			if(wt[i-1]<=j)
			 dp[i][j]=max(values[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			else
			 dp[i][j]=dp[i-1][j];
			}
		}
		}
		return dp[n][s];
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
     int res=sol.ks(wt,values,n,s);
  cout<<res;
  return 0;
}
