// write a program that returns 1 for prime number and 0 if not prime
//source: stephen kochan, programming in C, chapter 8
#include<stdio.h>


// function to check n is prime or not
void prime (int n)
{
  int i, c = 0;

      for (i = 1; i <= n; i++) {

             c++;
          }
      }
      if (c == 2) {
          printf("1\n");
      }
      else {
          printf("0\n");
      }

}
int main (void)
{
  void prime (int n);
  int m;

 printf("Please Give a number to check whether prime or not\n");
 scanf("%i", &m);
 prime(m);
 return 0;
}
