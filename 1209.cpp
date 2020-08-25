/*
stack for match substring with same char with size k
*/

string removeDuplicates(string s, int k) {
        stack<pair<char,int>> ms;
        if(s.size() == 0) return "";
        ms.emplace(s[0], 1);
        for(int i=1; i<s.size(); ++i){
            if(!ms.empty() && s[i] == ms.top().first){
                auto prev = ms.top();
                ms.pop();
                prev.second += 1;
                if(prev.second == k) continue;
                else ms.push(prev);
            }
            else ms.emplace(s[i], 1);
        }
        string res = "";
        while(!ms.empty()){
            auto cur = ms.top();
            ms.pop();
            for(int i=0; i<cur.second; ++i) res += cur.first;
        }
        reverse(res.begin(), res.end());
        return res;
    }