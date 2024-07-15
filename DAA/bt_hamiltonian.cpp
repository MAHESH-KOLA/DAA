#include<bits/stdc++.h>
using namespace std;
#define v 3
void print(int path[v]){
	for(int i=0;i<v;i++)
	    cout<<path[i]<<" ";
	  cout<<path[0];
}
bool issafe(int graph[v][v],int path[v],int pos,int val){
	if(graph[path[pos-1]][val]==0) return false;
	for(int i=0;i<pos;i++){
			if(path[i]==val) return false;
	}
	return true;
}
bool solve(int graph[v][v],int path[v],int pos){
	if(pos==v){
	   if(graph[path[pos-1]][path[0]]==1) return true;
	   else return false;
	}
	for(int i=1;i<v;i++){
		if(issafe(graph,path,pos,i)){
		    path[pos]=i;
		    if(solve(graph,path,pos+1)==1)
		      return true;
		    path[pos]=-1;
		}
	}
	return false;
}
bool hamiltonian(int graph[v][v]){
	int path[v];
	for(int i=0;i<v;i++) path[i]=-1;
	path[0]=0;
	if(solve(graph,path,1)==0){
	cout<<"no cycle";
	return 0;
	}
	print(path);
	return 1;
}
int main(){
	int graph[v][v];
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++)
		 cin>>graph[i][j];
	}
	hamiltonian(graph);
	return 0;
}