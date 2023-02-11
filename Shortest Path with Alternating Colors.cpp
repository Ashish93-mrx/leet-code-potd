 vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>> adj[n+1];
        vector<int> dis(n,-1);
        
        for(auto r:redEdges){
            adj[r[0]].push_back({r[1],1});
        }

        for(auto b:blueEdges){
            adj[b[0]].push_back({b[1],2});
        }

        queue<vector<int>> qe;
        qe.push({0,0,-1});


        while(!qe.empty())
        {
            auto curr=qe.front();
            qe.pop();

            int curN=curr[0],color=curr[2];

            if(dis[curN]==-1){
                dis[curN]=curr[1];
            }

            for(auto &childpair:adj[curN]){
                int node=childpair.first,edgeColorOfChild = childpair.second;

                if(node!=-1 &&(color==-1 || color!=edgeColorOfChild )){
                    qe.push({node,curr[1]+1,edgeColorOfChild});
                    childpair.first = -1;
                }
            }

        }
        return dis;
    }
