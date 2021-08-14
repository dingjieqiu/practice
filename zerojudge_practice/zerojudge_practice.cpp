#include<iostream>
#include <iomanip>
#include<algorithm>
using namespace std;

struct node {
	node* nextPt;
	int value;
};


class LinkedList {

	node* start;
	node* tail;
	public:
		LinkedList() {
			start = NULL;
			tail = start;
		}
		void insertion(int val) {
			if (start == NULL) {
				node* Node = new node;
				Node->value = val;
				Node->nextPt = NULL;
				start = Node;
				tail = start;
				return;
			}
			node* init = start;
			for (; init != NULL; init = init->nextPt) {
				//cout << init << endl;
				if (init->value == val)return;
			}
			init = new node;
			init->value = val;
			init->nextPt = NULL;
			tail->nextPt = init;
			tail = init;
		}
		void deletion(int val) {
			node* prev = start;
			if (prev == NULL)return;
			if (prev->value == val) {
				start = start->nextPt;
				delete prev;
				return;
			}
			node* curr = start->nextPt;
			for (; curr != NULL; curr = curr->nextPt) {
				if (curr->value == val) {
					if (curr->nextPt == NULL)tail = prev;
					prev->nextPt = curr->nextPt;
					delete curr;
					return;
				}
				prev = curr;
			}
		}
		void show(int index) {
			int arr[10000];
			int count = 0;
			for (node* init = start; init != NULL; init = init->nextPt) {
				arr[count++] = init->value;
			}
			sort(arr, arr + count);
			cout << '[' << setw(3) << setfill('0') << index;
			cout << "]:";
			for (int i = 0; i < count; i++) {
				cout << arr[i] << " -> ";
			}
			cout << "NULL\n";
		}

};

int main() {
	int k, m;
	while (cin >> k >> m) {
		LinkedList arr[200];
		for (int i = 0; i < k; i++) {
			int com, val;
			cin >> com;
			if (com == 1) {
				cin >> val;
				arr[val % m].insertion(val);
			}
			if (com == 2) {
				cin >> val;
				arr[val % m].deletion(val);
			}
			if (com == 3) {
				cout << "===== s =====\n";
				for (int j = 0; j < m; j++) {
					arr[j].show(j);
				}
				cout << "===== e =====\n";
			}
		}
	}
}