#include<stdio.h>

#include<math.h>

#define PI 3.14159265

void getData(double numPt, double step, double p, double q) {
  double t1, t2, t3,t4, fx_fourier, fx_real;

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
//Fourier series terms here (Check the fourier series, I'm not sure about this one)
   t1= 1/PI;
   t2= 0.5*sin(i) - 2* (cos(2*i))/3/PI;
   t3= 0.5*sin(i) - 2* (cos(4*i))/15/PI;
	t4=t3= 0.5*sin(i) - 2* (cos(6*i))/35/PI;

	

//Plotting 0 and sin x
if(i>0&&i<PI)
        fx_real = sin(i);
if(i<0&&i>-PI)
        fx_real = 0;
//Saving (x,fx_real) to txt file
    fprintf(fp2, "%lf %lf\n", i, fx_real);
//Fourier series function
    fx_fourier =  t1 + t2+t3+t4 ;
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

 p=-PI;
 q=PI;

  double step = (q-p) / numPt;

  getData(numPt, step, p, q);
  printf("\nDone ! Run plot.py \n");
  return 0;
}
