/*
count number of substring containing at least one occurence of 'a','b','c'
medium sliding window
*/

int numberOfSubstrings(string s) {
        int i=0, j=0, res=0;
        vector<int> chars(3, 0);
        for(; j<s.size(); ++j){
            chars[s[j]-'a']++;
            while(chars[0] && chars[1] && chars[2]){
                res += s.size()-j;
                chars[s[i++]-'a']--;
            }
        }
        return res;
    }