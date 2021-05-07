#include "Convert.h"
//4
//HỆ 10

//CÁC HÀM HỖ TRỢ

//So sánh a < b
bool isSmaller(string a, string b)
{
	int len1 = a.length(), len2 = b.length();
	if (len1 < len2)
		return true;
	if (len2 < len1)
		return false;
	for (int i = 0; i < len1; i++)
	{
		if (a[i] < b[i])
			return true;
		else if (a[i] > b[i])
			return false;
	}
	return false;
}

//So sánh a <= b
bool isSmallerAndEqual(string a, string b)
{
	int len1 = a.length(), len2 = b.length();
	if (len1 < len2)
		return true;
	if (len2 < len1)
		return false;
	for (int i = 0; i < len1; i++)
	{
		if (a[i] < b[i])
			return true;
		else if (a[i] > b[i])
			return false;
	}
	return true;
}

//Hàm ước lượng phần nguyên phép chia
string estimated(string x1, string x2)
{
	if (isSmaller(x1, x2))
		return "0";
	int i = 0;
	string tmp;
	while (isSmallerAndEqual(tmp, x1))
	{
		//Lấy x2 nhân từ từ lên, nếu >= x1 thì dừng
		tmp = multiDec(x2, to_string(++i));
	}
	return to_string(--i);
}

//CÁC HÀM TOÁN TỬ

//Hàm tính tổng hệ 10
string sumDec(string x1, string x2)
{
	//Kí tự dấu âm
	string nega = "";
	//2 thằng đều âm
	if (x1[0] == '-' && x2[0] == '-')
	{
		x1 = x1.substr(1);
		x2 = x2.substr(1);
		nega = '-';
	}
	//x1 âm + x2 dương
	else if (x1[0] == '-' && x2[0] != '-')
	{
		x1 = x1.substr(1);
		return subDec(x2, x1);
	}
	//x1 dương + x2 âm
	else if (x1[0] != '-' && x2[0] == '-')
	{
		x2 = x2.substr(1);
		return subDec(x1, x2);
	}

	//Bảo đảm chuỗi x2 là chuỗi dài hơn
	if (x1.length() > x2.length())
	{
		swap(x1, x2);
	}
	//Khởi tạo chuỗi kết quả
	string result = "";
	int len1 = x1.length(), len2 = x2.length();
	//Đảo 2 chuỗi để cộng từ dưới lên
	reverse(x1.begin(), x1.end());
	reverse(x2.begin(), x2.end());
	//Số nhớ
	int carry = 0;
	for (int i = 0; i < len1; i++)
	{
		int sum = (x1[i] - '0') + (x2[i] - '0') + carry;
		//Ghi phần đơn vị
		result.push_back(sum % 10 + '0');
		//Nhớ phần chục
		carry = sum / 10;
	}
	//Tiến hành cộng tiếp chuỗi 2 sau khi chuỗi 1 kết thúc
	for (int i = len1; i < len2; i++)
	{
		int sum = (x2[i] - '0') + carry;
		result.push_back(sum % 10 + '0');
		carry = sum / 10;
	}
	//Nếu chuỗi đã kết thúc nhưng số nhớ vẫn còn thì ghi thêm số nhớ vào đầu  
	if (carry) 
	{
		result.push_back(carry + '0');
	}
	//Loại các kí tự 0 ngay đầu
	while (result.length() > 1 && result[result.length() - 1] == '0')
		result.pop_back();
	//Đảo ngược chuỗi vừa cộng lại đúng hiển thị
	reverse(result.begin(), result.end());
	return nega+result;
}

