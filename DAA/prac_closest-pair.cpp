#include<bits/stdc++.h>
using namespace std;

struct point{
	int x;
	int y;
};
bool compareX(point a, point b){
   return a.x < b.x;
}
 int bruteforce(point p[10], int st, int end){
 	int mini=INT_MAX;
 	for(int i=st;i<end;i++){
 		for(int j=i+1;j<=end;j++){
 			int val=sqrt((p[j].y-p[i].y)*(p[j].y-p[i].y) + (p[j].x-p[i].x)*(p[j].x-p[i].x));
 			if(val<mini)
 				mini=val;
 		}
 	}
 	return  mini;
 }
int cp(point p[10], int st, int end){
	if(end-st<=2)
		return bruteforce(p,st,end);
	else{
		int mid=(st+end)/2;
		int dl=cp(p,st,mid);
		int dr=cp(p,mid+1,end);
		int k=min(dl,dr);
		struct point strip[10];
		int j=0;
		for(int i=st;i<=end;i++){
			if(abs(p[mid].x - p[i].x)<=k)
				strip[j++]=p[i];
		}
		int mini=bruteforce(strip,0,j-1);
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
	sort(p,p+n,compareX);
	float mini=cp(p,0,n-1);
	cout<<mini;
	return 0;
}