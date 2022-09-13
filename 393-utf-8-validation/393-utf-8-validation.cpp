class Solution {
public:
    bool solve(vector<int>&data,int i,int n){
        for(int j = i;j<i+n;j++){
            int first = data[j]&(1<<7);
            int second = data[j]&(1<<6);
            if(!first || second) return false;
        }
        return true;
    }
    bool validUtf8(vector<int>& data) {
        int i = 0;
        while(i<data.size()){
            int first_bit = data[i]&(1<<7);
            int second_bit = data[i]&(1<<6);
            int third_bit = data[i]&(1<<5);
            int fourth_bit = data[i]&(1<<4);
            int fifth_bit = data[i]&(1<<3);

            if(!first_bit) {
                i++;
                continue;
            }
            else if(!second_bit) return false;
            else if(!third_bit){
                if((i+1)>=data.size() || !solve(data,i+1,1)) return false;
                i+=2;
            }
            else if(!fourth_bit){
                if(i+2>=data.size() || !solve(data,i+1,2)) return false;
                i+=3;
            }
            else if(!fifth_bit){
                if(i+3>=data.size() ||!solve(data,i+1,3)) return false;
                i+=4;
            }
            else return false;
        }
        return true;
    }
};