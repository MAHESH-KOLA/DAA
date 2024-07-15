#include<bits/stdc++.h>
using namespace std;

struct point{
	int x;
	int y;
};
void convex(point p[10], int n,set<pair<int,int>> &s){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int a=p[i].y-p[j].y;
			int b=p[j].x-p[i].x;
			int c=p[i].x*p[j].y - p[j].x*p[i].y;
			int pos=0,neg=0;
			for(int k=0;k<n;k++){
				if(k==i || k==j) continue;
				int sign=a*p[k].x + b*p[k].y + c;
		        if(sign<0) neg++;
		        else pos++;
			}
			if(pos==0 or neg==0){
				s.insert(make_pair(p[i].x,p[i].y));
				s.insert(make_pair(p[j].x,p[j].y));
				cout<<endl;
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	point p[n];
	set<pair<int,int>> s;
	for(int i=0;i<n;i++)
		cin>>p[i].x>>p[i].y;
	convex(p,n,s);
	for(auto i:s){
		 cout<<i.first<<" "<<i.second;
		cout<<endl;
	}
}