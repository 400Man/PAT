#include<stdio.h>
#include<cmath>
#include<vector>

#define N 100000

using namespace std;

vector<int> Node[N];
int dep[N];
int m = 0;

void getDepth(int root,int depth){
  if(Node[root].size() == 0){
    dep[root] = depth;
    if(depth > m){
      m = depth;
    }
  }
  else{
    for(int i = 0;i < Node[root].size();i++){
      getDepth(Node[root][i],depth+1);
    }
  }
}

int main()
{
  int n;
  int root;
  int count=0;
  double price,r;
  scanf("%d %lf %lf",&n,&price,&r);
  int a[n];
  for(int i = 0;i < n; i++){
    scanf("%d",&a[i]);
    if(a[i] == -1){
      root = i;
    }
    else{
      Node[a[i]].push_back(i);
    }
  }
  getDepth(root,0);
  for(int i = 0;i < n ; i++){
    if(dep[i] == m){
      count++;
    }
  }
  printf("%.2lf %d\n",price*pow(1+r/100,m),count);
}