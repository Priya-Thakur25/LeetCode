class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort the folders lexicographically
        sort(folder.begin(), folder.end());
        
        vector<string> result;
        string prevFolder = "";
        
        for (const string& f : folder) {
            // Check if the current folder is a subfolder of the previous one
            if (prevFolder.empty() || f.compare(0, prevFolder.size(), prevFolder) != 0 || f[prevFolder.size()] != '/') {
                // Not a subfolder, so add it to the result
                result.push_back(f);
                prevFolder = f; // Update prevFolder to the current one
            }
        }
        
        return result;
    }
};