#include "AbstractCell.h"

void IntCell::setValue(const std::string& str) {
   try {
        _enum.intData = std::stoi(str);
        _enum.stringData = std::to_string(_enum.intData);
    } catch(std::exception& e) {
        std::cerr << "Invalid type" << e.what() << std::endl;
    }
}



en IntCell::getValue() const {
    return _enum;
}

IntCell::IntCell(const std::string& str) {
    setValue(str);
}

IntCell::IntCell(int num) {
    _enum.intData = num;
    _enum.stringData = std::to_string(_enum.intData);

}

const IntCell& IntCell::operator=(const IntCell& obj) {
    _enum.intData = obj._enum.intData;
    _enum.stringData = obj._enum.stringData;
    return *this;
}

const AbCell& IntCell::operator=(const std::string& str) {
    IntCell newCell(str);
    *this = newCell;
    return *this;
}
