#include<bits/stdc++.h>
using namespace std;

struct item{
	int value;
	int weight;
};
void solve(item item[10],vector<int> &temp,int& maxi,int s,int n){
	int sum=0;
	for(int i=0;i<n;i++){
		if(temp[i]==1) sum+=item[i].value;
	}
	maxi=max(maxi,sum);
}
void ks(int k,item item[10],int n,int s,vector<int> &temp,int &maxi){
	if(k==n){
		int sum=0;
		for(int i=0;i<n;i++){
			if(temp[i]==1) sum+=item[i].weight;
		}
		if(sum<=s){
			solve(item,temp,maxi,s,n);
		}
		return;
	}
	for(int i=0;i<2;i++){
		temp[k]=i;
		ks(k+1,item,n,s,temp,maxi);
	}
}
int main(){
	int n,s;
	cin>>n;
	item item[n];
	for(int i=0;i<n;i++){
		cin>>item[i].value;
		cin>>item[i].weight;
	}
	vector<int> temp(n,0);
	int maxi=0;
	ks(0,item,n,s,temp,maxi);
	cout<<maxi;
	return 0;
}