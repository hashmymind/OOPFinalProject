#include"calc.h"
using namespace std;
string calc(string& input)
{
	vector <string> deal;
	vector <char> sign;
	string tmp;
	bool flag = false;
	for (int i = 0; i < input.size(); i++)//無視所有空白
	{
		if (input[i] == ' ')
		{
			input.erase(input.begin() + i);
			i--;
		}
	}
	if (input[0] != '(')
	{
		tmp += input[0];
		input.erase(input.begin());
	}
	while (input.size())
	{
		if (flag == false)
		{
			flag = true;
			if (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/')
			{
				if(tmp!="")
					deal.push_back(tmp);
				tmp = "";			
				if (input[0] == '+')
				{
					sign.push_back(input[0]);
				}
				else if (input[0] == '-')
				{
					sign.push_back(input[0]);
				}
				else if (input[0] == '*')
				{
					sign.push_back(input[0]);
				}
				else if (input[0] == '/')
				{
					sign.push_back(input[0]);
				}
				input.erase(input.begin());
			}
		}
		else if (input[0] == '(')
		{
			flag = false;
			int count = 1;
			input.erase(input.begin());
			string temp;
			while (count)
			{
				if (input[0] == ')')
				{
					count--;
					if (count != 0)
					{
						temp += input[0];			
					}
					input.erase(input.begin());
				}
				else if (input[0] == '(')
				{
					count++;
					temp += input[0];
					input.erase(input.begin());
				}
				else
				{
					temp += input[0];
					input.erase(input.begin());
				}
			}
			string a = calc(temp);
			deal.push_back(a);
		}
		else
		{
			tmp += input[0];
			input.erase(input.begin());
			flag = false;
		}
	}
	if (tmp != "")
		deal.push_back(tmp);
	tmp = "";
	for (int i = 0; i < sign.size(); i++)
	{
		if (sign[i] == '*')
		{
			Integer a(deal[i]);
			Integer b(deal[i + 1]);
			deal[i] = (a*b).ToString();
			deal.erase(deal.begin() + i + 1);
			sign.erase(sign.begin() + i);
			i--;
		}
		else if (sign[i] == '/')
		{
			Integer a(deal[i]);
			Integer b(deal[i + 1]);
			deal[i] = (a / b).ToString();
			deal.erase(deal.begin() + i + 1);
			sign.erase(sign.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < sign.size(); i++)
	{
		if (sign[i] == '+')
		{
			Integer a(deal[i]);
			Integer b(deal[i + 1]);
			deal[i] = (a + b).ToString();
			deal.erase(deal.begin() + i + 1);
			sign.erase(sign.begin() + i);
			i--;
		}
		else if (sign[i] == '-')
		{
			Integer a(deal[i]);
			Integer b(deal[i + 1]);
			deal[i] = (a - b).ToString();
			deal.erase(deal.begin() + i + 1);
			sign.erase(sign.begin() + i);
			i--;
		}
	}
	return deal[0];
}
int main()
{
	string input;
	while (getline(cin, input))
	{
		cout << calc(input) << endl;
	}
    return 0;
}

