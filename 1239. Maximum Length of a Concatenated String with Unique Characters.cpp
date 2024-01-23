class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<string> ansList = {""};
        int ans = 0;

        for (const string& str : arr) {
            if (!uniqueCharacterString(str)) {
                continue;
            }

            vector<string> currStr;

            for (const string& candidate : ansList) {
                string temp = candidate + str;
                if (uniqueCharacterString(temp)) {
                    currStr.push_back(temp);
                    ans = max(ans, static_cast<int>(temp.length()));
                }
            }

            ansList.insert(ansList.end(), currStr.begin(), currStr.end());
        }

        return ans;
    }

private:
    bool uniqueCharacterString(const string& str) {
        if (str.length() > 26) return false;
        int freq[26] = {0};

        for (char ch : str) {
            freq[ch - 'a']++;
            if (freq[ch - 'a'] > 1) {
                return false;
            }
        }
        return true;
    }
};
