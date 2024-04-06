#include<iostream>
using namespace std;

struct node{ //creating the outline for linked list
    int data;
    node *next;
};

node *createNewNode(int x){ //creating a new node
    node *newnode=new node();
    newnode->data=x;
    newnode->next=nullptr;
    return newnode;
}

class Graph{ //creating the constructor for graph
    int nVertices;
    node **adjacencyList;
//adjacencyList will point to an array of pointers, where
//each pointer points to the head of a linked list
//representing the adjacency list of a vertex in the graph.
    bool directed;
public:
    Graph(int n,bool dir);
    void addEdge(int u,int v);
    bool isEdge(int u,int v);
    void display();
    ~Graph();
};

Graph::Graph(int n,bool dir){
    nVertices=n;
    directed=dir;
    adjacencyList=new node *[n];
//This line dynamically allocates an array of pointers to node objects.
//The new keyword is used to allocate memory dynamically.
//node*[n] indicates that adjacencyList will point to an array of pointers,
//and n is the number of elements in this array.
//Each element of this array is expected to hold the address of a node object.
    for(int i=0;i<nVertices;i++){
        adjacencyList[i]=nullptr;
    }
//This step ensures that each element initially points to nothing,
//indicating that no edges have been added to the graph yet.
}

void Graph::addEdge(int u,int v){
    if(u<0 || u>nVertices || v<0 || v>nVertices){
        return;
    }
    node *n1=createNewNode(v); //adjacencyList=new *node[n]=nullptr was the initial one
    n1->next=adjacencyList[u];
    adjacencyList[u]=n1;

    node *n2=createNewNode(u);
    n2->next=adjacencyList[v];
    adjacencyList[v]=n2;
}

bool Graph::isEdge(int u,int v){
    node *current=adjacencyList[u];
    for(int i=0;i<nVertices;i++){
        if(current->data!=v || current!=nullptr){
            current=current->next;
        }
    }
    if(current==nullptr) return false;
    return true;
}

void Graph::display(){
    cout<<"Printing list:\n";
    for(int i=0;i<nVertices;i++){
        cout<<i<<":";
        node *current=adjacencyList[i]; //adjacency list of that particular vertex
        while(current!=nullptr){
            cout<<current->data<<"\t";
            current=current->next;
        }
        cout<<endl;
    }
}

Graph::~Graph(){
    for(int i=0;i<nVertices;i++)
        delete adjacencyList[i];
    delete [] adjacencyList;
}

int main(){
    Graph g(4,false); //undirected with 4 vertices
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(1,2);
    g.display();
    }

