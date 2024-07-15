#include<bits/stdc++.h>
using namespace std;

int prims(int node,vector<vector<int>> &graph, int v,vector<vector<int>>& mst){
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int,int>>> > pq;
		vector<int> vis(v,0);
		int cost=0;
		pq.push({0,{-1,0}});
		while(!pq.empty()){
			int weight=pq.top().first;
			int parent=pq.top().second.first;
			int node=pq.top().second.second;
			pq.pop();
			if(vis[node]==1)
				continue;
			vis[node]=1;
			cost=cost+weight;
			mst.push_back({parent,node});
			for(int i=0;i<v;i++){
				if(graph[node][i]!=0 and vis[i]==0)
					pq.push({graph[node][i],{node,i}});
			}
		}
		return cost;
}

int main(){
	int v;
	cin>>v;
	vector<vector<int>> graph(v,vector<int>(v,0));
	cout<<"hello"<<endl;
	//cout<<"if no edge enter 0.. \n if edge enter the weight of an edge..";
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			int w; cin>>w; graph[i][j]=w;
		}
	}
	vector<vector<int>> mst;

	cout<<prims(0,graph,v,mst);

	cout<<endl;
	for(int i=0;i<v;i++){
		for(int j=0;j<2;j++)
		cout<<mst[i][j]<<" ";
	   cout<<endl;
	}
}