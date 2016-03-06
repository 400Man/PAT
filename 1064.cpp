#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int size = 0;
int a[1001],b[1001];
int n;

void inOrder(int begin){
  if(begin > n-1){
    return;
  }
  inOrder(2*begin);
  b[begin] = a[++size];
  inOrder(2*begin+1);
}

int main(){
  scanf("%d",&n);
  n++;
  for(int i = 1;i < n; i++){
    scanf("%d",&a[i]);
  }
  sort(a+1,a+n);
  inOrder(1);
  for(int i = 1;i < n; i++){
    printf(i==n-1?"%d\n":"%d ",b[i]);
  }
}