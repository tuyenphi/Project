#include "Convert.h"
void main() {
	string bit = "011110011001"; QInt q(bit);//Lưu dưới dạng QInt
	string bit1 = "11000101"; QInt q1(bit1);//Lưu dưới dạng QInt
	//Phép NOT
	QInt NOT = ~q1;
	cout << "Not result: ";
	cout << NOT.displayBits() << endl;
	//Phép >>
	QInt shiftleft = q.shiftLeft(1);
	cout << "ShiftLeft result: ";
	cout << shiftleft.displayBits() << endl;
	//Phép <<
	QInt shiftright = q.shiftRight(1);
	cout << "ShiftRight result: ";
	cout << shiftright.displayBits() << endl;
	//Phép Rotate Right
	QInt ror = q.ror();
	cout << "Ror result: ";
	cout << ror.displayBits() << endl;;
	//Phép Rotate Left
	QInt rol = q.rol();
	cout << "Rol result: ";
	cout << rol.displayBits() << endl;;
}