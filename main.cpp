#include <iostream>
#include <queue>
#include <cmath>

using namespace std; 

int misplacedTile(int puzzle[9]);
int manhattanDistance(int puzzle[9]);

class State
{
    public:   //for sake of project keep public
        State(int puzzle[9], int blank_index, int hn, int gn, int fn, State* parent) //constructor
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
            cout << "g(n) = " << gn << " " << "h(n) = " << hn << endl;
            cout << puzzle[0] << "  " << puzzle[1] << "  " << puzzle[2] << endl;
            cout << puzzle[3] << "  " << puzzle[4] << "  " << puzzle[5] << endl;
            cout << puzzle[6] << "  " << puzzle[7] << "  " << puzzle[8] << endl;
        }
        
        State* moveUp(int heuristic) //return new state to add to queue
        {
            State* statetoAdd; 
            
            int x = blank_index % 3;
            int y = blank_index / 3;
            int new_y = y - 1;
            int new_puzzle [9];
            
            for (int i = 0; i < 9; i++) //copy over puzzle
            {
                new_puzzle[i] = this->puzzle[i];
            }
            
            int new_blank = x + (new_y * 3);
            int temp = new_puzzle[this->blank_index];
            new_puzzle[this->blank_index] = new_puzzle[new_blank];
            new_puzzle[new_blank] = temp;
            
            int new_hn = 0; 
            if (heuristic == 1) //uniform cost is A* with h(n) harcoded to 0
            {
                new_hn = 0;
            }
            if (heuristic == 2)
            {
                new_hn = misplacedTile(new_puzzle); 
            }
            if (heuristic == 3)
            {
                new_hn = manhattanDistance(new_puzzle);
            }
            
            int new_gn = this->gn + 1;
            int new_fn = new_gn + new_hn;
            
            statetoAdd = new State(new_puzzle, new_blank, new_hn, new_gn, new_fn, this);
            
            //cout << "New state up: " << endl; 
            //statetoAdd->displayPuzzle();
            
            return statetoAdd;
        }
        
        State* moveDown(int heuristic)
        {
            State* statetoAdd; 
            
            int x = blank_index % 3;
            int y = blank_index / 3;
            int new_y = y + 1;
            int new_puzzle [9];
            
            for (int i = 0; i < 9; i++) //copy over puzzle
            {
                new_puzzle[i] = this->puzzle[i];
            }
            
            int new_blank = x + (new_y * 3);
            int temp = new_puzzle[this->blank_index];
            new_puzzle[this->blank_index] = new_puzzle[new_blank];
            new_puzzle[new_blank] = temp;
            
            int new_hn = 0;
            if (heuristic == 1)
            {
                new_hn = 0;
            }
            if(heuristic == 2)
            {
                new_hn = misplacedTile(new_puzzle); 
            }
            if(heuristic == 3)
            {
                new_hn = manhattanDistance(new_puzzle);
            }
            
            int new_gn = this->gn + 1;
            int new_fn = new_gn + new_hn;
            
            statetoAdd = new State(new_puzzle, new_blank, new_hn, new_gn, new_fn, this);
            
            //cout << "New state down: " << endl; 
            //statetoAdd->displayPuzzle();
            
            return statetoAdd;
        }
        
        State* moveLeft(int heuristic)
        {
            
            State* statetoAdd; 
            
            int x = blank_index % 3;
            int y = blank_index / 3;
            int new_x = x - 1;
            int new_puzzle [9];
            
            for (int i = 0; i < 9; i++) //copy over puzzle
            {
                new_puzzle[i] = this->puzzle[i];
            }
            
            int new_blank = new_x + (y * 3);
            int temp = new_puzzle[this->blank_index];
            new_puzzle[this->blank_index] = new_puzzle[new_blank];
            new_puzzle[new_blank] = temp;
            
            int new_hn = 0;
            if (heuristic == 1)
            {
                new_hn = 0;
            }
            if(heuristic == 2)
            {
                new_hn = misplacedTile(new_puzzle); 
            }
            if(heuristic == 3)
            {
                new_hn = manhattanDistance(new_puzzle);
            }
            
            int new_gn = this->gn + 1;
            int new_fn = new_gn + new_hn;
            
            statetoAdd = new State(new_puzzle, new_blank, new_hn, new_gn, new_fn, this);
            
            //cout << "New state left: " << endl; 
            //statetoAdd->displayPuzzle();
            
            return statetoAdd;  
        }
        
        State* moveRight(int heuristic)
        {
            State* statetoAdd; 
            
            int x = blank_index % 3;
            int y = blank_index / 3;
            int new_x = x + 1;
            int new_puzzle [9];
            
            for (int i = 0; i < 9; i++) //copy over puzzle
            {
                new_puzzle[i] = this->puzzle[i];
            }
            
            int new_blank = new_x + (y * 3);
            int temp = new_puzzle[this->blank_index];
            new_puzzle[this->blank_index] = new_puzzle[new_blank];
            new_puzzle[new_blank] = temp;
            
            int new_hn = 0;
            if (heuristic == 1) 
            {
                new_hn = 0;
            }
            if (heuristic == 2)
            {
                new_hn = misplacedTile(new_puzzle); 
            }
            if(heuristic == 3)
            {
                new_hn = manhattanDistance(new_puzzle);
            }
            
            int new_gn = this->gn + 1;
            int new_fn = new_gn + new_hn;
            
            statetoAdd = new State(new_puzzle, new_blank, new_hn, new_gn, new_fn, this);
            
            //cout << "New state right: " << endl; 
            //statetoAdd->displayPuzzle();
            
            return statetoAdd;
        }
        
        //State variables, make public for now so don't have to deal with get
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

