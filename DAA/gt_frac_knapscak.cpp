#include<bits/stdc++.h>
using namespace std;

struct item{
	int value;
	int weight;
};

int main(){
   int n;
   cin>>n;
   item item[n];
   for(int i=0;i<n;i++)
   	 cin>>item[i].value>>item[i].weight;
   	int capacity;
   	cin>>capacity;
   	multimap<double,pair<int,int>,greater<double> > m;
   	for(int i=0;i<n;i++)
   		m.insert(pair<double,pair<int,int>>
 ((float)item[i].value/(float)item[i].weight, {item[i].value,item[i].weight}));
     float res=0;
   		for(auto lt: m){
   			if(capacity>lt.second.second){
   				res+=lt.second.first;
   				capacity=capacity-lt.second.second;
   			}
   			else{
   				res=res+((float)capacity/(float)lt.second.second)*lt.second.first;
   				break;
   			}
          	}
          	cout<<"sol: "<<res;
}