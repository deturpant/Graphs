#include <iostream>
#include <fstream>
#include "Graph/Graph.h"
#include "Exceptions/MyException.h"
#include "Menu/MyMenu.h"
#include "Menu/MenuItem.h"

#define GRAPH_SIZE 5
#define SIZE_MENU 2
using namespace KVA;

void ReadGraphFromFile(any &param) {
    auto *graph = std::any_cast<Graph *>(param);
    int x, y;
    std::ifstream in("graph.txt");
    if (!in) {
        std::cout << "Cannot open file\n";
        return;
    }
    for (y = 0; y < GRAPH_SIZE; y++) {
        for (x = 0; x < GRAPH_SIZE; x++) {
            in >> graph->matrix[x][y];
        }
    }
    in.close();
}

void print(any &param) {
    auto *graph = std::any_cast<Graph *>(param);
    graph->ShowMatrix();
}

string MyException::file_name("test.txt");

int main() {
    Graph *graph = new Graph(GRAPH_SIZE);
    MenuItem items[SIZE_MENU] = {MenuItem("Show Graph", print), MenuItem("Load Graph from file", ReadGraphFromFile)};
    MyMenu menu("Graphs", items, SIZE_MENU);
    any param = graph;
    while (true) {
        menu.runCommand(param);
    }
    return 0;
}
