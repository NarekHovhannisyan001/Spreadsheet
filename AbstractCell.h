#ifndef AB_CELL
#define AB_CELL

#include <string>
#include <sstream>
#include <iostream>



struct  en{
    int intData;
    double doubleData;
    std::string stringData;
};

class AbCell;
std::ostream& operator<<(std::ostream&, const AbCell&);


class AbCell {
public:
    // AbCell();
    // AbCell(const std::string);
    virtual void setValue(const std::string&) = 0;
    virtual en getValue() const = 0; 
    virtual ~AbCell() = default;
    friend std::ostream& operator<<(std::ostream&, const AbCell&);
};  


class IntCell : public AbCell {
public:
    IntCell(int);
    IntCell(const std::string&);
    void setValue(const std::string&) override;
    en getValue() const override;
    virtual ~IntCell() = default;
    const IntCell& operator=(const IntCell&);
    const AbCell& operator=(const std::string&);
    
private:
    // int m_intValue;
    en _enum;
};




class DoubleCell : public AbCell {
public:
    DoubleCell(double);
    DoubleCell(const std::string&);
    void setValue(const std::string&) override;
    en getValue() const override;
    virtual ~DoubleCell() = default;
    const DoubleCell& operator=(const DoubleCell&);
    const AbCell& operator=(const std::string&);

private:
    // double m_doubleValue;
    en _enum;

};



class StringCell : public AbCell {
public:
    StringCell();
    StringCell(const std::string&);
    void setValue(const std::string&) override;
    en getValue() const override;
    virtual ~StringCell() = default;
    const StringCell& operator=(const StringCell&);
    const AbCell& operator=(const std::string&);
private:
   // std::string m_stringValue;
    en _enum;

};

std::ostream& operator<<(std::ostream& os, const AbCell& cell) {
    os << cell.getValue().stringData;
    return os;
}











#endif //AB_CELL