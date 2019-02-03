#include <iostream>
#include <algorithm>
using namespace std;

int dp[510][510],arr[510][510];

int tri(int i, int j) {
	if (i == n) return arr[i][j];
	int &ret = dp[510][510];
	if (ret != 0) return ret;
	ret = arr[i][j] + max(tri(i + 1, j) + (tri(i + 1, j + 1));
	return ret;
}
int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	return 0;
}