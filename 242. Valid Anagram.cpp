// Problem (short):
// Given two strings, check if one is an anagram of the other.

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n =s.size();
        int m=t.size();
        vector<int> track(26, 0);
        for(int i=0; i<n; i++){
            track[s[i]-'a']+=1;
        }

        for(int i=0;i<m;i++){
            track[t[i]-'a']-=1;
        }

        bool res=true;

        for(int i=0; i<26 ;i++){
            if(track[i]!=0) res=false;
        }

        return res;
        
    }
};