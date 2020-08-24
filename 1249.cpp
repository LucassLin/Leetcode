/*
stack based problem to match parenthesis
only push left parenthesis index in order to keep track of the index of unused left parenthesis
right parenthesis can be easy checked whether balanced or not by simply checking whether stack is not empty
*/

string minRemoveToMakeValid(string s) {
        stack<int> ms;
        for(int i=0; i<s.size(); ++i){
            char c = s[i];
            if(c=='(') ms.push(i);
            else if(c==')'){
                if(!ms.empty()) ms.pop();
                else s[i] = '*';
            }
        }
        while(!ms.empty()){
            int idx = ms.top();
            ms.pop();
            s[idx] = '*';
        }
        string res;
        for(char c : s){
            if(c!='*') res += c;
        }
        return res;
    }