//
// Created by deturpant on 17.11.22.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

namespace KVA {

    class Graph {
    public:
        int matrix[7][7];
        int matrix_size;
        Graph();
        Graph(int _n);
        int &operator() (int _i, int _j);
        void setMatrix(int _n);
        void ShowMatrix();
    };

} // KVA

#endif //GRAPHS_GRAPH_H
