//https://codeforces.com/problemset/problem/996/A
#include<iostream>
#include<limits.h>
using namespace std;
int arr[]={100,20,10,5,1};

int dp(int i)
{
	int min=0;
	for(int j=0;j<5;j++){
		if(i>=arr[j]){
			min+=(i/arr[j]);
			i%=arr[j];
		}
	}
	return min;
}

int main(){
	int n;
	cin>>n;
	cout<<dp(n);
	return 0;
}