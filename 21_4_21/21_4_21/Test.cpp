#include "Template.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	/*char sqlstr[256];
	char name[100];
	scanf("%s", name);

	sprintf(sqlstr, "select * from t_student where name = '%s'", name);
	printf("%s\n", sqlstr);*/

	//stringstream ss;
	//string name;
	//cin >> name;
	//ss << "select * from t_student where name = '";
	//ss << name;
	//ss << "'";

	//string sql = ss.str();
	//cout << sql;

	stringstream ss("������������ 21:50:28 ����ˣ�����Ӳ�");
	string name;
	string time;
	string message;

	ss >> name;
	ss >> time;
	ss >> message;

	return 0;
}


//// ʹ���ļ�IO�����ı��������Ʒ�ʽ��ʾ��д�����ļ�
//struct ServerInfo
//{
//	char _ip[32];	// ip
//	int _port;		// �˿�
//};
//
//struct ConfigManager
//{
//public:
//	ConfigManager(const char* filename)
//		:_configfile(filename)
//	{}
//
//	void WriteBin(const ServerInfo& info)
//	{
//		ofstream ofs(_configfile);
//		ofs.write((char*)&info, sizeof(ServerInfo));
//	}
//
//	void WriteText(const ServerInfo& info)
//	{
//		ofstream ofs(_configfile);
//		ofs << info._ip << " ";
//		ofs << info._port;
//	}
//
//	void ReadBin(ServerInfo& info)
//	{
//		ifstream ifs(_configfile);
//		ifs.read((char*)&info, sizeof(ServerInfo));
//	}
//
//	void ReadText(ServerInfo& info)
//	{
//		ifstream ifs(_configfile);
//		ifs >> info._ip;
//		ifs >> info._port;
//	}
//
//private:
//	string _configfile; // �����ļ�
//};
//
//int main()
//{
//	ServerInfo myInfo = { "192.168.1.1", 8000 };
//	ConfigManager cm("server.config");
//	/*cm.WriteBin(myInfo);*/
//	ServerInfo yourInfo;
//	cm.ReadBin(yourInfo);
//
//	return 0;
//}



//int main()
//{
//	cout << "�������" << endl;
//	cerr << "�������" << endl;
//	clog << "��־���" << endl;
//
//	//int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		printf("%d\n", n);
//	}
//
//	// istream& operator>> (int& val);
//	//while (cin>>n)
//	//{
//	//	cout << n << endl;
//	//}
//
//	return 0;
//}

//int main()
//{
//	TFunc(10);
//	//TFunc(10.11);
//
//
//	return 0;
//}