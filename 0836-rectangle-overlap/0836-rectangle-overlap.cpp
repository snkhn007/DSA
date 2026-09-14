class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // x2 of rec1 < x1 of rec 2 X
        // y2 of rec1 < y1 of rec 2 X

        // 1 left of 2
        // 2 left of 1
        // 1 below 2
        // 2 below 1 

        if(rec1[2] <= rec2[0] || rec2[2] <= rec1[0] ||       
           rec1[3] <= rec2[1] || rec2[3] <= rec1[1]) return false;
        return true;        
    }
};