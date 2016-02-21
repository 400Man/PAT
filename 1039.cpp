#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int c(char a[]){
  int id = 0;
  for(int i = 0; i < 3; i++){
    id = id*26 + a[i] - 'A';
  }
  id = id*10 + a[3] - '0';
  return id;
}

int main()
{
  int n,m;
  scanf("%d %d",&m,&n);
  vector<int> selectCourse[26*26*26*10+1];
  for(int i = 0; i < n; i++){
    int x,y;
    scanf("%d %d",&x,&y);
    for(int j = 0; j < y; j++){
      char name[5];
      scanf("%s",name);
      selectCourse[c(name)].push_back(x);
    }
  }
  
  for(int i = 0; i < m; i++){
    char name[5];
    scanf("%s",name);
    printf("%s %lu",name,selectCourse[c(name)].size());
    sort(selectCourse[c(name)].begin(),selectCourse[c(name)].end());
    for(int j = 0; j < selectCourse[c(name)].size(); j++){
      printf(" %d",selectCourse[c(name)][j]);
    }
    putchar(10);
  }
  return 0;
}