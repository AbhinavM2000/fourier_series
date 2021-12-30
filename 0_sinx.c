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

  for (double i = -PI ; i <= PI; i = i + step) {
//Fourier series terms here
   t1 = 2/PI;
   t2 = cos(2*i);
	t2=t2*2;
t2=-t2;
t2=t2/3;
t2=t2/PI;
t3 = cos(4*i);
t3=t3*2;
t3=t3/15;
t3=t3/PI;	
    w = w + step;

//Plotting 0 and sin x
if(i>0&&i<PI)
        fx_real = sin(i);
if(i<0&&i>-PI)
        fx_real = 0;
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
  period=2*PI;

  printf("Enter the number of points e.g. 100\n");
  scanf("%d", & numPt);

 p=-PI;
 q=PI;

  double step = period / numPt;

  getData(period, numPt, step, p, q);
  printf("\nDone ! Run plot.py \n");
  return 0;
}
