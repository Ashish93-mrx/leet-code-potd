bool valide(string b,string t)
        {
            int l=0;
            if(b.size()!=t.size()){
                return false;
            }
            for(int i=0;i<t.size();i++)
            {
                if(t[i]!=b[i]){
                    l++;
                }
            }
            return l==1;      
        }
    
     int minMutation(string start, string end, vector<string>& bank) {    
        int j=0;
        for(j=0;j<bank.size();j++)
        {
            if(bank[j]==end)
                break;
        }
        
        if(j==bank.size())
        {
                return -1;
        }
        
        queue<string> qe;
        unordered_map<string,bool> mp;
        
        mp[start]=true;
        
        qe.push(start);
        
        int res=0;
        
        while(!qe.empty())
        {
            res++;
            int sz=qe.size();
            for(int e=0;e<sz;e++)
            {
                string temp=qe.front();
                qe.pop();
            
                for(int i=0;i<bank.size();i++)
                {
                    if(mp[bank[i]]!=true)
                    {
                        if(valide(bank[i],temp))
                        {
                            if(bank[i]==end){
                                return res;
                            }
                            mp[bank[i]]==true;
                            qe.push(bank[i]);
                        }
                    }
                }    
            }
        }
        return -1;
    }
