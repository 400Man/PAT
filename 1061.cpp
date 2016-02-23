#include<iostream>
#include<ctype.h>
#include<string>

using namespace std;

int main()
{
  char week[8][10] = {"","MON","TUE","WED","THU","FRI","SAT","SUN"};
  string a[4];
  for(int i = 0;i < 4; i++){
    cin >> a[i];
  }
  int i = 0;
  int b,c,d;
  for(; i < a[0].size(); i++){
    if(a[0][i]>='A' && a[0][i]<='G'){
      if(a[0][i] == a[1][i]){
        b = a[0][i]-'A'+1;
        i++;
        break;
      }
    }
  }
  
  for(; i < a[0].size(); i++){
    if(a[0][i]>='A' && a[0][i]<='N'){
      if(a[0][i] == a[1][i]){
        c = a[0][i]-'A'+10;
        break;
      }
    }
    if(isdigit(a[0][i])){
      if(a[0][i] == a[1][i]){
        c = a[0][i]-'0';
        break;
      }
    }
  }
  
  for(int i = 0;i < a[2].size();i++){
    if(isalpha(a[2][i])){
      if(a[2][i] == a[3][i]){
        d = i;
        break;
      }
    }
  }
  printf("%s ",week[b]);
  if(i == 60){
    printf("%02d:00",c+1);
  }
  else{
    printf("%02d:",c);
    printf("%02d\n",d);
  }
  
  return 0;
}