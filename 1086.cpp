#include<iostream>
#include<stack>
#include<string>

using namespace std;

int n;
int pre[100],in[100],post[100];

struct node{
  int data;
  node* lchild;
  node* rchild;
};

node* create(int L1,int R1,int L2,int R2){
  if(L1 > R1){
    return NULL;
  }
  node* p = new node;
  p->data = pre[L1];
  int i;
  for(i = L2; i < R2 ; i++){
    if(in[i] == pre[L1]){
      break;
    }
  }
  int numLeft = i - L2;
  p->lchild = create(L1+1,L1+numLeft,L2,i-1);
  p->rchild = create(L1+numLeft+1,R1,i+1,R2);
  return p;
}

int num = 0;
void postOrder(node* p){
  if(p == NULL){
    return;
  }
  postOrder(p->lchild);
  postOrder(p->rchild);
  printf("%d",p->data);
  num++;
  if(num != n){
    putchar(' ');
  }
}

int main()
{
  stack<int> s;
  cin >> n;
  int pr =0, size = 0;
  for(int i = 0;i < 2*n; i++){
    string str;
    int num;
    cin >> str;
    if(str == "Push"){
      getchar();
      cin >> num;
      s.push(num);
      pre[pr++] = num;
    }
    else{
      in[size++] = s.top();
      s.pop();
    }
  }
  
  postOrder(create(0,n-1,0,n-1));
  putchar(10);
  return 0;
}