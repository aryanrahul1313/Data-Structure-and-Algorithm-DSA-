class Solution {
private:
    bool checkEqual(int arr1[26], int arr2[26]){
        for(int i=0; i<26; i++){
            if(arr1[i] != arr2[i]){
                return 0;
            }
        }
        return 1;
    }

public:
    bool checkInclusion(string s1, string s2) {
        //character count array
        int count1[26] = {0}; 
        for(int i=0; i<s1.length(); i++){
            int index = s1[i] - 'a';
            count1[index]++;
        }
    //traversing s2 in window of s1 length and compare
        int i = 0;
        int count2[26] = {0};
        int windowSize = s1.length();

        //running for 1st window
        while(i<windowSize && i<s2.length()){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        if(checkEqual(count1, count2))
            return 1;

        while(i<s2.length()){
            char newch = s2[i];
            int index = newch - 'a';
            count2[index]++;

            char oldch = s2[i-windowSize];
            index = oldch - 'a';
            count2[index]--;

            i++;

            if(checkEqual(count1, count2))
                return 1;
        }
        return 0;
    }
};
