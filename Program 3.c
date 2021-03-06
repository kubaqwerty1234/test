prompt > cat d.c ; gcc -Wall -g d.c -o d ; ./d
#include <stdio.h>

#define PRINT_INT_EXP(xx_exp) \
  fprintf(stdout,"%-40s = %10ld\n", # xx_exp,(long)(xx_exp))
#define PRINT_DBL_EXP(xx_exp) \
  fprintf(stdout,"%-40s = %17.6f\n", # xx_exp,(double)(xx_exp))
int
main(int argc, char **argv, char **envr)
{
   int   a   = 3;
   int   b   = 4;
   int   c   = 5;
   float a_2 = 1.674; // a_2 value
   float b_2 = 1.322; // b_2 value
   float c_2 = a_2 + b_2; // c_2 value
   long  a_3 = a_2 * 10000;
   long  b_3 = b_2 * 10000;
   long  c_3 = a_3 + b_3;
   float third = 1.0/3.0;
   float sixth = 1.0/6.0;


   PRINT_INT_EXP(a);
   PRINT_INT_EXP(b);
   PRINT_INT_EXP(c);
   PRINT_INT_EXP(a<b+c);
   PRINT_INT_EXP(a<(b+c))
   PRINT_INT_EXP(a*a + b*b);
   PRINT_INT_EXP(c*c);
   PRINT_INT_EXP(a_3);
   PRINT_INT_EXP(b_3);
   PRINT_INT_EXP(c_3);
   PRINT_DBL_EXP(a_2);
   PRINT_DBL_EXP(b_2);
   PRINT_DBL_EXP(c_2);
   PRINT_INT_EXP((c_2 * 100));
   PRINT_DBL_EXP((c_2 * 100)/100);
   PRINT_DBL_EXP(((long)(sixth *100))/100.0);
   PRINT_DBL_EXP(((long)(third *100))/100.0);
   PRINT_DBL_EXP(((long)(2*third *100))/100.0);
   PRINT_DBL_EXP(((long)(2*third *100.0 + .5))/100.0);
   PRINT_DBL_EXP(((long)(2*sixth *100))/100.0);
   PRINT_DBL_EXP(third);
   PRINT_DBL_EXP(sixth);
   PRINT_INT_EXP((sixth * 1000)  );
   PRINT_INT_EXP((sixth * 1000) + .5);
   PRINT_INT_EXP(third * 1000);
   PRINT_INT_EXP((third * 1000)+.5);
   PRINT_INT_EXP(argc);
   return(0);

}
a                                        =          3
b                                        =          4
c                                        =          5
a<b+c                                    =          1
a<(b+c)                                  =          1
a*a + b*b                                =         25
c*c                                      =         25
a_3                                      =      16740
b_3                                      =      13220
c_3                                      =      29960
a_2                                      =          1.674000
b_2                                      =          1.322000
c_2                                      =          2.996000
(c_2 * 100)                              =        299
(c_2 * 100)/100                          =          2.996000
((long)(sixth *100))/100.0               =          0.160000
((long)(third *100))/100.0               =          0.330000
((long)(2*third *100))/100.0             =          0.660000
((long)(2*third *100.0 + .5))/100.0      =          0.670000
((long)(2*sixth *100))/100.0             =          0.330000
third                                    =          0.333333
sixth                                    =          0.166667
(sixth * 1000)                           =        166
(sixth * 1000) + .5                      =        167
third * 1000                             =        333
(third * 1000)+.5                        =        333
argc                                     =          1
prompt >
