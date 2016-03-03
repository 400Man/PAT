#include<stdio.h>
#include<queue>

using namespace std;

int n;
char l[100],r[100];
int flag[257] ={0};
int head;

void reverse(int head){
  if(l[head] != '-')
    reverse(l[head]-'0');
  if(r[head] != '-')
    reverse(r[head]-'0');
  char temp = l[head];
  l[head] = r[head];
  r[head] = temp;
}

int nu = 0;
void in(int head){
  if(l[head] != '-')
    in(l[head]-'0');
  nu++;
  printf(nu==n?"%d\n":"%d ",head);
  if(r[head] != '-')
    in(r[head]-'0');
}

int num=0;
void level(int head){
  queue<int> q;
  q.push(head);
  while(!q.empty()){
    int now = q.front();
    num++;
    printf(num==n?"%d\n":"%d ",now);
    q.pop();
    if(l[now] != '-')
      q.push(l[now]-'0');
    if(r[now] != '-')
      q.push(r[now]-'0');
  }
}

int main()
{
  scanf("%d",&n);
  for(int i =0 ; i < n; i++){
    getchar();
    scanf("%c %c",&l[i],&r[i]);
  }
  
  for(int i = 0;i < n; i++){
    flag[l[i]] = flag[r[i]] = 1;
  }
  for(int i = 0;i < n; i++){
    if(flag[i+'0'] != 1){
      head = i;
    }
  }
  reverse(head);
  level(head);
  in(head);
  return 0;
}