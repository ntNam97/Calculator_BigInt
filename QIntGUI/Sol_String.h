#pragma once
#include<iostream>
#include<string>
using namespace std;

void chuanHoa(string &, string &);//Chuẩn hóa độ dài 2 chuỗi
int stringToNum(char);//Chuyển ký tự sang số
char numToString(int);//Chuyển sô sang chuỗi
void del_0_FrontString(string&);//Xóa các số 0 ở đầu của 1 chuỗi số

string add(string, string);//Cộng 2 chuỗi
string subtract(string, string);//Trừ 2 chuỗi
string multi_sml(char, string);//Nhân 1 chữ số với nhiều chữ số
string multi(string, string);// Nhân 2 chuỗi số nguyên lớn
string StrDiv2(string);//Chia chuỗi số nguyên cho 2
string LuyThua2(int k);//Trả về chuỗi 2^k

char BoolToStr(bool x);//Chuyển phần tử kiểu bool sang char
string boolArrToString(bool *, int);//Chuyển mảng kiểu bool sang chuỗi
string charArrToString(char *, int);//chuyển từ mảng ký tự kiểu char sang chuỗi string
bool *StringToBool(string, int);//Chuyển từ chuỗi ký tự sang mảng kiểu bool 

bool *StringToBool(string x, int n)
{
	bool *Sol = new bool[n];
	for (size_t i = 0; i < n; i++)
	{
		if (x[i] == '0')
			Sol[i] = false;
		else
			Sol[i] = true;
	}
	return Sol;
}

int stringToNum(char c)
{
	return c - '0';
}

char numToString(int n)
{
	return (char)(n + 48);
}

void del_0_FrontString(string &x)
{
	while (x[0] == '0')
		x.erase(0, 1);
}

void chuanHoa(string &a, string &b)
{
	if (a.length() > b.length())
		b.insert(b.begin(), a.length() - b.length(), '0');
	if (a.length() < b.length())
		a.insert(a.begin(), b.length() - a.length(), '0');
}

string add(string a, string b)
{
	string s = "";
	chuanHoa(a, b);
	int l = a.length();

	int temp = 0;
	for (int i = l - 1; i >= 0; i--)   // duyet va cong
	{
		temp = stringToNum(a[i]) + stringToNum(b[i]) + temp;    // tinh tong tung doi mot
		s.insert(0, 1, numToString(temp % 10));         // gan phan don vi vao
		temp = temp / 10;     // lay lai phan hang chuc
	}
	if (temp>0)  // neu hang chuc > 0 thi them vao KQ
	{
		s.insert(0, 1, numToString(temp));
	}
	return s;
}

string subtract(string a, string b)
{
	string s = "";
	chuanHoa(a, b);
	int temp = 0;

	for (int i = b.length() - 1; i >= 0; i--)
	{
		int flag = 0;
		int int_a = stringToNum(a[i]);
		int int_b = stringToNum(b[i]);
		if (int_a < int_b)
		{
			int_a += 10;
			flag = 1;
		}
		s.insert(0, 1, numToString((int_a - int_b)) - temp);
		if (flag == 1)
			temp = 1;
		else
			temp = 0;
	}
	del_0_FrontString(s);
	return s;
}

string multi_sml(char a, string b)
{
	string s = "";
	int temp = 0;
	for (int i = b.length() - 1; i >= 0; i--)
	{
		temp = stringToNum(a) * stringToNum(b[i]) + temp;
		s.insert(0, 1, numToString(temp % 10));
		temp = temp / 10;
	}

	if (temp>0)
	{
		s.insert(0, 1, numToString(temp));
	}
	return s;
}

string multi(string a, string b)
{
	string s = "";
	int l = a.length();
	string s1;

	for (int i = l - 1; i >= 0; i--)   // nhan tung chu so cua a voi b sau do cong don vao
	{
		s1 = multi_sml(b[i], a);   // nhan tung so cua a voi b
		s1.insert(s1.end(), l - i - 1, '0');
		s = add(s, s1);  // cong don theo cach cong so lon
	}
	return s;
}

char BoolToStr(bool x)
{
	if (x)
		return'1';
	return '0';
}

string LuyThua2(int k)
{
	string a = "1";
	for (int i = 0; i < k; i++)
	{
		a = multi_sml('2', a);
	}
	return a;
}

string StrDiv2(string a)
{
	int cout = 0;
	string s = "";
	string kq = "";
	string temp1 = "";
	string temp2 = "";
	int sochia = stoi("2");
	del_0_FrontString(a);
	int l = a.length();
	if (a.length() == 1 && a < "2")
		return "0";
	while (true)
	{
		if ((a[0] == '0'))//bat dau bang 0
		{
			kq = "0";
			s += kq;
			cout++;
		}
		else if ((a[0] - '0' < 2) && (cout == l - 1))//neu chi con mot chu so va nho hon 2
		{
			kq = "0";
			s += kq;
			cout++;
		}
		else if ((a[0] - '0' < 2) && (temp2 == "") && cout>0 && cout<l - 1)// nếu số đầu nhỏ hơn 2, không phải số đầu hoặc cuối, và số dư phép toán trước bằng không
		{
			cout += 2;
			string sobichia = a.substr(0, 2);
			kq = to_string(stoi(sobichia) / sochia);
			s += "0";
			s += kq;
		}
		else if (a[0] - '0' < 2)// lấy 2 số đầu chia cho b nếu số đầu nhỏ hơn b
		{
			cout += 2;
			string sobichia = a.substr(0, 2);
			kq = to_string(stoi(sobichia) / sochia);
			s += kq;
		}
		else
		{
			cout++;
			kq = to_string((a[0] - '0') / sochia);
			s += kq;
		}

		//Khối lệnh sau nhầm nhân lại và trừ được a mới để tiếp tục chia
		string multback = multi("2", kq);
		if (a.length() > multback.length())
		{
			temp1 = a.substr(0, multback.length());
			temp2 = subtract(temp1, multback);
			del_0_FrontString(temp2);
			if ((temp2 == "" || (temp2 == "1" && temp2.length() == 1)) && cout == l)//nếu đã chia hết các phần tử trong chuỗi
				break;
			a = temp2 + a.substr(multback.length(), a.length());//gán chuỗi còn lại sau phép toán
			if (temp2 != "")
				cout--;
		}
		else
		{
			a = subtract(a, multback);
			del_0_FrontString(a);
			if ((a == "" || (a == "1" && a.length() == 1)) && cout == l)
				break;
			if (a != "")
				cout--;
		}
	}
	return s;
}

inline string boolArrToString(bool * x, int n)
{
	string Sol = "";
	for (size_t i = 0; i < n; i++)
	{
		if (x[i] == true)
			Sol += "1";
		else
			Sol += "0";
	}
	return Sol;
}

inline string charArrToString(char *x, int n)
{
	string Sol = "";
	for (size_t i = 0; i < n; i++)
	{
		Sol.insert(Sol.end(), 1, x[i]);
	}
	return Sol;
}
