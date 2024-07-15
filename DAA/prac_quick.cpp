#include<bits/stdc++.h>
using namespace std;
/*
void qs(int a[10], int st,int end){
	if(st<end){
		int i=st;
		int j=end;
		int p=st;
	while(i<j){
		while(a[i]<=a[p] and i<=end)
			i++;
		while(a[j]>a[p])
			j--;
		if(i<j)
			swap(a[i],a[j]);
	}
	swap(a[p],a[j]);
	qs(a,st,j-1);
	qs(a,j+1,end);
}
}
*/

/*
void merge(int a[10], int st,int mid, int end){
	int k=0,temp[end],i=st,j=mid+1;
	while(i<=mid and j<=end){
		if(a[i]<=a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=mid) temp[k++]=a[i++];
	while(j<=end) temp[k++]=a[j++];
	for(int i=0;i<k;i++)
		a[st+i]=temp[i];
}

void divide(int a[10], int st, int end){
	if(st<end){
		int mid=(st+end)/2;
		divide(a,st,mid);
		divide(a,mid+1,end);
		merge(a,st,mid,end);
	}
}
*/
void heapify(int a[10], int st, int end){
	int child,parent;
	for(int i=1;i<=end;i++){
		for(child=i;child>0; child=parent){
			parent=(child-1)/2;
			if(a[child]>a[parent])
				swap(a[child],a[parent]);
		}
	}
}
void heap_sort(int a[10],int st,int end){
	heapify(a,st,end);
	swap(a[0],a[end]);
	for(int i=end-1;i>=0;i--){
		heapify(a,0,i);
		swap(a[0],a[i]);
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
	//qs(a,0,n-1);
	//divide(a,0,n-1);
	heap_sort(a,0,n-1);
		cout<<"after sort: ";
	for(int i=0;i<n;i++)
	 cout<<a[i]<<" ";
	return 0;	
}
