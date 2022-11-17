//
// Created by deturpant on 22.10.22.
//

#include "MyMenu.h"

namespace KVA {
    MyMenu::MyMenu() {}

    MyMenu::MyMenu(string _name, MenuItem *items, size_t count) : m_title(_name), m_items(items), m_count(count) {}

    void MyMenu::print() {
        std::cout << m_title << "\n";
        for (size_t i{}; i < m_count; ++i) {
            std::cout << i + 1 << ". ";
            m_items[i].print();
            std::cout << std::endl;
        }
    }
    void MyMenu::runCommand(std::vector<any> params) {
        cout << "\n";
        print();
        cout << "\nSelect ==> ";
        cin >> m_select;
        if (m_select > m_count || m_select <= 0) {
            throw MyException{"Wrong index command in menu"};
        }

        return m_items[m_select - 1].run(params);

    }
    void MyMenu::runCommand(any &param) {
        cout << "\n";
        print();
        cout << "\nSelect ==> ";
        cin >> m_select;
        if (m_select > m_count || m_select <= 0) {
            throw MyException{"Wrong index command in menu"};
        }

        return m_items[m_select - 1].run(param);

    }
} // KVA