#include<bits/stdc++.h>
using namespace std;
void print(vector<int> a,int n){
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int issafe(int pos,int val,vector<int> &a){
	for(int i=0;i<pos;i++){
		if(a[i]==val || abs(pos-i)==abs(a[i]-val))
			return false;
	}
	return true;
}
void queen(int k,int n,vector<int> &a){
	if(k==n){
	  print(a,n);
	  return;
	}
	for(int i=0;i<n;i++){
		if(issafe(k,i,a)){
			a[k]=i;
			queen(k+1,n,a);
		}
	}

}

int main(){
	int n;
	cin>>n;
	vector<int> a(n,0);
	queen(0,n,a);
	return 0;
}