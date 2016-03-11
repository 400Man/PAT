#include<iostream>
#include<string>

using namespace std;

int main()
{
  string a;
  getline(cin,a);
  int max=0,now;
  int j = 1;
  for(int i = 0;i < a.size();i++){
    j = 1;
    now = 1;
    while(1){
      if(i-j < 0 || i+j >= a.size()){
        break;
      }
      if(a[i-j] != a[i+j]){
        break;
      }
      now += 2;
      if(now > max){
        max = now;
      }
      j++;
    }
    
    j = 1;
    now = 0;
    while(1){
      if(i-j+1 < 0 || i+j >= a.size()){
        break;
      }
      if(a[i-j+1] != a[i+j]){
        break;
      }
      now += 2;
      if(now > max){
        max = now;
      }
      j++;
    }

  }
  if(a.size() == 1 || max == 0){
    printf("1\n");
  }
  else{
    printf("%d\n",max);
  }
  
}