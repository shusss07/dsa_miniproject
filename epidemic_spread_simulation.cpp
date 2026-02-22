// the dsa concepts we are going to use for this project is graph + BFS search + queue

#include<iostream>
#include<vector>

using namespace std;
// LETS first create a graph:



class graph{
    private:
        int V;
        vector<int> adjlist[];

    public:
    // making a constructor
        graph (int V){
            this-> V = V;
        }
        // a function to make the bidirectional edge
        void addEdge(int s, int d){
            adjlist[s].push_back(d);
            adjlist[d].push_back(s);
        }

        // a function to print the graph:
        void printgraph(int V){
        for(int i=0; i<V ; i++){
            cout<<"Vertex :"<<i;
            for (int no : adjlist[i]){
                cout<< no << ",";
                 }
            cout<<endl;     
            }
        }

    };

int main(){

    graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,4);


    return 0;
}