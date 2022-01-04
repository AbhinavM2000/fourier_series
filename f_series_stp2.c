#include<stdio.h>
#include<math.h>
#define PI 3.14159265

double calc_n_terms(double x, double an[100], double bn[100], int n) { //function that evaluates ao/2 + Σ 1 to 100 (an cosnx + bn sin nx) at x
  return ((an[n]) * cos(n * x)) + ((bn[n]) * sin(n * x)); // returned to line 40 for summation
}

void getData(int numPt, double p, double q, double an[100], double bn[100], int num_coeff) { //received an and bn
  double fx_fourier, fx_real, ao, step;
  int n;
  step = (q - p) / numPt; //calculating step
  ao = 1; //ao for this function
  n = 1;

  //Opening files
  FILE * fp;
  fp = fopen("data.txt", "w");
  FILE * fp2;
  fp2 = fopen("data2.txt", "w");

  for (double x = p; x <= q; x = x + step) { //for loop #1 to vary x in f(x)

    //Plotting step fn
    if (x >= -PI && x < 0)
      fx_real = 0;
    if (x <= PI && x > 0)
      fx_real = 1;
    //Saving (x,fx_real) to txt file
    fprintf(fp2, "%lf %lf\n", x, fx_real);


    for (int n = 1; n <= num_coeff; n++) { //for loop #2 to sum up coefficients from 1 to num_coeff for that value of x
      //Fourier series function
      fx_fourier = fx_fourier + calc_n_terms(x, an, bn, n); //passed an bn and x
    }

    //Saving (x,fx_fourier) to txt file
    fprintf(fp, "%lf %lf \n", x, ((ao / 2) + fx_fourier)); // ao/2 added to the final f(x) value
    
    fx_fourier = 0; // reset for the next value of x
  }
  fclose(fp);
  fclose(fp2);
}



int main() {
  int numPt, N, num_coeff;
  double p, q, an[100], bn[100];
  N = 1;

  //limits
  p = -PI;
  q = PI;

  printf("Enter the number of points e.g. 100\n");
  scanf("%d", & numPt);
  printf("Enter the number of coefficients e.g. 100\n");
  scanf("%d", & num_coeff);


  //Calculating required number of coefficients for an and bn for this function
  while (N <= num_coeff) {
    an[N] = 0; //Formula for an
    bn[N] = (1 - pow(-1, N)) / PI / N; //Formula for bn
    N++;
  }

  
  //passed an and bn
  getData(numPt, p, q, an, bn, num_coeff);


  printf("\nDone ! Run plot.py \n");
  return 0;
}
