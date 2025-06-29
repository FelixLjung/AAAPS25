#include <iostream>
#include <vector>

using namespace std;

typedef struct pair {
	vector<string> placeholder;
	vector<string> word;
	pair(string placeholder, string word) {
		this->placeholder.push_back(placeholder);
		this->word.push_back(word);
	}
} pair_t;

std::vector<string> split_line(string line)
{

	std::vector<string> words;
	std::string word;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == ' ' && word.size() > 0)
		{
			// words[words.size()] = word;
			words.push_back(word);
			word.clear();
		}
		else
		{
			word += line[i];
		}
	}

	words.push_back(word);

	return words;
}

void print_vector(std::vector<string> line)
{
	for (int i = 0; i < line.size(); i++)
	{
		cout << line.at(i) + " ";
	}
}

bool is_placeholder(std::string word)
{
	if (word.at(0) = '<' && word.back() == '>')
	{
		return true;
	}

	return false;
}

std::string compare_line(std::vector<string> line1, std::vector<string> line2)
{
	if (line1.size() != line2.size())
	{
		return "-";
	}

	string output;

	for (int word = 0; word < line1.size(); word++)
	{
		string word1 = line1[word];
		string word2 = line2[word];

		bool is_placeholder1 = is_placeholder(word1);
		bool is_placeholder2 = is_placeholder(word2);

		std::vector<string> placeholders1;
		std::vector<string> placeholders2;

		if (word1 != word2 && !is_placeholder1 && !is_placeholder2)
		{
			return "-";
		}
		else
		{
			if (is_placeholder1 && !is_placeholder2)
			{
				output += word2;
				output += " "; // add blankspace
				pair_t* pair = new pair_t(word1, word2);

			}
			else if (is_placeholder2 && !is_placeholder1)
			{
				output += word1;
				output += " ";
			}
			else if (!is_placeholder1 && !is_placeholder2)
			{
				output += word1;
				output += " ";
			}
		}
	}

	return output;
}

void help(string lines[])
{
	int tests = std::stoi(lines[0]);

	for (int i = 1; i < tests * 2; i += 2)
	{
		std::vector<string> line1 = split_line(lines[i]);
		std::vector<string> line2 = split_line(lines[i + 1]);

		cout << compare_line(line1, line2);
		// print_vector(line1);S

		// cout << lines[i];
		// cout << "\n";
		// cout << lines[i + 1];
		cout << "\n";
	}
}

int main()
{

	string input[100] = {"3",
						 "how now brown <animal>",
						 "<foo> now <color> cow",
						 "who are you",
						 "<a> <b> <a>",
						 "<a> b",
						 "c <a>"};

	help(input);

	// how now brown cow
	//-
	// c b

	return 0;
}