//Tính hiệu hệ 10
string subDec(string x1, string x2)
{
	//Kí tự số âm
	string nega = "";
	if (x1[0] != '-' && x2[0] != '-')
	{
		if (isSmaller(x1, x2))
		{
			nega = "-";
		}
	}
	//2 thằng đều âm
	else if (x1[0] == '-' && x2[0] == '-')
	{
		x2 = x2.substr(1);
		return sumDec(x1, x2);
	}
	//x1 âm + x2 dương
	else if(x1[0]=='-' && x2[0]!='-')
	{
		x2 = "-" + x2;
		return sumDec(x1, x2);
	}
	//x1 dương + x2 âm
	else if (x1[0] != '-' && x2[0] == '-')
	{
		x2 = x2.substr(1);
		return sumDec(x1, x2);
	}
	

	//Phải chắc chắn x1 > x2
	if (isSmaller(x1, x2))
	{
		swap(x1, x2);
	}
	//Khởi tạo chuỗi kết quả
	string result = "";
	int len1 = x1.length(), len2 = x2.length();

	//Đảo chuỗi 
	reverse(x1.begin(), x1.end());
	reverse(x2.begin(), x2.end());
	//Số nhớ
	int carry = 0;
	for (int i = 0; i < len2; i++)
	{
		int sub = (x1[i] - '0') - (x2[i] - '0') - carry;

		//Nếu kết quả trừ < 0 thì + 10 và số nhớ = 1
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		//Nếu không thì số nhớ = 0
		else carry = 0;


		result.push_back(sub + '0');
	}

	//Tiếp tục với độ dài còn lại của chuỗi 1 sau khi chuỗi 2 hết
	for (int i = len2; i < len1; i++)
	{
		int sub = (x1[i] - '0') - carry;
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else carry = 0;

		result.push_back(sub + '0');
	}
	//Loại các kí tự 0 ngay đầu
	while (result.length() > 1 && result[result.length() - 1] == '0')
		result.pop_back();
	//Đảo lại để hiển thị kết quả
	reverse(result.begin(), result.end());
	return nega+result;
}

//Tính tích hệ 10
string multiDec(string x1, string x2)
{
	//Kí tự dấu âm
	string nega = "";
	//2 thằng đều âm
	if (x1[0] == '-' && x2[0] == '-')
	{
		x1 = x1.substr(1);
		x2 = x2.substr(1);
	}
	//1 âm 1 dương
	else if (x1[0] == '-' && x2[0] != '-')
	{
		x1 = x1.substr(1);
		nega = "-";
	}
	else if (x1[0] != '-'&&x2[0] == '-')
	{
		x2 = x2.substr(1);
		nega = "-";
	}

	reverse(x1.begin(), x1.end());
	reverse(x2.begin(), x2.end());

	vector<int> m(x1.length() + x2.length(), 0);

	for (int i = 0; i < x1.length(); i++)
	{
		for (int j = 0; j < x2.length(); j++)
		{
			m[i + j] += (x1[i] - '0')*(x2[j] - '0');
		}
	}

	string result = "";
	for (int i = 0; i < m.size(); i++)
	{
		int digit = m[i] % 10;
		int carry = m[i] / 10;
		if (i + 1 < m.size())
		{
			m[i + 1] += carry;
		}
		result += digit + '0';
	}

	while (result.length() >= 2 && result[result.length() - 1] == '0')
		result.pop_back();


	reverse(result.begin(), result.end());
	return nega+result;
}

//Tính thương hệ 10
string divDec(string x1, string x2)
{
	//Kí tự dấu âm
	string nega = "";
	//2 thằng đều âm
	if (x1[0] == '-' && x2[0] == '-')
	{
		x1 = x1.substr(1);
		x2 = x2.substr(1);
	}
	//1 âm 1 dương
	else if (x1[0] == '-' && x2[0] != '-')
	{
		x1 = x1.substr(1);
		nega = "-";
	}
	else if (x1[0] != '-'&&x2[0] == '-')
	{
		x2 = x2.substr(1);
		nega = "-";
	}

	//x1 nhỏ hơn x2 thì thương = 0
	if (isSmaller(x1, x2))
		return "0";
	//Lấy n kí tự bằng với độ dài của chuỗi cần chia
	string tmp = x1.substr(0, x2.length());
	int i = x2.length();
	string result = "";
	//Phải cho i bằng độ dài chuỗi 1 để xét kí tự cuối
	while (i <= x1.length())
	{
		//Chia lấy nguyên
		string digit = estimated(tmp, x2);
		//Lưu nguyên vào kết quả
		result += digit ;
		//Tính phần dư và + với kí tự tiếp theo của chuỗi
		tmp = subDec(tmp, multiDec(x2, digit)) + x1[i++];
	} 
	//Loại các số 0 ngay đầu
	while (result[0] == '0')
		result = result.substr(1);
	return nega+result;
}

