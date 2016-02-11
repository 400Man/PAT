#include<stdio.h>
#include<algorithm>
#include<string.h>

#define magicNum 20000

using namespace std;

int pairs[5000][2];
int size = 0;

struct Car{
  char plate[8];
  int h,m,s;
  int times;
  int span;
  int state;
  int correct;
}cars[10001];

bool cmp(Car a,Car b){
  int t = strcmp(a.plate,b.plate);
  if(t != 0)
    return t < 0;
  else
    return a.times < b.times;
}

int timeline[86400] = {0};

int main()
{
  int n,m;
  scanf("%d %d",&n,&m);
  char t[4];
  for(int i = 0; i < n; i++)
  {
    scanf("%s %d:%d:%d %s",cars[i].plate,&cars[i].h,&cars[i].m,&cars[i].s,t);
    cars[i].correct = 0;
    cars[i].span = 0;
    cars[i].times = cars[i].h*60*60 + cars[i].m*60 + cars[i].s;
    if(strcmp(t,"in")==0)
      cars[i].state = 1;
    else
      cars[i].state = 0;
  }
  int requre[m];
  int h,mi,s;
  for(int i = 0; i < m; i++)
  {
    scanf("%d:%d:%d",&h,&mi,&s);
    requre[i] = h*60*60 + mi*60 + s;
  }
  
  sort(cars,cars+n,cmp);
  
  if(m > magicNum)
  {
  char temp[10];
  int j;
  int max = 0;
  for(int i = 1; i < n ; i++)
  {
    strcpy(temp,cars[i].plate);
    int sum = 0;
    while(strcmp(temp,cars[i].plate) == 0)
    {
      if(cars[i].state == 0 && cars[i-1].state == 1)
      {
        for(int u = cars[i-1].times; u<cars[i].times;u++)
          timeline[u]++;   // update timeline
        cars[i-1].correct = 1;
        sum += cars[i].times - cars[i-1].times;
      }
      j = i;
      i++;
    }
    cars[j].span = sum;
    if(sum > max)
      max = sum;
  }
  
  for(int i = 0; i < m;i++)
    printf("%d\n",timeline[requre[i]]);
  
  for(int i = 0; i < n; i++)
    if(cars[i].span == max)
      printf("%s ",cars[i].plate);
      
  printf("%02d:%02d:%02d\n",max/3600,max%3600/60,max%60);
  }
  
  else
  {
  char temp[10];
  int j;
  int max = 0;
  for(int i = 1; i < n ; i++)
  {
    strcpy(temp,cars[i].plate);
    int sum = 0;
    while(strcmp(temp,cars[i].plate) == 0)
    {
      if(cars[i].state == 0 && cars[i-1].state == 1)
      {
        pairs[size][0] = cars[i-1].times;
        pairs[size++][1] = cars[i].times;
        cars[i-1].correct = 1;
        sum += cars[i].times - cars[i-1].times;
      }
      j = i;
      i++;
    }
    cars[j].span = sum;
    if(sum > max)
      max = sum;
  }
  
    for(int i = 0; i < m ;i++)
    {
      int num = 0;
      for(int j = 0; j < size ; j++)
      {
        if(requre[i] >= pairs[j][0] && requre[i] < pairs[j][1])
          num++;
      }
      printf("%d\n",num);
    }
  
  for(int i = 0; i < n; i++)
    if(cars[i].span == max)
      printf("%s ",cars[i].plate);
      
  printf("%02d:%02d:%02d\n",max/3600,max%3600/60,max%60);
  }

}