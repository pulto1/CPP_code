#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

#include <iostream>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        string ret;

        int end1 = num1.size() - 1, end2 = num2.size() - 1;
        char next = 0;
        while (end1 >= 0 || end2 >= 0)
        {
            char x1 = 0, x2 = 0;
            if (end1 >= 0)
            {
                x1 = num1[end1] - '0';
                --end1;
            }

            if (end2 >= 0)
            {
                x2 = num2[end2] - '0';
                --end2;
            }

            char retch = x1 + x2 + next;
            if (retch >= 10)
            {
                retch -= 10;
                next = 1;
            }

            else
            {
                next = 0;
            }

            ret += (retch + '0');
        }

        if (next == 1)
            next += '1';

        reverse(ret.begin(), ret.end());

        return ret;
    }
};

int main()
{
	string s1;
	string s2;
	string s3;
	
	/*cin >> s1;
	cout << s1 << endl;*/

	/*getline(cin, s2);
	cout << s2 << endl;*/

	getline(cin, s3, ' ');
	cout << s3 << endl;

	return 0;
}

//int main()
//{
//    string s;
//    getline(cin, s);
//
//    size_t pos = s.rfind(' ');
//    if (pos == string::npos)
//    {
//        cout << s.size() << endl;
//    }
//
//    else
//    {
//        cout << s.size() - pos - 1 << endl;
//    }
//    return 0;
//}
//
//class Solution {
//public:
//    int firstUniqChar(string s)
//    {
//        int count[26] = { 0 };
//
//        for (auto ch : s)
//        {
//            count[ch - 'a']++;
//        }
//
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (count[s[i] - 'a'] == 1)
//                return i;
//        }
//
//        return -1;
//    }
//};
//
//class Solution {
//public:
//    bool isLetter(char ch)
//    {
//        if (ch >= 'a' && ch <= 'z')
//            return true;
//
//        if (ch >= 'A' && ch <= 'Z')
//            return true;
//
//        return false;
//    }
//
//    string reverseOnlyLetters(string S)
//    {
//        if (S.empty())
//            return S;
//
//        size_t begin = 0, end = S.size() - 1;
//        while (begin < end)
//        {
//            while (begin < end && !isLetter(S[begin]))
//                ++begin;
//
//            while (begin < end && !isLetter(S[end]))
//                --end;
//
//            swap(S[begin], S[end]);
//            ++begin;
//            --end;
//        }
//
//        return S;
//    }
//};
//
//int main()
//{
//	string s1 = "hello";
//	cout << s1 << endl;
//
//	cout << s1 + " world" << endl;
//	cout << s1 << endl;
//	return 0;
//}

//int main()
//{
//	string url = "http://www.cplusplus.com/reference/string/string/substr/";
//	
//	cout << url << endl;
//
//	size_t pos1 = url.find(':');
//	if (pos1 != string::npos)
//	{
//		cout << url.erase(0, pos1 + 3) << endl;
//	}
//	
//	/*size_t pos2 = url.find('/', pos1 + 3);
//	if (pos1 != string::npos)
//	{
//		cout << url.substr(pos1 + 3, pos2 - (pos1 + 3)) << endl;
//	}
//	
//	cout << url.substr(pos2 + 1) << endl;*/
//
//	/*string s1 = "string.cpp.tar.zip";*/
//	/*cout << s1.find('.') << endl;
//	cout << s1.rfind('.') << endl;*/
//
//	/*string s("1234");
//	s.insert(s.begin(), '0');
//	cout << s <<endl;
//
//	s.insert(0, 10, '0');
//	cout << s << endl;
//
//	s.insert(0, "2222");
//	cout << s << endl;
//
//	s.insert(4, "3333");
//	cout << s << endl;*/
//
//	return 0;
//}