#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct item
{
	int value;
	int weight;
	item(int value, int weight)
	{
		this->value = value;
		this->weight = weight;
	}
} item_t;

typedef struct sack
{
	int max_weight;
	int value;
	int current_weight;
	vector<item_t> items;
	vector<item_t> all_items;
} sack_t;

void knapsack()
{
}

vector<string> split_line(string line)
{
	vector<string> strs;

	bool next = false;

	string word1;
	string word2;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == ' ')
		{
			next = true;
			continue;
		}
		if (next)
		{
			word2 += line[i];
		}
		else
		{
			word1 += line[i];
		}
	}

	strs.push_back(word1);
	strs.push_back(word2);
	return strs;
}

vector<sack_t> parse_input(vector<string> lines)
{
	int lines_parsed = 0;
	int total_lines = lines.size();

	int capacity;
	int nr_of_items;

	vector<string> firstline = split_line(lines[0]);
	capacity = stoi(firstline.at(0));
	nr_of_items = stoi(firstline.at(1));
	// cout << capacity << ", " << nr_of_items;

	lines_parsed++;
	int index = 1;

	vector<sack_t> sacks;
	while (lines_parsed < total_lines)
	{
		sack_t sack;
		sack.max_weight = capacity;

		for (int i = 0; i < nr_of_items; i++)
		{
			vector<string> values = split_line(lines[lines_parsed]);
			item_t *item = new item_t(stoi(values[0]), stoi(values[1]));
			sack.all_items.push_back(*item);
			lines_parsed++;
		}

		sacks.push_back(sack);
		if (lines_parsed == total_lines)
			break;

		lines_parsed++;
		vector<string> next_sack_metdata = split_line(lines[lines_parsed]);
		capacity = stoi(next_sack_metdata.at(0));
		nr_of_items = stoi(next_sack_metdata.at(1));
	}

	// cout << sacks.size();

	return sacks;
}

void pack_sack(sack_t sack)
{
	

}

void pack_all_sacks(vector<sack_t> sacks)
{

	for (sack_t sack : sacks)
	{
		pack_sack(sack);
	}
}

int main()
{
	vector<string> input = {
		"5 3",
		"1 5",
		"10 5",
		"100 5",
		"6 4",
		"5 4",
		"4 3",
		"3 2",
		"2 1"};

	vector<sack_t> sacks = parse_input(input);
	cout << sacks.at(1).all_items.size();
	return 0;
}