#include<stdio.h>
#include<string.h>

int main()
{
  int N;
  scanf("%d",&N);
  
  char user[N][100];
  char password[N][100];
  int mod[N];
  for(int i = 0; i < N ; i++)
    mod[i] = 0;
  int modified = 0;
  
  for(int i = 0; i < N ; i++)
    scanf("%s %s",user[i],password[i]);
  
  for(int i = 0; i < N ; i++)
  {   
    for(int j = 0; j < strlen(password[i]); j++)
    {
      if(password[i][j] == '1')
      {
        mod[i] = 1;
        password[i][j] = '@';
      }
      
      if(password[i][j] == 'l')
      {
        mod[i] = 1;
        password[i][j] = 'L';
      }
      
      if(password[i][j] == '0')
      {
        mod[i] = 1;
        password[i][j] = '%';
      }
      
      if(password[i][j] == 'O')
      {
        mod[i] = 1;
        password[i][j] = 'o';
      }
    }
    if(mod[i] == 1)
      modified++;
  }

  
  if(modified == 0)
    printf(N<2?"There is %d account and no account is modified\n":"There are %d accounts and no account is modified\n",N);
    
  else
  {
    printf("%d\n",modified);
    for(int i = 0; i < N; i++)
      if(mod[i] == 1)
        printf("%s %s\n",user[i],password[i]);
  }
  return 0;
}