//HỆ 2

//CÁC HÀM HỖ TRỢ

//Hàm khởi tạo
QInt::QInt()
{
	arrBits[0] = 0;
	arrBits[1] = 0;
	length = 0;
}

//Hàm lưu chuỗi bits vào QInt
QInt::QInt(string bits)
{
	arrBits[0] = 0;
	arrBits[1] = 0;
	length = bits.length()-1;
	reverse(bits.begin(), bits.end()); //Đảo chuỗi
	for (int i = 0; i<=length; i++)
		setBit(i, bits[i] - '0');
}

//Hàm set bit
void QInt::setBit(int i, int bit)
{
	//Ép kiểu để đảm bảo đúng kiểu dữ liệu int64
	if (i < 64)
	{
		if(bit==0)
			arrBits[1] = ~((__int64)1 << i) & arrBits[1];
		else 
			arrBits[1] = ((__int64)1 << i) | arrBits[1];

	}
	else if(i>=64 && i<=127)
	{
		if (bit==0)
			arrBits[0] = ~((__int64)1 << (i - 64)) & arrBits[0];
		else
			arrBits[0] = ((__int64)1 << (i-64)) | arrBits[0];
	}
	else
	{
		length = -1;
		return;
	}
}

//Hàm get bit
int QInt::getBit(int i)
{
	//Ép kiểu để đảm bảo đúng kiểu dữ liệu int64
	if (i < 64)
	{
		return (arrBits[1] >> i) & (__int64)1;
	}
	else
		return (arrBits[0] >> (i-64)) & (__int64)1;
}

//In dãy bit
string QInt::displayBits()
{
	string result = "";
	if (length == -1)
	{
		return "OVERFLOW!!" ; //Nếu độ dài là -1 thì là TH overflow
	}
	for (int i = length; i >= 0; i--)
	{
		result.push_back(getBit(i)+'0');
	}
	return result;
}

//Sửa độ dài in ra
void QInt::fixLength()
{
	//Chạy từ vị trí 127 đến 0 , gặp số 1 thì dừng 
	for (int i = 127; i >= 0; i--)
	{
		if (getBit(i))
		{ 
			length = i;
			return;
		}
	}
	length = 0;
}

//Ham AND
QInt QInt:: operator &(QInt q1) {
	QInt ans = *this;
	int bit, bit1;
	for (int i = 0; i <= 127; i++)
	{
		bit = ans.getBit(i);
		bit1 = q1.getBit(i);
		if ((bit != bit1) | (bit == 0 && bit1 == 0)) {
			ans.setBit(i, 0);
		}
		else
			ans.setBit(i, 1);
	}
	ans.fixLength();
	return ans;
}

//Ham OR
QInt QInt::  operator |(QInt q1) {
	QInt ans = *this;
	int bit, bit1;
	for (int i = 0; i <= 127; i++)
	{
		bit = ans.getBit(i);
		bit1 = q1.getBit(i);
		if ((bit != bit1) | (bit == 1 && bit1 == 1)) {
			ans.setBit(i, 1);
		}
		else
			ans.setBit(i, 0);
	}
	ans.fixLength();
	return ans;
}

//Ham XOR
QInt QInt:: operator ^(QInt q1) {
	QInt ans = *this;
	int bit, bit1;
	for (int i = 0; i <= 127; i++)
	{
		bit = ans.getBit(i);
		bit1 = q1.getBit(i);
		if ((bit != bit1)) {
			ans.setBit(i, 1);
		}
		else
			ans.setBit(i, 0);
	}
	ans.fixLength();
	return ans;
}

