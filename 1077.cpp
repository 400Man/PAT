#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

int main()
{
  int n;
  cin >> n;
  getchar();
  string a[110];
  int ans[1000];
  int size = 0;
  int len[n];
  int min = 0xfffffff;
  
  for(int i = 0;i < n; i++){
    getline(cin,a[i]);
  }
  for(int i = 0;i < n;i++){
    len[i] = a[i].size();
    if(len[i] < min){
      min = len[i];
    }
  }
    
  
  while(1){
    int c = a[0][--len[0]];
    for(int i = 1; i < n; i++){
      if(a[i][--len[i]] != c){
        goto end;
      }
    }
    ans[size++] = c;
    if(size >= min)
      goto end;
  }
  end:
  if(size == 0){
    cout << "nai" << endl;
  }
  else{
    for(int i = size -1; i >=0; i--){
      printf("%c",ans[i]);
    }
    putchar(10);
  }
  return 0;
}