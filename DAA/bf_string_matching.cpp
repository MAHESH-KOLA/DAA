#include<bits/stdc++.h>
using namespace std;

int main(){
	string a;
	cin>>a;
	string b;
	cin>>b;
	int m=a.size();
	int n=b.size();
	int k=0;
	for(int i=0;i<=(m-n);i++){
		if(a[i]==b[0]){
			int ind=i,f=1;
			for(int j=1;j<n;j++){
			   if(a[j+i]!=b[j]){
			    f=0;
			   }
			}
			if(f==1){
			cout<<"yes: "<<i;
			k=1;
			break;
		}
		}
	}
	if(k==0) cout<<"no";
}