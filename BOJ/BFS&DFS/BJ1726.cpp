#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int M, N;
int field[111][111];
bool check[111][111][5];
int MIN = INT_MAX;
int stx, sty, sd, dtx, dty, dd;
int dx[] = { 0,0,0,1,-1 };
int dy[] = { 0,1,-1,0,0 };

typedef struct {
	int x; int y; int dir; int dist;
}rb;
queue <rb> q;

int left(int ddir) {
	if (ddir == 1)
		return 4;
	if (ddir == 2)
		return 3;
	if (ddir == 3)
		return 1;
	if (ddir == 4)
		return 2;
}
int right(int ddir) {
	if (ddir == 1)
		return 3;
	if (ddir == 2)
		return 4;
	if (ddir == 3)
		return 2;
	if (ddir == 4)
		return 1;
}


int bfs(int xx, int yy, int fd) {
	q.push({ xx,yy,fd, 0 });

	while (!q.empty()) {
		int ox = q.front().x;
		int oy = q.front().y;
		int od = q.front().dir;
		int os = q.front().dist;
		check[ox][oy][od] = 1;
		q.pop();

		if (ox == dtx && oy == dty && od == dd)
			return min(MIN, os);

		else {
			if (MIN > os + 1) {
				for (int k = 1; k <= 3; k++) {
					int nx = ox + dx[od] * k;
					int ny = oy + dy[od] * k;
					if (field[nx][ny] == 1 || check[nx][ny][od])
						break;

					if (!check[nx][ny][od] && field[nx][ny] == 0 && 1 <= nx && nx <= M && N >= ny && ny >= 1) {
						q.push({ nx,ny,od,os + 1 });
					}
				}
				int ld = left(od);
				int rd = right(od);
				if (!check[ox][oy][ld]) 
					q.push({ ox,oy,ld,os + 1 });
				if (!check[ox][oy][rd]) 
					q.push({ ox,oy,rd,os + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			cin >> field[i][j];
	cin >> stx >> sty >> sd;
	cin >> dtx >> dty >> dd;

	cout << bfs(stx, sty, sd);
	return 0;
}