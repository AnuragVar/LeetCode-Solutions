
    class Solution {
public:
    static bool comp(vector<int> & a, vector<int> & b){
        if(a[0]==b[0]) return a[1]>b[1];
        //here is a catch
        else {
            return a[0]<b[0];
        }
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int> temp;
        temp.push_back(envelopes[0][1]);

        int n = envelopes.size();
        for(int i =1;i<n;i++){
            if(temp.back()<envelopes[i][1]) temp.push_back(envelopes[i][1]);
            else {
                int it = lower_bound(temp.begin(),temp.end(),envelopes[i][1])-temp.begin();
                temp[it] = envelopes[i][1];
            }
        }
        return temp.size();
    }
};