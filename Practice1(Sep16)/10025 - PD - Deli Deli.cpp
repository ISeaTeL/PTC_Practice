#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int main() {
	int a, b;
	char str[100];
	while (~scanf("%d%d", &a, &b)) {
		map<string, string> M;
		for (int i = 0; i < a; i++) {
			scanf("%s", str);
			string tmp = str;
			scanf("%s", str);
			string tmp2 = str;
			M[tmp] = tmp2;
		}
		for (int i = 0; i < b; i++) {
			scanf("%s", str);
			string tmp = str;
			if (M.find(tmp) != M.end()) {
				printf("%s\n", M[tmp].c_str());
			} else {
				char a2 = tmp[tmp.length() - 2];
				char b2 = tmp[tmp.length() - 1];
				char mom[5] = {'a', 'e', 'i', 'o', 'u'};
				bool bg = true;
				for (int j = 0; j < 5; j++) {
					if (a2 == mom[j]) bg = false;
				}
				if (b2 == 'y' && bg) {
					for (int k = 0; k < tmp.length() - 1; k++) {
						putchar(tmp[k]);
					}
					printf("ies\n");
				} else {
					if (b2 == 'o' || b2 == 's' || b2 == 'x') {
						printf("%ses\n", tmp.c_str());
					} else if (b2 == 'h' && (a2 == 'c' || a2 == 's')) {
						printf("%ses\n", tmp.c_str());
					} else {
						printf("%ss\n", tmp.c_str());
					}
				}
			}
		}
	}
	return 0;
}