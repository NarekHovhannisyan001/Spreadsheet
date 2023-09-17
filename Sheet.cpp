#include "Sheet.h"

    Sheet::Sheet() : m_cells{nullptr}, m_column{}, m_row{} {}
    
    Sheet::Sheet(int rows, int columns) : m_cells(nullptr), m_row(rows), m_column(columns) {
        m_cells = new AbCell**[m_row];
        for (int i = 0; i < m_row; ++i) {
            m_cells[i] = new AbCell*[m_column];
            for (int j = 0; j < m_column; ++j) {
                m_cells[i][j] = nullptr; 
            }
        }
    }

    Sheet::Sheet(Sheet&& obj) {
        m_column = obj.m_column;
        m_row = obj.m_row;
        m_cells = obj.m_cells;
        obj.m_cells = nullptr;
        obj.m_column = obj.m_row = 0;
    }

    Sheet::Sheet(const Sheet& obj) {
        m_column = obj.m_column;
        m_row = obj.m_row;
        m_cells = new AbCell**[m_row];
        for (int i = 0; i < m_row; ++i) {
        m_cells[i] = new AbCell*[m_column];
        }

    

    for (int i = 0; i < m_row; ++i) {
        for (int j = 0; j < m_column; ++j) {
            m_cells[i][j] = obj.m_cells[i][j];
        }
    }

    }



    void Sheet::setCell(int row, int col, const std::string& str) {
    if (row >= 0 && row < m_row && col >= 0 && col < m_column) {
        try {
            size_t pos;
            int intValue = std::stoi(str, &pos);

            if (pos == str.length()) {
                m_cells[row][col] = new IntCell(intValue);
            } else {
                double doubleValue = std::stod(str);
                m_cells[row][col] = new DoubleCell(doubleValue);
            }
        } catch (const std::invalid_argument& e) {
            m_cells[row][col] = new StringCell(str);
        }
    } else {
        std::cerr << "Invalid cell coordinates";
        throw std::exception();
    }
}



    const AbCell& Sheet::getCell(int row, int col) const {
        if (row >= 0 && row < m_row && col >= 0 && col < m_column) {
           return *m_cells[row][col];
        } else {
            std::cerr << "Invalid cell coordinates";
            throw std::exception();
        }
    }






    void Sheet::addRow(int row) {
        AbCell*** newCells = new AbCell**[m_row + row];

    for (int i = 0; i < m_row + row; ++i) {
        newCells[i] = new AbCell*[m_column];
    }

    for (int i = 0; i < m_row; ++i) {
        for (int j = 0; j < m_column; ++j) {
            newCells[i][j] = m_cells[i][j];
        }
    }

    for (int i = 0; i < m_row; ++i) {
        delete[] m_cells[i];
    }
    delete[] m_cells;

    m_cells = newCells;
    m_row += row;
    }

    void Sheet::addColumn(int column) {
         if (column <= 0) {
        std::cerr << "Invalid column count";
        throw std::exception();
    }

    AbCell*** newCells = new AbCell**[m_row];
    for (int i = 0; i < m_row; ++i) {
        newCells[i] = new AbCell*[m_column + column];

        for (int j = 0; j < m_column; ++j) {
            newCells[i][j] = m_cells[i][j];
        }

        for (int j = m_column; j < m_column + column; ++j) {
            *newCells[i][j] = StringCell();
        }
    }

    for (int i = 0; i < m_row; ++i) {
        delete[] m_cells[i];
    }
    delete[] m_cells;

    m_cells = newCells;
    m_column += column;
    }

    void Sheet::print() {
        if (m_row <= 0 || m_column <= 0) {
            std::cout << "Empty spreadsheet." << std::endl;
            return;
        }

        for (int i = 0; i < m_row; ++i) {
            for (int j = 0; j < m_column; ++j) {
                if (m_cells[i][j] == nullptr || m_cells[i][j]->getValue().stringData == "") {
                    std::cout << "- ";
                } else {
                    std::cout << m_cells[i][j]->getValue().stringData << " ";
                }
            }
            std::cout << "\n";
        }
    }


Sheet::~Sheet() {
    for (int i = 0; i < m_row; ++i) {
        // for (int j = 0; j < m_column; ++j) {
        //     delete[] m_cells[i][j];
        // }
        delete[] m_cells[i];
    }
    delete[] m_cells;
}


AbCell& Sheet::operator()(int row, int col) {
    if (row >= 0 && row < m_row && col >= 0 && col < m_column) {
        if (m_cells[row][col] == nullptr) {
            m_cells[row][col] = new StringCell();
        }
        return *m_cells[row][col];
    } else {
        std::cerr << "Invalid cell coordinates";
        throw std::exception();
    }
}


