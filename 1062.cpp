//#  talent idea

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
  int foo;
};

bool cmp(T a,T b){
  if(a.foo != b.foo)
    return a.foo < b.foo;
  if(a.tag != b.tag)
    return a.tag < b.tag;
  if(a.total != b.total)
    return a.total > b.total;
  if(a.virtue != b.virtue)
    return a.virtue > b.virtue;
  int u = strcmp(a.name,b.name);
    return u < 0;
}

int main()
{
  int n,score1,score2,m = 0;
  scanf("%d %d %d",&n,&score1,&score2);
  T person[n];
  for(int i = 0; i < n; i++){
    scanf("%s %d %d",person[i].name,&person[i].virtue,&person[i].talent);
    if(person[i].virtue < score1 || person[i].talent < score1)
    {
      person[i].foo = 1;
      m++;
    }
    else
      person[i].foo = 0;
      
    if(person[i].talent >= score2 && person[i].virtue >= score2)
      person[i].tag = 1;
    if(person[i].talent < score2 && person[i].virtue >= score2)
      person[i].tag = 2;
    if(person[i].talent < score2 && person[i].virtue < score2)
      person[i].tag = 3;
    if(person[i].talent >= score2 && person[i].virtue < score2)
      person[i].tag = 4;
      
    person[i].total = person[i].talent + person[i].virtue;
  }
  sort(person,person+n,cmp);
  
  printf("%d\n",n-m);
  for(int i = 0; i < n-m; i++)
    printf("%s %d %d\n",person[i].name,person[i].virtue,person[i].talent);
  return 0;
}