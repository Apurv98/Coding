#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > tree;
vector<bool> visited;
vector<int> value;
vector<int> ans;

void deleteBadBoys(int v){
  visited[v] = true;
  bool isBad = true;
  for(int u:tree[v]){
    if(!visited[u]){
      if(!value[u])
      isBad=false;
      deleteBadBoys(u);
    }
  }
  if(value[v] && isBad)
    ans.push_back(v);
}

int main(){
  int n,p,root,c;
  cin>>n;
  tree.assign(n+1,vector<int>());
  visited.assign(n+1,false);
  value.assign(n+1,0);
  for(int i=1;i<=n;i++){
    cin>>p>>c;
    value[i]=c;
    if(p==-1)
      root=i;
    else{
      tree[p].push_back(i);
      tree[i].push_back(p);
  }
  }
  deleteBadBoys(root);
  if(ans.size()==0){
    cout<<"-1";
    return 0;
  }
  sort(ans.begin(),ans.end());
  for(int i:ans){
      cout<<i<<" ";
  }
  return 0;
}
