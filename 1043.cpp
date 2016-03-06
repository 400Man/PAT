#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> origin,opr,mpr;
int n;

struct node{
  int data;
  node* lchild;
  node* rchild;
};

void insert(node* &p,int x){
  if(p == NULL){
    p = new node;
    p->data = x;
    p->lchild = p->rchild = NULL;
    return;
  }
  if(p->data > x){
    insert(p->lchild,x);
  }
  else{
    insert(p->rchild,x);
  }
}

void preOrder(node* p){
  if(p == NULL){
    return;
  }
  opr.push_back(p->data);
  preOrder(p->lchild);
  preOrder(p->rchild);
}

void premOrder(node* p){
  if(p == NULL){
    return;
  }
  mpr.push_back(p->data);
  premOrder(p->rchild);
  premOrder(p->lchild);
}

int pn = 0; 
void postOrder(node* p){
  if(p == NULL){
    return;
  }
  postOrder(p->lchild);
  postOrder(p->rchild);
  printf((pn++)==n-1?"%d\n":"%d ",p->data);
}

int pu = 0; 
void postmOrder(node* p){
  if(p == NULL){
    return;
  }
  postmOrder(p->rchild);
  postmOrder(p->lchild);
  printf((pu++)==n-1?"%d\n":"%d ",p->data);
}

int main()
{
  scanf("%d",&n);
  int a[n];
  node* p = NULL;
  for(int i = 0;i < n ; i++){
    scanf("%d",&a[i]);
    origin.push_back(a[i]);
    insert(p,a[i]);
  }
  preOrder(p);
  premOrder(p);
  if(origin == opr){
    printf("YES\n");
    postOrder(p);
  }
  else if(origin == mpr){
    printf("YES\n");
    postmOrder(p);
  }
  else{
    printf("NO\n");
  }
  return 0;

}