#include<iostream>
#include<ctype.h>
#include<map>

using namespace std;

int main()
{
  string a;
  map<string,int> u;
  getline(cin,a);
  a += ',';
  int i= 0;
  int in = 0;
  int begin,end;
  while(a[i]!= '\0'){
    a[i] = tolower(a[i]);
    if(in == 0){
      if(isalnum(a[i])){
        begin = i;
        in = 1;
      }
    }
    else{
      if(!isalnum(a[i])){
        end = i-begin;
        if(u.find(a.substr(begin,end)) == u.end()){
          u[a.substr(begin,end)] = 1;
        }
        else{
          u[a.substr(begin,end)]++;
        }
        in = 0;
      }
    }
    i++;
  }
  int maxNum = 0;
  map<string,int>::iterator it = u.begin(),max;
    for(; it != u.end();it++){
      if(it->second > maxNum){
        maxNum = it->second;
        max = it;
      }
    }
  cout << max->first << " "<< max->second << endl;
}