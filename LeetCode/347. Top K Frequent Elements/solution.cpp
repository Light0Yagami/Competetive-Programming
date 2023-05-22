/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> map;
        for(auto n : nums){
            map[n]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;

        for(auto &i : map){
            min_heap.push({i.second,i.first});
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }

        vector<int> res;
        while(k--){
            res.push_back(min_heap.top().second);
            min_heap.pop();
        } 
        return res;
    }
};
