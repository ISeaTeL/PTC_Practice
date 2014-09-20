#include <stdio.h>
#include <string.h>

int r, n, c, m;
int map[105][105], pic[105][105];
bool fg;
int ct;

bool isAns() {
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < n; j++)
			if (pic[i][j] != map[i][j])
				return false;
	return true;
}
/*
void dfs(int x, int y){
    if(y == n){
        if(x == r - 1){
            if(isAns()){
                fg = true;
            }
        }
        else
            dfs(x + 1, 0);
        return;
    }
    int i;
    if(map[x][y] == pic[x][y]){
        dfs(x, y + 1);
        return;
    }
    else{
        dfs();
    }
}
*/
bool solve() {
	int i, j, k, l;
	for (i = 0; i <= r - c; i++) {
		for (j = 0; j <= n - m; j++)
			if (map[i][j] != pic[i][j]) {
				for (k = i; k < i + c; k++)
					for (l = j; l < j + m; l++)
						pic[k][l] = !pic[k][l];
				ct++;
			}
	}
	return isAns();
}

int main() {
	int i, j;
	while (scanf("%d %d %d %d", &r, &n, &c, &m), r + n + c + m) {
		getchar();
		for (i = 0; i < r; i++, getchar())
			for (j = 0; j < n; j++) {
				map[i][j] = getchar() - 48;
			}
		memset(pic, 0, sizeof(pic));
		//dfs(0, 0);
		ct = 0;
		if (solve()) {
			printf("%d\n", ct);
		}
		else
			puts("-1");
	}
	return 0;
}