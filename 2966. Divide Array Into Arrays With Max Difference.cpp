class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> sol;
        
        if(nums.size()%3!=0) return sol;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i =2;i<n;i++){
            if(nums[i]-nums[i-2]<=k){
                sol.push_back({nums[i-2],nums[i-1],nums[i]});
                i = i+2;
            }
            else{
                return {};
            }
        }
       return sol;
       //T.C === O(n);
       //S.C === O(n);
    }
};