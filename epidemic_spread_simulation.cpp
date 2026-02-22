// the dsa concepts we are going to use for this project is graph + BFS search + queue

#include<iostream>
#include<vector>

using namespace std;
// LETS first create a graph:



class graph{
    public:
        int numvertices;
        vector<int> adjlist[5];
    // making a constructor
        graph (int n){
            int numpeople = n;
        }

        void addEdge(int s, int d){

            // making a bidirectional edges
            adjlist[s].push_back(d);
            adjlist[d].push_back(s);

        }
};

int main(){
    return 0;
}