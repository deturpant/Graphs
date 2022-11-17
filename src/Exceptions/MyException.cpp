//
// Created by deturpant on 25.09.22.
//

#include "MyException.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
namespace KVA {
    const char *MyException::getError() const {
        return m_error.c_str();
    }
    MyException::MyException(std::string error) {
        m_error = error;
        logging();
    }

    void MyException::logging() {
        std::fstream file;
        auto now = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(now);
        file.open(file_name, std::ios::app);
        file <<  "WARNING: " << m_error.c_str() << " | " << std::ctime(&end_time);
        file.close();
    }

    void MyException::setFileName(std::string _name) {
        file_name = _name;
    }
} // KVA