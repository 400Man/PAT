#include<iostream>
#include<map>
#include<string>
#include<ctype.h>

using namespace std;

int main()
{
  char digit[13][6] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
  char second[13][6] = {"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
  int n;
  scanf("%d",&n); getchar();
  map<string,int> f,s;
  for(int i = 0; i < 13; i++){
    f[digit[i]] = i;
    s[second[i]] = i;
  }
  string input[100];
  char c;
  for(int i = 0; i < n ; i++){
    int size = 0;
    while((c = getchar())!= '\n')
      input[i] += c;
  }
  
  for(int i = 0; i < n; i++){
    if(isdigit(input[i][0])){
      int num = 0;
      for(int j = 0; j < input[i].length();j++){
        num = num*10 + input[i][j] -'0';
      }
      int a=num/13,b=num%13;
      if(a == 0)
        printf("%s\n",digit[b]);
      else{
        if(a != 0 && b == 0)
          printf("%s\n",second[a]);
        else
          printf("%s %s\n",second[a],digit[b]);
      }
    }
    else{
      if(input[i].size() == 3){
        if(f.find(input[i]) != f.end()){
          printf("%d\n",f[input[i]]);
        }
        else{
          printf("%d\n",s[input[i]]*13);
        }
      }
      else{
        printf("%d\n",s[input[i].substr(0,3)]*13+f[input[i].substr(4,3)]);
      }
    }
  }
  // printf("%s\n",input[i].c_str());
  return 0;
}