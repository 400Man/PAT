#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

struct T{
  char name[10];
  int talent;
  int virtue;
  int tag;
  int total;
};

bool cmp(T a,T b){
  if(a.tag != b.tag)
    return a.tag < b.tag;
  if(a.total != b.total)
    return a.total > b.total;
  if(a.virtue != b.virtue)
    return a.virtue > b.virtue;
  return strcmp(a.name,b.name) < 0;
}

int main()
{
  int n,score1,score2;
  scanf("%d %d %d",&n,&score1,&score2);
  int m = n;
  T person[n];
  for(int i = 0; i < n; i++){
    scanf("%s %d %d",person[i].name,&person[i].virtue,&person[i].talent);
    person[i].total = person[i].talent + person[i].virtue;
    if(person[i].virtue < score1 || person[i].talent < score1)
    {
      person[i].tag = 5;
      m--;
    }
    else if(person[i].talent >= score2 && person[i].virtue >= score2)
      person[i].tag = 1;
    else if(person[i].talent < score2 && person[i].virtue >= score2)
      person[i].tag = 2;
    else if(person[i].virtue >= person[i].talent)
      person[i].tag = 3;
    else
      person[i].tag = 4;
  }
  
  sort(person,person+n,cmp);
  
  printf("%d\n",m);
  for(int i = 0; i < m; i++)
    printf("%s %d %d\n",person[i].name,person[i].virtue,person[i].talent);
  return 0;
}