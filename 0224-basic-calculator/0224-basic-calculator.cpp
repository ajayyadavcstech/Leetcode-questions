class Solution {
public:
    int calculate(string s) {
        stack<int> value;
        stack<int> sign;
        int pr_v = 0;
        int pr_s = 1;
        int sum = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='-' || s[i]=='+'){
                int sgn = (s[i]=='-' ? -1 : 1);
                sum = sum + pr_v*pr_s;
                pr_s = sgn;
                pr_v = 0;
            }
            else if(s[i]>='0' && s[i]<='9'){
                pr_v = pr_v*10 + (s[i]-'0');
            }
            else if(s[i]=='('){
                value.push(sum);
                sign.push(pr_s);
                sum = 0;
                pr_s = 1;
            }
            else if(s[i]==')'){
                sum = sum + pr_v*pr_s;
                pr_s = 0;
                pr_v = 0;
                sum = value.top() + sign.top()*sum;
                value.pop();
                sign.pop();
            }
        }
        sum = sum + pr_s*pr_v;
        while(value.size()){
            sum = value.top() + sign.top()*sum;
            value.pop();
            sign.pop();
        }
        return sum;
    }
};