bool comp(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b){
    if(a.second>b.second) return 1;
    else if(a.second<b.second) return 0;
    else {
        if(a.first.first<b.first.first) return 1;
        return 0;
    }
}
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        //alice will take either
        //stone have max value
        //stone that have corresponding max value for bob

        //same goes to bob
        vector<pair<pair<int,int>,int>> v;
        int n = aliceValues.size();
        for(int i =0;i<n;i++){
            v.push_back({{aliceValues[i],bobValues[i]},aliceValues[i]+bobValues[i]});
        }
        // O(n)
        sort(v.begin(),v.end(),comp);
        int aliceSum =0,bobSum =0;
        
        for(int i=0;i<n;i=i+2){
            aliceSum +=v[i].first.first;
            if(i!=n-1)bobSum +=v[i+1].first.second;
        }
        // O(n)
        if(aliceSum>bobSum)return 1;
        else if(aliceSum<bobSum) return -1;
        return 0;
       //T.C. = O(n);
    //    S.C. = O(n);

    }
};