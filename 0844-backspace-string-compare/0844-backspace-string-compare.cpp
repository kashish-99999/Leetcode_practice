class Solution {
public:
    string build(string s) {
        string result;

        for (char c : s) {
            if (c == '#') {
                if (!result.empty())
                    result.pop_back();
            } else {
                result.push_back(c);
            }
        }

        return result;
    }

    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};