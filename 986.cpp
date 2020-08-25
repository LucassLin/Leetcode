/*

*/

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i=0, j=0;
        vector<vector<int>> res;
        while(i<A.size() && j<B.size()){
            vector<int> cur;
            cur.push_back(max(A[i][0], B[j][0]));
            cur.push_back(min(A[i][1], B[j][1]));
            if(cur[1]>=cur[0]) res.push_back(cur);
            if(A[i][1]<B[j][1]) i++;
            else j++;
        }
        return res;
    }