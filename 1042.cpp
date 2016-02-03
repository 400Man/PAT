#include<stdio.h>
#define N 54

int main()
{
  char num[54][4] = {"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",\
                     "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",\
                     "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",\
                     "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13","J1","J2"};
  int c;
  int card[22][N];
  int change[N];
  
  scanf("%d",&c);
  for(int i = 0; i < N ; i++)
  {
    scanf("%d",&change[i]);
    change[i]--;
    card[0][i] = i;
  }
 
  for(int j = 1; j <= c; j++)
  {
    for(int i = 0; i < N; i++)
      card[j][change[i]] = card[j-1][i];
  }
  
  for(int i = 0; i < N ;i++)
    printf(i==N-1?"%s":"%s ",num[card[c][i]]);
  printf("\n");
  
}