#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print_file(vector<string> lines)
{
	for (string line : lines)
	{
		cout << line << "\n";
	}
}

bool compare_line(string line1, string line2)
{
	sort(line1.begin(), line1.begin() + line1.size());
	sort(line2.begin(), line2.begin() + line2.size());

	if (line1.compare(line2) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void compare_files(vector<string> file1, vector<string> file2)
{
	if (file1.size() != file2.size())
	{
		cout << "TEST FAILED, different size";
		return;
	}

	for (int i = 0; i < file1.size(); i++)
	{
		string line1 = file1.at(i);
		string line2 = file2.at(i);

		if (line1.size() != line2.size())
		{
			cout << "ERROR different line length at: " << i;
		}
		else
		{
			bool passed = compare_line(line1, line2);
			if (passed == false)
			{
				cout << "error at : " << i;
			}
		}
	}

	cout << "all tests passed";
}

int main()
{
	string my_output;
	string expected_output;
	ifstream file1("testout.ans");
	ifstream file2("testexpected.ans");

	vector<string> lines1;
	vector<string> lines2;

	bool skipfirst = true;
	while (getline(file1, my_output))
	{
		if (skipfirst)
		{
			skipfirst = false;
			continue;
		}
		if (my_output.back() == ' ')
			my_output.pop_back();
		lines1.push_back(my_output);
	}

	while (getline(file2, expected_output))
	{
		if (expected_output.back() == ' ')
			expected_output.pop_back();

		lines2.push_back(expected_output);

		;
	}

	print_file(lines1);
	cout << "\n";
	print_file(lines2);
	compare_files(lines1, lines2);
}