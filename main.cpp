#include <iostream>
#include <queue>
#include <vector>

using namespace std; 

class State
{
    public:   //for sake of project keep public
        State(int puzzle [9], int blank_index, int hn, int gn, int fn, State* parent) //constructor
        {
            for (int i = 0; i < 9; i++)
            {
                this->puzzle[i] = puzzle[i];
            }
            this->blank_index = blank_index;
            this->hn = hn;
            this->gn = gn;
            this->fn = fn;
            this->parent = parent;
        }
        
        void displayPuzzle()
        {
            cout << "g(n) = " << gn << " " << "h(n) = " << fn << endl;
            cout << puzzle[0] << "  " << puzzle[1] << "  " << puzzle[2] << endl;
            cout << puzzle[3] << "  " << puzzle[4] << "  " << puzzle[5] << endl;
            cout << puzzle[6] << "  " << puzzle[7] << "  " << puzzle[8] << endl;
        }
        
        State* moveUp()
        {
            return 0; //fixme
        }
        
        State* moveDown()
        {
            return 0; //fixme
        }
        
        State* moveLeft()
        {
            return 0; //fixme  
        }
        
        State* moveRight()
        {
            return 0; //fixme
        }
        
        //variables
        State* parent; 
        int puzzle[9];
        int blank_index;
        int hn;
        int gn;
        int fn;
};

class compareState //compare function for priority queue
{
    public: 
        int operator() (State* state1, State* state2)
        {
            return state1->fn > state2->fn;
        }
};

void general_search(State* problem, int algChoice)
{
    int heuristic = algChoice;
    int goal_state[9] = {1,2,3,4,5,6,8,7,0};
    int states_expanded = 0;
    int max_queue_size = 0;
    
    priority_queue <State*, vector<State*>, compareState > pq; 
    
    State* currNode; 
    
    pq.push(problem);
    
    while(pq.size() != 0)
    {
        if (pq.size() > max_queue_size) //update max queue size for statistics
        {
            max_queue_size = pq.size();
        }
        
        cout << "checking state";
        currNode = pq.top();
        pq.pop();
        
        for (int i = 0; i < 9; i++) //check for goal state
        {
            if (currNode->puzzle[i] != goal_state[i])
            {
                break;
            }
            else if ((currNode->puzzle[i] == goal_state[i]) && (i == 8))
            {
                currNode->displayPuzzle(); 
                cout << "Puzzle Solved!" << endl;
                return;
            }
        }
        
        
        if (algChoice == 1) //uniform cost
        {
            cout << "FIXME" << endl;
        }
        else if (algChoice == 2) //misplaced tile
        {
            cout << "FIXME" << endl;
        }
        else if (algChoice == 3) //manhattan
        {
            cout << "FIXME" << endl; 
        }
    }
    
    cout << "No solution found!" << endl;
}



//void general

int main()
{
    //int userPuzzle[9];
    int userPuzzle[9] = {1,2,3,4,5,6,7,8,0}; //TESTING
    int algChoice;
    int blank_index; 
    
   /* cout << "Enter 3 tiles in first row following each tile with a return: ";
    cin >> userPuzzle[0];
    cin >> userPuzzle[1];
    cin >> userPuzzle[2];
    cout << "Enter 3 tiles in first row following each tile with a return: ";
    cin >> userPuzzle[3];
    cin >> userPuzzle[4];
    cin >> userPuzzle[5];
    cout << "Enter 3 tiles in first row following each tile with a return: ";
    cin >> userPuzzle[6];
    cin >> userPuzzle[7];
    cin >> userPuzzle[8]; */
    
    for (int i = 0; i < 9; i++)
    {
        if (userPuzzle[i] == 0)
        {
            blank_index = i;
        }
    }
    
    
    
    cout << "Enter algorithm choice: " << endl;
    cout << "   Enter \"1\" for Uniform Cost Search" << endl;
    cout << "   Enter \"2\" for A* w/ Misplaced Tile Heuristic" << endl;
    cout << "   Enter \"3\" for A* w/ Manhattan Distance Heuristic" << endl;
    
    cin >> algChoice;
    
    State* problem = new State(userPuzzle, 0, 0, 0, 0, 0);
    
    general_search(problem, algChoice);
    
    
    return 0; 
} 