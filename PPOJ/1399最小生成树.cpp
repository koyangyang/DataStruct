#include<bits/stdc++.h>
using namespace std;
struct status {
	int cost;
	int vis;
	status() {
	}
	status(int a, int b): cost(a), vis(b) {}
	status(const status &p) {
		cost = p.cost;
		vis = p.vis;
	}
};
class graph {
		int **matrix;
		int num;
		vector<status> mem;
	public:
		graph(int n) {
			num = n;
			matrix = new int*[n];
			mem.resize(num);
			for (int i = 0; i < num; i++) {
				matrix[i] = new int[num];
			}
			for (int i = 0; i < num; i++) {
				for (int j = 0; j < num; j++) {
					cin >> matrix[i][j];
				}
			}
		}
		void prim(int start) {
			for (int i = 0; i < num; i++) {
				if (i == start) {
					status p(0, 1);
					mem[i] = p;
				} else {
					if (matrix[start][i] != 0) {
						status p(matrix[start][i], 0);
						mem[i] = p;
					} else {
						mem[i] = {INT_MAX, 0};
					}
				}

			}
			int sum = 0;
			for (int i = 0; i < num - 1; i++) {
				int idx, mindis;
				mindis = INT_MAX - 1;
				idx = -1;
				for (int j = 0; j < num; j++) {
					if (mem[j].vis == 0 && mindis > mem[j].cost) {
						idx = j;
						mindis = mem[j].cost;
					}
				}
				mem[idx].vis = 1;
				sum += mindis;
				for (int j = 0; j < num; j++) {
					if (mem[j].vis == 0 && matrix[idx][j] != 0 && matrix[idx][j] < mem[j].cost) {
						mem[j].cost = matrix[idx][j];
					}
				}
			}

			cout << sum << endl;
		}
};

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		graph p(n);
		p.prim(0);
	}
	return 1;
}
