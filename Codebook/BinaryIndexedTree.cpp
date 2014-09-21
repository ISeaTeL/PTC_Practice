//Binary Indexed Tree
#include<cstdio>
#define MAX 60000
int n, s[MAX], t[MAX];
int lower_bit(int x) {
	return x & -x;
}
int sum(int x) {
	int tot = 0;
	while (x > 0) {
		tot += t[x];
		x -= lower_bit(x);
	}
	return tot;
}
void add(int x, int c) {
	while (x <= n) {
		t[x] += c;
		x += lower_bit(x);
	}
}
int query(int a, int b) {
	return sum(b) - sum(a - 1);
}
void build(int x) {
	for (int i = 1; i <= x; i++)
		t[i] = s[i] + query(i - lower_bit(i) + 1, i - 1);
}

int main(int argc, char *argv[]) {
	for (int i = 0; i < 10000; i++)
		s[i] = 1;
	build(10000);
	printf("%d\n", query(3, 1333));
	return 0;
}