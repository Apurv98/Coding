//https://codeforces.com/problemset/problem/913/B
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > tree;
vector<bool> leaf;

bool isSpruceTree(int v)
{
  if(leaf[v])
    return true;
  int count=0;
  bool ans=true;
  for(int u:tree[v]){
    if(leaf[u])
      count++;
    ans&=isSpruceTree(u);
  }
  if(count >= 3)
    return true & ans;
  else
    return false;
}

int main(){
  int n,t;
  cin>>n;
  tree.assign(n+1,vector<int>());
  leaf.assign(n+1,true);
  leaf[1]=false;
  for(int i=2;i<=n;i++){
    cin>>t;
    tree[t].push_back(i);
    leaf[t]=false;
  }
  cout<<(isSpruceTree(1)?"Yes":"No");
  return 0;
}
