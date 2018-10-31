#include <iostream>
#include <queue>
#include <vector>

using namespace std; 

class Node
{
    public:   //for sake of project keep public
        Node(int puzzle [9], int cost)
        {
            for (int i = 0; i < 9; i++)
            {
                this->puzzle[i] = puzzle[i];
            }
            fn = cost; 
        }
        int puzzle [];
        int fn;
};

class compareNode
{
    public: 
        int operator() (const Node& node1, const Node& node2)
        {
            return node1.fn > node2.fn;
        }
};

int main()
{
    int puzzle [9] = {1,2,3,4,5,6,7,8,0};
    
    Node node1(puzzle, 1);
    Node node2(puzzle, 3);
    Node node3(puzzle, 6);
    Node node4(puzzle, 10);
    
    priority_queue <Node, vector<Node>, compareNode > pq; 
    
    pq.push(node1);
    pq.push(node2);
    pq.push(node3);
    pq.push(node4);
    
    cout << pq.top().fn << endl;
    pq.pop();
    cout << pq.top().fn << endl;
    pq.pop();
    
    pq.push(node1);
    
    cout << pq.top().fn << endl;
    pq.pop();
    cout << pq.top().fn << endl;
    pq.pop();
    cout << pq.top().fn << endl;
    pq.pop();
    
    return 0; 
}