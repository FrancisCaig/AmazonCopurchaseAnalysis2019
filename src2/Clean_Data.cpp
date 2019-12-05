#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>
#include <utility>
#include <unordered_map>
#include <iostream>
#include <fstream>
using namespace std;


string firstword(string& s)
{
	string r;
	if (s.empty())
		return r;
	int c = 0;
	int zero = 0;
	for (; c < s.size(); c++)
	{
		if (s[c] == ' ' && r.empty())
		{
			zero++;
			continue;
		}
		else if (s[c] == ' ' || s[c] == ':')
			break;
	}
	r = s.substr(zero, c-zero);
	s = s.substr(zero);
	return r;
}



int main()
{
	cout << 3 << endl << 5 << endl << endl << 7;


	ifstream myfile("amazon-meta.txt");
	ofstream outfile("out.txt"); //ios::app指追加写入
	string temp;
	vector<string> store;
	while (getline(myfile, temp)) //按行读取字符串 
	{
		string word = firstword(temp);
		if (word == "Id" || word == "ASIN" || word == "group" || word == "categories" || word == "reviews")
		{
			store.push_back(temp);
			//outfile << temp;//写文件
			//outfile << endl;
		}
		if (word == "iscontinued product")
			store.clear();
		if (word == "reviews")
		{
			for (unsigned int i = 0; i < store.size(); i++)
			{
				outfile << store[i] << endl;
			}
			outfile << endl;
			store.clear();
		}
	}
	myfile.close();
	outfile.close();
	return 0;


}


	