// 1. abc三个数都可以放下，但a+b longlong 就放不下了，所以只需要考虑溢出的情况就OK了
// 2. temp = a + b , 而不要直接使用 a + b, 因为在溢出的时候 a+b 表现未知

#include<stdio.h>

int main()
{
  int n,i=1;
  long long a,b,c;
  scanf("%d",&n);
  while(n--){
    scanf("%lld %lld %lld",&a,&b,&c);
    long long temp = a+b;
    if(a>0&&b>0&&temp<=0)     goto end1;
    else if(a<0&&b<0&temp>=0) goto end2;
    else if(temp > c)         goto end1;
    else                      goto end2;
    }
    end1: printf("Case #%d: true\n",i++); continue;
    end2: printf("Case #%d: false\n",i++); continue;
  }
  return 0;
}