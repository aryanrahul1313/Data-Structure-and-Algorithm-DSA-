class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int index = 0;
        while(i < chars.size()){
            int j = i + 1;
            while(j < chars.size() && chars[i] == chars[j]){
                j++;
            }
            chars[index++] = chars[i];
            int count = j - i;

            if(count > 1){
                //converting count into single ans and saving
                string cnt = to_string(count);
                for(char ch : cnt){ 
                    chars[index++] = ch;
                } 
            }
            i = j;
        }
        return index;
    }
};
