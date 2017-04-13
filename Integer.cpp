#include "Integer.h"
//	Integer 相關運算

//	四則運算
std::string Calc(std::vector<std::string>& Numbers, std::vector<char>& sign) {
	for (int i = 0; i < sign.size(); i++) {
		if (sign[i] == '*') {
			Numbers[i] = (Integer(Numbers[i]) * Integer(Numbers[i + 1])).ToString();
			Numbers.erase(Numbers.begin() + i + 1);
			sign.erase(sign.begin() + i); i--;
		}
		else if (sign[i] == '/') {
			Numbers[i] = (Integer(Numbers[i]) / Integer(Numbers[i + 1])).ToString();
			Numbers.erase(Numbers.begin() + i + 1);
			sign.erase(sign.begin() + i); i--;
		}
	}
	while (sign.size()) {
		if (sign[0] == '+')
			Numbers[0] = (Integer(Numbers[0]) + Integer(Numbers[1])).ToString();
		else if (sign[0] == '-')
			Numbers[0] = (Integer(Numbers[0]) - Integer(Numbers[1])).ToString();
		Numbers.erase(Numbers.begin() + 1);
		sign.erase(sign.begin());
	}
	return Numbers[0];
}

//	字串分析
Integer Analysis(std::string& in) {
	std::string num;
	std::vector<std::vector<char>> sign;
	std::vector<std::vector<std::string>> Numbers;
	std::vector<std::string> all;
	int position = 0;
	Numbers.resize(SizeMax);
	sign.resize(SizeMax);
	for (int i = 0; i < in.size(); i++) {
		if (in[i] == ' ') {
			in.erase(in.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < in.size(); i++) {
		if (in[i] == '+') all.push_back("+");
		else if (in[i] == '*') all.push_back("*");
		else if (in[i] == '/') all.push_back("/");
		else if (in[i] == '(') all.push_back("(");
		else if (in[i] == ')') all.push_back(")");
		else {
			if (in[i] == '-' && in[i + 1] == '-') {
				all.push_back("-");
				num += in[i + 1];
				i++;
			}
			else if (in[i] == '-' && (i>0 && (in[i - 1] >= '0'&&in[i - 1] <= '9'))) {
				all.push_back("-");
			}
			else {
				num += in[i];
				if (in[i + 1] == '+' || in[i + 1] == '-' || in[i + 1] == '*' || in[i + 1] == '/' || in[i + 1] == '(' || in[i + 1] == ')') {
					all.push_back(num);
					num.resize(0);
				}
				else if (i + 1 == in.size()) {
					all.push_back(num);
					num.resize(0);
				}
			}
		}
	}
	while (all.size()) {
		if (all[0] == "+") sign[position].push_back('+');
		else if (all[0] == "-") sign[position].push_back('-');
		else if (all[0] == "*") sign[position].push_back('*');
		else if (all[0] == "/") sign[position].push_back('/');
		else if (all[0] == "(") {
			Numbers[position].push_back("here");
			position++;
		}
		else if (all[0] == ")") {
			num = Calc(Numbers[position], sign[position]);
			Numbers.erase(Numbers.begin() + position);
			sign.erase(sign.begin() + position);
			position--;
			for (int i = Numbers[position].size() - 1; i >= 0; i--) {
				if (Numbers[position][i] == "here") {
					Numbers[position][i] = num;
					break;
				}
			}
		}
		else Numbers[position].push_back(all[0]);
		all.erase(all.begin());
	}
	return Integer(Calc(Numbers[0], sign[0]));
}
