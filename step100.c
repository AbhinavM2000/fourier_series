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
	
//Plotting step fn
if(i>=-PI&&i<0)
        fx_real = -1;
if(i<PI&&i>0)
        fx_real = 1;

//Saving (x,fx_real) to txt file
    fprintf(fp2, "%lf %lf\n", i, fx_real);
//Fourier series function
    fx_fourier =  calc_100_terms(double x);
//Saving (x,fourier) to txt file
    fprintf(fp, "%lf %lf\n", i, fx_fourier);

  }
  fclose(fp);
  fclose(fp2);
}


double calc_100_terms(double x)
{
double fxxx,an[100],bn[100],ao;
int n,w;
n=0;
w=0;
while(n<=100)
{
an[w]= -2*sin(0.5*n*PI);
an[w]= an[w]/PI;
an[w]=an[w]*-1;
an[w]=an[w]/n;
bn[w]=cos(n*0.5*PI)- pow(-1,n);
bn[w]=bn[w]/PI;
bn[w]=2*bn[w];
bn[w]=bn[w]/n;
n++;
w++;
}

while(w<=100)
{

fxxx= an[w]*cos(w*x) + bn[w]*sin(w*x);
fxxx = fxxx + ao/2;

}

return fxxx;
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
