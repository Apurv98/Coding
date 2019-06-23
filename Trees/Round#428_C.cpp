//https://codeforces.com/problemset/problem/839/C
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
vector<vector<int> > tree;
vector<bool> visited;
vector<double> ans;

double calculateAverageDistance(int v){
  double calc=0,k=0;
  visited[v]=true;
  for(int u:tree[v]){
    if(!visited[u]){
      calc+=calculateAverageDistance(u);
      k+=1.0;
    }
  }
  return (k==0)?0:(calc/k)+1.0;
}

int main(){
  int n,p,q;
  cin>>n;
  tree.assign(n+1,vector<int>());
  visited.assign(n+1,false);
  ans.assign(n+1,0);
  for(int i=0;i<n-1;i++){
    cin>>p>>q;
    tree[p].push_back(q);
    tree[q].push_back(p);
  }
  cout<<setprecision(15)<<calculateAverageDistance(1);
  return 0;
}
