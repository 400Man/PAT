#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
  vector<long long> a;
  long long  n,m;
  long long  i = 0;
  scanf("%lld",&n);
  for(;i < n; i++){
    long long u;
    scanf("%lld",&u);
    a.push_back(u);
  }
  scanf("%lld",&m);
  for(;i < m+n; i++){
    long long u;
    scanf("%lld",&u);
    a.push_back(u);
  }
  sort(a.begin(),a.end());
  int s;
  if(a.size()%2==0){
    s = a.size()/2-1;
  }
  else{
    s = a.size()/2;
  }
  printf("%lld\n",a[s]);
  
}