/*
easy sliding window for size of k
*/

int maxVowels(string s, int k) {
        int cur = 0, imax = 0, i = 0, j = 0;
        for(; j<s.size(); ++j){
            char c = s[j];
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') cur++;
            if(j-i>=k){
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') cur--;
                i++;
            }
            imax = max(imax, cur);
        }
        return imax;
    }