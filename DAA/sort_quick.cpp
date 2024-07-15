#include<bits/stdc++.h>
using namespace std;
void qs(int a[],int st,int end){
	int i,j,p;
	if(st<end){
		i=st; j=end; p=st;
		while(i<j){
			while(a[i]<=a[p] and i<=end) i++;
			while(a[j]>a[p]) j--;
			if(i<j)
			 swap(a[i],a[j]);
		}
		swap(a[j],a[p]);
		qs(a,st,j-1);
		qs(a,j+1,end);
	}
}
int main(){
	int n;
	cout<<"enter n: ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	   cin>>a[i];
	cout<<"before sort: ";
	for(int i=0;i<n;i++)
	 cout<<a[i]<<" ";
	cout<<endl;
	qs(a,0,n-1);
		cout<<"after sort: ";
	for(int i=0;i<n;i++)
	 cout<<a[i]<<" ";

	
}
