#include "AbstractCell.h"

void StringCell::setValue(const std::string& str) {
   _enum.stringData = str;
} 




en StringCell::getValue() const {
    return _enum;
}
StringCell::StringCell() {
    _enum.stringData = "";
}

StringCell::StringCell(const std::string& str) {
    _enum.stringData = str;
}

const StringCell& StringCell::operator=(const StringCell& obj) {
    _enum.stringData = obj._enum.stringData;
    return *this;
}

const AbCell& StringCell::operator=(const std::string& str) {
    _enum.stringData = str;
    return *this;
}



