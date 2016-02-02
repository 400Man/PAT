#include<stdio.h>

  struct Stu{
    char id[20];
    int signIn;
    int signOut;
  };

int main()
{
  int n;
  scanf("%d",&n);
  Stu s[n];
  int h1,m1,s1,h2,m2,s2,out = 0,in = 60*60*24+1,min,max;
  for(int i = 0; i < n ; i++)
  {
    scanf("%s %d:%d:%d %d:%d:%d",s[i].id,&h1,&m1,&s1,&h2,&m2,&s2);
    s[i].signIn = h1*60*60+m1*60+s1;
    s[i].signOut = h2*60*60+m2*60+s2;
  }
  for(int i = 0; i < n ;i++)
  {
    if(s[i].signIn < in)
    {
      in = s[i].signIn;
      min = i;
    }
    if(s[i].signOut > out)
    {
      out = s[i].signOut;
      max = i;
    }
  }
  printf("%s %s\n",s[min].id,s[max].id);
  return 0;
}