//   只排前100，这个剪枝好！！！

#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

struct Rich{
  char name[10];
  int age;
  int doller;
};

bool cmp(Rich a,Rich b){
  if(a.doller != b.doller)
    return a.doller > b.doller;
  else if(a.age!= b.age)
    return a.age < b.age;
  return strcmp(a.name,b.name) < 0;
}

int main()
{
  int n,m;
  scanf("%d %d",&n,&m);
  Rich rich[n],richest[n];
  int size=0;
  int r[m][3];
  int age[201] = {0};
  for(int i = 0; i < n; i++){
    scanf("%s %d %d",rich[i].name,&rich[i].age,&rich[i].doller);
  }

  for(int i= 0; i < m; i++){
    scanf("%d %d %d",&r[i][0],&r[i][1],&r[i][2]);
  }
    
  sort(rich,rich+n,cmp);
  for(int i = 0; i < n; i++){
    if(age[rich[i].age]++ <= 100){
      richest[size++] = rich[i];
    }
  }
  
  for(int i = 0; i< m;i++){
    int count = 0;
    printf("Case #%d:\n",i+1);
    for(int j = 0; j < size;j++){
      if(richest[j].age >= r[i][1] && richest[j].age <= r[i][2]){
        if(count++ == r[i][0])
          goto con;
        printf("%s %d %d\n",richest[j].name,richest[j].age,richest[j].doller);
      }
    }
    con:
    if(count == 0)
      printf("None\n");
  }
}