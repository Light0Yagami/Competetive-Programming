/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        map<int,int> map;
        
        for(int i = 0; i<nums1.size();i++){
            map[nums1[i]]++;
        }
        
        for(int i = 0; i< nums2.size(); i++){
            auto it = map.find(nums2[i]);
            if(it != map.end() && it->second > 0){
                ans.push_back(nums2[i]);
                it->second--;
            }
        }
        return ans;
    }
};
