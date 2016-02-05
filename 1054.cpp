#include<stdio.h>

int hash[16777216]={0};

int main()
{
  int n,m,a;
  scanf("%d %d",&m,&n);
  int pix[m*n];
  int k = 0,max=0,index;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
    {
      scanf("%d",&a);
      hash[a]++;
      if(hash[a]==1)
        pix[k++] = a;
    }
  for(int i = 0; i < k;i++)
  {
    if(hash[pix[i]]>max)
    {
      max = hash[pix[i]];
      index = i;
    }
  }
  printf("%d\n",pix[index]);
  return 0;
}
