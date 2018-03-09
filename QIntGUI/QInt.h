#pragma once
#include"Sol_String.h"

struct QInt
{
	int data[4];
};

void Init(QInt &a);
void SetBit(QInt &a, int bit, int i);//Set bit tại vị trí thứ i của số QInt a
void readbit(int a, int *x);//Đọc các bit của số nguyên a đưa vào con trỏ x
bool* SumBit(bool*a, bool*b);//Trả về dãy bit tổng của 2 dãy bit truyền vào
void StrToQInt(string X, QInt &a);//Nhập số QInt a từ chuỗi số X
string QIntToString(QInt x);//Khởi tạo QInt bằng 0
int GetBit(QInt x, int i);//Trả về bit thứ i của số QInt x
bool*AndBit(bool*a, bool*b);//Phép toán logic AND giữa 2 dãy bit a và b
bool*OrBit(bool*a, bool*b);//Phép toán logic OR giữa 2 dãy bit a và b
bool*XorBit(bool*a, bool*b);//Phép toán logic XOR giữa 2 dãy bit a và b
bool*NotBit(bool*a);//Phép toán logic NOT dãy bit a
bool *SHL_Bit(bool*a, int k);//Phép dịch trái dãy bit
bool* SHR_Bit(bool*a, int k);//Phép dịch phải dãy bit
string ROL_Bit(string temp);//Phép xoay trái dãy bit
string ROR_Bit(string temp);//Phép xoay phải dãy bit
QInt TwoComplement(QInt x);//Trả về số bù 2 của số QInt x

char *BinToHex(bool *bit);//Chuyển từ hệ cơ số 2 sang hệ cơ số 16
QInt BinToDec(bool *bit);//Chuyển từ hệ cơ số 2 sang hệ cơ số 10
bool *DecToBin(QInt a);//Chuyển từ hệ cơ số 10 sang hệ cơ số 2
char *DecToHex(QInt x);//Chuyển từ hệ cơ số 10 sang hệ cơ số 16
bool *HexToBin(string);//Chuyển từ hệ cơ số 16 sang hệ cơ số 2
QInt HexToDec(string);//Chuyển từ hệ cơ số 16 sang hệ cơ số 10

QInt SumQInt(QInt a, QInt b);//Trả về tổng 2 số QInt truyền vào (a+b)
QInt SubtractQInt(QInt a, QInt b);//Trả về hiệu 2 số QInt truyền vào (a-b)
QInt MulQInt(QInt a, QInt b);//Trả về tích 2 số QInt truyền vào (a*b)
QInt DivQInt(QInt, QInt);//Trả về thương 2 số QInt truyền vào (a/b)

QInt DivQInt(QInt a, QInt b)
{
	//Q/M
	bool* bit_a = DecToBin(a);
	bool* bit_b = DecToBin(b);
	QInt a_unsigned;
	QInt b_unsigned;
	if (bit_a[0])
		a_unsigned = TwoComplement(a);
	else
		a_unsigned = a;
	if (bit_b[0])
		b_unsigned = TwoComplement(b);
	else
		b_unsigned = b;
	QInt Sol;
	int k = 128;
	Init(Sol);
	string Q, M, A;

	Q = boolArrToString(DecToBin(a_unsigned), 128);
	M = boolArrToString(DecToBin(b_unsigned), 128);
	A.insert(0, 128, '0');
	string Cal = "";
	while (k > 0)
	{
		Cal = A + Q;
		Cal.erase(Cal.begin() + 1);
		Cal.insert(Cal.end(), '0');
		A = Cal.substr(0, 128);
		Q = Cal.substr(128, 128);

		A = boolArrToString(SumBit(StringToBool(A, 128), DecToBin(TwoComplement(b_unsigned))), 128);
		if (A[0] == '1')
		{
			Q[127] = '0';
			A = boolArrToString(SumBit(StringToBool(A, 128), DecToBin(b_unsigned)), 128);
		}
		else
			Q[127] = '1';
		k--;
	}
	Sol = BinToDec(StringToBool(Q, 128));
	if ((bit_a[0] && !bit_b[0]) || (!bit_a[0] && bit_b[0]))
		return TwoComplement(Sol);
	return Sol;
}

