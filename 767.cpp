/*
check if a string can be rearranged such that no two adjacent char are the same
1. use greedy to first place the most count char to position 0,2,4,6,8...
2. priority queue 
*/

string reorganizeString(string S) {
        vector<int> v(26, 0);
        int imax = 0, maxNum = 0;
        for(char c : S){
            if(++v[c-'a']>imax){
                imax = v[c-'a'];
                maxNum = c-'a';
            }
        }
        if(imax > (S.size()+2-1)/2) return "";
        string res(S.size(), '0');
        int i = 0;
        for(; i<res.size() && v[maxNum]; i+=2){
            res[i] = maxNum+'a';
            v[maxNum]--;
        }
        for(int j=0; j<v.size(); ++j){
            while(v[j]--){
                if(i>=res.size()) i = 1;
                res[i] = 'a'+j;
                i += 2;
            }
        }
        return res;
    }