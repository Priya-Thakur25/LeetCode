class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i=0; i<piles.size(); i++){
            pq.push(piles[i]);
        }

        while(k--){
            int val = ceil((float)pq.top()/2);
            pq.pop();
            pq.push(val);
        }

        int sum = 0;
        while(!pq.empty()){
            cout << pq.top() << " ";
            sum = sum + pq.top();
            pq.pop();
        }

        return sum;
    }
};