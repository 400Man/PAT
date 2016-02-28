#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool cmp(string a,string b){
  return a + b < b + a;
}

int main(){
  int n;
  cin >> n;
  string a[10000],b;
  for(int i = 0;i < n; i++){
    cin >> a[i];
  }
  sort(a,a+n,cmp);
  for(int i = 0;i < n; i++){
    b += a[i];
  }
  while(b[0] == '0' && b.size() != 1){
    b.erase(b.begin());
  }
  cout << b << endl;
}