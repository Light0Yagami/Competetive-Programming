/*
Alice has some cards, each card has one number written on it. She wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
Given an integer array hand of size N where hand [ i ] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.


*/

bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        map<int,int> mm;
        for(auto x:hand)mm[x]++;
        int num=-1,c=0;
        while(true){
            num=mm.begin()->first;
            c=0;
            while(c<groupSize){
                if(mm[num]==0)return false;
                mm[num]--;
                if(mm[num]==0)mm.erase(num);
                num++;
                c++;
            }
            if(mm.size()==0)break;
        }
        return true;
    }
