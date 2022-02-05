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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* header = nullptr;
      ListNode* current = nullptr;
      
      int minimus = INT_MAX;
      while(list1!=nullptr && list2!=nullptr) {
        if(list1->val < list2->val) {
          minimus = list1->val;
          list1 = list1->next;
        } else {
          minimus = list2->val;
          list2 = list2->next;
        }
        //ListNode node(minimus);
        ListNode *node = new ListNode(minimus, nullptr);
        if(header == nullptr) {
          header = node;
          current = header;
        } else {
          current->next = node;
          current = current->next;
        }
        node = nullptr;
        cerr<<"Log1 : ";
        // header->printer();
        //cerr<<"Log: 1 minimus = "<<minimus<<"\n";
      }

      while(list1!=nullptr) {
          minimus = list1->val;
          list1 = list1->next;
      
        ListNode *node = new ListNode(minimus, nullptr);
        // ListNode node(minimus);
        if(header == nullptr) {
          header = node;
          current = header;
        } else {
          current->next = node;
          current = current->next;
        }
          //      cerr<<"Log: 2 minimus = "<<minimus<<"\n";
              cerr<<"Log 2 : ";
        // header->printer();
        node = nullptr;
      }

      while(list2!=nullptr) {
        //cerr<<"log 4: "<<"\n";
          minimus = list2->val;
          list2 = list2->next;
      
        ListNode *node = new ListNode(minimus, nullptr);
        // ListNode node(minimus);
        if(header == nullptr) {
          header = node;
          current = header;
        } else {
          current->next = node;
          current = current->next;
        }
        node = nullptr;
          //      cerr<<"Log: 3 minimus = "<<minimus<<"\n";
              cerr<<"Log 3 : ";
        // header->printer();
      }
      //cerr<<"log5\n";
      current = nullptr;

      return header;        
    }




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

	ListNode* a3 = new ListNode(3, nullptr);
	ListNode* a2 = new ListNode(2, a3);
	ListNode* a1 = new ListNode(1, a2);

	
	ListNode* a6 = new ListNode(6, nullptr);
	ListNode* a5 = new ListNode(5, a6);
	ListNode* a4 = new ListNode(4, a5);


	ListNode* a8 = new ListNode(6);
	ListNode* a7 = new ListNode(2, a8);

	lists.push_back(a1);
	lists.push_back(a4);
	lists.push_back(a7);

	Solution s;
	ListNode* output = s.mergeTwoLists(a1, a4);
  cerr<<"log 6\n";
	while(output!=nullptr) {
  //cerr<<"log 7\n";
		cout<<output->val<<" ";
		output = output->next;
	//cerr<<"log 8\n";
	
  }
	cout<<"\n";

	return 0;
}
