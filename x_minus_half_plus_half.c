#include<stdio.h>

#include<math.h>

#define PI 3.14159265

void getData(double numPt, double step, double p, double q) {
  double t1, t2, t3, fx_fourier, fx_real;

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
   t1= sin(2*PI*i);
   t2= -0.5*sin(4*PI*i);
   t3= (1/3)*sin(6*PI*i);
	

//Plotting 0 and sin x
if(i>0&&i<PI)
        fx_real = sin(i);
if(i<0&&i>-PI)
        fx_real = 0;
//Saving (x,fx_real) to txt file
    fprintf(fp2, "%lf %lf\n", i, fx_real);
//Fourier series function
    fx_fourier =  (t1 + t2 + t3 )/PI ;
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

 p=-0.5;
 q=0.5;

  double step = (q-p) / numPt;

  getData(numPt, step, p, q);
  printf("\nDone ! Run plot.py \n");
  return 0;
}
