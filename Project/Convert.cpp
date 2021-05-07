#include "Convert.h"
//3
//Ham chia 2 so nguyen lon
string divineX(string x)
{
	int i = 0;
	string ans;
	int tmp = x[i] - '0';
	while (tmp < 2)
		tmp = tmp * 10 + (x[++i] - '0');
	while (i < x.size())
	{
		ans += (tmp / 2) + '0';

		tmp = (tmp % 2) * 10 + x[++i] - '0';
	}



	if (ans.length() == 0)
		return "0";

	return ans;
}

	
// He 10 -> He 2
QInt dec2bin(string x){
	bool Negative=false;
	QInt a;
	int i = 0;
	if (x[0] == '-') //Kiểm tra số âm.
	{
		x.erase(x.begin());
		Negative = true;
	}
	while (x != "1")
	{
		int bit =((x[x.size() - 1] -'0') % 2) ;
		a.setBit(i, bit); 
		x = divineX(x);
		i++;
	}
	a.setBit(i, 1);
	a.length = i;
	if (i >= 128)
		a.length = -1;
	QInt b = a;
	if (Negative == true)
	{
		b=a.offset2();
		
	}
	
	b.fixLength();
	return b;

}
//He 2->He 10
string bin2dec(string bin) {
	string res = "";
	string expo = "1";
	reverse(bin.begin(), bin.end());
	//bit đầu tiên mũ 0
	if (bin[0] == '1') {
		res = sumDec(res, "1");
	}

	for (int i = 1; i <= bin.length(); i++)
	{
		expo = multiDec(expo, "2");
		if (bin[i] == '1')
		{

			if (i == 127) {
				expo = expo.insert(0, "-");

			}
			res = sumDec(res, expo);

		}
	}

	return res;
	
	return res;
}
//2->16
string bin2hex(string bin) {
	string tmp;
	string a;
	while (bin.size() % 4 != 0) {//chèn để đủ bộ 4 bit
		bin.insert(bin.begin(), '0');
	}
	for (int i = 0; i < bin.size(); i++)
	{
		tmp.push_back(bin[i]);

		if (i % 4 == 3) //nhận đủ 4 bit r so sánh
		{
			if (tmp == "0000")
			{
				a.push_back('0');
			}
			else
			{
				if (tmp == "0001")
				{
					a.push_back('1');
				}
				else
				{
					if (tmp == "0010")
					{
						a.push_back('2');
					}
					else
					{
						if (tmp == "0011")
						{
							a.push_back('3');
						}
						else
						{
							if (tmp == "0100")
							{
								a.push_back('4');
							}
							else
							{
								if (tmp == "0101")
								{
									a.push_back('5');
								}
								else
								{
									if (tmp == "0110")
									{
										a.push_back('6');
									}
									else
									{
										if (tmp == "0111")
										{
											a.push_back('7');
										}
										else
										{
											if (tmp == "1000")
											{
												a.push_back('8');
											}
											else
											{
												if (tmp == "1001")
												{
													a.push_back('9');
												}
												else
												{
													if (tmp == "1010")
													{
														a.push_back('A');
													}
													else
													{
														if (tmp == "1011")
														{
															a.push_back('B');
														}
														else
														{
															if (tmp == "1100")
															{
																a.push_back('C');
															}
															else
															{
																if (tmp == "1101")
																{
																	a.push_back('D');
																}
																else
																{
																	if (tmp == "1110")
																	{
																		a.push_back('E');
																	}
																	else
																	{
																		if (tmp == "1111")
																		{
																			a.push_back('F');
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}

			tmp.clear(); //hết 1 lần so sánh xóa chuỗi temp để nạp tiếp bit
		}
	}
	while (a[0] == '0') {
		a.erase(a.begin() + 0);
	}

	return a;
}
//16->2
QInt hex2bin(string hex) {

	string a;

	for (int i = 0; i < hex.size(); i++)
	{
		switch (hex[i])
		{
		case '0':
		{
			a = a + "0000";
			break;
		}
		case '1':
		{
			a = a + "0001";
			break;
		}
		case '2':
		{
			a = a + "0010";
			break;
		}
		case '3':
		{
			a = a + "0011";
			break;
		}
		case '4':
		{
			a = a + "0100";
			break;
		}
		case '5':
		{
			a = a + "0101";
			break;
		}
		case '6':
		{
			a = a + "0110";
			break;
		}
		case '7':
		{
			a = a + "0111";
			break;
		}
		case '8':
		{
			a = a + "1000";
			break;
		}
		case '9':
		{
			a = a + "1001";
			break;
		}
		case 'A':
		{
			a = a + "1010";
			break;
		}
		case 'B':
		{
			a = a + "1011";
			break;
		}
		case 'C':
		{
			a = a + "1100";
			break;
		}
		case 'D':
		{
			a = a + "1101";
			break;
		}
		case 'E':
		{
			a = a + "1110";
			break;
		}
		case 'F':
		{
			a = a + "1111";
			break;
		}
		}
	}
	QInt ans(a);
	ans.offset2();
	ans.fixLength();
	return ans;
}
//10->16
string dec2hex(string dec) {
	QInt a=dec2bin(dec);
	string ans=bin2hex(a.displayBits());
	return ans;
}
//16->10
string hex2dec(string hex) {
	QInt a=hex2bin(hex);
	string ans = bin2dec(a.displayBits());
	return ans;
}