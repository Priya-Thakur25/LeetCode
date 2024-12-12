class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        long long count = 0;
        int i=0; 
        for(i=0; i<gifts.size(); i++){
            pq.push(gifts[i]);
        }

        i=0;
        while(i < k){
            int front = pq.top();
            pq.pop();
            front = sqrt(front);
            cout << front << " ";
            pq.push(front);
            i++;
        }
        while(!pq.empty()){
            count = count + pq.top();
            pq.pop();
        }

        return count;
    }
};