int misplacedTile(int puzzle[9])
{
    int hn = 0; 
    for (int i = 0; i < 9; i++)
    {
        if (puzzle[i] != (i + 1) % 9 && puzzle[i] != 0) 
        {
            ++hn;
        }
        
    }
    //cout << "num misplaced tile test " << hn << endl;
    return hn; 
}

int manhattanDistance(int puzzle[9])
{
     int hn = 0;
     int goal_index; 
     int goal_value; 
     for (int i = 0; i < 9; i++)
     {
         goal_value = (i + 1) % 9;
         if (puzzle[i] != 0 && puzzle[i] != goal_value) //don't include 0 in heuristic
         {
             goal_index = puzzle[i] - 1; 
             hn += (abs((i % 3) - (goal_index % 3)) + abs((i / 3) - (goal_index / 3)));
             //cout << puzzle[i] << "is " << (abs((i % 3) - (goal_index % 3)) + abs((i / 3) - (goal_index / 3))) << "off" << endl;
         }
     }
    
    return hn; 
}

void general_search(State* problem, int algChoice)
{
    int goal_state[9] = {1,2,3,4,5,6,7,8,0};
    int states_expanded = 0;
    int max_queue_size = 0;
    int heuristic = algChoice; 
    
    priority_queue <State*, vector<State*>, compareState > pq; 
    
    State* currNode; 
    
    pq.push(problem);
    
    while(pq.size() != 0)
    {
        if (pq.size() > max_queue_size) //update max queue size for statistics
        {
            max_queue_size = pq.size();
        }
        
        currNode = pq.top();
        pq.pop();
        //currNode->displayPuzzle(); 
        
        for (int i = 0; i < 9; i++) //check for goal state
        {
            if (currNode->puzzle[i] != goal_state[i])
            {
                //cout << "TESTING: " << currNode->puzzle[i] << " does not match " << goal_state[i] << endl;
                //cin >> max_queue_size; //testing
                break;
            }
            else if ((currNode->puzzle[i] == goal_state[i]) && (i == 8))
            {
                cout << "Max queue size: " << max_queue_size << endl;
                cout << "States expanded: " << states_expanded << endl;
                cout << "Puzzle Solved!" << endl;
                currNode->displayPuzzle();
                return;
            }
        }
        
        cout << "Expanding state " << endl;
        currNode->displayPuzzle();
        states_expanded += 1; //expanding state, update count
        
        // check where blank is and determine what operators are possible
        // add those states to priority queue
        if (currNode->blank_index != 0  && currNode->blank_index != 1 && currNode->blank_index != 2)
        {
            pq.push(currNode->moveUp(heuristic));
        }
        if (currNode->blank_index != 6  && currNode->blank_index != 7 && currNode->blank_index != 8)
        {
            pq.push(currNode->moveDown(heuristic));
        }
        if (currNode->blank_index != 0  && currNode->blank_index != 3 && currNode->blank_index != 6)
        {
            pq.push(currNode->moveLeft(heuristic));
        }
        if (currNode->blank_index != 2 && currNode->blank_index != 5 && currNode->blank_index != 8)
        {
            pq.push(currNode->moveRight(heuristic));
        }
        
    }
    
    cout << "No solution found!" << endl;
}

int main()
{
    //int userPuzzle[9];
    int userPuzzle[9]; //= {1,2,3,4,8,0,7,6,5}; //TESTING
    int algChoice;
    int blank_index; 
    
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
    
    State* problem = new State(userPuzzle, blank_index, 0, 0, 0, 0);
    
    if (algChoice == 2)
    {
        problem->hn = misplacedTile(problem->puzzle);
    }
    if (algChoice == 3)
    {
        problem->hn = manhattanDistance(problem->puzzle);
    }
    
    
    general_search(problem, algChoice);
    
    
    return 0; 
} 