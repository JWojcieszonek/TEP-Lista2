#include "CTable.h"
#include <iostream>
#include <ctype.h>
using namespace std;

const string CTable::DEFAULT_NAME = "Name";
const string CTable::DEFAULT_PASSWORD = "Qwerty";
const string::size_type CTable::MIN_PASSWORD_LENGTH = 5;
const int CTable::DEFAULT_TABLE_SIZE = 5;
const int CTable::MAX_TABLE_SIZE = 10000;

CTable::CTable()
{
	s_name = DEFAULT_NAME;
	s_password =DEFAULT_PASSWORD;
	cout << "bezp: " << s_name << endl;
	i_table_size = DEFAULT_TABLE_SIZE;
	pi_table = new int[i_table_size];
	vFillTableZeros(pi_table,i_table_size);
}

CTable::CTable(string sName, int iTableLen, string sPassword)
{
	if (sPassword.size() >= MIN_PASSWORD_LENGTH && bPasswordIsCorrect(sPassword))
		s_password = sPassword;
	else
		s_password = DEFAULT_PASSWORD;
	s_name = sName;
	cout << "parametr: " << s_name << endl;
	if (iTableLen > 0 && iTableLen < MAX_TABLE_SIZE)
		i_table_size = iTableLen;
	else
		i_table_size = DEFAULT_TABLE_SIZE;
	pi_table = new int[i_table_size];
	vFillTableZeros(pi_table,i_table_size);

}

CTable::CTable(string sName, int iTableLen,int start, string sPassword)
{
	if (sPassword.size() >= MIN_PASSWORD_LENGTH && bPasswordIsCorrect(sPassword))
		s_password = sPassword;
	else
		s_password = DEFAULT_PASSWORD;
	s_name = sName;
	cout << "parametr: " << s_name << endl;
	if (iTableLen > 0 && iTableLen < MAX_TABLE_SIZE)
		i_table_size = iTableLen;
	else
		i_table_size = DEFAULT_TABLE_SIZE;
	pi_table = new int[i_table_size];
	vFillTableZeros(pi_table, i_table_size);

}

CTable::CTable(const CTable &pcOther)
{
	s_name = pcOther.s_name + "_copy";
	cout << "kopiuj: " << s_name << endl;
	i_table_size = pcOther.i_table_size;
	pi_table = new int[i_table_size];
	for (int i = 0; i < i_table_size; i++)
	{
		pi_table[i] = pcOther.pi_table[i];
	}
	
}

CTable::~CTable()
{
	cout << "usuwam: " << s_name << endl;
	delete[] pi_table;
}

void CTable::vSetName(string sName)
{
	s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) // do poprawy
{
	if (iTableLen > 0 && iTableLen < MAX_TABLE_SIZE && iTableLen!=i_table_size)
	{
		int* pi_resized_table = new int[iTableLen];
		if (iTableLen > i_table_size)
		{
			for (int i = 0; i < i_table_size; i++)
			{
				pi_resized_table[i] = pi_table[i];
			}
			for (int i = i_table_size; i < (iTableLen); i++)
			{
				pi_resized_table[i] = 0;
			}
			delete[] pi_table;
			i_table_size = iTableLen;
			pi_table = pi_resized_table;
		}
		else
		{
			for (int i = 0; i < iTableLen; i++)
			{
				pi_resized_table[i] = pi_table[i];
			}
			delete[] pi_table;
			pi_table = pi_resized_table;
			i_table_size = iTableLen;
			
		}
		
		return true;
	}
	else
		return false;
}

string CTable::sGetPassword()
{
	return s_password;
}

void CTable::vSetValueAt(int iOffset, int iNewVal)
{
	if (iOffset > 0 && iOffset < MAX_TABLE_SIZE)
	{
		pi_table[iOffset] = iNewVal;
	}
}

void CTable::printTable()
{
	for (int i = 0; i < i_table_size; i++)
	{
		cout<< "[" <<i << "] = " <<pi_table[i] <<endl;
	}
}

bool CTable::bSetPassword(string sPassword)
{
	if (sPassword.size() >= MIN_PASSWORD_LENGTH && bPasswordIsCorrect(sPassword) && sPassword.compare(s_password) != 0)
	{
		s_password = sPassword;
		cout << "Nowe haslo: " << s_password << endl;
		return true;
	}
	else
	{
		cout << "Nieprawidlowe nowe haslo: " << sPassword << endl;
		return false;
	}
}

void CTable::vFillTableZeros( int * piTable, int iTableLen)
{
	for (int i = 0; i < iTableLen; i++)
	{
		pi_table[i] = 0;
	}
}

void CTable::vFillTable(int start)
{
	for (int i = 0; i <i_table_size; i++)
	{
		pi_table[i] = start+i;
	}
}

CTable CTable::operator+(CTable &cTableToAdd)
{
	CTable c_concatenated_table =  CTable(); //musi byæ na stercie
	
	c_concatenated_table.bSetNewSize(i_table_size + cTableToAdd.i_table_size);
	for (int i = 0; i < i_table_size; i++)
	{
		c_concatenated_table.pi_table[i] = pi_table[i];
	}
	for (int i = 0; i < cTableToAdd.i_table_size; i++)
	{
		c_concatenated_table.pi_table[i + i_table_size] = cTableToAdd.pi_table[i];
	}
	return c_concatenated_table;
}

void CTable::operator=(const CTable & pcOther)
{
	if (this != &pcOther)
	{
		s_name = pcOther.s_name + "_copy";
		cout << "operator=: " << s_name << endl;
		delete pi_table;
		i_table_size = pcOther.i_table_size;
		pi_table = new int[i_table_size];
		for (int i = 0; i < i_table_size; i++)
		{
			pi_table[i] = pcOther.pi_table[i];
		}
	}
}

bool CTable::bPasswordIsCorrect(string sPassword)
{
	bool b_hasUpper = false;
	bool b_hasLower = false;
	for (string::size_type i = 0; i < sPassword.size(); i++)
	{
		if (!isalpha(sPassword[i]))
		{
			return false;
		}
		else if (islower(sPassword[i]))
		{
			b_hasLower = true;
		}
		else  if (isupper(sPassword[i]))
		{
			b_hasUpper = true;
		}
	}
	return b_hasLower && b_hasUpper;
}

CTable * CTable::pcClone()
{
	return new CTable(this->s_name, this->i_table_size, this->s_password);
}

void CTable::v_mod_tab(CTable *pcTab, int iNewSize)
{
	if (iNewSize > 0 && iNewSize < MAX_TABLE_SIZE)
		pcTab->bSetNewSize(iNewSize);
}
void CTable::v_mod_tab(CTable cTab, int iNewSize)
{
	if (iNewSize > 0 && iNewSize < MAX_TABLE_SIZE)
		cTab.bSetNewSize(iNewSize);
}



