//
// Created by deturpant on 17.11.22.
//

#include <cstdlib>
#include <iostream>
#include "Graph.h"

namespace KVA {
    Graph::Graph() {
        this->matrix_size = 7;
        for (int i = 0; i < this->matrix_size; i++) {
            for (int j = 0; j < this->matrix_size; j++) {
                this->matrix[i][j] = 0;
                this->matrix[j][i] = this->matrix[i][j];
            }
        }
    }

    Graph::Graph(int _n) {
        this->matrix_size = _n;
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

} // KVA