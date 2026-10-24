class Solution {
public:
    int dayNumber(string str) {
        string month = str.substr(0, 2);
        string days = str.substr(3, 2);
        int mnt = stoi(month);
        int day = stoi(days);
        int arr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int total =day;
        for (int i = 0; i < mnt - 1; i++) total += arr[i];
        return total;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceStart = dayNumber(arriveAlice);
        int aliceEnd = dayNumber(leaveAlice);
        int bobStart = dayNumber(arriveBob);
        int bobEnd = dayNumber(leaveBob);

        int strt = max(aliceStart, bobStart);
        int end = min(aliceEnd, bobEnd);
        if (end < strt) return 0; // no common day
        return end-strt+1;        
    }
};