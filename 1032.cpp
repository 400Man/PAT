#include<stdio.h>

struct node{
  char c;
  int next;
  int flag;
}node[100010];

int main()
{
  int a,b,n;
  scanf("%d %d %d",&a,&b,&n);
  for(int i = 0;i < n; i++){
    int address;
    scanf("%d ",&address);
    scanf("%c %d",&node[address].c,&node[address].next);
    node[address].flag = 0;
  }
  
  if((node[a].next == 0)||(node[b].next == 0)){
    printf("-1\n");
    return 0;
  }
  
  while(node[a].next != -1){
    node[a].flag = 1;
    a = node[a].next;
  }
  while(node[b].next != -1){
    if(node[b].flag == 1){
      printf("%05d\n",b);
      return 0;
    }
    b = node[b].next;
  }
  printf("-1\n");
  return 0;
}