#include "AbstractCell.h"

void DoubleCell::setValue(const std::string& str) {
    try {
       _enum.doubleData = std::stod(str);
        _enum.stringData = std::to_string(_enum.doubleData);
    } catch(std::exception& e) {
        std::cerr << "Invalid type" << e.what() << std::endl;
    }
} 




en DoubleCell::getValue() const {
    return _enum;
}

DoubleCell::DoubleCell(const std::string& str) {
    setValue(str);
}

DoubleCell::DoubleCell(double num) {
   _enum.doubleData = num;
    _enum.stringData = std::to_string(_enum.doubleData);
}


const DoubleCell& DoubleCell::operator=(const DoubleCell& obj) {
    _enum.doubleData = obj._enum.doubleData;
    _enum.stringData = obj._enum.stringData;
    return *this;
}

const AbCell& DoubleCell::operator=(const std::string& str) {
    DoubleCell newCell(str);
    *this = newCell;
    return *this;
}


