#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
		Solution() {
			ios_base::sync_with_stdio(0);
			cin.tie(0); cout.tie(0);			
		}

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
				unordered_set<string> isVisited;
				unordered_set<string> wordDict;

				for(auto word: wordList) {
					wordDict.insert(word);
				}

				// etay time memory beshi lagse, so no 
				// while(!wordList.empty()) {
				// 	string word = wordList[wordList.size() - 1]; 
				// 	wordList.pop_back();
				// 	wordDict.insert(word);
				// }

				int count = 0;
				bool isFound = false;

				pair<string, int> p;
				string front = "";
				
				// bfs
				q.push({beginWord, 1});
				while(!q.empty()) {
					p = q.front();
					q.pop();
					front = p.first;
					int currentLevel = p.second;
					
					if(front == endWord) {
						isFound = true;
						count = currentLevel;
						break;
					}

					int N = front.size();
					for(int i=0; i<N; i++) {
						char original = front[i];
						for(int j=0; j<26; j++) {
							char ch = j + 'a';
							// if(ch != original) {
								// todo logic, but too much intendation, so 
								// use negative logic, continue, and write main logic out below if block
							// }
							if(ch == original) {
								continue;
							}
							string temp = front;
							temp[i] = ch;

							bool exists = wordDict.find(temp) != wordDict.end(); // find(wordList.begin(), wordList.end(), temp) != wordList.end();
							bool notVisited = isVisited.find(temp) == isVisited.end();
							if(exists && notVisited) {
								int nextLevel = currentLevel + 1;
								q.push({temp, nextLevel});
								isVisited.insert(temp);
							}
						}
					}
				}

				if(isFound) {
					return count;
				} return 0;
    }
};

int main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);

	Solution s;
	vector<string> v1 = {"hot","dot","dog","lot","log","cog"};
	vector<string> v2 = {"hot","dot","dog","lot","log"};

	cout<<s.ladderLength("hit", "cog", v1)<<"\n";
	cout<<s.ladderLength("hit", "cog", v2)<<"\n";
	
// Example 1:
// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 


	return 0;
}
