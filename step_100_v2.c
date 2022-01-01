#include<stdio.h>

#include<math.h>

#define PI 3.14159265
 
double calc_100_terms(double x, double an[100], double bn[100], int n) { //function that evaluates ao/2 + Σ 1 to 100 (an cosnx + bn sin nx) @ x
  double fxxx, ao;
  fxxx = 0;
  return ((an[n]) * cos(n * x))+((bn[n]) * sin(n * x)); // returned for printing to txt
}

void getData(double numPt, double step, double p, double q, double an[100], double bn[100]) { //received an and bn
  double fx_fourier, fx_real, ao;
  ao = -0.5; //ao for this function
  int k;
  k=1;
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
 for (double k = 1; k <= 100; k++) {  //for loop #2
    //Fourier series function
    fx_fourier = fx_fourier + calc_100_terms(i, an, bn,k); //passed an bn and x , here k is for denoting the kth coefficient of an bn 
 }
    //Saving (x,fourier) to txt file
    fprintf(fp, "%lf %lf\n", i, (ao/2) + fx_fourier); // ao/2 added
    fx_fourier=0; // reset for the next value of x
  }
  fclose(fp);
  fclose(fp2);
}

int main() {
  int numPt, N;
  N = 1;
  double p, q, an[100], bn[100];

  //Calculating 100 coefficients for an and bn for this function
  while (N <= 100) {
    an[N] = -2 * sin(0.5 * N * PI);
    an[N] = (an[N]) / PI;
    an[N] = -(an[N]);

    an[N] = (an[N]) / N;
    bn[N] = cos(N * 0.5 * PI) - pow(-1, N);

    bn[N] = (bn[N]) / PI;
    bn[N] = 2 * (bn[N]);
    bn[N] = (bn[N]) / N;
    N++;
  }

  printf("Enter the number of points e.g. 100\n");
  scanf("%d", & numPt);

  //limits
  p = -1;
  q = 1;

  //calculating step
  double step = (q - p) / numPt;

  //passed an and bn
  getData(numPt, step, p, q, an, bn);

  printf("\nDone ! Run plot.py \n");
  return 0;
}
