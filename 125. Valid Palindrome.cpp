#include <bits/stdc++.h>
using namespace std;
class Solution { static bool isAlnum(char c){ return isalnum((unsigned char)c); } public: bool isPalindrome(string s){ int l=0,r=s.size()-1; while(l<r){ while(l<r && !isAlnum(s[l])) l++; while(l<r && !isAlnum(s[r])) r--; if(tolower((unsigned char)s[l])!=tolower((unsigned char)s[r])) return false; l++; r--; } return true; } };
