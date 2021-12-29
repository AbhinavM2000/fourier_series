#include<stdio.h>

#include<math.h>

#define PI 3.14159265

void getData(double period, double numPt, double step, double p, double q) {
  double l = period / 2;
  int period_int, width;
  period_int = l;
  width = q - p;
  double t1, t3, t5, t7, t9, fx_fourier, fx_real, k, w;
  k = 1;
  w = 0;
//Opening files
  FILE * fp;
  fp = fopen("data.txt", "w");
  FILE * fp2;
  fp2 = fopen("data2.txt", "w");
  if (fp == NULL || fp2 == NULL) {
    printf("cannot create file");
    return;
  }

  for (double i = -l + p + 1; i <= l + q - 1; i = i + step) {
//Fourier series terms here
    t1 = sin((PI * i) / l);
    t3 = sin((PI * 3 * i) / l) / 3;
    t5 = sin((PI * 5 * i) / l) / 5;
    t7 = sin((PI * 7 * i) / l) / 7;
    t9 = sin((PI * 9 * i) / l) / 9;
    w = w + step;

//Plotting the square wave

    if (w >= period / 2) {
      k = k * -1;
      w = 0;

      if (k == 1) {
        fx_real = -1;
      }
      if (k == -1) {
        fx_real = 1;
      }
    }
    if (i < -l + p + 1 + 0.5 * period * 0.5 && width % 2 == 0) {
      if (width % 2 == 0)
        fx_real = -1;
      if (width % 2 == 1)
        fx_real = 1;
    }
    if (i < -l + p + 1 + 0.5 * period * 0.5 && width % 2 == 1) {
      if (width % 2 == 0)
        fx_real = 1;
      if (width % 2 == 1)
        fx_real = -1;
    }
//Saving (x,fx_real) to txt file
    fprintf(fp2, "%lf %lf\n", i, fx_real);
//Fourier series function
    fx_fourier = 4 * (t1 + t3 + t5 + t7 + t9) / PI;
//Saving (x,fourier) to txt file
    fprintf(fp, "%lf %lf\n", i, fx_fourier);

  }
  fclose(fp);
  fclose(fp2);
}

int main() {
  int numPt;
  double period, p, q;

  printf("Enter the period (2L) e.g. 1\n");
  scanf("%lf", & period);

  printf("Enter the number of points e.g. 100\n");
  scanf("%d", & numPt);

  printf("Enter the start and end points of the X-axis e.g -2 and 3 \n");
  scanf("%lf", & p);
  scanf("%lf", & q);

  double step = period / numPt;

  getData(period, numPt, step, p, q);
  printf("\nDone ! Run plot.py \n");
  return 0;
}
