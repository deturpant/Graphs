//
// Created by deturpant on 17.11.22.
//

#include <cstdlib>
#include <iostream>
#include "Graph.h"

namespace KVA {
    Graph::Graph() {
        this->matrix_size = 7;
        nodes = new int[matrix_size];
        for (int i = 0; i < this->matrix_size; i++) {
            nodes[i] = 0;
            for (int j = 0; j < this->matrix_size; j++) {
                this->matrix[i][j] = 0;
                this->matrix[j][i] = this->matrix[i][j];
            }
        }
    }

    Graph::Graph(int _n) {
        this->matrix_size = _n;
        nodes = new int[matrix_size];
        for (int i = 0; i < this->matrix_size; i++) {
            for (int j = 0; j < this->matrix_size; j++) {
                this->matrix[i][j] = 0;
                this->matrix[j][i] = this->matrix[i][j];
            }
        }
    }

    int &Graph::operator()(int _i, int _j) {
        return this->matrix[_i][_j];
    }

    void Graph::setMatrix(int _n) {
        this->matrix_size = _n;
    }

    void Graph::ShowMatrix() {
        std::cout << "Матрица смежности:\n";
        for (int i = 0; i < matrix_size; i++) {
            for (int j = 0; j < matrix_size; j++) {
                std::cout << " " << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void Graph::DFS() {
        cout << "----------DFS----------------\n";
        Stack.push(0);
        while (!Stack.empty()) {
            int node = Stack.top();
            Stack.pop();
            if (nodes[node] == 2) continue;
            nodes[node] = 2;
            for (int j = matrix_size - 1; j >= 0; j--) {
                if (matrix[node][j] == 1 && nodes[j] != 2) {
                    Stack.push(j);
                    nodes[j] = 1;
                }
            }
            cout << node + 1 << " ";
        }
        cout << endl;
        cout << "----------DFS----------------\n";
        reloadNodes();
    }

    void Graph::reloadNodes() {
        for (int i = 0; i < matrix_size; i++) {
            nodes[i] = 0;
        }

    }

    void Graph::BFS() {
        cout << "----------BFS----------------\n";
        Queue.push(0);
        while (!Queue.empty()) {
            int node = Queue.front();
            Queue.pop();
            nodes[node] = 2;
            for (int j = 0; j < matrix_size; j++) {
                if (matrix[node][j] == 1 && nodes[j] == 0) {
                    Queue.push(j);
                    nodes[j] = 1;
                }
            }
            cout << node + 1 << " ";
        }
        cout << endl;
        cout << "----------BFS----------------\n";
        reloadNodes();
    }

    void Graph::printGraph() {
        cout << "----------GRAPH----------------\n";
        for (int i = 0; i < matrix_size; i++) {
            for (int j = 0; j < matrix_size; j++) {
                if (matrix[i][j] == 1) {
                    cout << i + 1 << " --> " << j + 1 << std::endl;
                }
            }
        }
        cout << "----------GRAPH----------------\n";
    }

    void Graph::addVertex(int _countSV, int *arrVert) {
        setMatrix(matrix_size + 1);
        for (int i = 0; i < matrix_size - 1; i++) {
            for (int z = 0; z < _countSV; z++) {
                if (arrVert[z] == i) {
                    matrix[i][matrix_size - 1] = 1;
                    matrix[matrix_size - 1][i] = 1;
                }
            }
        }
    }

    void Graph::deleteVertex(int _number) {
        for (int i = 0; i < matrix_size; i++) {
            for (int j = 0; j < matrix_size; j++) {
                if (j == _number) {
                    matrix[i][j] = 0;
                    matrix[j][i] = 0;
                }
            }
        }
        for (int j = _number + 1; j <matrix_size;j++) {
            for (int z = 0; z< matrix_size;z++) {
                matrix[j-1][z] = matrix[j][z];
            }
        }
        for (int i = 0; i<matrix_size;i++) {
            for (int j = _number+1 ; j <matrix_size;j++) {
                matrix[i][j-1] = matrix[i][j];
            }
        }

        setMatrix(matrix_size - 1);
    }

} // KVA