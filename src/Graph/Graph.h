//
// Created by deturpant on 17.11.22.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H
#include <stack>
#include <queue>
using namespace std;
namespace KVA {

    class Graph {
    private:
        stack<int> Stack;
        queue<int> Queue;
        int *nodes;
        void reloadNodes();
    public:
        int matrix[7][7];
        int matrix_size;
        Graph();
        Graph(int _n);
        int &operator() (int _i, int _j);
        void setMatrix(int _n);
        void printGraph();
        void ShowMatrix(); // распечатать матрицу
        void DFS(); // обход в глубину
        void BFS(); //обход в ширину
    };

} // KVA

#endif //GRAPHS_GRAPH_H
