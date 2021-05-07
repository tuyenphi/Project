#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;
//2
//HỆ 2
class QInt
{
public:
	long long arrBits[2];
	int length;
	QInt();
	QInt(string bits); //Hàm lưu chuỗi bits vào QInt

	void setBit(int i, int bit); //Hàm set bit
	int getBit(int i); //Hàm get bit
	string displayBits(); //In dãy bit
	void fixLength(); //Sửa độ dài in ra

	bool isNegative(); //Hàm kiểm tra số âm
	QInt offset2(); //Hàm chuyển về dạng bù 

	QInt& ror();
	QInt& rol();

	QInt operator &(QInt q1);
	QInt operator |(QInt q1);
	QInt operator ^(QInt q1);
	QInt operator ~(); //Hàm NOT

	
	QInt operator +(QInt x); //Hàm tính tổng nhị phân 
	QInt operator -(QInt x); //Hàm tính hiệu nhị phân
	QInt operator *(QInt x); //Hàm tính tích nhị phân
	QInt operator /(QInt x); //Hàm tính thương nhị phân

	QInt shiftLeft(int x); //Dịch trái
	QInt shiftRight(int x); //Dịch phải
};

//HỆ 10

//CÁC HÀM HỖ TRỢ
bool isSmaller(string a, string b); //So sánh a < b
bool isSmallerAndEqual(string a, string b); //So sánh a <= b
string estimated(string x1, string x2); //Hàm ước lượng phần nguyên phép chia

//HÀM TOÁN TỬ
string sumDec(string x1, string x2); //Tính tổng hệ 10
string subDec(string x1, string x2); //Tính hiệu hệ 10
string multiDec(string x1, string x2); //Tính tích hệ 10
string divDec(string x1, string x2);//Tính thương hệ 10

//HỆ 16

//HÀM TOÁN TỬ
string sumHex(string x1, string x2);//Hàm cộng hệ 16
string subHex(string x1, string x2);//Hàm trừ hệ 16
string multiHex(string x1, string x2);//Hàm nhân hệ 16
string divHex(string x1, string x2);//Hàm chia hệ 16