#include<bits/stdc++.h>
using namespace std;

struct point{
	int x;
	int y;
};
bool compareX(point a, point b){
	return a.x < b.x;
}
float bruteforce(point p[10],int st,int end){
	float mini=FLT_MAX-1000;
	for(int i=st;i<end;i++){
		for(int j=i+1;j<=end;j++){
			float value= sqrt((p[j].x-p[i].x)*(p[j].x-p[i].x) + (p[j].y-p[i].y)*(p[j].y-p[i].y));
			if(value<mini)
				mini=value;
		}
	}
	return mini;
}

float cc(point p[10],int st,int end){
	if(end-st<=2)
		return bruteforce(p,st,end);
	else{
		int mid=(st+end)/2;
		float dl=cc(p,st,mid);
		float dr=cc(p,mid+1,end);
		float k=min(dl,dr);
		struct point strip[10];
		int j=0;
		for(int i=st;i<=end;i++){
			if(abs(p[mid].x - p[i].x )<=k)
				strip[j++]=p[i];
		}
		float mini=bruteforce(strip,0,j-1);
		mini=min(mini,k);
		return mini;
	}
}
int main(){
	int n;
	cin>>n;
	point p[n];
	for(int i=0;i<n;i++)
		cin>>p[i].x>>p[i].y;
	for(int i=0;i<n;i++){
		cout<<p[i].x<<" "<<p[i].y;
		cout<<endl;
	}
	sort(p,p+n,compareX);
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<p[i].x<<" "<<p[i].y;
		cout<<endl;
	}
	float min=cc(p,0,n-1);
	cout<<endl;
	cout<<"min: "<<min;
	return 0;
}