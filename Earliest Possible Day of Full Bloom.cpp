class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n=plantTime.size();
        vector<pair<int, int>> temp(n);
        
        
        for(int i=0;i<n;i++)
        {
            temp[i].first = -growTime[i];
            temp[i].second = plantTime[i];
        }
        
        sort(temp.begin(),temp.end());
        
        int cur=0;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,cur+temp[i].second-temp[i].first);
            cur+=temp[i].second;
        }
        
        return ans;
    
