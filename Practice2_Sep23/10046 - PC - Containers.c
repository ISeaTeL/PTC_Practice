#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int t;
	long long int n, x, k, i, a, b, area, ansA, ansB, ansArea, tmp;
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		x = (n - 1) / 5 + 1;
		k = sqrt(x) + 1;
		ansArea = 1e18;
		for(i = k; i >= 1; i--){
			if(x % i == 0)
				a = i, b = x / i;
			else
				a = i, b = x / i + 1;
			area = 88 * a + 40 * b + 8 + a * b * 440;
			if(ansArea > area || (ansArea == area && abs(a - b) < abs(ansA - ansB)))
				ansA = a * 40 + (a + 1) * 4, ansB = b * 8 + (b + 1) * 2, ansArea = area;
			area = 88 * b + 40 * a + 8 + a * b * 440;
			if(ansArea > area || (ansArea == area && abs(a - b) < abs(ansA - ansB)))
				ansA = b * 40 + (b + 1) * 4, ansB = a * 8 + (a + 1) * 2, ansArea = area;
		}
		if(ansA < ansB)
			tmp = ansA, ansA = ansB, ansB = tmp;
		printf("%lld X %lld = %lld\n", ansA, ansB, ansArea);
	}
	return 0;
}
