//
// Created by deturpant on 17.11.22.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H
#include <stack>
#include <queue>
#define MAX_SIZE 100
using namespace std;
namespace KVA {

    class Graph {
    private:
        stack<int> Stack;
        queue<int> Queue;
        int *nodes;
        int *degree;
        int countEdge = 0;
        void reloadNodes();
        void updateCountEdge();
        void updateDegree(); // обновить степени вершин
    public:
        int matrix[MAX_SIZE][MAX_SIZE];
        int matrix_size;
        Graph();
        Graph(int _n);
        void setMatrix(int _n); // установить размер
        void printGraph(); // распечатать ребра
        void ShowMatrix(); // распечатать матрицу
        void DFS(); // обход в глубину
        void BFS(); //обход в ширину
        void addVertex(int _countSV, int *arrVert); // добавление вершины
        void deleteVertex(int _number); // удаление вершины по номеру
        int getSumDegree(); // получить сумму степеней вершин
        int getCountEdge();
    };

} // KVA

#endif //GRAPHS_GRAPH_H
