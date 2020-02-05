#pragma once
#include <string>
using namespace std;


class CTable
{
public:
	CTable();
	CTable(string sName, int iTableLen, string sPawssord);
	CTable(string sName, int iTableLen,int start,string sPawssord);
	CTable(const CTable &pcOther);
	~CTable();
	void vSetName(string sName);
	bool bSetNewSize(int iTableLen);
	bool bSetPassword(string sPassword);
	string sGetPassword();
	void vSetValueAt(int iOffset, int iNewVal);
	void printTable();

	CTable *pcClone();
	static void v_mod_tab(CTable *pcTab, int iNewSize);
	static void v_mod_tab(CTable cTab, int iNewSize);

	static const string DEFAULT_NAME;
	static const string DEFAULT_PASSWORD;
	static const string::size_type MIN_PASSWORD_LENGTH;
	static const int DEFAULT_TABLE_SIZE;
	static const int MAX_TABLE_SIZE;
	void vFillTable(int start);
	CTable operator+(CTable &cTableToAdd);
	void operator=(const CTable &pcOther);
	
	

private:
	string s_name;
	int i_table_size;
	int *pi_table;
	string s_password;
	
	void vFillTableZeros(int* piTable, int iTableLen);
	bool bPasswordIsCorrect(string sPassword);
};

