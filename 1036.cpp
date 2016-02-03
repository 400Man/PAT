#include<stdio.h>

struct Stu{
  char name[11];
  char gender;
  char id[11];
  int grade;
};

int main()
{
  int max = -1,min = 101;
  int maxid,minid;
  int n;
  scanf("%d",&n);
  Stu stu[n];
  for(int i = 0 ; i < n; i++)
  {
    scanf("%s %c %s %d",stu[i].name,&stu[i].gender,stu[i].id,&stu[i].grade);
    if(stu[i].gender=='F')
    {
      if(stu[i].grade > max)
      {
        max = stu[i].grade;
        maxid = i;
      }
    }
    if(stu[i].gender=='M')
    {
      if(stu[i].grade < min)
      {
        min = stu[i].grade;
        minid = i;
      }
    }
  }
  
  if(max==-1)
    printf("Absent\n");
  else
    printf("%s %s\n",stu[maxid].name,stu[maxid].id);
  if(min==101)
    printf("Absent\n");
  else
    printf("%s %s\n",stu[minid].name,stu[minid].id);
  
  if(max==-1||min==101)
    printf("NA\n");
  else
    printf("%d\n",max-min);
}