QInt HexToDec(string x)
{
	bool *bin = new bool[128];
	bin = HexToBin(x);
	QInt Sol = BinToDec(bin);
	return Sol;
}

bool *HexToBin(string x)
{
	string temp;
	string bin_string;
	bool *bin = new bool[128];
	while (!x.empty())
	{
		temp = x.substr(0, 1);

		if (temp == "0")
			bin_string += "0000";
		if (temp == "1")
			bin_string += "0001";
		if (temp == "2")
			bin_string += "0010";
		if (temp == "3")
			bin_string += "0011";
		if (temp == "4")
			bin_string += "0100";
		if (temp == "5")
			bin_string += "0101";
		if (temp == "6")
			bin_string += "0110";
		if (temp == "7")
			bin_string += "0111";
		if (temp == "8")
			bin_string += "1000";
		if (temp == "9")
			bin_string += "1001";
		if (temp == "A")
			bin_string += "1010";
		if (temp == "B")
			bin_string += "1011";
		if (temp == "C")
			bin_string += "1100";
		if (temp == "D")
			bin_string += "1101";
		if (temp == "E")
			bin_string += "1110";
		if (temp == "F")
			bin_string += "1111";
		x.erase(0, 1);
	}
	bin = StringToBool(bin_string, 128);
	return bin;
}

QInt TwoComplement(QInt x)
{
	QInt a;
	Init(a);
	QInt one;
	Init(one);
	StrToQInt("1", one);
	bool* bit = DecToBin(x);
	string temp = boolArrToString(bit, 128);
	bool* bit1 = DecToBin(one);
	string temp_ = boolArrToString(bit1, 128);
	for (int i = 0; i < 128; i++)
	{
		if (bit[i] == true)
			bit[i] = false;
		else
			bit[i] = true;
	}
	bool *bu2 = new bool[128];
	bu2 = SumBit(bit, bit1);
	string _temp = boolArrToString(bu2, 128);
	for (size_t i = 0; i < 128; i++)
	{
		SetBit(a, bu2[i], i);
	}
	return a;
}

QInt SubtractQInt(QInt a, QInt b)
{
	return SumQInt(a, TwoComplement(b));
}

inline QInt MulQInt(QInt a, QInt b)
{
	//M*Q
	QInt Sol;
	int k = 128;
	Init(Sol);
	string A;
	string Q_1 = "0";
	A.insert(0, 128, '0');
	string Q = boolArrToString(DecToBin(b), 128);

	string Cal = "";

	while (k > 0)
	{
		QInt TwoComplement_a = TwoComplement(a);

		char Q_0 = Q[Q.length() - 1];
		if (Q_1 == "0" && Q_0 == '1')
			A = boolArrToString(SumBit(StringToBool(A, 128), DecToBin(TwoComplement_a)), 128);
		if (Q_1 == "1" && Q_0 == '0')
			A = boolArrToString(SumBit(StringToBool(A, 128), DecToBin(a)), 128);

		Cal = A + Q + Q_1;
		Cal.erase(Cal.end() - 1);
		Cal.insert(0, 1, '0');

		A = Cal.substr(0, 128);
		Q = Cal.substr(128, 128);
		Q_1 = Cal[256];
		k = k - 1;
	}
	Cal = Cal.substr(128, 255);
	Sol = BinToDec(StringToBool(Cal, 128));
	return Sol;
}

QInt SumQInt(QInt a, QInt b)
{
	bool* bit_a = DecToBin(a);
	bool* bit_b = DecToBin(b);
	return BinToDec(SumBit(bit_a, bit_b));
}

void Init(QInt &a)
{
	for (size_t i = 0; i < 4; i++)
	{
		a.data[i] = 0;
	}

}

