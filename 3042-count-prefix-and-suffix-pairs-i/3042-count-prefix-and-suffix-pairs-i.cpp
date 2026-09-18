class Node {
public:
    Node* links[26] = {};
    int cnt = 0;   // words ending here

    bool contains(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* next(char ch) {
        return links[ch - 'a'];
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->contains(ch))
                node->put(ch, new Node());

            node = node->next(ch);
        }

        node->cnt++;
    }

    int search(string &word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->contains(ch))
                return 0;

            node = node->next(ch);
        }

        return node->cnt;
    }
};

class Solution {
public:
    bool isPrefixAndSuffix(string &a, string &b) {
        int n = a.size();

        if (n > b.size()) return false;

        return b.substr(0, n) == a &&
               b.substr(b.size() - n) == a;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        Trie trie;
        int ans = 0;

        for (string &word : words) {

            Node* node = trie.root;
            string pref = "";

            for (char ch : word) {
                if (!node->contains(ch))
                    break;

                node = node->next(ch);
                pref += ch;

                if (node->cnt > 0 && isPrefixAndSuffix(pref, word))
                    ans += node->cnt;
            }

            trie.insert(word);
        }

        return ans;
    }
};
