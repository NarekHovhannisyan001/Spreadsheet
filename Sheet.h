#ifndef SHEET
#define SHEET

#include "AbstractCell.h"

class Sheet {
public:
    Sheet();
    Sheet(Sheet&&);
    Sheet(const Sheet&);
    Sheet(int row, int columns);
    void setCell(int row, int col, const std::string&);
    const AbCell& getCell(int row, int col) const;
    void addRow(int row);
    void addColumn(int column);
    void removeRow(int row);
    void removeColumn(int col);
    void print();
    ~Sheet();
    AbCell& operator()(int row, int col);
private:
    AbCell*** m_cells;
    int m_row;
    int m_column;
};

#endif //SHEET