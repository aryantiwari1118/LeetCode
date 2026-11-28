class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int b) {
        int n = items.size();
        vector<vector<int>> pos(n + 1);
        for (int i = 0; i < n; i++) {
            pos[items[i][0]].push_back(i);
        }
        vector<int> cnt(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int mult = i; mult <= n; mult += i) {
                cnt[i] += pos[mult].size();
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq1, pq2;
        for (auto v : items) {
            int f=v[0],c=v[1];
            int d = cnt[f]-1;
            if (d >= 1) {
                pq2.push({c, d});
                pq1.push({c,1});
            } else {
                pq1.push({c, 1});
            }
        }
        long long cost=LLONG_MAX;
        if(!pq1.empty()){
            auto [c,d]=pq1.top();
            cost=min(cost,1LL*2*c);
        }
        if(pq1.size()>=2){
            auto [c1,d1]=pq1.top();
            pq1.pop();
            auto [c2,d2]=pq1.top();
            pq1.pop();
            cost=min(cost,1LL*c1+c2);
            pq1.push({c1,d1});
            pq1.push({c2,d2});



        }

        long long ans = 0;

        while(b>0&&pq2.size()>0){
            auto[c,d]=pq2.top();
            pq2.pop();
            if(c>cost)break;
            int take=min(d,b/c);
            ans+=2*take;
            b-=take*c;
        }
        int minic=pq1.top().first;
        ans+=floor((double)b/minic);

        return ans;
       
        
    }
};