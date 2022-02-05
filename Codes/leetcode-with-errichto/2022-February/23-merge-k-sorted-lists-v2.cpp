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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
			ListNode* header, *current;
      header = nullptr;
      current = nullptr;

      priority_queue<int> pq; // by default Descending order
      // easiest way to create min priority queue is to use save negative number in the 
      // pq, and multiply by -1 while poping

      int n = 0;
      int N = lists.size();
      for(int i=0; i<N; i++) {
        cerr<<"Log: i = "<<i<<"\n";
        current = lists[i];
        while(current!=nullptr) {
          n = -1 * current->val;
          current = current->next;
          pq.push(n);
          cerr<<"Log: pq.push = "<<n<<"\n";
        }
      }
				cerr<<"insert into pq ok\n";
      while (!pq.empty()) {
        /* code */
        n = -1 * pq.top();
        cerr<<"Log: pq.top = "<<n<<"\n";
        pq.pop();
        ListNode *node = new ListNode(n);
        if(header == nullptr) {
          cerr<<"log1\n";
          header = node;
          current = header;
          cerr<<"log2\n";
        } else {
          cerr<<"log3\n";
          current->next = node;
          current = current->next;
        cerr<<"log4\n";
        }


        node = nullptr;
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
