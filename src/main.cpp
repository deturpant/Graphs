#include <iostream>
#include <fstream>
#include <limits>
#include "Graph/Graph.h"
#include "Exceptions/MyException.h"
#include "Menu/MyMenu.h"
#include "Menu/MenuItem.h"

#define SIZE_MENU 12
#define LOAD_GRAPH auto *graph = any_cast<Graph*>(params[0]);
#define LOAD_OUTPUT_FILE auto out = any_cast<string>(params[1]);
#define LOAD_DATA_FILE auto fn = any_cast<string>(params[2]);

using namespace KVA;

void addEdge(vector<any>params) {
    LOAD_GRAPH;
    int _f;
    int _to;
    graph->ShowMatrix();
    cout << "Пожалуйста, введите первую вершину ребра: ";
    cin >> _f;
    if (_f > graph->matrix_size || _f<=0) {
        throw MyException{"Wrong index vertex"};
    }
    cout << "Пожалуйста, введите вторую вершину ребра: ";
    cin >> _to;
    if (_to > graph->matrix_size || _to<=0) {
        throw MyException{"Wrong index vertex"};
    }
    graph->addEdge(_f, _to);
    cout << "Ребро успешно добавлено!\n";
    graph->ShowMatrix();
}
void deleteEdge(vector<any> params){
    LOAD_GRAPH;
    int _f;
    int _to;
    graph->ShowMatrix();
    cout << "Пожалуйста, введите первую вершину ребра: ";
    cin >> _f;
    if (_f > graph->matrix_size || _f<=0) {
        throw MyException{"Wrong index vertex"};
    }
    cout << "Пожалуйста, введите вторую вершину ребра: ";
    cin >> _to;
    if (_to > graph->matrix_size || _to<=0) {
        throw MyException{"Wrong index vertex"};
    }
    graph->deleteEdge(_f, _to);
    cout << "Ребро успешно удалено!\n";
    graph->ShowMatrix();

}
void ReadGraphFromFile(vector<any> params) {
    LOAD_GRAPH
    LOAD_DATA_FILE
    int x, y;
    int counter = 5;
    std::ifstream in(fn);
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
void addVert(vector<any> params) {
    LOAD_GRAPH
    cout << "Введите кол-во вершин, с которыми будет связана новая вершина --> ";
    int counter;
    cin >>counter;
    int *arr = new int[counter];
    int temp;
    for (int i = 0; i< counter;i++) {
        cout << "Введите вершину №" << i+1 << " -->";
        cin >> temp;
        if (temp >graph->matrix_size) {
            throw MyException{"Вершины не существует"};
        }
        arr[i] = temp-1;
    }
    graph->addVertex(counter, arr);
    cout << "\nВершина и соответствующие связи установлены!\n";
}
void deleteVert(vector<any> params) {
    LOAD_GRAPH
    graph->ShowMatrix();
    cout << "Введите индекс удаляемой вершины по матрице смежностей --> ";
    int tmp;
    cin >> tmp;
    if (tmp >graph->matrix_size) {
        throw MyException{"Вершины не существует"};
    }
    graph->deleteVertex(tmp-1);
    cout << "Удаление успешно завершено!\n";
}
void printBFS(vector<any> params) {
    LOAD_GRAPH
    cout << "Запущена функция обхода графа в ширину...\n";
    graph->BFS();
}
void printDFS(vector<any> params) {
    LOAD_GRAPH
    cout << "Запущена функция обхода графа в глубину...\n";
    graph->DFS();
}
void printMatrix(vector<any> params) {
    LOAD_GRAPH
    cout << "Запущена функция вывода матрицы смежности...\n";
    graph->ShowMatrix();
}
void printG(vector<any> params) {
    LOAD_GRAPH
    cout << "Запущена функция вывода перемещений между вершинами...\n";
    graph->printGraph();
}
void printCountEdge(vector<any> params) {
    LOAD_GRAPH
    cout << "Запущена функция вывода кол-ва рёбер...\n";
    cout << "Результат ==> " << graph->getCountEdge() << " рёбер.";
}
void printSumDegree(vector<any> params) {
    LOAD_GRAPH
    cout << "Запущена функция вывода суммы степеней вершин...\n";
    cout << "Результат ==> " << graph->getSumDegree();
}
void saveData(string file_name, Graph *graph) {
    ofstream file;
    string s;
    file.open(file_name, std::ios::out);
    for (int i=0; i<graph->matrix_size; i++) {
        for (int j = 0; j<graph->matrix_size;j++) {
            file << graph->matrix[i][j] << " ";
        }
        file << "\n";
    }
    file.close();
}
void lemma(vector<any> params) {
    LOAD_GRAPH
    cout << "Запущена проверка утверждения:\nСумма степеней всех вершин графа"
            " равна удвоенному числу рёбер.\n";
    if (graph->getSumDegree() == graph->getCountEdge()*2) {
        cout << "Сумма степеней: " << graph->getSumDegree() <<" = " << graph->getCountEdge() << "*2 Удвоенному числу рёбер\n";
        cout << "Утверждение верно!\n";
    }
    else {
        cout << "Утверждение неверно!\n";
    }
}
void exit(vector<any> params) {
    LOAD_GRAPH
    LOAD_OUTPUT_FILE
    saveData(out, graph);
    exit(0);
}
void clearCIN() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
}
string MyException::file_name = "logs.txt";
int main(int argc, char *argv[]) {
    std::string load_data_file = "data1.txt";
    std::string write_data_file = "data2.txt";
    std::string log_data_file = "logs.txt";
    if (argc >=3) {
        load_data_file = argv[1];
        write_data_file = argv[2];
        log_data_file = argv[3];
    }
    MyException::setFileName(log_data_file);

    Graph *graph = new Graph(1);
    MenuItem items[SIZE_MENU] = {
      MenuItem("Добавить вершину", addVert),
      MenuItem("Удалить вершину", deleteVert),
      MenuItem("Добавить ребро", addEdge),
      MenuItem("Удалить ребро", deleteEdge),
      MenuItem("Обход графа в ширину", printBFS),
      MenuItem("Обход графа в глубину", printDFS),
      MenuItem("Вывести матрицу смежности", printMatrix),
      MenuItem("Вывод возможных перемещений между вершинами", printG),
      MenuItem("Вывести количество ребёр в графе", printCountEdge),
      MenuItem("Вывести сумму степеней вершин в графе", printSumDegree),
      MenuItem("Проверка утверждения", lemma),
      MenuItem("Выход из программы", exit)
    };
    MyMenu menu("Graphs", items, SIZE_MENU);
    vector<any> params = {graph, write_data_file, load_data_file};
    ReadGraphFromFile(params);
    while (true) {
        try {
            menu.runCommand(params);
        }
        catch(const MyException &ex) {
            cout << "\nError: " << ex.getError() << "\n";
            clearCIN();
        }
    }
    return 0;
}
