class Solution {
public:
    pair<bool,int> num(string s){
        if(s=="I") return {true,1};
        else if(s=="V") return {true,5};
        else if(s=="X") return {true,10};
        else if(s=="L") return {true,50};
        else if(s=="C") return {true,100};
        else if(s=="D") return {true,500};
        else if(s=="M") return {true,1000};
        else if(s=="IV") return {true,4};
        else if(s=="IX") return {true,9};
        else if(s=="XL") return {true,40};
        else if(s=="XC") return {true,90};
        else if(s=="CD") return {true,400};
        else if(s=="CM") return {true,900};
        else return {false,0};
    }
    int romanToInt(string s) {
        int i = 0;
        int ans = 0;
        while(i<s.size()){
            if(i<s.size()-1){
                pair<bool,int> p = num(s.substr(i,2));
                if(p.first) {
                    ans+=p.second;
                    i+=2;
                }
                else {
                    ans+=(num(s.substr(i,1))).second;
                    i++;
                }
            }
             else {
                    ans+=(num(s.substr(i,1))).second;
                    i++;
                }
        }
        return ans;
    }
};