#include<iostream>
using namespace std;
class DynamicArray{
    private:
        int* arr;
        int size;
        int capacity;
        void resize(int capacity){
            int* new_arr = new int[capacity*2];
            for(int i = 0; i < size; i++){
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            capacity = capacity*2;
        }
    public:
        DynamicArray(): arr(new int[1]), size(0), capacity(1){}
        ~DynamicArray(){
            delete[] arr;
        }
        void push_back(int value){
            if(size == capacity){
                resize(capacity);
            }
            arr[size++] = value;
        }
        int& operator[](int index){
            if (index < 0 || index >= size) {
                throw out_of_range("Index out of bounds");
            }
            return arr[index];
        }
        int getSize() const {
            return size;
        }
};
class Queue{
    private:
        struct Node{
            int data;
            Node* next;
            Node(int d): data(d), next(nullptr){}
        };
        Node* front;
        Node* rear;
    public:
    Queue(): front(nullptr), rear(nullptr){}
    ~Queue(){
        while(!isEmpty()){
            dequeue();
        }
    }
    void enqueue(int value){
        Node* temp = new Node(value);
        if(rear == nullptr){
            front = rear = temp;
        }
        rear->next = temp;
        rear = temp;
    }
    void dequeue(){
        if (isEmpty()) {
            throw runtime_error("Cannot dequeue from an empty queue");
        }
        Node* temp = front;
        front = front->next;
        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;
    }
    int getFront(){
        if(isEmpty()){
            throw runtime_error("Queue is empty");
        }
        return front->data;
    }
    bool isEmpty(){
        return front == nullptr;
    }
};
class Graph{
    private:
        int V;
        DynamicArray* adj;
    public:
        Graph(int vertics): V(vertics){
            adj = new DynamicArray[V];
        }
        ~Graph(){
            delete[] adj;
        }

        // Undirected Graph
        void addEdge_Undirected(int v, int w){
            if (v < 0 || v >= V || w < 0 || w >= V) {
                throw std::out_of_range("Vertex index out of bounds");
            }
            adj[v].push_back(w);
            adj[w].push_back(v); // This line makes it undirected
        }

        bool hasEdge(int v, int w) const {
            if (v < 0 || v >= V || w < 0 || w >= V) {
                throw std::out_of_range("Vertex index out of bounds");
            }
            for (int i = 0; i < adj[v].getSize(); ++i) {
                if (adj[v][i] == w) return true;
            }
            return false;
        }
        
        // Prints the adjacency list of the graph
        void printGraph() {
            for (int v = 0; v < V; v++) {
                cout << "Adjacency list of vertex " << v << ": ";
                for (int i = 0; i < adj[v].getSize(); i++) {
                    cout << adj[v][i] << " ";
                }
                cout<<endl;
                }
            }
};

int main(){
    Graph g(5); // Create a graph with 5 vertices

    g.addEdge_Undirected(0, 1);
    g.addEdge_Undirected(0, 2);
    g.addEdge_Undirected(1, 3);
    g.addEdge_Undirected(2, 3);
    g.addEdge_Undirected(1, 4);

    std::cout << "Graph representation:" << std::endl;
    g.printGraph();
}