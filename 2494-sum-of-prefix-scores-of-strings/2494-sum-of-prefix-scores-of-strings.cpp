class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {};
        int count = 0;
    };

    class Trie {
    public:
        TrieNode* root;
        
        Trie() {
            root = new TrieNode();
        }

        void insert(const string& word) {
            TrieNode* node = root;
            for (char ch : word) {
                int index = ch - 'a';
                if (!node->children[index]) {
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
                node->count++;  // Increment the count for this prefix
            }
        }

        int getPrefixScore(const string& word) {
            TrieNode* node = root;
            int score = 0;
            for (char ch : word) {
                int index = ch - 'a';
                node = node->children[index];
                score += node->count;  // Add the count of this prefix
            }
            return score;
        }
    };

    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        // Insert all words into the Trie
        for (const string& word : words) {
            trie.insert(word);
        }

        // Calculate the prefix score for each word
        vector<int> result;
        for (const string& word : words) {
            result.push_back(trie.getPrefixScore(word));
        }

        return result;
    }
};
