#include<stdio.h>
#include<stack>

using namespace std;

int main()
{
  int M,N,K;
  scanf("%d %d %d",&M,&N,&K);
  int table[K][N];
  for(int i = 0; i < K; i++){
    int p = 1;
    stack<int> s;
    int flag = 0;
    for(int j = 0; j < N; j++){
      scanf("%d",&table[i][j]);
    }
    for(int j = 0; j < N; j++){
      while(p <= table[i][j]){
        s.push(p);
        p++;
      }
      if(p > N+1 || s.size() > M || s.top() != table[i][j]){
        printf("NO\n");
        flag = 1;
        break;
      }
      s.pop();
    }
    if(flag == 0)
      printf("YES\n");
  }
}