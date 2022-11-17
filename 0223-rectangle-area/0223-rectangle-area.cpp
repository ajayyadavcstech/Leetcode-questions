class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int cx1 = max(ax1,bx1);
        int cy1 = max(ay1,by1);
        int cx2 = min(ax2,bx2);
        int cy2 = min(ay2,by2);
        int l = (cx2-cx1);
        int b = (cy2-cy1);
        int total_area  = (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1);
        return (l<0 || b<0) ? total_area : total_area - l*b ;
    }
};