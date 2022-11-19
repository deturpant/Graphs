#include <iostream>
#include <fstream>
#include "Graph/Graph.h"
#include "Exceptions/MyException.h"
#include "Menu/MyMenu.h"
#include "Menu/MenuItem.h"

#define SIZE_MENU 11
using namespace KVA;

void ReadGraphFromFile(any &param) {
    auto *graph = std::any_cast<Graph *>(param);
    int x, y;
    cout << "Введите кол-во вершин в графе -->";
    int counter;
    cin >> counter;
    std::ifstream in("../graph.txt");
    if (!in) {
        std::cout << "Cannot open file\n";
        return;
    }
    for (y = 0; y < counter; y++) {
        for (x = 0; x < counter; x++) {
            in >> graph->matrix[x][y];
        }
    }
    graph->setMatrix(counter);
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
        arr[i] = temp-1;
    }
    graph->addVertex(counter, arr);
    cout << "\nВершина и соответствующие связи установлены!\n";
}
void createGraph(any &param) {
    auto *graph = std::any_cast<Graph*>(param);
    //Graph *graph = new Graph(1);
    cout << "Граф успешно создан. Создана вершина №1.\n";
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
void exit(any &param) {
    exit(0);
}
string MyException::file_name("test.txt");

int main() {
    Graph *graph = new Graph(1);
    MenuItem items[SIZE_MENU] = {
            MenuItem("Создать граф", createGraph),
      MenuItem("Добавить вершину", addVert),
      MenuItem("Удалить вершину", deleteVert),
      MenuItem("Обход графа в ширину", printBFS),
      MenuItem("Обход графа в глубину", printDFS),
      MenuItem("Вывести матрицу смежности", printMatrix),
      MenuItem("Вывод возможных перемещений между вершинами", printG),
      MenuItem("Вывести количество ребёр в графе", printCountEdge),
      MenuItem("Вывести сумму степеней вершин в графе", printSumDegree),
      MenuItem("Загрузить граф из файла", ReadGraphFromFile),
      MenuItem("Выход из программы", exit)
    };
    MyMenu menu("Graphs", items, SIZE_MENU);
    any param = graph;
    while (true) {
        menu.runCommand(param);
    }
    return 0;
}
