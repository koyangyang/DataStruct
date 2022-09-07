#include<bits/stdc++.h>
using namespace std;
class solution {
		int num;
	public:
		solution(int a) {
			num = a;
		}
		void move(int n, char from, char to) {
			printf("Move disk %d from %c to %c\n", n, from, to);
		}
		void hanoi(int n, char x, char y, char z) {
			if (n == 1) {
				move(1, x, z);
			} else {
				hanoi(n - 1, x, z, y);
				move(n, x, z);
				hanoi(n - 1, y, x, z);
			}
		}
};
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		solution p(n);
		p.hanoi(n, 'A', 'B', 'C');
		cout << endl;
	}

	return 1;
}
