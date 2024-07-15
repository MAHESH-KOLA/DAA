#include<bits/stdc++.h>
using namespace std;

int omp(int n, vector<int>& v){
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0;i<n;i++) pq.push(v[i]);
	int res=0;
	while(pq.size()>1){
		int a=pq.top();
		pq.pop();
		int b=pq.top();
		pq.pop();
		res+=a+b;
		pq.push(a+b);
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n,0);
	for(int i=0;i<n;i++){
		int input; cin>>input; v[i]=input;
	}
	cout<<omp(n,v);
	return 0;
}