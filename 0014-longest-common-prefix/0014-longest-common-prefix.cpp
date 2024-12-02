class Trie{
    public:
    char val;
    Trie* children[26];
    bool isTerminal;
    
    Trie(char val){
        this->val = val;
        for(int i=0; i<26; i++){
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

//insertion
void insertion(Trie* root, string word){
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }
    
    char ch = word[0];
    int index = ch - 'a';
    Trie* child;
    if(root->children[index] != NULL){
        //already present a character
        child = root->children[index];
    }
    else{
        //bana li h bs fill krdo
        child = new Trie(ch);
        root->children[index] = child;
    }
    //recursive call 
    insertion(child, word.substr(1));
}

void helper(Trie* root, int count, string &ans){
    if(root == NULL || root->isTerminal) return;
    int index = 0;
    for(int i=0 ; i<26; i++){
        if(root->children[i] != NULL){
            index = i;
            count++;
        }
    }
    if(count > 1) return;
    if(count == 1) ans = ans+root->children[index]->val;
    helper(root->children[index], 0, ans);
}
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* temp = new Trie('-');
        for(int i=0 ;i<strs.size(); i++){
            insertion(temp, strs[i]);
        }
        string tempstr = "";
        int count = 0;
        helper(temp, count, tempstr);
        return tempstr;
    }
};