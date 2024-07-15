#include<bits/stdc++.h>
using namespace std;

int mcc(int coins[],int n,int s){
			if(n==0)
			  return 9999;
			if(s==0)
			  return 0;
			if(coins[n-1]<=s)
			  return min(1+ mcc(coins,n,s-coins[n-1]) , mcc(coins,n-1,s));
			else
			  return mcc(coins,n-1,s);
}
int main(){
	int n;
	//cout<<"enter no. of coins: ";
	cin>>n;
	int coins[n];
	//cout<<"enter coins: ";
	for(int i=0;i<n;i++)
	   cin>>coins[i];
	int s;
	//cout<<"enter sum to make: ";
	cin>>s;
		
	cout<<mcc(coins,n,s);

}

