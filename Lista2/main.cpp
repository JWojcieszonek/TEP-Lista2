#include "CTable.h"
#include <iostream>
using namespace std;

int main()
{

	CTable c_tab_0, c_tab_1;
	c_tab_0.bSetNewSize(3);
	c_tab_1.bSetNewSize(4);
	c_tab_0.vFillTable(0);
	c_tab_1.vFillTable(50);
	c_tab_1.vSetValueAt(2, 123);
	//c_tab_1.bSetNewSize(8);
	cout << "ctab0" << endl;
	c_tab_0.printTable();
	cout << "ctab1" << endl;
	c_tab_1.printTable();
	CTable c_tab_2 = c_tab_0 + c_tab_1;
	cout << "po dodaniu" << endl;
	c_tab_2.printTable();
	
	c_tab_0 = c_tab_1;
	cout << "po przypisaniu" << endl;

	c_tab_0.printTable();
	c_tab_1.printTable();

	return 0;
}