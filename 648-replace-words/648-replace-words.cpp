class Solution {
public:
    string replace(string word,unordered_set<string> &st){
        string s;
        for(int i=0;i<word.size();i++){
            s.push_back(word[i]);
            if(st.find(s)!=st.end()){
                return s;
            }
        }
        return s;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st;
        for(auto x : dictionary) st.insert(x);
        string ans = "";
        int j = 0;
        for(int i=0;i<sentence.size();i++){
            j = i;
            while(j!=sentence.size() && sentence[j]!=' ') j++;
            ans = ans + replace(sentence.substr(i,j-i),st) + " ";
            i = j;
        }
        ans.pop_back();
        return ans;
    }
};