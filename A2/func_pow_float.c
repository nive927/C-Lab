#include<stdio.h>

float power(float X, int N)
{ 
  float Y=1;

  if(N>=0)
  {	for(int i=1; i<=N; i++)
   		Y*=X;
  }

  else
  {	for(int i=1; i<=-N; i++)
   		Y*=(1/X);
  }

  
  return Y; 
}

int main()
{
  int n;
  float x;

  printf("Enter base: ");
  scanf("%f", &x);

  printf("Enter power: ");
  scanf("%d", &n);
  
  printf("RESULT: %.4f\n", power(x, n));
  
  return 0;
}