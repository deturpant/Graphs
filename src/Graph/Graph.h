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
        void reloadNodes();
    public:
        int matrix[MAX_SIZE][MAX_SIZE];
        int matrix_size;
        Graph();
        Graph(int _n);
        int &operator() (int _i, int _j);
        void setMatrix(int _n); // установить размер
        void printGraph(); // распечатать ребра
        void ShowMatrix(); // распечатать матрицу
        void DFS(); // обход в глубину
        void BFS(); //обход в ширину
        void addVertex(int _countSV, int *arrVert); // добавление вершины
        void deleteVertex(int _number); // удаление вершины по номеру
        void updateDegree(); // обновить степени вершин
        int getSumDegree(); // получить сумму степеней вершин
    };

} // KVA

#endif //GRAPHS_GRAPH_H
