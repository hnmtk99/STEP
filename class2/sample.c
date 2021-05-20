#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double get_time() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6;
}

int main() {
  int n, i, j;
  FILE *fp;
  fp = fopen("test1.dat", "w");

  if(fp == NULL) {
    printf("ファイルをオープンできませんでした。\n");
    return 1;
  }
  else printf("ファイルをオープンしました。\n");

  // n=1から100まで それぞれ10回の平均時間を記録
  for(n=1; n<=100; n++) {
    double* a = (double*)malloc(n * n * sizeof(double)); // Matrix A
    double* b = (double*)malloc(n * n * sizeof(double)); // Matrix B
    double* c = (double*)malloc(n * n * sizeof(double)); // Matrix C


    double m_time = 0;
    for(int l=0; l<10; l++) {
    
      // Initialize the matrices to some values.
      int i, j;
      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          a[i * n + j] = i * n + j; // A[i][j]
          b[i * n + j] = j * n + i; // B[i][j]
          c[i * n + j] = 0; // C[i][j]
        }
      }

      double begin = get_time();

      /* C = A * B */
      int k;
      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
        for (k = 0; k < n; k++) {
          c[i * n + j] += a[i * n + k] * b[k * n + j];
          }
        //printf("%f\n", c[i * n + j]);
        }
      }

      double end = get_time();
      m_time += end - begin;
    }

    fprintf(fp, "%d %.6lf\n", n, m_time / 10);
    free(a);
    free(b);
    free(c);
  }


  fclose(fp);
  printf("ファイルをクローズしました。\n");
  return 0;
}
