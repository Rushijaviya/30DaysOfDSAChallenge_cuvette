// https://leetcode.com/problems/minimum-window-substring/

class Solution
{
public:
    string minWindow(string s, string t)
    {

        int l1 = s.length();
        int l2 = t.length();

        if (l2 > l1)
            return "";

        vector<int> freq(123, 0);
        int startIndex, min = INT_MAX;

        for (int i = 0; i < l2; ++i)
            freq[t[i]]++;

        int l = 0, r = 0, counter = l2;

        while (r < l1)
        {
            if (freq[s[r]] > 0)
                counter--;

            freq[s[r]]--;
            r++;

            while (counter == 0)
            {
                if (r - l < min)
                {
                    startIndex = l;
                    min = r - l;
                }

                freq[s[l]]++;

                if (freq[s[l]] > 0)
                    counter++;

                l++;
            }
        }

        if (min == INT_MAX)
            return "";

        return s.substr(startIndex, min);
    }
};
