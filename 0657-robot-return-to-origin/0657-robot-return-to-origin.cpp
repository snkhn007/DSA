class Solution {
public:
    bool judgeCircle(string moves) {
        int verticle = 0, horizontal = 0;
        for(auto i : moves){
            if(i == 'U') verticle++;
            else if(i == 'D') verticle --;
            else if(i == 'L') horizontal++;
            else horizontal--;
        }
        if(verticle == 0 && horizontal == 0) return true;
        return false;
    }
};