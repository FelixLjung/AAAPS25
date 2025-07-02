#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct item {
    int value;
    int index;
    item(int value, int index) {
        this->value = value;
        this->index = index;
    }
} item_t;


vector<item_t> read_seq(string line) {
    vector<item_t> seq;
    int index = 0;
    for (int i = 0; i < line.length();i++) {
        char c = line[i];
        if (c == ' ') continue;
        item_t *item = item(c+"",index++);
        seq.push_back(c+"");
    }
}


void parse_input(vector<string> lines) {

    for (int i = 1; i < lines.size();i+=2) {
        vector<item_t> seq = read_seq(lines.at(i)) 

        
    }
}


int main() {

    vector<string> data;
	string line;
	while (std::getline(std::cin, line))
	{
		// std::cout << line << std::endl;
		data.push_back(line);
	}




}