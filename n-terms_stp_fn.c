#include<stdio.h>

#include<math.h>

#define PI 3.14159265

double calc_100_terms(double x, double an[100], double bn[100], int n) { //function that evaluates ao/2 + Σ 1 to 100 (an cosnx + bn sin nx) at x
   double fxxx, ao;
   fxxx = 0;
   return ((an[n]) * cos(n * x)) + ((bn[n]) * sin(n * x)); // returned for printing to txt
}

void getData(double numPt, double step, double p, double q, double an[100], double bn[100], int num_coeff) { //received an and bn
   double fx_fourier, fx_real, ao;
   ao = -1; //ao for this function
   int k;
   k = 1;
   //Opening files
   FILE * fp;
   fp = fopen("data.txt", "w");
   FILE * fp2;
   fp2 = fopen("data2.txt", "w");
   if (fp == NULL || fp2 == NULL) {
      printf("cannot create file");
      return;
   }

   for (double i = p; i <= q; i = i + step) { //for loop #1

      //Plotting step fn
      if (i >= -PI && i < 0)
         fx_real = -1;
      if (i < PI && i > 0)
         fx_real = 1;

      //Saving (x,fx_real) to txt file
      fprintf(fp2, "%lf %lf\n", i, fx_real);
      for (double k = 1; k <= num_coeff; k++) { //for loop #2
         //Fourier series function
         fx_fourier = fx_fourier + calc_100_terms(i, an, bn, k); //passed an bn and x , here k is for representing the kth coefficient of an bn 
      }
      //Saving (x,fourier) to txt file
      fprintf(fp, "%lf %lf\n", i, 2 * ((ao / 2) + fx_fourier)); // ao/2 added
      fx_fourier = 0; // reset for the next value of x
   }
   fclose(fp);
   fclose(fp2);
}

int main() {
   int numPt, N, flag, num_coeff;
   N = 1;
   flag = 1;

   printf("Enter the number of points e.g. 100\n");
   scanf("%d", & numPt);

   printf("Enter the number of coefficients e.g. 100\n");
   scanf("%d", & num_coeff);

   double p, q, an[num_coeff], bn[num_coeff];

   //Calculating 100 coefficients for an and bn for this function
   while (N <= num_coeff) {
      if (N % 2 == 0) //N even case
      {
         an[N] = 0;
         bn[N] = 0;
      }

      if (N % 2 == 1) // N odd case
      {
         flag = flag * -1;
         bn[N] = (2 / PI) / N;
      }
      if (N % 2 == 1 && flag == 1) // 1 , 5 , 9 , 13 .....
      {
         an[N] = -(2 / PI) / N;
      }
      if (N % 2 == 1 && flag == -1) // 3 , 7 , 11 , 15 .....
      {
         an[N] = (2 / PI) / N;
      }
      N++;
   }

   //limits
   p = -1;
   q = 1;

   //calculating step
   double step = (q - p) / numPt;

   //passed an and bn
   getData(numPt, step, p, q, an, bn, num_coeff);

   printf("\nDone ! Run plot.py \n");
   return 0;
}
