#include <iostream>
#include <vector>

using namespace std; 

class Node
{
    public:                     //for sake of project keep public
        vector<int> puzzle; 
        int gn; 
        int hn; 
};

class compareNode
{
    public: 
        int operator() (const Node& node1, const Node& node2)
        {
            return 
        }
}