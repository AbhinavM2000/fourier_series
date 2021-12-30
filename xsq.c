#include<stdio.h>

#include<math.h>

#define PI 3.14159265

void getData(double period, double numPt, double step, double p, double q) {
  double l = period / 2;
  int period_int, width;
  period_int = l;
  width = q - p;
  double t1, t2, t3, fx_fourier, fx_real, k, w;
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

  for (double i = -l ; i <= l; i = i + step) {
//Fourier series terms here
    t1 = 1/3;
    t2 = +4*PI*cos(PI*i);
    t3 = -PI*cos(PI*2*i);
	
    w = w + step;

//Plotting x square

        fx_real = i*i;

//Saving (x,fx_real) to txt file
    fprintf(fp2, "%lf %lf\n", i, fx_real);
//Fourier series function
    fx_fourier =  (t1 + t3 + t3 ) ;
//Saving (x,fourier) to txt file
    fprintf(fp, "%lf %lf\n", i, fx_fourier);

  }
  fclose(fp);
  fclose(fp2);
}

int main() {
  int numPt;
  double period, p, q;
  period=2;

  printf("Enter the number of points e.g. 100\n");
  scanf("%d", & numPt);

 p=-1;
 q=1;

  double step = period / numPt;

  getData(period, numPt, step, p, q);
  printf("\nDone ! Run plot.py \n");
  return 0;
}
