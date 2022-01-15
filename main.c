#include <stdio.h>
#include <stdlib.h>
int check(int); //check ว่าเป็น primenumbersไหม

int main(int argc, char *argv[] ) 
{
  int i, N, temp, j = 0;
  int *a, *b;
  N = argc - 1;
  a = (int*) malloc (sizeof(int)*N); //รับargvทั้งหมด
  b = (int*) malloc (sizeof(int)*N); //รับprime argv
  
  for(i = 1; i < argc; i++)
  {
    a[i-1] = atoi(argv[i]);
    if(check(a[i-1]) == 1)
    {
        b[j] = a[i-1];
        j++;
    }
  }
  
  if(j==0) 
    {
      printf("No prime number found.");
      return 0;
    }

  for(i = 0; i < j; i++) //sort
  {
    for(int k = i+1; k < j; k++)
    {
      if(b[i]>b[k])
      {
        temp = b[i];
        b[i] = b[k];
        b[k] = temp;
      }
    }
  }

  printf("The smallest prime numbers is %d.\n",b[0]);
  printf("The biggest  prime numbers is %d.\n",b[j-1]);

  return 0;
}

int check(int n) //check ว่าเป็น primenumbersไหม
{
  if(n<=1)
  {
    return 0;
  }
  for(int i=n-1; i > 1; i--)
  {
    if(n%i == 0)
    {
      return 0;
    }
  }
  return 1;
}