class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1) return 1;
        vector<int> depthInd;
        vector<int> candie(ratings.size(),1);
        for(int i=0;i<ratings.size();i++){
            if(i==0){ 
                if(ratings[i]<=ratings[i+1])
                  depthInd.push_back(i);
            }
            else if(i==ratings.size()-1){
                if(ratings[i]<=ratings[i-1])
                  depthInd.push_back(i);
            }
            else if(ratings[i]<=ratings[i-1] && ratings[i]<=ratings[i+1]){
                depthInd.push_back(i);
            }
        }
        for(auto x : depthInd){
            candie[x] = 1;
            int i = x;
            i++;
            if(x!=ratings.size()-1){
                while(i!=ratings.size() && ratings[i]>ratings[i-1]){
                    if(!(candie[i]>candie[i-1])){
                        candie[i] = candie[i-1]+1;
                    }
                    i++;
                }
            }
            i = x;
            i--;
            if(x!=0){
                while(i!=-1 && ratings[i]>ratings[i+1]){
                    if(!(candie[i]>candie[i+1])){
                        candie[i] = candie[i+1] + 1;
                    }
                    i--;
                }
            }
        }
        int total_candie = 0;
        for(auto x : candie){
            total_candie+=x;
        }
        return total_candie;
    }
};