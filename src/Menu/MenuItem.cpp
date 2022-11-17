#include "MenuItem.h"
#include <any>

namespace KVA {

    MenuItem::MenuItem(string _name, MenuItem::func_type _func) {
        name = _name;
        func = _func;
    }
    MenuItem::MenuItem(std::string _name, func_type2 func) {
        name = _name;
        func2 = func;
    }
    void MenuItem::run(any &param) {
            return func(param);
    }
    void MenuItem::run(vector<std::any>params) {
        return func2(params);
    }
    void MenuItem::print() {
        cout << name;
    }

}