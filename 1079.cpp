#include<stdio.h>
#include<vector>
#include<cmath>

using namespace std;

double sum = 0.0;
int n;
double pri,interest;

struct node{
  vector<int> q;
  double price;
}G[100010];

void DFS(int p,int depth){
  if(G[p].q.size() == 0){
    sum += G[p].price*pow(1+interest,depth);
    return;
  }
  for(int i = 0; i < G[p].q.size();i++){
    DFS(G[p].q[i],depth+1);
  }
}

int main()
{
  scanf("%d %lf %lf",&n,&pri,&interest);
  interest /= 100;
  for(int i = 0; i < n; i++){
    int v;
    scanf("%d",&v);
    if(v != 0){
      for(int j = 0; j < v; j++){
        int x;
        scanf("%d",&x);
        G[i].q.push_back(x);
      }
    }
    else{
      scanf("%lf",&G[i].price);
    }

  }
  DFS(0,0);
  printf("%.1lf\n",pri*sum);
}