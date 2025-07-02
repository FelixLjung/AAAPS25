#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct item
{
	int value;
	int weight;
	int index;
	item(int value, int weight, int index)
	{
		this->value = value;
		this->weight = weight;
		this->index = index;
	}
} item_t;

typedef struct sack
{
	int max_weight;
	int value;
	int current_weight;
	vector<item_t> items;
	vector<item_t> all_items;
	sack()
	{
		this->value = 0;
		this->current_weight = 0;
	}
} sack_t;

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
			item_t *item = new item_t(stoi(values[0]), stoi(values[1]), i);
			sack.all_items.push_back(*item);
			lines_parsed++;
		}

		sacks.push_back(sack);
		if (lines_parsed == total_lines)
			break;

		vector<string> next_sack_metdata = split_line(lines[lines_parsed]);
		capacity = stoi(next_sack_metdata.at(0));
		nr_of_items = stoi(next_sack_metdata.at(1));
		lines_parsed++;
	}

	return sacks;
}

vector<item_t> sort_items_by_ration(vector<item_t> items)
{
	vector<item_t> sorted;

	int index = 1;
	sorted.push_back(items.at(0)); // add first item
	while (sorted.size() < items.size())
	{
		item_t current_item = items.at(index);
		double ratio = current_item.value / current_item.weight;

		for (int j = 0; j < sorted.size(); j++)
		{
			item_t compare = sorted.at(j);
			double compare_ratio = compare.value / compare.weight;

			if (ratio >= compare_ratio)
			{ // this item is better, add in front
				sorted.insert(sorted.begin(), current_item);
				break;
			}

			if (j == sorted.size() - 1)
			{ // we reached the end of the vector
				sorted.push_back(current_item);
				break;
			}
		}

		index++;
	}

	return sorted;
}

sack_t pack_sack(sack_t sack)
{
	// sortera alla items efter högst value to weight ratio, och lägg sedan in så många som möjligt?
	sack.all_items = sort_items_by_ration(sack.all_items);
	for (item_t item : sack.all_items)
	{
		if (sack.current_weight + item.weight <= sack.max_weight)
		{
			sack.items.push_back(item);
			sack.current_weight += item.weight;
			sack.value += item.value;
		}
	}

	return sack;
}

void print_result(vector<sack_t> sacks)
{
	for (sack_t sack : sacks)
	{
		cout << "\n";
		cout << sack.items.size() << "\n";
		for (item_t item : sack.items)
		{
			cout << item.index << " ";
		}
	}

	cout << "\n";
}

vector<sack_t> pack_all_sacks(vector<sack_t> sacks)
{
	vector<sack_t> packed;

	for (sack_t sack : sacks)
	{
		sack = pack_sack(sack);
		packed.push_back(sack);
	}

	return packed;
}

int main()
{
	vector<string> data;
	string line;
	while (std::getline(std::cin, line))
	{
		// std::cout << line << std::endl;
		data.push_back(line);
	}
	if (data.size() == 0)
		return 0;
	vector<sack_t> sacks = parse_input(data);
	sacks = pack_all_sacks(sacks);
	print_result(sacks);
	return 0;
}