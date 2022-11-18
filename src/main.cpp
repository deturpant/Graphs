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
    std::ifstream in("../graph.txt");
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
void addVert(any &param) {
    auto *graph = std::any_cast<Graph *>(param);
    cout << "Введите кол-во вершин, с которыми будет связана новая вершина --> ";
    int counter;
    cin >>counter;
    int *arr = new int[counter];
    int temp;
    for (int i = 0; i< counter;i++) {
        cout << "Введите вершину №" << i+1 << " -->";
        cin >> temp;
        arr[i] = temp;
    }
    graph->addVertex(counter, arr);
    cout << "\nВершина и соответствующие связи установлены!\n";
}
void deleteVert(any &param) {
    auto *graph = std::any_cast<Graph *>(param);
    graph->ShowMatrix();
    cout << "Введите индекс удаляемой вершины по матрице смежностей --> ";
    int tmp;
    cin >> tmp;
    graph->deleteVertex(tmp-1);
    cout << "Удаление успешно завершено!\n";
}
void printBFS(any &param) {
    auto *graph = std::any_cast<Graph *>(param);
    cout << "Запущена функция обхода графа в ширину...\n";
    graph->BFS();
}
void printDFS(any &param) {
    auto *graph = std::any_cast<Graph *>(param);
    cout << "Запущена функция обхода графа в глубину...\n";
    graph->DFS();
}
void printMatrix(any &param) {
    auto *graph = std::any_cast<Graph *>(param);
    cout << "Запущена функция вывода матрицы смежности...\n";
    graph->ShowMatrix();
}
void printG(any &param) {
    auto *graph = std::any_cast<Graph *>(param);
    cout << "Запущена функция вывода перемещений между вершинами...\n";
    graph->printGraph();
}
void printCountEdge(any &param) {
    auto *graph = std::any_cast<Graph *>(param);
    cout << "Запущена функция вывода кол-ва рёбер...\n";
    cout << "Результат ==> " << graph->getCountEdge() << " рёбер.";
}
void printSumDegree(any &param) {
    auto *graph = std::any_cast<Graph *>(param);
    cout << "Запущена функция вывода суммы степеней вершин...\n";
    cout << "Результат ==> " << graph->getSumDegree();
}
void print(any &param) {
    auto *graph = std::any_cast<Graph *>(param);
    graph->ShowMatrix();
    graph->printGraph();
    int *arr = new int[2];
    arr[0] = 3;
    arr[1] = 4;
    graph->addVertex(2, arr);
    graph->ShowMatrix();
    graph->printGraph();
    graph->deleteVertex(2);
    graph->ShowMatrix();
    graph->printGraph();
    cout << graph->getSumDegree() << endl;
    cout << graph->getCountEdge();
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
