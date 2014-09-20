#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <cctype>
#include <cmath>
#define STEP 0.01
using namespace std;
long long int q(int n, double x) {
	return (long long  int)(pow(x, 1.0 / n) / 0.01);
}
int main() {
	for (long long int a = 1; a <= 221; a++) {
		long long int bct = q(3, 20.0 / (a * STEP));
		for (long long int b = a; b <= bct; b++) {
			long long int cct = q(2, 20.0 / (a * STEP) / (b * STEP));
			if (cct > 2000) cct = 2000;
			for (long long int c = b; c <= cct; c++) {
				if (a * b * c - 1000000 == 0)
					continue;
				if (1000000 * (a + b + c) % (a * b * c - 1000000) == 0) {
					long long int d = 1000000 * (a + b + c) / (a * b * c - 1000000);
					if (d >= c && a + b + c + d <= 2000)
						printf("%.2lf %.2lf %.2lf %.2lf\n", a * STEP, b * STEP, c * STEP, d * STEP);
				}
			}
		}
	}
	return 0;
}