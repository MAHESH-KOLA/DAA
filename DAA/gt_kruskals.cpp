#include<bits/stdc++.h>
using namespace std;
int find_min(vector<vector<int>> &graph, int n,int *u,int *v){
	int mini=INT_MAX;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(graph[i][j]!=0 and mini>graph[i][j]){
				mini=graph[i][j];
				*u=i; *v=j;
			}
		}
	}
	return mini;
}
int find_parent(vector<int> &parent, int i){
	while(parent[i]!=-1)
		i=parent[i];
	return i;
}
int kruskals(vector<vector<int>> &graph, int n,vector<vector<int>>& mst,
		vector<int>& parent){
	int mini=0,c=1;
	while(c<n){
		int u,v,pu,pv;
		int min=find_min(graph,n,&u,&v);
		pu=find_parent(parent,u);
		pv=find_parent(parent,v);
		if(pu!=pv){
			parent[pu]=pv;
			mini+=min;
			mst.push_back({u,v});
			c++;
		}
		graph[u][v]=0;
	}
	return mini;
}
int main(){
	int v;
	cin>>v;
	vector<vector<int>> graph(v,vector<int>(v,0));
	//cout<<"if no edge enter 0.. \n if edge enter the weight of an edge..";
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			int w; cin>>w; graph[i][j]=w;
		}
	}
	vector<vector<int>> mst;
	vector<int> parent(v,-1);

	cout<<kruskals(graph,v,mst,parent);
	cout<<endl;
	for(int i=0;i<v;i++){
		for(int j=0;j<2;j++)
		cout<<mst[i][j]<<" ";
	   cout<<endl;
	}
}

/*
6
0 3 0 0 0 7
3 0 5 0 8 0
0 5 0 6 0 4
0 0 6 0 4 0
0 8 0 4 0 2
7 0 4 0 2 0
*/