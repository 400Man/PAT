#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

struct S{
  char id[7];
  int a;
  int c;
  int m;
  int e;
  int min[4];
  char top;
  int topNum;
};

bool cmp(int a , int b){
  return a>b;
}

int main()
{
  char map[5] = "ACME";
  int n,u;
  scanf("%d %d",&n,&u);
  S stu[n];
  int a[n],c[n],m[n],e[n];
  char find[u][7];
  
  for(int i = 0; i < n;i++)
  {
    scanf("%s %d %d %d",stu[i].id,&stu[i].c,&stu[i].m,&stu[i].e);
    stu[i].a = (stu[i].c+stu[i].m+stu[i].e)/3;
    a[i] = stu[i].a;
    c[i] = stu[i].c;
    m[i] = stu[i].m;
    e[i] = stu[i].e;
  }
  for(int i = 0; i < u ; i++)
    scanf("%s",find[i]);
    
  sort(a,a+n,cmp);
  sort(c,c+n,cmp);
  sort(m,m+n,cmp);
  sort(e,e+n,cmp);

  
  for(int i = 0; i < n ; i++)
  {
    int flaga = 0,flagc = 0,flagm = 0,flage = 0;
    for(int j = 0; j < n ; j++)
    {
    if((a[j] == stu[i].a)&&(flaga == 0))
    {
      flaga = 1;
      stu[i].min[0] = j+1;
    }
    if((c[j] == stu[i].c)&&(flagc == 0))
    {
      flagc = 1;
      stu[i].min[1] = j+1;
    }
    if((m[j] == stu[i].m)&&(flagm == 0))
    {
      flagm = 1;
      stu[i].min[2] = j+1;
    }
    if((e[j] == stu[i].e)&&(flage == 0))
    {
      flage = 1;
      stu[i].min[3] = j+1;
    }
    }
  }
  
  for(int i = 0; i < n ; i++)
  {
    int min = 2000;
    for(int j = 0; j < 4; j++)
    {
      if(stu[i].min[j] < min)
      {
        min = stu[i].min[j];
        stu[i].top = map[j];
        stu[i].topNum = min;
      }
    }
  }
  
  for(int i = 0 ; i < u ; i++)
  {
    int flag = 0;
    for(int j = 0; j < n ; j++)
    {
      if(strcmp(find[i],stu[j].id)==0)
      {
        printf("%d %c\n",stu[j].topNum,stu[j].top);
        flag = 1;
        break;
      }
    }
    if(flag == 0)
      printf("N/A\n");
  }
  return 0;
  
}