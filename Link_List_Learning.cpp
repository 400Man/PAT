#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  node* next;
};

node* build(int a[],int);
void insert(node*,int,int);
void del(node*,int);
int find(node*,int);

int main()
{
  int n;
  printf("Input Array size: ");
  scanf("%d",&n);
  printf("Array: ");
  int a[n];
  for(int i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }
  
  node *head = build(a,n);
  
  printf("\n1# ================= PRINT test\n");
  printf("\nLink list : ");
  node *p = head->next;       //  跳过头结点
  while(p != NULL){
    printf("%d ",p->data);
    p = p -> next;            //  万万没想到能把你忘了
  }
  putchar(10);
  
  
  printf("\n2# ================= INSERT test\n");
  
  int num,pos;
  printf("\nThe number you want to insert: ");
  scanf("%d",&num);
  printf("Position: ");
  scanf("%d",&pos);
  insert(head,num,pos);
  
  printf("\nLink list now become: ");
  p = head->next;     
  while(p != NULL){
    printf("%d ",p->data);
    p = p -> next;         
  }
  putchar(10);
  
  
  printf("\n3# ================= DELETE test\n");
  int de;
  printf("\nThe number you want delete: ");
  scanf("%d",&de);
  del(head,de);
  
  printf("\nLink list now become: ");
  p = head->next;     
  while(p != NULL){
    printf("%d ",p->data);
    p = p -> next;         
  }
  putchar(10);
  
  printf("\n4# ================= SERACHING test\n");
  
  int nu=-1;
  printf("\nThe number you want to find: ");
  scanf("%d",&nu);
  int postion = find(head,nu);
  if(nu == -1)
    printf("Not find ~\n\n");
  else
    printf("Find it!\nPosition: %d\n\n",postion);
    
  return 0;
}

node* build(int a[],int size){
  node* head = new node;
  node *pre;
  head->next = NULL;
  pre = head;
  for(int i = 0 ; i < size; i++){
    node *p = new node;
    p->data = a[i];
    p->next = NULL;
    pre->next = p;
    pre = p;
  }
  return head;
}

void insert(node* L, int x , int y){
  node *p = L;
  
  for(int i = 0; i < y-1; i++){
    p = p->next;
  }
  
  node *q = new node;
  q->data = x;
  q->next = p->next;
  
  p->next = q;
}

void del(node *L,int x){
  node *p = L ,*pre = L;
  while(p != NULL){
    if(p->data == x){
      pre->next = p->next;
      delete(p);
    }
    pre = p;
    p = p->next;
  }
}

int find(node *L,int x){
  node *p = L;
  int count = 0;
  while(p != NULL){
    if(p->data == x){
      return count;
    }
    count++;
    p = p->next;
  }
  return -1;
}