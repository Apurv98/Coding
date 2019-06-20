//https://codeforces.com/problemset/problem/755/C
//Disjoint-Set Union
#include<iostream>
#include<vector>
using namespace std;
vector<int> parent;
vector<vector<int> > tree;
vector<bool> visited;
void DFS(int v)
{
  visited[v]=true;
  for(int u:tree[v]){
    if(!visited[u])
    DFS(u);
  }
}

int find(int u)
{
  if(parent[u]==u)
  return u;
  else{
    int result = find(parent[u]);
    parent[u] = result;
    return result;
  }
}

void a_union(int i,int j)
{
  int pi = find(i);
  int pj = find(j);
  if(pi==pj)
  return;
  parent[pi]=pj;
}

int main(){
  int n,q;
  cin>>n;
  parent.assign(n+1,0);
  tree.assign(n+1,vector<int>());
  visited.assign(n+1,false);
  for(int i=1;i<=n;i++)
  parent[i]=i;
  for(int p=1;p<=n;p++){
    cin>>q;
    a_union(p,q);
  }
  for(int i=1;i<=n;i++){
    int pi = find(i);
    if(pi!=i){
        tree[pi].push_back(i);
        tree[i].push_back(pi);
    }
  }
  int count=0;
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      count++;
      DFS(i);
    }
  }
  cout<<count;
  return 0;
}
