
/////////////////////////////////////
/*
         SWEA5644 무선 충전
                                   */
/////////////////////////////////////

/*
조건 범위가 겹치는 조건을 찾는 게 엄청 어려웠다.
그래서 무선 충전기의 위치와 범위를 벡터에 푸쉬하고,
사용자가 이동하는 좌표가 겹치는지를 확인하고,
겹친다면 u1,u2 배열을 1로 바꿔주고,
같은 충전기를 볼 때와 아닐 때로 구분해서 
조건을 만들었다.
나중에 다시 한번 짜봐야겠다.
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int T, M, A;//테케, 사용자 이동횟수, 충전기 개수
int dx[5] = { 0,0,1,0,-1 };
int dy[5] = { 0,-1,0,1,0 };

typedef struct {
	int X;
	int Y;
	int C;
	int P;
} BC;
vector<BC> v;

int charge(int y1, int x1, int y2, int x2) {
	int ans = 0;
	bool u1[10] = {};
	bool u2[10] = {};

	for (int i = 0; i < A; i++) {
		if (abs(y1 - v[i].Y) + abs(x1 - v[i].X) <= v[i].C) {
			u1[i] = 1;
		}
		if (abs(y2 - v[i].Y) + abs(x2 - v[i].X) <= v[i].C) {
			u2[i] = 1;
		}
	}

	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++) {
			int tmp = 0;
			if (i == j) {
				if (u1[i] || u2[j]) tmp = v[i].P;//2로 나눠서 두번 더하나 안 나누고 한번 더하나 같기 때문.
			}
			else {
				if (u1[i]) tmp += v[i].P;
				if (u2[j]) tmp += v[j].P;
			}
			if (ans < tmp) ans = tmp;
		}
	}
	return ans;
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {

		int arr1[111] = {}, arr2[111] = {};
		v.clear();

		scanf("%d%d", &M, &A);
		for (int m = 0; m < M; m++) {
			scanf("%d", &arr1[m]);
		}
		for (int m = 0; m < M; m++) {
			scanf("%d", &arr2[m]);
		}
		//사용자 이동경로
		for (int k = 0; k < A; k++) {//충전기 입력
			int x, y, c, p;
			scanf("%d%d%d%d", &x, &y, &c, &p);
			BC bc = { x,y,c,p };
			v.push_back(bc);
		}
		int x1 = 1, y1 = 1;
		int x2 = 10, y2 = 10;
		int MAX = charge(y1, x1, y2, x2);//이동하기전, 첫 지점에서의 충전값으로 MAX를 초기화 시킨다.
		for (int m = 0; m < M; m++) {
			x1 += dx[arr1[m]];
			y1 += dy[arr1[m]];
			x2 += dx[arr2[m]];
			y2 += dy[arr2[m]];
			MAX += charge(y1, x1, y2, x2);
		}
		printf("#%d %d\n", t, MAX);
	}
	return 0;
}