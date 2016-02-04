#include<cstdio>
int main(){
  int a1,b1,c1,a2,b2,c2;
  scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
  printf("%d.%d.%d\n",a1+a2+((c1+c2)/29+b1+b2)/17,((c1+c2)/29+b1+b2)%17,(c1+c2)%29);
}