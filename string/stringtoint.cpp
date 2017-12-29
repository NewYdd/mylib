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