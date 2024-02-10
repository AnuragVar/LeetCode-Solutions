class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:nums){
            pq.push(it);
        }
        while(k>0){
            long long topp = pq.top();
            pq.pop();
            topp++;
            pq.push(topp);
            k--;
        }
        long long ans =1;
        int mod = 1e9+7;
        while(!pq.empty()){
            ans = (ans*pq.top())%mod;
            pq.pop();
        }
        return ans;
    }
};