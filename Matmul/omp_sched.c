# include <stdlib.h>
# include <stdio.h>

# include <omp.h>

int prime(int n, omp_sched_t sched, int chunk);

int main ( int argc, char *argv[] ) {
  int primes;
  double time1, time2, time3, time4;

  printf ( "\n  Number of threads = %d\n", omp_get_max_threads());

  int low = 1;
  int high = 524288;
  int factor = 2;

  printf ( "\n" );
  printf ( "                           Default        Static       Dynamic        Guided\n" );
  printf ( "         N     Pi(N)          Time          Time          Time          Time\n" );
  printf ( "\n" );

  int n = low;

  while (n <= high)
  {
    time1 = omp_get_wtime();
    primes = prime(n, omp_sched_static, 0);
    time1 = omp_get_wtime() - time1;

    time2 = omp_get_wtime();
    primes = prime(n, omp_sched_static, 100);
    time2 = omp_get_wtime() - time2;

    time3 = omp_get_wtime();
    primes = prime(n, omp_sched_dynamic, 100);
    time3 = omp_get_wtime() - time3;

    time4 = omp_get_wtime();
    primes = prime(n, omp_sched_guided, 100);
    time4 = omp_get_wtime() - time4;

    printf("  %8d  %8d  %12f  %12f  %12f  %12f\n", n, primes, time1, time2, time3, time4);

    n *= factor;
  }

  printf("\n");

  return 0;
}

int prime(int n, omp_sched_t sched, int chunk) {
  int prime;
  int sum = 0;

  omp_set_schedule(sched, chunk);

  #pragma omp parallel shared(n) private(prime) 
  {
    #pragma omp for reduction (+:sum) schedule(runtime)
    for (int i = 2; i <= n; ++i) {
      prime = 1;

      for (int j = 2; j < i; ++j) {
        if ( i % j == 0 ) {
          prime = 0;
          break;
        }
      }
      
      sum = sum + prime;
    }
  }

  return sum;
}