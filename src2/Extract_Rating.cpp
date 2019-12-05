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
#include <stack>
#include <cmath>
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
	r = s.substr(zero, c - zero);
	s = s.substr(zero);
	return r;
}

pair<int, int> findpoints(string& s)
{
	int a = 0;  //rating
	int b = 0;   //vote
	unsigned int i = 38;
	for (; i + 8 < s.size(); i++)
	{
		if (s.substr(i, 8) == "rating: ")
		{
			a = s[i + 8] - '0';
			break;
		}

	}
	i += 9;
	for (; i + 9 < s.size(); i++)
	{
		if (s.substr(i, 8) == "votes:  ")
		{
			if (s[i + 8] == ' ')
				b = s[i + 9] - '0';
			else
				b = 10 * (s[i + 8] - '0') + (s[i + 9] - '0');
			break;
		}
	}
	return make_pair(a, b);
}




int main()
{

	//char a = '5';
	//int b = a - '0';
	vector<int> Book(5,0);
	vector<int> DVD(5, 0);
	vector<int> Video(5, 0);
	vector<int> Music(5,0);

	ifstream myfile("amazon-meta.txt");
	ofstream outfile("out.txt"); 
	string temp;
	vector<string> store;
	while (getline(myfile, temp)) 
	{
		string word = firstword(temp);
		if (word == "group")
		{
			string pro = temp.substr(7);
			if (pro == "Book")
			{
				while (getline(myfile, temp))
				{
					int flag = -1;
					if (firstword(temp) == "reviews")
					{
						flag = 1;
						while (getline(myfile, temp))
						{
							if (temp.empty())
								break;
							pair<int, int> rv = findpoints(temp);
							Book[rv.first - 1] += rv.second;
						}
					}
					if (flag == 1)
						break;
				}
			}
			else if (pro == "DVD")
			{
				while (getline(myfile, temp))
				{
					int flag = -1;
					if (firstword(temp) == "reviews")
					{
						flag = 1;
						while (getline(myfile, temp))
						{
							if (temp.empty())
								break;
							pair<int, int> rv = findpoints(temp);
							DVD[rv.first - 1] += rv.second;
						}
					}
					if (flag == 1)
						break;
				}
			}
			else if (pro == "Video")
			{
				while (getline(myfile, temp))
				{
					int flag = -1;
					if (firstword(temp) == "reviews")
					{
						flag = 1;
						while (getline(myfile, temp))
						{
							if (temp.empty())
								break;
							pair<int, int> rv = findpoints(temp);
							Video[rv.first - 1] += rv.second;
						}
					}
					if (flag == 1)
						break;
				}
			}
			else if (pro == "Music")
			{
				while (getline(myfile, temp))
				{
					int flag = -1;
					if (firstword(temp) == "reviews")
					{
						flag = 1;
						while (getline(myfile, temp))
						{
							if (temp.empty())
								break;
							pair<int, int> rv = findpoints(temp);
							Music[rv.first - 1] += rv.second;
						}
					}
					if (flag == 1)
						break;
				}
			}

		}

	}
	myfile.close();
	outfile.close();
	cout << "Book:" << endl;
	for (unsigned int i = 0; i < 5; i++)
	{
		cout << "rating: " << i + 1 << ", " << "votes: " << Book[i] << endl;
	}
	cout << "DVD:" << endl;
	for (unsigned int i = 0; i < 5; i++)
	{
		cout << "rating: " << i + 1 << ", " << "votes: " << DVD[i] << endl;
	}
	cout << "Video:" << endl;
	for (unsigned int i = 0; i < 5; i++)
	{
		cout << "rating: " << i + 1 << ", " << "votes: " << Video[i] << endl;
	}
	cout << "Music:" << endl;
	for (unsigned int i = 0; i < 5; i++)
	{
		cout << "rating: " << i + 1 << ", " << "votes: " << Music[i] << endl;
	}


	return 0;

}