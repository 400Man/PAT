#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

struct Apply{
  int id;
  int ge,gi;
  int sum;
  int want[5];
};

bool cmp(Apply a,Apply b){
  if(a.sum != b.sum)
    return a.sum > b.sum;
  return a.ge > b.ge;
}

int main()
{
  int n,m,k;
  scanf("%d %d %d",&n,&m,&k);
  vector<int> lucky[101];
  vector<int> l[101];
  int quota[m];
  Apply app[n];
  for(int i = 0; i < m; i++){
    scanf("%d",&quota[i]);
  }
  for(int i = 0; i < n; i++){
    scanf("%d %d",&app[i].ge,&app[i].gi);
    app[i].sum = app[i].ge + app[i].gi;
    app[i].id = i;
    for(int j = 0; j < k; j++)
      scanf("%d",&app[i].want[j]);
  }
  
  sort(app,app+n,cmp);
  
  int u;
  for(int i = 0; i < n ; i++){
    for(int j = 0; j < k; j++){
      u = app[i].want[j];
      if(lucky[u].size() < quota[u] ){
        lucky[u].push_back(app[i].id);
        l[u].push_back(i);
        goto succed;
      }
      if(app[i].sum == app[l[u][l[u].size()-1]].sum && app[i].ge == app[l[u][l[u].size()-1]].ge){
        lucky[u].push_back(app[i].id);
        goto succed;
      }
    }
    succed:
    int a;
  }
  
  for(int i = 0; i < m ; i++){
    sort(lucky[i].begin(),lucky[i].end());
    for(int j = 0; j < lucky[i].size(); j++){
      printf(j == lucky[i].size()-1?"%d":"%d ",lucky[i][j]);
    }
    putchar(10);
  }
  
}