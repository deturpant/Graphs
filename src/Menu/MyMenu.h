//
// Created by deturpant on 22.10.22.
//

#ifndef TADS_LAB2_MYMENU_H
#define TADS_LAB2_MYMENU_H

#include "MenuItem.h"
#include "../Exceptions/MyException.h"
#include <vector>
namespace KVA {

    class MyMenu {
    public:
        using func_type = void (*)(any &param);
        using func_type2 = void(*)(std::vector<any> params);
        MyMenu();

        MyMenu(string _name, MenuItem *items, size_t count);

        void print();

        void runCommand(any &param);
        void runCommand(std::vector<any> params);

    private:
        int m_select{-1};
        size_t m_count{};
        string m_title{};
        MenuItem *m_items{};
    };

} // KVA

#endif //TADS_LAB2_MYMENU_H
