//  这也太神奇了！！！！
//  大输入的情况下负号就不输出了！！！！！
//  这真是一道奇妙的题。。。
//  先是遭遇了一个大bug， 又遭遇了一个大郁闷。。。

#include<iostream>
#include<string>

using namespace std;

int main()
{
  string a,b;
  string::iterator it = a.begin();    //  两个大问题 都和 it 有关。。。。。
  cin>>a;
  int sign,e = 0;
  sign = a[0];                         //  问题2：不能用 sign = it...
  a.erase(a.begin());                  //  问题1：不能   erase(it)...
                                       //  it 都是刚刚初始化的。。。。
  it = a.begin() + a.find('E')+1;
  while(++it != a.end()){
    e = e*10 + *it -'0';
  }

  if(a[a.find('E')+1]=='-')
    e = -e;
  a.erase(a.find('E')+a.begin(),a.end());
  a.erase(a.find('.')+a.begin());
  
  if(e <= 0){
    for(int i = 0; i < -e;i++){
      b += '0';
    }
    a.insert(a.begin(),b.begin(),b.end());
    a.insert(a.begin()+1,'.');
  }
  
  else{
    if(e < a.size() - 1){
      a.insert(a.begin()+e+1,'.');
    }
  
    else{
      int u = a.size()-1;
      for(int i = 0; i < (e - u); i++)
        a.insert(a.end(),'0');
    }
  }

  if(sign == '-')
    cout << '-';
  cout << a << endl;
}