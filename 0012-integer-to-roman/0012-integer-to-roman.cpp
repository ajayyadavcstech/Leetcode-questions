class Solution {
public:
    pair<string,int> solve(int& n){
        if(n>=1000) return {"M",n-1000};
        if(n>=900) return {"CM",n-900};
        if(n>=500) return {"D",n-500};
        if(n>=400) return {"CD",n-400};
        if(n>=100) return {"C",n-100};
        if(n>=90) return {"XC",n-90};
        if(n>=50) return {"L",n-50};
        if(n>=40) return {"XL",n-40};
        if(n>=10) return {"X",n-10};
        if(n>=9) return {"IX",n-9};
        if(n>=5) return {"V",n-5};
        if(n==4) return {"IV",0};
        if(n==3) return {"III",0};
        if(n==2) return {"II",0};
        return {"I",0};
        
    }
    string intToRoman(int num) {
        string ans;
        while(num){
            cout<<num<<" ";
            pair<string,int> p = solve(num);
            ans+=p.first;
            num = p.second;
        }
        return ans;
    }
};