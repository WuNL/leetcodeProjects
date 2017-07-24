//Given a string, find the length of the longest substring without repeating characters.
//
//Examples:
//
//Given "abcabcbb", the answer is "abc", which the length is 3.
//
//Given "bbbbb", the answer is "b", with the length of 1.
//
//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        if(s.size()==1)
            return 1;
        unsigned int maxlength = 0;
        for(unsigned int i = 0;i<s.size();++i)
        {
            map<char,int> tmpmap;
            unsigned int j = i;
            while(j<s.size())
            {
                if(tmpmap.insert(pair<char,int>(s[j],1)).second == false)
                    break;
                ++j;
            }
            if(tmpmap.size()>maxlength)
                maxlength = tmpmap.size();
        }
        return maxlength;
    }
};

int main()
{
    Solution s;
    cout<<s.lengthOfLongestSubstring("aaa")<<endl;;
    return 0;
}
