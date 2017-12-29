#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
using namespace std;
string name = "C:\\Users\\HP\\Desktop\\11.txt";
string result_name = "C:\\Users\\HP\\Desktop\\result.txt";
fstream my_file;
fstream result_file;


int Char16ToInt(char c);
int StrToNum16(const char* str)

{
	int len = strlen(str);
	int num = 0;
	for (int i = 0; i < len; i++)
	{
		num = num * 16 + Char16ToInt(str[i]);
	}

	return num;
}
int Char16ToInt(char c)
{
	switch (c)
	{
	case '0':
		return 0;
		break;
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	case 'A':
		return 10;
		break;
	case 'B':
		return 11;
		break;
	case 'C':
		return 12;
		break;
	case 'D':
		return 13;
		break;
	case 'E':
		return 14;
		break;
	case 'F':
		return 15;
		break;
	default:
		return 0;
		break;

	}

}

void process(string line)
{
	vector<string> data;
	int result[10];
	string word;
	for (int i = 0; i < line.size(); ++i)
	{
		if (isspace(line[i]))
		{
			data.push_back(word);
			word.clear();
		}
		else
			word += line[i];
	}
	int i = 0;
	for (int j=0;j<data.size();++j)
	{
		result[i] = StrToNum16(data[j].c_str());
		i++;
	}
	result[9] = 0;
	int resultd34 = result[2] + result[3] *256;
	int result56 = result[4] + result[5] *256;
	int result7890 = result[6] + result[7] *256 + result[8] *256*256 + result[9] *256*256*256;
	result_file << resultd34 << " " << result56<<" "<< result7890;
	result_file << endl;

}

int main()
{
	
	my_file.open(name);
	result_file.open(result_name,std::ofstream::app);
	string line;
	while (std::getline(my_file, line))
	{
		process(line);
		line.clear();
	}
	
	
	
	system("PAUSE");
	return 0;
}