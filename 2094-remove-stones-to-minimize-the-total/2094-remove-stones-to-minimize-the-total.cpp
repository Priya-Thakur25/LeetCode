class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i=0; i<piles.size(); i++){
            pq.push(piles[i]);
        }

        while(k--){
            float val = pq.top();
            pq.pop();
            val = val/2;
            val = ceil(val);
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