void SetBit(QInt &a, int bit, int i)
{
	if (bit == 1)
	{
		int temp = (1 << (32 - 1 - i));
		if (i < 32)
			a.data[0] = temp | a.data[0];
		else if (i >= 32 && i <= 63)
			a.data[1] = temp | a.data[1];
		else if (i >= 64 && i <= 95)
			a.data[2] = temp | a.data[2];
		else if (i >= 96 && i <= 127)
			a.data[3] = temp | a.data[3];
	}
}

void readbit(int a, int *x)
{
	for (size_t i = 0; i < 32; i++)
	{
		x[i] = ((a >> (32 - 1 - i)) & 1);
	}
}

bool *DecToBin(QInt a)
{
	int *x = new int[32];
	bool* bin = new bool[128];
	int temp = 0;
	for (size_t i = 0; i < 4; i++)
	{
		readbit(a.data[i], x);
		for (size_t j = 0; j < 32; j++)
		{
			bin[temp] = x[j];
			temp++;
		}
	}
	return bin;
}

void StrToQInt(string X, QInt &a)
{
	if (X[0] == '-')
	{
		X.erase(0, 1);
		bool* listbit = new bool[128];
		bool* bit1 = new bool[128];
		for (int i = 0; i < 128; i++)//khoi tao day bit false
		{
			listbit[i] = false;
			bit1[i] = false;
		}
		bit1[127] = 1;//tao day bit cua so 1
		int i = 127; // bắt đầu set bit tại vị trí cuối cùng
		while (X != "0")
		{
			int bit = (X[X.length() - 1] - 48) % 2; // Tính phần dư
													//SetBit(a, bit, i); // Tạo bit (biến bit) tại vị trí bit i của biến a
			if (bit == 1)
				listbit[i] = true;
			X = StrDiv2(X); // Chia chuỗi số X cho 2
			i--;
		}
		for (int i = 0; i < 128; i++)//dao bit
		{
			if (listbit[i] == true)
				listbit[i] = false;
			else
				listbit[i] = true;
		}
		bool *bu2 = new bool[128];
		bu2 = SumBit(listbit, bit1);
		for (size_t i = 0; i < 128; i++)
		{
			SetBit(a, bu2[i], i);
		}
		//		a = BinToDec(SumBit(listbit, bit1));
	}
	else
	{
		int i = 127; // bắt đầu set bit tại vị trí cuối cùng
		while (X != "0")
		{
			int bit = (X[X.length() - 1] - 48) % 2; // Tính phần dư
			SetBit(a, bit, i); // Tạo bit (biến bit) tại vị trí bit i của biến a
			X = StrDiv2(X); // Chia chuỗi số X cho 2
			i--;
		}
	}
}

string QIntToString(QInt x)
{
	string s = "0";
	if (GetBit(x, 0) == 1)
	{
		s = add(s, LuyThua2(127));
		for (int i = 1; i < 128; i++)
		{
			if (GetBit(x, i) == 1)
				s = subtract(s, LuyThua2(127 - i));
		}
		s.insert(0, 1, '-');
	}
	else
	{
		for (int i = 1; i < 128; i++)
		{
			if (GetBit(x, i) == 1)
				s = add(s, LuyThua2(127 - i));
		}

	}
	return s;
}

int GetBit(QInt x, int i)
{
	if (i < 0 || i>127)
	{
		printf("ERROR !");
		return-1;
	}
	else
	{
		int a, b;
		a = i / 32;
		b = i % 32;
		return (x.data[a] >> (127 - b) & 1);
	}
}


bool * AndBit(bool * a, bool * b)
{
	bool*c = new bool[128];
	for (size_t i = 0; i < 128; i++)
	{
		if (a[i] == 1 && b[i] == 1)
			c[i] = 1;
		else
			c[i] = 0;
	}
	return c;
}

