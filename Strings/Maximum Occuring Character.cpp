class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int arr[26] = {0};
        for(int i=0; i<str.length(); i++){
            char ch  = str[i];
            int num = 0;
            num = ch - 'a';
            arr[num]++;
        }
        
        int maxi = -1, ans = 0;
        for(int j=0; j<26; j++){
            if(maxi < arr[j]){
                ans = j;
                maxi  = arr[j];
            }
        }
        char final = ans + 'a';
        return final;
    }
};
