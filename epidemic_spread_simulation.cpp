// the dsa concepts we are going to use for this project is graph + BFS search(implemented using queue)
// we are going to implement graph using adjacency linked list

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAX_PEPS = 50;

enum State{
    Healthy,
    Infected,
    Recovered,  // may also be considered as some people died due to infection 
    Quarantine,
};


State personstate[MAX_PEPS];

// LETS first create a graph:
class graph{
    private:
        int peoples;
        vector<int> adjlist[MAX_PEPS];

    public:
    // making a constructor
        graph (int n){
            peoples = n;
        }
        // a function to make the bidirectional edge
        void addEdge(int s, int d){
            // here s and d are two nodes between which a edge exists!!
            adjlist[s].push_back(d);
            adjlist[d].push_back(s);
        }

        // a function to print the graph:
        void printgraph(){
        for(int i=0; i < peoples ; i++){
            cout<<"Vertex :"<<i<<"\t";
            for (int no : adjlist[i]){
                cout<< no << ",";
                 }
            cout<<endl;     
            }
        }


        // BFS Traversal implementation using queue
        void bfs(){
            // we are using queue to store our source node and then pop it;
            queue<int> Queue;
            // then we are using a vector of booleans to check whether the people/vertex is already visited or not
            vector<bool> visited(peoples,false);
            // pushing our first element/ first source to the queue
            Queue.push(0);
            visited[0] = true;

            while(Queue.size()>0){
                int s = Queue.front();
                Queue.pop();
                // printing the source of the graph
                cout<<s<<" ";
                for (int d : adjlist[s]){
                if(!visited[d]){
                    // changing the bool value to true
                    visited[d]= true;
                    // added our destination node to the queue to make it a new source
                    Queue.push(d);
                }
            }
            }
        }

        // Setting patients zero; first person to get infected in the peoples
        
        // starting node for our bfs
        void patientzero(int person){

            personstate[person] = Infected;
            cout<<"The first infected person in our simulation is "<<person<<endl;

        }
};

int main(){

    // at first everyone is healthy
for (int i =0 ; i < 4 ; i++){
    personstate[i] = Healthy;
}

    graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);

    g.printgraph();
    g.patientzero(0);
    g.bfs();

    return 0;
}