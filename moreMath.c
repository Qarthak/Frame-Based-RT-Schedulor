#include "moreMath.h"
#include "vectorLL.h"
#include <stdlib.h>

long long GCD(long long x, long long y){
	if (y == 0)
		return x;
	return GCD(y, x % y);
}

long long LCM(long long x, long long y){
	return (x*y)/GCD(x,y);
}

long long roofSqrt(long long x){
	if(x<0){
		return -1;
	}
	long long low = 0;
	long long mid = (low+x+1)/2;
	while(low<=x){
		if(mid*mid==x){
			return mid;
		}
		if(low>=x){
			return x;
		}
		else if(mid*mid<x){
			low = mid+1;
		}
		else{
			x = mid-1;
		}
		mid = (low+x+1)/2;
	}
	return x;
}

void allFactors(long long n, vectorLL* factors){
	long long i;
	for (i=1; i*i<n; i++){
		if (n % i == 0)
			vectorLLPushback(factors, i);
	}
	
	if (i-(n/i)==1)
		i--;
	
	for ( ;i>=1; i--){
		if (n % i == 0)
			vectorLLPushback(factors, n/i);
	}
}

long long max(long long x, long long y){
	return x > y ? x : y;
}

long long min(long long x, long long y){
	return x > y ? y : x;
}

int upperBound(vectorLL* arr, long long x){
	
	int low = 0;
	int high = vectorLLSize(arr)-1;
	int mid = (low+high+1)/2;
	while(low<=high){
		if(vectorLLGet(arr, mid)==x){
			return mid;
		}
		else if(vectorLLGet(arr, mid)<x){
			low = mid+1;
		}
		else{
			high = mid-1;
		}
		mid = (low+high+1)/2;
	}
	return low;
}