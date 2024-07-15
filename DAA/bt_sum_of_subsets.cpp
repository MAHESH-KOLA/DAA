#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &a,vector<int> &temp){
	for(int i=0;i<a.size();i++){
		if(temp[i]==1)
			cout<<a[i]<<" ";
	}
	cout<<endl;
}
void subset(int k,vector<int> &a,int n,vector<int> &temp,int s){
	if(k==n){
		int sum=0;
		for(int i=0;i<n;i++){
			if(temp[i]==1) sum+=a[i];
		}
		if(sum==s){
			print(a,temp);
		}
		return;
	}
	for(int i=0;i<2;i++){
		temp[k]=i;
		subset(k+1,a,n,temp,s);
	}
}
int main(){
	int n,s;
	cin>>n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++){ int t; cin>>t; a[i]=t;};
	cin>>s;
	vector<int> temp(n,0);
	subset(0,a,n,temp,s);
	return 0;
}