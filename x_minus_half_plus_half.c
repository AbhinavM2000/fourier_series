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

  for (double i = -l; i <= l ; i = i + step) {
//Fourier series terms here
    t1 = PI*sin(i);
    t2 =-0.5*PI*sin(2*PI*i);
    t3 = PI/3*sin(PI*3*i)-0.25*PI*sin(4*PI*i); //t4 inc.
	
    w = w + step;

//Plotting x 

        fx_real = i;

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
  period=1;

  printf("Enter the number of points e.g. 100\n");
  scanf("%d", & numPt);

 p=-0.5;
 q=0.5;

  double step = period / numPt;

  getData(period, numPt, step, p, q);
  printf("\nDone ! Run plot.py \n");
  return 0;
}
