#ifndef LOG_H
#define LOG_H

#include <fstream>   
#include <iostream>  
#include <string>
#include<time.h>
#include <stdio.h> 
#include <sstream>

#include <errno.h> 
#include <sys/types.h>  
#include <sys/stat.h>

using namespace std;

#if 1  
typedef struct stat Stat_t;
#define StatFunc(x,y) stat(x,y)  
#else  
typedef struct stat64 Stat_t;  //部分平台不支持  
#define StatFunc(x,y) stat64(x,y)  
#endif  
// log 配置结构体
struct logConfig  
{
	string fileName;  //文件名
	bool cover;		  //是否覆盖
	int fileSize;	  //文本大小
	int frequence;	  //记录频率
	
	logConfig() {}
	logConfig( string _fileName, bool _cover, int _size,int _frequence)
		: fileName(_fileName), cover(_cover), fileSize(_size),frequence(_frequence) {}
};

bool openFile(string fileName, ofstream &OsWrite);          //打开文件
void closeFile(ofstream &OsWrite);                          //关闭文件
string string_to_hex(const string& str, ofstream &OsWrite); //转为16进制
void record_string(string log_type, const string& str, ofstream &OsWrite, logConfig log,bool stamped =true); //记录数据，默认有时间戳
int get_size(string fileName, time_t &createTime,bool show = false);//获取文本大小以及文本创建时间
void clear_file(string fileName);                           //清空文本
void split_file(ofstream &OsWrite,logConfig log);           //分布文本，模式：覆盖或新建


	
	bool openFile(string fileName, ofstream &OsWrite)
	{

		OsWrite.open(fileName.c_str(), std::ofstream::app);
		if (OsWrite.is_open())
		{
			//cout << "open file sucess" << endl;
			return true;
		}
		else
		{
			cout << "open file error" << endl;
			return false;
		}
	}

	void closeFile(ofstream &OsWrite)                //关闭文本
	{

		if (OsWrite.is_open())
		{
			OsWrite.close();
			//cout << "close file sucess" << endl;
		}
		else
		{
			cout << "no open file " << endl;
		}
	}

	string string_to_hex(const string& str, ofstream &OsWrite) //transfer string to hex-string  
	{
		string result;
		string tmp;
		stringstream ss;
		for (int i = 0; i<str.size(); i++)
		{
			ss << hex << (short int)str[i] << endl;
			ss >> tmp;
			result += "0x";
			result += tmp;
			result += " ";
		}
		time_t t;
		time(&t);
		OsWrite << ctime(&t) << result;
		OsWrite << endl;
		return result;
	}

	void record_string(string log_type, const string& str, ofstream &OsWrite, logConfig log,bool stamped) //是否有时间戳 默认有
	{
		static int count = 0;
		if (++count == log.frequence)
		{
			split_file(OsWrite, log);
			string logString;
			logString += "[";
			logString += log_type;
			logString += "]: ";
			logString += str;
			if (stamped)
			{
				time_t t;
				time(&t);
				OsWrite << ctime(&t);
			}
			OsWrite<< logString;
			OsWrite << endl;
			count = 0;
		}
	}
	void record_time(ofstream &OsWrite)
	{
		time_t t;
		time(&t);
		OsWrite << ctime(&t);
	}

	int get_size(string fileName,time_t &createTime, bool show) // get the file size
	{
		int nRet = 0;
		Stat_t s;
		createTime = 0;
		struct tm stuTimeTmp;
		memset(&s, 0, sizeof(Stat_t));
		nRet = StatFunc(fileName.c_str(), &s);
		if (nRet)
		{
			printf("stat %s failed! error_code: %s", fileName, strerror(errno));
			return -1;
		}
		if (s.st_size > 0 && show)
		{
			printf("\n size ========%0.3lf KB  %0.3lf M   %0.3lf G ======\n",
				s.st_size / 1024.0, s.st_size / 1024.0 / 1024.0, s.st_size / 1024.0 / 1024.0 / 1024.0);
		}
		createTime = (s.st_ctime);  //文件创建时间
		return s.st_size;
	}

	void clear_file(string fileName)
	{
		ofstream f(fileName, ios::trunc);
		f.close();
	}

	string newName(string old_fileName, time_t &t) //按时间重命名
	{
		char str[30];
		struct tm *ptr;
		ptr = localtime(&t);
		strftime(str, 100, "%Y%m%e_%H%M%S", ptr);
		string temp = old_fileName;
		temp.pop_back(); temp.pop_back(); temp.pop_back(); temp.pop_back();
		temp += str;
		temp += ".bak";
		return temp;
	}

	void split_file(ofstream &OsWrite, logConfig log)
	{
		time_t t = 0;
		int size = get_size(log.fileName,t,true);
		if (size > log.fileSize)
		{
			if (log.cover) //cover the old content
			{
				closeFile(OsWrite);
				clear_file(log.fileName);
				openFile(log.fileName, OsWrite);
				cout << "cover the old file" << endl;
			}
			else
			{
				closeFile(OsWrite);
				t = time(NULL);
				string temp = newName(log.fileName, t);
				int	result = rename(log.fileName.c_str(), temp.c_str());
				if (result == 0)
					puts("File successfully renamed");
				else
					perror("Error renaming file");
				openFile(log.fileName, OsWrite);
			}
		}
	}







#endif
