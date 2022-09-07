//和DFS几乎一模一样，就是注意为了输出时方便，我们用数组保存节点，然后如果某一节点已经访问过，我们就不加入备忘录即可。
#include<bits/stdc++.h>
using namespace std;
class graph {
	int **matrix;
	int num;
	vector<int> vis;
public:
	graph(int n) {
		num = n;
		matrix = new int*[n];
		vis.resize(num, 0);
		for (int i = 0; i < num; i++) {
			matrix[i] = new int[num];
		}
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				cin >> matrix[i][j];
			}
		}
	}
	void BFS_travel() {
		for (int i = 0; i < num; i++) {
			if (vis[i] == 0)
				BFS(i);
		}
		cout << endl;
	}
	void BFS(int pos) {
		queue<int> mque;
		mque.push(pos);
		while (!mque.empty()) {
			int temp = mque.front();
			mque.pop();
			if(vis[temp]==0)
			{
				cout<<temp;
				vis[temp]=1;
			}
			else continue;
			for (int i = 0; i < num; i++) {
				if (vis[i] == 0 && matrix[temp][i] == 1)
					mque.push(i);
			}
		}
	}
};

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		graph p(n);
		p.BFS_travel();
	}
	return 1;
}
