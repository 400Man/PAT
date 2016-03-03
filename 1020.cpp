#include<stdio.h>
#include<queue>

using namespace std;

struct node{
  int data;
  node* lchild;
  node* rchild;
};

int post[31],in[31],n;

node* create(int L3,int R3,int L2,int R2){
  if(L3 > R3){
    return NULL;
  }
  node* p = new node;
  p->data = post[R3];
  int k;
  for(k = L2; k <= R2; k++){
    if(in[k] == post[R3]){
      break;
    }
  }
  int num = k - L2;
  p->lchild = create(L3,L3+num-1,L2,k-1);
  p->rchild = create(L3+num,R3-1,k+1,R2);
  return p;
}

int co = 0;
void level(node* p){
  queue<node*> que;
  que.push(p);
  while(!que.empty()){
    node* now = que.front();
    que.pop();
    co++;
    printf(co == n ?"%d\n":"%d ",now->data);
    if(now->lchild != NULL){
      que.push(now->lchild);
    }
    if(now->rchild != NULL){
      que.push(now->rchild);
    }
  }
}

int main()
{
  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    scanf("%d",&post[i]);
  }
  for(int i = 0; i < n; i++){
    scanf("%d",&in[i]);
  }
  node* root = create(0,n-1,0,n-1);
  level(root);
  return 0;
}