//Hàm not
QInt QInt::operator ~()
{
	QInt result = *this;
	int x;
	for (int i =0; i <=127; i++)
	{
		x = getBit(i);
		if (x == 1)
			result.setBit(i, 0);
		else result.setBit(i, 1);
	}
	result.fixLength();
	return result;
}
//Ham ROR
QInt& QInt::ror() {
	int x = this->getBit(0);
	int tmp;
	for (int i = 1; i < 127; i++)
	{
		tmp = this->getBit(i);
		this->setBit(i - 1, tmp);
	}
	setBit(127, x);
	this->fixLength();
	return *this;
}
QInt& QInt::rol() {
	int x = this->getBit(127);
	int tmp;
	for (int i = 126; i >= 0; i--)
	{
		tmp = this->getBit(i);
		this->setBit(i + 1, tmp);
	}
	setBit(0, x);
	this->fixLength();
	return *this;
}

//Hàm kiểm tra số âm
bool QInt::isNegative()
{
	return getBit(127); //Kiểm tra bit thứ 127 có phải là 1 hay không
}

//Hàm chuyển về dạng bù 2
QInt QInt::offset2()
{
	QInt result = ~*this; //Đảo bit
	int tmp = 1, i = 0,sum=0;
	while (tmp)
	{
		sum = result.getBit(i) + tmp;
		if (sum == 2)
		{
			result.setBit(i, 0);
			tmp = 1;
		}
		else if (sum == 1)
		{
			result.setBit(i, 1);
			tmp = 0;
		}
		i++;
	} 
	result.fixLength();
	return result;
}

//CÁC HÀM TOÁN TỬ

//Hàm tính tổng nhị phân
QInt QInt::operator +(QInt x)
{
	QInt max = *this;
	QInt min = x ;
	QInt result;
	//Tương tự như tính tổng hệ 10, chuỗi có độ dài lớn hơn là chuỗi max
	if (max.length < min.length)
	{
		QInt tmp = max;
		max = min;
		min = tmp;
	}
	//carry là số nhớ
	int i = 0, carry=0;
	while (i <= min.length)
	{
		int sum = max.getBit(i) + min.getBit(i) + carry;
		//Dư là bit
		int digit = sum % 2;
		//Thương là số nhớ
		result.setBit(i, digit);
		carry = sum / 2;
		sum = 0;
		i++;
	}

	//Sau khi độ dài dãy bit nhỏ hơn hết, tiếp tục cho hết độ dài dãy bit max
	while (i <= max.length)
	{
		//Tương tự như trên
		int sum = max.getBit(i) + carry;
		int digit = sum % 2;
		result.setBit(i, digit);
		carry = sum / 2;
		sum = 0;
		i++;
	}
	i--;

	result.fixLength();

	//Nếu số nhớ vẫn còn, nếu dãy bit chưa đầy thì thêm 1 vào vị trí tiếp theo 
	if (carry == 1 && i <= 126)
	{
		result.setBit(i+1, 1);
		result.length = i+1;
	}
	//Âm + Âm = Dương
	if (this->isNegative() && x.isNegative() && !result.isNegative())
		result.length = -1;
	//Dương + Dương = Âm
	else if (!this->isNegative() && !x.isNegative() && result.isNegative())
		result.length = -1;
	return result;
}

//Hàm tính hiệu nhị phân
QInt QInt::operator-(QInt x)
{
	//Đổi dãy bit thứ 2 về bù 2
	x=x.offset2();
	QInt result;
	//Và tiến hành toán tử +
	result = *this + x;
	return result;
}

//Hàm tính tích nhị phân
QInt QInt::operator *(QInt x)
{
	//Khởi tạo vector chứa kết quả nhân 
	vector<int> m(128, 0);

	//Thực hiện nhân như bình thường
	for (int i = 0; i <= length; i++)
	{
		for (int j = 0; j <= x.length; j++)
		{
			m[i + j] += getBit(i)*x.getBit(j);
		}
	}

	QInt result;
	for (int i = 0; i <= 127; i++)
	{
		//Phần dư sẽ thành bit 
		int digit = m[i] % 2;
		//Phần thương sẽ thành số nhớ
		int carry = m[i] / 2;
		if (i + 1 < 127)
		{
			m[i + 1] += carry;
		}
		result.setBit(i, digit);
	}
	result.fixLength();
	//Dương * dương = âm
	if (!isNegative() && !x.isNegative() && result.isNegative())
		result.length = -1;
	//Âm * âm = âm
	if (isNegative() && x.isNegative() && result.isNegative())
		result.length = -1;
	//Âm * dương = dương
	if (isNegative() && !x.isNegative() && !result.isNegative())
		result.length = -1;
	//Dương * âm = dương
	if (!isNegative() && x.isNegative() && !result.isNegative())
		result.length = -1;
	return result;
}

