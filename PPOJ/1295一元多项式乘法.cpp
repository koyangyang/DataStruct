#include<bits/stdc++.h>
using namespace std;
struct node {
	node *next;
	int coff;
	int exp;
	node(int a, int b) {
		coff = a;
		exp = b;
		next = NULL;
	}
	node(): next(NULL) {}
};

class linklist {
		node *rear;

	public:
		node *head;
		int len;
		linklist() {
			len = 0;
			head = new node;
		}
		linklist(int n) {
			len = n;
			head = new node;
			node *p = head;
			for (int i = 0; i < len; i++) {
				int coff, exp;
				cin >> coff >> exp;
				node *s = new node(coff, exp);
				p->next = s;
				p = s;
			}
		}
		void print() {
			node *p = head->next;
			while (p) {
				cout << p->coff << " " << p->exp << " ";
				p = p->next;
			}
		}
};

void calculate(linklist &a, linklist &b, linklist &c) {
	node *p = a.head->next;
	node *q = b.head->next;
	if (p == NULL || q == NULL) {
		cout << "0 0" << endl;
		return ;
	}
	while (p) {
		int coff1 = p->coff;
		int exp1 = p->exp;
		node *t = q;

		while (t) {
			int cf = coff1 * t->coff;
			int ex = exp1 + t->exp;
			node *k = c.head->next;
			node *pre = c.head;
			int flag = 0;
			while (k) {
				if (k->exp == ex) {
					k->coff += cf;
					if (k->coff == 0) {
						pre->next = pre->next->next;
						delete k;
						c.len--;
					}
					flag = 1;
					break;
				} else if (k->exp < ex) {
					node *temp = new node(cf, ex);
					temp->next = pre->next;
					pre->next = temp;
					flag = 1;
					c.len++;
					break;
				}
				pre = k;
				k = k->next;
			}
			if (flag == 0) {
				node *temp = new node(cf, ex);
				temp->next = pre->next;
				pre->next = temp;
				c.len++;
			}
			t = t->next;
		}
		p = p->next;
	}


}
int main() {
	int m, n;
	cin >> m;
	linklist a(m);
	cin >> n;
	linklist b(n);
	linklist c;
	calculate(a, b, c);
	c.print();
	return 1;
}
