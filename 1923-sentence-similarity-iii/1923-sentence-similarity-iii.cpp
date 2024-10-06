class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Split the sentences into words
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        
        // Two pointers to check prefix and suffix
        int i = 0, j = 0;
        int len1 = words1.size(), len2 = words2.size();

        // Check for common prefix
        while (i < len1 && i < len2 && words1[i] == words2[i]) {
            i++;
        }

        // Check for common suffix
        while (j < len1 - i && j < len2 - i && words1[len1 - j - 1] == words2[len2 - j - 1]) {
            j++;
        }

        // After removing the common prefix and suffix, check if one sentence is fully consumed
        return i + j >= min(len1, len2);
    }

    // Helper function to split a sentence into words
    vector<string> split(const string &sentence) {
        vector<string> result;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            result.push_back(word);
        }
        return result;
    }
};
