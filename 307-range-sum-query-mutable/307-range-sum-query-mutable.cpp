class NumArray {
public:
    
    vector<int> Tree;
    int n ;
    NumArray(vector<int>& nums) {
        Tree.resize(nums.size()*4,0);
        n = nums.size();
        segmentTree(nums,Tree,0,nums.size()-1,0);
    }
    
    void update(int index, int val) {
        Update(Tree,0,n-1,index,0,val);
    }
    
    int sumRange(int left, int right) {
        return Sum(Tree,0,n-1,left,right,0);
    }
    
    void Update(vector<int>&minRange,int s,int e,int range,int ind,int val){
    if(range<s || range>e) return ;
    if(s==e && e==range){
        minRange[ind] = val;
        return;
    }
    int mid = s + (e-s)/2;
    Update(minRange,s,mid,range,ind*2+1,val);
    Update(minRange,mid+1,e,range,ind*2+2,val);
    minRange[ind] = minRange[ind*2+1]+minRange[ind*2+2];
}
    
   int Sum(vector<int>&Tree,int s,int e,int st,int en,int ind){
    //No overlapping 
    if(e<st || s>en) return 0;

    // compleate overlapping
    if(s>=st && e<=en) return Tree[ind];

    //partial overlapping
    int mid = s + (e-s)/2;
    int left = Sum(Tree,s,mid,st,en,ind*2+1);
    int right = Sum(Tree,mid+1,e,st,en,ind*2+2);
    return left + right;
}
    
    void segmentTree(vector<int> &v, vector<int> &Tree, int s, int e, int ind)
{
    if (s == e)
    {
        Tree[ind] = v[s];
        return ;
    }
    int mid = s + (e - s) / 2;
    segmentTree(v, Tree, s, mid, ind * 2 + 1);
    segmentTree(v, Tree, mid + 1, e, ind * 2 + 2);
    Tree[ind] = Tree[ind * 2 + 1] + Tree[ind * 2 + 2];
}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */