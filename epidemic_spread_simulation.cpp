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


        // BFS spread  implementation using queue
        void bfs_spread(){

            queue<int> Queue;

            // finding the patient zero
            for(int i =0 ; i<peoples ; i++){

                if (personstate[i]== Infected){
                    Queue.push(i);
                }
            }


           // vector<bool> visited(peoples,false); -- this is no longer needed as this is done by our states

            // adding the day counter since my model has become infect everyone script:
            int day = 0;

            while(Queue.size()!=0){
                cout<<"Day :"<<day<<endl;

                // bug fixed; level shou;d be how many peps are there in queue not what day it is
                int level = Queue.size();

                for (int j =0 ; j< level ; j++){
                int source = Queue.front();
                Queue.pop();


                for (int neighbor : adjlist[source]){

                if(personstate[neighbor] == Healthy ){

                    personstate[neighbor] = Infected;
                    // added our destination node to the queue to make it a new source
                    Queue.push(neighbor);

                    }

                }
                personstate[source] = Recovered;

                }
                printStates();
                day++;
            }
            

        }

        // Setting patients zero; first person to get infected in the peoples
        
        // starting node for our bfs
        void patientzero(int person){

            personstate[person] = Infected;
            cout<<"The first infected person in our simulation is "<<person<<endl;

        }

        void printStates(){
            for (int i = 0 ; i<peoples;i++){
                cout<< i <<"\t";
                //cout<<personstate[i];
    
                if(personstate[i] == Healthy){
                    cout<<"Healthy"<<endl;}
                else if(personstate[i] == Recovered){
                    cout<<"Recoverd"<<endl;}
                else if(personstate[i] == Infected){
                    cout<<"Infected"<<endl;}
                else {
                    cout<< "the person is kept in quarantine"<<endl;}
            }
        }

        void quarantine(int person){
            cout<<"the infected person that got quarantine is " <<person;
            personstate[person] = Quarantine; // chaining the state
            adjlist[person].clear(); // clearing the connection/edges so the disease doesnot spread 
            // ie. deleting the node for person 2
        }

        void generateEdge(int seed){

            srand(seed); // for getting same sequence -- easier to debug
            for (int i=0 ; i<peoples ; i++){
                int contacts = 2 + rand() % 4; // value of contacts will be between 2 and 5
                for(int j=0 ; j< contacts; j++ ){
                int connections = rand() % peoples;
                    if(connections != i ){// to avoid self loops
                        addEdge(connections,i); // adding edges between 2 nodes
                    }
                    }

            }

        }
};

int main(){

    int n =30;
    // at first everyone is healthy
for (int i =0 ; i < n ; i++){
    personstate[i] = Healthy;
}

    graph g(n);

    // for generating edges
    g.generateEdge(42);

    // printing the graph to see the connections
    g.printgraph();

    // setting the person 0 as the initial infected 
    g.patientzero(0);

    // also setting person 2 as infected
    g.patientzero(2);

    // keeping no 2 in quarantine
    g.quarantine(2);

    // printing the states of people
    g.printStates();

    // visualizing the spread
    g.bfs_spread();

    return 0;
}