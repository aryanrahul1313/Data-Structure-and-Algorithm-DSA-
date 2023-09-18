class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meetPair;
        
        for(int i=0; i<n; i++){
            pair<int, int> p = make_pair(start[i], end[i]);
            meetPair.push_back(p);
        }
        
        sort(meetPair.begin(), meetPair.end(), cmp);
        
        int count = 1;
        int ansEnd = meetPair[0].second;
        
        for(int i=1; i<n; i++){
            if(meetPair[i].first > ansEnd){
                count++;
                ansEnd = meetPair[i].second;
            }
        }
        return count;
    }
};
