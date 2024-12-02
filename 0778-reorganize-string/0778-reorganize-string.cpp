class compare {
public:
    bool operator()(pair<char, int>& a, pair<char, int>& b) {
        return a.second < b.second;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> pq;
        unordered_map<char, int> mapping;
        for (auto ch : s) {
            mapping[ch]++;
        }

        for (auto mp : mapping) {
            pq.push({mp.first, mp.second});
        }

        int val = pq.top().second;
        if (s.length() % 2 != 0) {
            if (val > (s.length() / 2) + 1)
                return "";
        } else if (val > (s.length() / 2))
            return "";

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            if (!ans.empty() && ans.back() != temp.first) {
                ans.push_back(temp.first);
                temp.second--;
            } else if (ans.empty()) {
                ans.push_back(temp.first);
                temp.second--;
            }

            if (!pq.empty()) {
                auto tempo = pq.top();
                pq.pop();
                if (!ans.empty() && ans.back() != tempo.first) {
                    ans.push_back(tempo.first);
                    tempo.second--;
                }
                if (tempo.second > 0)
                    pq.push({tempo.first, tempo.second});
            }
            if (temp.second > 0)
                pq.push({temp.first, temp.second});
        }
        return ans;
    }
};