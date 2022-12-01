class Solution {
public:
    int arr[10] = {'a','e','i','o','u','A','E','I','O','U'};
    bool is_vowels(char ch){
        for(int i=0;i<10;i++) if(ch==arr[i]) return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int cnt_1 = 0;
        int cnt_2 = 0;
        for(int i=0;i<s.size()/2;i++){
            if(is_vowels(s[i])) cnt_1++;
        }
        for(int i=s.size()/2;i<s.size();i++){
            if(is_vowels(s[i])) cnt_2++;
        }
        return cnt_1==cnt_2;
    }
};