inline bool * OrBit(bool * a, bool * b)
{
	bool*c = new bool[128];
	for (size_t i = 0; i < 128; i++)
	{
		if (a[i] == 1 || b[i] == 1)
			c[i] = 1;
		else
			c[i] = 0;
	}
	return c;
}

inline bool * XorBit(bool * a, bool * b)
{
	bool*c = new bool[128];
	for (size_t i = 0; i < 128; i++)
	{
		if (a[i] != b[i])
			c[i] = 1;
		else
			c[i] = 0;
	}
	return c;
}

inline bool * NotBit(bool * a)
{
	bool*c = new bool[128];
	for (size_t i = 0; i < 128; i++)
	{
		if (a[i] != true)
			c[i] = 1;
		else
			c[i] = 0;
	}
	return c;
}

inline bool * SHL_Bit(bool * a, int k)
{
	bool*c = new bool[128];
	string temp = boolArrToString(a, 128);
	temp.erase(0, k);
	temp.insert(temp.end(), k, '0');
	c = StringToBool(temp, 128);
	return c;
}

inline bool * SHR_Bit(bool * a, int k)
{
	bool*c = new bool[128];
	string temp = boolArrToString(a, 128);
	temp.erase(temp.end() - k, temp.end());
	if (temp[0] == '0')
		temp.insert(0, k, '0');
	else
		temp.insert(0, k, '1');
	c = StringToBool(temp, 128);
	return c;
}

string ROL_Bit(string temp)
{

	char Bit_0 = temp[0];
	temp.erase(0, 1);
	temp.insert(temp.end(), 1, Bit_0);
	return temp;
}

string ROR_Bit(string temp)
{
	char Bit_0 = temp[temp.length() - 1];
	temp.erase(temp.end() - 1);
	temp.insert(0, 1, Bit_0);
	return temp;
}


char *BinToHex(bool *bit)
{
	char*a = new char[32];
	for (int i = 127; i >= 0; i = i - 4)
	{
		string temp = "";
		for (int j = 3; j >= 0; j--)
			temp += BoolToStr(bit[i - j]);
		int sum_temp = (stringToNum(temp[3]) + stringToNum(temp[2]) * 2 + stringToNum(temp[1]) * 4 + stringToNum(temp[0]) * 8);
		if (sum_temp < 10)
			a[(i + 1) / 4 - 1] = numToString(sum_temp);
		else
			a[(i + 1) / 4 - 1] = numToString(sum_temp + 7);
	}
	return a;
}

QInt BinToDec(bool *bit)
{
	QInt a;
	Init(a);
	string s = "0";
	if (bit[0])
	{
		s = add(s, LuyThua2(127));
		for (int i = 1; i < 128; i++)
		{
			if (bit[i])
				s = subtract(s, LuyThua2(127 - i));
		}
		s.insert(0, 1, '-');
	}
	else
	{
		for (int i = 1; i < 128; i++)
		{
			if (bit[i])
				s = add(s, LuyThua2(127 - i));
		}
	}
	StrToQInt(s, a);
	return a;
}

char *DecToHex(QInt x)
{
	return BinToHex(DecToBin(x));
}

bool* SumBit(bool*a, bool*b)
{
	bool*s = new bool[128];
	int temp = false;
	for (int i = 127; i >= 0; i--)
	{
		if ((a[i]) && (b[i]))
		{
			if (!temp)
			{
				s[i] = false;
				temp = true;
			}
			else
			{
				s[i] = true;
				temp = true;
			}
		}
		else if (((a[i]) && (!b[i])) || ((!a[i]) && (b[i])))
		{
			if (!temp)
			{
				s[i] = true;
				temp = false;
			}
			else
			{
				s[i] = false;
				temp = true;
			}
		}
		else if ((!a[i]) && (!b[i]))
		{
			if (!temp)
			{
				s[i] = false;
				temp = false;
			}
			else
			{
				s[i] = true;
				temp = false;
			}
		}
	}
	return s;
}


