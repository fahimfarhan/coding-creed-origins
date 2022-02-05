#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class ListNode{
// public:
// 	int val;
// 	ListNode* next;

// 	ListNode() {
// 		val = -1; next = nullptr;
// 	}

// 	ListNode(int x) {
// 		val = x; next = nullptr;
// 	}

// 	ListNode(int x, ListNode* next1) {
// 		val = x; next = next1;
// 	}

// };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& p) {
			ListNode* current = nullptr;
  		ListNode* header = nullptr;
			
			int minimus = INT_MAX;
			int minimusPos = -1;
			int N = p.size();

			
			// ListNode** p = new ListNode*[N];

			// for(int i=0; i<N; i++) {
			// 	p[i] = lists[i];
			// }
			

			int nullCount = 0;

			// ListNode* node = nullptr;
			
			while(nullCount != N) {
				for(int i=0; i<N; i++) {
					if(i == 0) {
						minimus = INT_MAX;
						nullCount = 0;
					}
					if(p[i] != nullptr) {
						if( (p[i]->val) < minimus) {
							minimusPos = i;
							// node = lists[i];
							minimus = p[i]->val;
						}
					} else {
						nullCount++;
					}

					if( (i == N-1) && (nullCount < N)) {
						ListNode *temp = new ListNode(minimus);
						// cout<<"minimus = "<<minimus<<"\n";
						if(header == nullptr) {
							header = temp;
							current = header;
						} else {
							// mergedList->next = temp;
							current->next = temp;
							current = current->next;
						}
						temp = nullptr;
						// node = node->next;
						// cerr<<"minimusPos = "<<minimusPos<<"\n";
						p[minimusPos] = p[minimusPos]->next;
					
						// printer
						// cerr<<"printer start\n";
						// ListNode *t;
						// t = header;
						// while(t != nullptr) {
						// 	cerr<<t->val<<" ";
						// 	t = t->next;
						// } cerr<<"\n";
						// cerr<<"Printer end\n";
					}
				}
			}	

			current = nullptr;

			return header;
    }
};


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// lists = [[1,4,5],[1,3,4],[2,6]]
	vector<ListNode*> lists;

	ListNode* a3 = new ListNode(5);
	ListNode* a2 = new ListNode(4, a3);
	ListNode* a1 = new ListNode(1, a2);

	
	ListNode* a6 = new ListNode(4);
	ListNode* a5 = new ListNode(3, a6);
	ListNode* a4 = new ListNode(1, a5);


	ListNode* a8 = new ListNode(6);
	ListNode* a7 = new ListNode(2, a8);

	lists.push_back(a1);
	lists.push_back(a4);
	lists.push_back(a7);

	Solution s;
	ListNode* output = s.mergeKLists(lists);

	while(output!=nullptr) {

		cout<<output->val<<" ";
		output = output->next;
	}
	cout<<"\n";

	return 0;
}
