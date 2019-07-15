//https://codeforces.com/problemset/problem/702/A
#include<iostream>
using namespace std;
int dp[(int)1e5];
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		if(arr[i]>arr[i-1])
		dp[i]=dp[i-1]+1;
		else
			dp[i]=1;
	}
	int ans=-1;
	for(int i=0;i<=100000;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}