#pragma once
#include<fstream> 
#include"QInt.h"

void File_Process(string in, string out)//Hàm xử lý file nhập vào và xuất ra file như yêu cầu
{

	fstream fin, fout;
	fin.open(in, ios::in);
	fout.open(out, ios::out);
	while (!fin.eof())
	{
		string s;
		string result;
		getline(fin, s);
		string *a = new string[4];
		int found = 0;
		int i = 0;
		while (found != string::npos)
		{
			found = s.find(' ');
			a[i] = s.substr(0, found);
			s = s.substr(found + 1, s.length() - 1);
			i++;
		}
		if ((a[2] == "+") || (a[2] == "-") || (a[2] == "*") || (a[2] == "/"))
		{
			if (a[0] == "2")
			{
				int length = a[1].length();
				a[1].insert(0, 128 - a[1].length(), '0');
				bool* bit1 = StringToBool(a[1], 128);
				a[3].insert(0, 128 - a[3].length(), '0');
				bool* bit2 = StringToBool(a[3], 128);
				QInt cal;
				if (a[2] == "+")
					cal = SumQInt(BinToDec(bit1), BinToDec(bit2));
				else if (a[2] == "-")
					cal = SubtractQInt(BinToDec(bit1), BinToDec(bit2));
				else if (a[2] == "*")
					cal = MulQInt(BinToDec(bit1), BinToDec(bit2));
				else if (a[2] == "/")
					cal = DivQInt(BinToDec(bit1), BinToDec(bit2));
				bool* bit = DecToBin(cal);
				result = boolArrToString(bit, 128);

			}
			else if (a[0] == "10")
			{
				QInt cal;
				QInt x1, x2;
				Init(x1); Init(x2);
				StrToQInt(a[1], x1);
				StrToQInt(a[3], x2);
				if (a[2] == "+")
					cal = SumQInt(x1, x2);
				else if (a[2] == "-")
					cal = SubtractQInt(x1, x2);
				else if (a[2] == "*")
					cal = MulQInt(x1, x2);
				else if (a[2] == "/")
					cal = DivQInt(x1, x2);
				result = QIntToString(cal);
			}
			else if (a[0] == "16")
			{
				QInt cal;
				QInt x1, x2;
				Init(x1); Init(x2);
				a[1].insert(0, 32 - a[1].length(), '0');
				x1 = HexToDec(a[1]);
				a[3].insert(0, 32 - a[3].length(), '0');
				x2 = HexToDec(a[3]);
				if (a[2] == "+")
					cal = SumQInt(x1, x2);
				else if (a[2] == "-")
					cal = SubtractQInt(x1, x2);
				else if (a[2] == "*")
					cal = MulQInt(x1, x2);
				else if (a[2] == "/")
					cal = DivQInt(x1, x2);
				result = charArrToString(DecToHex(cal), 32);
			}
		}
		else if ((a[2] == "<<") || (a[2] == ">>"))
		{
			if (a[0] == "2")
			{
				a[1].insert(0, 128 - a[1].length(), '0');
				bool* bit = StringToBool(a[1], 128);
				if (a[2] == ">>")
				{
					bit = SHR_Bit(bit, stringToNum((a[3])[0]));
				}
				else
				{
					bit = SHL_Bit(bit, stringToNum((a[3])[0]));
				}
				result = boolArrToString(bit, 128);
			}
			else if (a[0] == "10")
			{
				QInt temp;
				Init(temp);
				StrToQInt(a[1], temp);
				bool* bit = DecToBin(temp);
				if (a[2] == ">>")
				{
					bit = SHR_Bit(bit, stringToNum((a[3])[0]));
				}
				else
				{
					bit = SHL_Bit(bit, stringToNum((a[3])[0]));
				}
				result = QIntToString(BinToDec(bit));
			}
			else
			{
				a[1].insert(0, 32 - a[1].length(), '0');
				bool* bit = HexToBin(a[1]);
				if (a[2] == ">>")
				{
					bit = SHR_Bit(bit, stringToNum((a[3])[0]));
				}
				else
				{
					bit = SHL_Bit(bit, stringToNum((a[3])[0]));
				}
				result = charArrToString(BinToHex(bit), 32);
			}
		}
		else if ((a[2] == "&") || (a[2] == "|") || (a[2] == "^"))
		{
			if (a[0] == "2")
			{
				a[1].insert(0, 128 - a[1].length(), '0');
				bool* bit1 = StringToBool(a[1], 128);
				a[3].insert(0, 128 - a[3].length(), '0');
				bool* bit2 = StringToBool(a[3], 128);
				if (a[2] == "&")
				{
					bit1 = AndBit(bit1, bit2);
				}
				else if (a[2] == "|")
				{
					bit1 = OrBit(bit1, bit2);
				}
				else
				{
					bit1 = XorBit(bit1, bit2);
				}
				result = boolArrToString(bit1, 128);
			}
			else if (a[0] == "10")
			{
				QInt temp1, temp2;
				Init(temp1);
				Init(temp2);
				StrToQInt(a[1], temp1);
				StrToQInt(a[3], temp2);
				bool *bit1 = DecToBin(temp1);
				bool *bit2 = DecToBin(temp2);
				if (a[2] == "&")
				{
					bit1 = AndBit(bit1, bit2);
				}
				else if (a[2] == "|")
				{
					bit1 = OrBit(bit1, bit2);
				}
				else
				{
					bit1 = XorBit(bit1, bit2);
				}
				result = QIntToString(BinToDec(bit1));
			}
			else
			{
				a[1].insert(0, 32 - a[1].length(), '0');
				bool* bit1 = HexToBin(a[1]);
				a[3].insert(0, 32 - a[3].length(), '0');
				bool* bit2 = HexToBin(a[3]);
				if (a[2] == "&")
				{
					bit1 = AndBit(bit1, bit2);
				}
				else if (a[2] == "|")
				{
					bit1 = OrBit(bit1, bit2);
				}
				else
				{
					bit1 = XorBit(bit1, bit2);
				}
				result = charArrToString(BinToHex(bit1), 32);
			}
		}
		else if (a[1] == "~")
		{
			if (a[0] == "2")
			{
				a[2].insert(0, 128 - a[2].length(), '0');
				bool* bit = StringToBool(a[2], 128);
				bit = NotBit(bit);
				result = boolArrToString(bit, 128);
			}
			if (a[0] == "10")
			{
				QInt temp;
				Init(temp);
				StrToQInt(a[2], temp);
				bool* bit = DecToBin(temp);
				bit = NotBit(bit);
				result = QIntToString(BinToDec(bit));
			}
			if (a[0] == "16")
			{
				a[2].insert(0, 32 - a[2].length(), '0');
				bool* bit = HexToBin(a[2]);
				bit = NotBit(bit);
				result = charArrToString(BinToHex(bit), 32);
			}
		}
		else if ((a[1] == "ror") || (a[1] == "rol"))
		{
			if (a[0] == "2")
			{
				if (a[1] == "ror")
				{
					a[2] = ROR_Bit(a[2]);
				}
				else
				{
					a[2] = ROL_Bit(a[2]);
				}
				result = a[2];
			}
			else if (a[0] == "10")
			{
				QInt temp;
				Init(temp);
				StrToQInt(a[2], temp);
				string x = boolArrToString(DecToBin(temp), 128);
				del_0_FrontString(x);
				if (a[1] == "ror")
				{
					x = ROR_Bit(x);
				}
				else
				{
					x = ROL_Bit(x);
				}
				x.insert(0, 128 - x.length(), '0');
				result = QIntToString(BinToDec(StringToBool(x, 128)));
			}
			else
			{
				a[2].insert(0, 32 - a[2].length(), '0');
				string x = boolArrToString(HexToBin(a[2]), 128);
				if (a[1] == "ror")
				{
					x = ROR_Bit(x);
				}
				else
				{
					x = ROL_Bit(x);
				}
				x.insert(0, 128 - x.length(), '0');
				result = charArrToString(BinToHex(StringToBool(x, 128)), 32);
			}
		}
		else
		{
			if (a[0] == "2")
			{
				a[2].insert(0, 128 - a[2].length(), '0');
				bool* bit = StringToBool(a[2], 128);
				if (a[1] == "10")
				{
					QInt temp = BinToDec(bit);
					result = QIntToString(temp);
				}
				else
				{
					result = charArrToString(BinToHex(bit), 32);
				}
			}
			else if (a[0] == "10")
			{
				QInt temp;
				Init(temp);
				StrToQInt(a[2], temp);
				if (a[1] == "2")
				{
					bool* bit = DecToBin(temp);
					result = boolArrToString(bit, 128);
				}
				else
				{

					result = charArrToString(DecToHex(temp), 32);
				}
			}
			else
			{
				a[2].insert(0, 32 - a[2].length(), '0');
				if (a[1] == "2")
				{
					bool* bit = HexToBin(a[2]);
					result = boolArrToString(bit, 128);
				}
				else
				{
					QInt temp = HexToDec(a[2]);
					result = QIntToString(temp);
				}
			}
		}
		del_0_FrontString(result);
		if (result == "")
			result = "0";
		fout << result << endl;
	}

}