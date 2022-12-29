class Solution {
public:
    struct pqComp {
        bool operator()(const pair<int, int> &x, const pair<int, int> &y) const {
            if(x.first != y.first){
                return x.first > y.first;
            }
            return x.second > y.second;
        }
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> Ans;
        vector<pair<int, pair<int, int>>> vec;

        for(int i = 0; i < tasks.size(); i++){
            int encodeTime = tasks[i][0];
            int processTime = tasks[i][1];
            int idx = i;
            vec.push_back({encodeTime, {processTime, idx}});
        }

        sort(vec.begin(), vec.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, pqComp> pq;
        long long int time = 1;
        int i = 0;

        while(i < vec.size()){
            while(i < vec.size() && time >= vec[i].first){
                int processTime = vec[i].second.first;
                int idx = vec[i].second.second;
                pq.push({processTime, idx});
                i++;
            }

            if(!pq.empty()){
                pair<int, int> tmp = pq.top();
                pq.pop();
                time += tmp.first;
                Ans.push_back(tmp.second);
            }
            else{
                time = vec[i].first;
            }
        }

        while(!pq.empty()){
            pair<int, int> tmp = pq.top();
            pq.pop();
            time += tmp.first;
            Ans.push_back(tmp.second);
        }

        return Ans;
    }
};
