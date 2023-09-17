#include "Sheet.h"


int main() {
    Sheet ob;
    ob.addRow(2);
    ob.addColumn(2);
    ob.setCell(0, 0, "hello");
    ob.setCell(0, 1, "3.14");
    ob.setCell(1, 1, "val");
    ob.setCell(1, 0, "3");
    ob.print();
    ob.addRow(3);
    ob.addColumn(3);
    ob.print();
}