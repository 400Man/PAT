#include<stdio.h>

int main()
{
  float m[3][3];
  float m1,m2,m3;
  int h[3];
  float sum = 1;
  char r[3] = {'W','T','L'};
  for(int i = 0; i < 3; i++)
  {
    float max = 0.0;
    for(int j = 0 ; j < 3; j++)
    {
      scanf("%f",&m[i][j]);
      if(m[i][j] > max)
      {
        max = m[i][j];
        h[i] = j;
      }
    }
    sum *= max;
  }
  for(int i = 0; i < 3; i++)
    printf("%c ",r[h[i]]);
  printf("%.2f\n",(sum * 0.65 -1.0)*2.0);
  return 0;  
}