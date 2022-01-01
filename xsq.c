#include<stdio.h>

#include<math.h>

#define PI 3.14159265

void getData(double period, double numPt, double step, double p, double q) {
  double t1, t2, t3, fx_fourier, fx_real, k;
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

  for (double i = p ; i <= q; i = i + step) {
//Fourier series terms here
    t1 = 1/3;
    t2 = -cos(PI*i);
    t3 = +cos(PI*2*i)/4-cos(PI*3*i)/9;
	

//Plotting x square

        fx_real = i*i;

//Saving (x,fx_real) to txt file
    fprintf(fp2, "%lf %lf\n", i, fx_real);
//Fourier series function
    fx_fourier =  t1 + (4/PI/PI)*(t2 + t3) ;
//Saving (x,fourier) to txt file
    fprintf(fp, "%lf %lf\n", i, fx_fourier);

  }
  fclose(fp);
  fclose(fp2);
}

int main() {
  int numPt;
  double p, q;
 

  printf("Enter the number of points e.g. 100\n");
  scanf("%d", & numPt);

 p=-1;
 q=1;

  double step = (q-p) / numPt;

  getData(q-p, numPt, step, p, q);
  printf("\nDone ! Run plot.py \n");
  return 0;
}
