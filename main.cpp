#include <iostream>
#include <queue>
#include <vector>

using namespace std; 

class State
{
    public:   //for sake of project keep public
        State(int puzzle [9], int hn, int gn, int fn, State* parent) //constructor
        {
            for (int i = 0; i < 9; i++)
            {
                this->puzzle[i] = puzzle[i];
            }
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
        
        
        
        //variables
        State* parent; 
        int puzzle[9];
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

void general_search(State* initialState, int algChoice)
{
    int heuristic = algChoice;
    int goal_state[9] = {1,2,3,4,5,6,7,8,0};
    
    priority_queue <State*, vector<State*>, compareState> pq; 
    
    pq.push(initialState);
    pq.top()->displayPuzzle();
}

//void general

int main()
{
    int userPuzzle[9];
    int algChoice; 
    
    cout << "Enter 3 tiles in first row following each tile with a return: ";
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
    cin >> userPuzzle[8];
    
    cout << "Enter algorithm choice: " << endl;
    cout << "   Enter \"1\" for Uniform Cost Search" << endl;
    cout << "   Enter \"2\" for A* w/ Misplaced Tile Heuristic" << endl;
    cout << "   Enter \"3\" for A* w/ Manhattan Distance Heuristic" << endl;
    
    cin >> algChoice;
    
    State* initState = new State(userPuzzle, 0, 0, 0, 0);
    
    general_search(initState, algChoice);
    
    
    return 0; 
} 