#ifndef OLARH
#define OLARH
#include <math.h>
#include <inttypes.h>
int oula6(int n) {
	if(n <= 0 || n > INT32_MAX) {
		return 0;
	}
	int sum = 0,num = 0;
	for(int i = 1; i <= n; i++) {
		if(sum > INT32_MAX - i|| num > INT32_MAX - i * i || i > INT32_MAX / i) {
            printf("error\n");
		    return 0;
		}
		sum += i;
        num += i * i;
	}
	return sum * sum - num;
}

///7
/*
int oula7(int n) {
	int prime[n + 5] = {0};
	int M = n * 30;
    for (int i = 2; i <= M; ++i) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] * i <= M; ++j) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return prime[n];
}
*/


//15

int64_t oula15(int n) {
	if(n < 0 || n > INT32_MAX) {
		return 0;
	}
	int64_t m = n;
    int64_t ans  = 1;
    for(int i = n * 2; i > n; i--) {
    	if(ans > INT64_MAX / i) {
//	     printf("error\n");
		 return 0;
    	}
        ans *= i;
        while(m != 0 && ans % m == 0) {
            ans /= m;
            m--;
        }
    }
	return ans;
}



int oula16(int n) {
	if(n < 0 || n > INT32_MAX) {
	//  printf("error\n");
	  return 0;
	}
	int f[2000] = {0};
	    f[0] = f[1] = 1;
	
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= f[0]; j++) {
            f[j] *= 2;
        }
        for(int k = 1; k <= f[0]; k++) {
            if(f[k] < 10) continue;
            f[k + 1] += f[k] / 10;
            f[k] = f[k] % 10;
            if(k == f[0]) {
               f[0]++;
               if(f[0] >= 2000) {
	             printf("error\n");
	             return 0;
               }
            }
        }
    }
    int  ans = 0;
    for(int i = 1; i <= f[0];i++) {
        ans += f[i];
    }
    return ans;
}



int oula31(int n) {
	if(n < 0 || n > INT32_MAX) {
		//printf("error\n");
		return 0;
	}
     int32_t many[8]={1, 2, 5, 10, 20, 50, 100, 200};
     int32_t d[205] = {0};
     d[0] = 1;
     for (int32_t i = 0; i < 8; i++)
       for (int32_t j = 0; j <= n - many[i]; j++)
         d[j + many[i]] += d[j];
      return d[n];
  }
#endif
