#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 100010;
const int maxN = 1000100;
bool flag[101000] = {false};

struct node{
  int address;
  int data;
  int next;
  int order;
}G[maxn];

bool cmp(node a,node b){
  return a.order < b.order;
}

int main()
{
  for(int i = 0; i < maxn; i++){
    G[i].order = maxN;
  }
  int begin,n,address;
  cin >> begin >> n;
  for(int i = 0;i  < n; i++){
    cin >> address;
    cin >> G[address].data >> G[address].next;
    G[address].address = address;
  }
  int p = begin;
  int valid = 0,removed = 0;
  while(p != -1){
    if(flag[abs(G[p].data)]){
      G[p].order = removed + maxn;
      removed++;
    }
    else{
      flag[abs(G[p].data)] = true;
      G[p].order = valid;
      valid++;
    }
    p = G[p].next;
  }
  sort(G,G+maxn,cmp);
  for(int i = 0; i < valid; i++){
    if(i != valid - 1)
      printf("%05d %d %05d\n",G[i].address,G[i].data,G[i+1].address);
    else
      printf("%05d %d -1\n",G[i].address,G[i].data);
  }
  // printf("\n%d %d\n",valid,removed);
  for(int i = valid; i < valid + removed ; i++){
    if(i != valid + removed - 1)
      printf("%05d %d %05d\n",G[i].address,G[i].data,G[i+1].address);
    else
      printf("%05d %d -1\n",G[i].address,G[i].data);
  }
}