User
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> zeroLoss, oneLoss, moreLoss;

        for (auto& match : matches) {
            int winner = match[0], loser = match[1];
            // Add winner.
            if ((oneLoss.find(winner) == oneLoss.end()) &&
                (moreLoss.find(winner) == moreLoss.end())) {
                zeroLoss.insert(winner);
            }
            // Add or move loser.
            if (zeroLoss.find(loser) != zeroLoss.end()) {
                zeroLoss.erase(loser);
                oneLoss.insert(loser);
            } else if (oneLoss.find(loser) != oneLoss.end()) {
                oneLoss.erase(loser);
                moreLoss.insert(loser);
            } else if (moreLoss.find(loser) != moreLoss.end()) {
                continue;
            } else {
                oneLoss.insert(loser);
            }
        }

        vector<vector<int>> answer(2, vector<int>());
        answer[0].assign(zeroLoss.begin(), zeroLoss.end());
        answer[1].assign(oneLoss.begin(), oneLoss.end());
        
        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());

        return answer;
    }
};


------------------------EASY TO UNDERSTAND CODE-----------------------

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp;

        for(int i=0;i<matches.size();i++){
            mp[matches[i][0]]+=0;
            mp[matches[i][1]]++;
        }

        vector<vector<int>>ans(2);
        for(auto a: mp){
            if(a.second==0)ans[0].push_back(a.first);
            if(a.second==1)ans[1].push_back(a.first);
        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
};