//Hàm tính thương nhị phân
QInt QInt::operator /(QInt x)
{
	if (length < x.length)
		return QInt();
	string x1 = displayBits();
	string x2 = x.displayBits();
	string tmp = x1.substr(0,x2.length());
	int i = x2.length();
	string result = "";
	while (i <= x1.length())
	{
		if(stoi(tmp)>=stoi(x2))
		{
			result += "1";
			tmp = (QInt(tmp) - QInt(x2)).displayBits() + x1[i++];
		}
		else 
		{
			result += "0";
			tmp += x1[i++];
		}
	}
	while (result[0] == '0')
		result = result.substr(1);

	QInt result1(result);
	//Dương / dương = âm
	if (!isNegative() && !x.isNegative() && QInt(result).isNegative())
		result1.length = -1;
	//Âm / âm = âm
	if (isNegative() && x.isNegative() && QInt(result).isNegative())
		result1.length = -1;
	//Âm * dương = dương
	if (isNegative() && !x.isNegative() && !QInt(result).isNegative())
		result1.length = -1;
	//Dương * âm = dương
	if (!isNegative() && x.isNegative() && !QInt(result).isNegative())
		result1.length = -1;
	return result1;
}

//Hàm dịch trái
QInt QInt::shiftLeft(int x)
{
	length = 127;
	string result=displayBits();
	if (x <= 127)
	{
		result = result.substr(x);
		result.insert(result.end(), x, '0');
	}
	else result = "0";
	QInt tmp = QInt(result);
	tmp.fixLength();
	return tmp;
}

//Hàm dịch phải
QInt QInt::shiftRight(int x)
{
	length = 127;
	string result = displayBits();
	char first = result[0];
	if (x <= 127)
	{
		result = result.substr(0,result.length() - x);
		result.insert(result.begin(), x, first);
	}
	else result = "0";
	QInt tmp = QInt(result);
	tmp.fixLength();
	return tmp;
}

//HỆ 16

//CÁC HÀM HỖ TRỢ

//Hàm lấy giá trị của kí tự
int valueHex(char x)
{
	if (x == 'A')
		return 10;
	else if (x == 'B')
		return 11;
	else if (x == 'C')
		return 12;
	else if (x == 'D')
		return 13;
	else if (x == 'E')
		return 14;
	else if (x == 'F')
		return 15;
	else return x-'0';
}

//Hàm đổi giá trị sang kí tự Hex
string hexOfValue(int x)
{
	if (x == 10)
		return "A";
	else if (x == 11)
		return "B";
	else if (x == 12)
		return "C";
	else if (x == 13)
		return "D";
	else if (x == 14)
		return "E";
	else if (x == 15)
		return "F";
	else return to_string(x);
}

//CÁC HÀM TOÁN TỬ

//Hàm cộng hệ 16
string sumHex(string x1, string x2)
{
	string result = (hex2bin(x1) + hex2bin(x2)).displayBits();
	return bin2hex(result);
}

//Hàm trừ hệ 16
string subHex(string x1, string x2)
{
	string result = (hex2bin(x1) - hex2bin(x2)).displayBits();
	return bin2hex(result);
}

//Hàm nhân hệ 16
string multiHex(string x1, string x2)
{
	string result = (hex2bin(x1) * hex2bin(x2)).displayBits();
	return bin2hex(result);
}

//Hàm chia hệ 16
string divHex(string x1, string x2)
{
	string result = (hex2bin(x1) / hex2bin(x2)).displayBits();
	return bin2hex(result);
}