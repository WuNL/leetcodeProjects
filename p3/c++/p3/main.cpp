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
            unsigned int j = i+1;
//            cout<<s.substr(0,1)<<endl;
            string subStr;
            char b;
            do
            {
                b = s[j];
                if(j==s.size())
                {
                    if(subStr.find(s[j-1],0)==string::npos && (subStr.size()+1)>maxlength)
                        maxlength=(subStr.size()+1);
                    return maxlength;
                }

                subStr = s.substr(i,j-i);
                if(subStr.size()>maxlength)
                    maxlength = subStr.size();
                ++j;
            }
            while(subStr.find(b,0)==string::npos);
        }
        return maxlength;
    }
};

int main()
{
    Solution s;
    cout<<s.lengthOfLongestSubstring("abcabcbb")<<endl;;
    return 0;
}
