#include <iostream>
#include "Graph/Graph.h"
#include "Exceptions/MyException.h"
#include "Menu/MyMenu.h"
#include "Menu/MenuItem.h"

using namespace KVA;
void test(any &param) {
    std::cout << "Test func";
}
string MyException::file_name("test.txt");
int main() {
    MenuItem items[1] = {MenuItem("test func",test)};
    MyMenu menu("rer", items, 1);
    any param;
    while (true) {
        menu.runCommand(param);
    }
    return 0;
}
