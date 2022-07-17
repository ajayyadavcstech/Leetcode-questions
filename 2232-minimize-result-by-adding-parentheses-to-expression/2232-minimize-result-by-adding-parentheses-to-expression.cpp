class Solution {
public:
     pair<string,int> evaluate(string st,int i,int j){
        st.insert(j,")");
        st.insert(i,"(");
         j++;
        int sumInd = st.find('+');
        int num = stoi(st.substr(i+1,sumInd-i-1)) + stoi(st.substr(sumInd+1,j-sumInd-1));
        int first = 1;
        int second = 1;
        if(i!=0) first = stoi(st.substr(0,i));
        if(j!=st.size()-1){
            second = stoi(st.substr(j+1,st.size()-j-1));
        }
        return make_pair(st,num*first*second);
    }
    pair<string,int> solve(string &st,int i,int j){
        if(st[i]=='+' || st[j-1]=='+') return make_pair(" ",INT32_MAX);
        
        pair<string,int> cur = evaluate(st,i,j);
        pair<string,int> p1 = solve(st,i+1,j);
        pair<string,int> p2 = solve(st,i,j-1);
        
        return (cur.second<(p1.second<p2.second?p1:p2).second?cur:(p1.second<p2.second?p1:p2));
    }
    string minimizeResult(string expression) {
        return solve(expression,0,expression.size()).first;
    }
};