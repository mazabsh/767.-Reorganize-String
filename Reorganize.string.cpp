#include<iostream> 
#include<vector> 
#include<queue> 
#include<unordered_map> 

using namespace std; 

class Solution{
public: 
    string reorganizeString(string s) {
      unordered_map<char, int> freq; 
      for(char c:s) freq[c]++; 

      priority_queue<pair<int, char>> pq; 
      for(auto [c, count]: freq){
        if(count> (s.size()+1)/2) return ""; 
        pq.push({count,c}); 
      }
      string ans; 
      while(pq.size()>=2){
        auto [count1, c1] = pq.top(); pq.pop(); 
        auto [count2, c2] = pq.top(); pq.pop(); 
        ans +=c1; 
        ans +=c2; 
        if(--count1>0) pq.push({count1,c1}); 
        if(--count2>0) pq.push({count2,c2}); 
        
      }
      if(!pq.empty()){
        auto [count,c] = pq.top(); pq.pop(); 
        ans +=c; 
      }
      return ans; 
    }
};
int main(){
  string s = "aaabcde"; 
  Solution sol; 
  cout << sol.reorganizeString(s) << endl; 
  return 0; 
}
