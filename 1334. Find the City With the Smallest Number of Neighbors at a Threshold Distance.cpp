class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int m = edges.size();
        vector<vector<int>> s(n,vector<int>(n,1e9));//O(n^2)
            for(int i =0;i<m;i++){
                int u =edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
                s[u][v] = wt;
                s[v][u] = wt;
            } 
            //O(m)
            for(int i =0;i<n;i++) s[i][i] = 0;
            for(int via =0;via<n;via++){
                for(int i =0;i<n;i++){
                    for(int j = 0;j<n;j++){
                        s[i][j] = min(s[i][j],s[i][via]+s[via][j]);
                    }
                }
            }//O(n^3)
            int ans =0;
            int cntm =INT_MAX;
            for(int i =0;i<n;i++){
                int cnt =0;
                for(int j=0;j<n;j++){
                        // cout<<s[i][j]<<" ";
                    if(s[i][j]<=distanceThreshold){
                        cnt++;
                    }
                }
                // cout<<endl;
                // cout<<i<<" "<<cnt<<endl;
                if(cnt<=cntm){
                    cntm = cnt;
                    ans = i;
                }
            }//O(n^2)
        return ans;
        }
    //T.C. = O(n^3)
    //S.C. = O(n^2)
};