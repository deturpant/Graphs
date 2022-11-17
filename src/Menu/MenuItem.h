//
// Created by deturpant on 22.10.22.
//
#pragma once

#include <iostream>
#include <string>
#include <any>
#include "../Exceptions/MyException.h"
#include <vector>
using namespace std;
namespace KVA {

    class MenuItem {
    public:
        using func_type = void (*)(any &param);
        using func_type2 = void (*)(vector<any> params);
        MenuItem(string _name, func_type _func);
        MenuItem(string _name, func_type2 _func);
        void run(any &param);
        void run(vector<any> params);
        void print();


    private:
        std::string name{};
        func_type func = nullptr;
        func_type2 func2 = nullptr;
        vector<any> params{};
    };
}