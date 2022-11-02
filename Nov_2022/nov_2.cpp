//433. Minimum Genetic Mutation

class Solution {
public:
    
    // use of bfs.
    // create a queue to get the track of nodes while traversing.
    //also create unordered_set for storing all the visited nodes.
    // while creating different nodes, do look if it is already visited and has it been present in the bank.
    // if it is not, then add the new node in the queue and insert the node in the visited unordered_set.
    
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> visited;
        
        q.push(start);
        visited.insert(start);
        
        int res = 0;
        
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0; i<s; i++)
            {
                string node = q.front();
                q.pop();
                
                if(node==end)
                {
                    return res;
                }
                
                
                for(char ch: "ACGT")
                {
                    for(int j=0; j<node.size();j++)
                    {
                        string next_node = node;
                        next_node[j] = ch;
                        
                        if((visited.find(next_node)==visited.end()) && (find(bank.begin(), bank.end(),next_node)!=bank.end()))
                        {
                            q.push(next_node);
                            visited.insert(next_node);
                        }
                    }
                }
            }
            
            res++;
        }
        
        return -1;
        
    }
};
