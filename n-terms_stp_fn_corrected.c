#include<stdio.h>
#include<math.h>
#define PI 3.14159265

double calc_100_terms(double x, double an[100], double bn[100], int n) { //function that evaluates ao/2 + Σ 1 to 100 (an cosnx + bn sin nx) at x

  return ((an[n]) * cos(n * x)) + ((bn[n]) * sin(n * x)); // returned to line 37 for summation
}

void getData(double numPt, double step, double p, double q, double an[100], double bn[100]) { //received an and bn
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

  for (double i = p; i <= q; i = i + step) { //for loop #1 to vary x in f(x)

    //Plotting step fn
    if (i >= -PI && i < 0)
      fx_real = -1;
    if (i <= PI && i > 0)
      fx_real = 1;
    //Saving (x,fx_real) to txt file
    fprintf(fp2, "%lf %lf\n", i, fx_real);
    for (double k = 1; k <= 100; k++) { //for loop #2 to sum up coefficients from 1 to 100 for that value of x
      //Fourier series function
      fx_fourier = fx_fourier + calc_100_terms(i, an, bn, k); //passed an bn and x , here k is for representing the kth coefficient of an bn 
    }
    //Saving (x,fourier) to txt file
    fprintf(fp, "%lf %lf\n", i,  ((ao / 2) + fx_fourier)); // ao/2 added to the final f(x) value
    fx_fourier = 0; // reset for the next value of x
  }
  fclose(fp);
  fclose(fp2);
}

int main() {
  int numPt, N;
  N = 1;
  printf("Enter the number of points e.g. 100\n");
  scanf("%d", & numPt);


  double p, q, an[100], bn[100];

  //Calculating required number of coefficients for an and bn for this function
  while (N <= 100) {
    an[N] = -(0.6366/N)*sin(N * PI/2);  //Formula for an
    bn[N] = (0.6366/N)*(cos(N * PI/2) - (pow(-1, N)));   //Formula for bn
printf("%d %lf %lf \n",N, an[N], bn[N]);
    N++;
  }
  //limits
  p = -PI;
  q = PI;
  //calculating step
  double step = (q - p) / numPt;
  //passed an and bn
  getData(numPt, step, p, q, an, bn);
  printf("\nDone ! Run plot.py \n");
  return 0;
}
