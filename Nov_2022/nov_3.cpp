//2131. Longest Palindrome by Concatenating Two Letter Words

class Solution {
public:
    
    int longestPalindrome(vector<string>& words) {
        
        map<string, int> mp;
        
        for(auto it: words)
        {
            mp[it]++;
        }
        
        int count = 0;
        
        // we need to take only one self palindrome pair if present. ["aa", "bb"]. Then either only aa or bb. thats why use flag.
        bool flag = false;
        
        for(auto it: words)
        {
            string new_s = it;
            
            reverse(new_s.begin(), new_s.end());

            // case 1: ac = ca
            if(new_s!=it && mp[new_s]>0 && mp[it]>0)
            {
                mp[new_s]--;
                mp[it]--;
                count = count + 4;
            }
            
            // case 2: aa = aa (pair of self palindrome present)
            else if(new_s==it && mp[it]>1)
            {
                mp[it]-=2;
                count = count + 4;
            }
            
            //case 3: only one aa pair present
            else if(new_s==it && mp[it]>0 && !flag)
            {
                mp[it]--;
                count = count + 2;
                flag=true;
            }
            
        }
        
        return count;
        

    }
};
