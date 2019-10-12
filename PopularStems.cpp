/********************************************************************
 *
 * Popular Stems from /usr/share/dict/words
 *
 *******************************************************************/

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <array>
#include <string>
#include <map>
using namespace std;
#define WORD_LENGTH 120


map<string, int> determineStems(vector<string>& words)
{
	// build a dictionary of (stem, count) pairs
	map<string, int> stemCounts;

	for(string word : words)
	{
		for(unsigned i = 1; i <= word.size(); i++)
		{
			string stem = word.substr(0, i);
			stemCounts[stem]++;
		}
	}
	return stemCounts;
}

array<tuple<string,int>,WORD_LENGTH> processStems(map<string, int> stemCounts)
{
    /*
       build an array containing (stem, count) tuples
       - element 2 contains the most popular 2 stem
       - element 3 contains the most popular 3 stem
       - element 4 contains the most popular 4 stem ...
    */
	array<tuple<string,int>,WORD_LENGTH> popularStems;
	popularStems.fill(make_tuple("", 0));

	for(auto i = stemCounts.begin(); i != stemCounts.end(); ++i)
	{
		auto t = *i;
		string key = get<0>(t);
		int value = get<1>(t);
		int index = key.size();
		string popularKey = get<0>(popularStems[index]);
		int popularValue = get<1>(popularStems[index]);
		if(popularValue < value)
		{
			popularStems[index] = make_tuple(key, value);
		}
	}
    return popularStems;
}

vector<string> extractLinesFromFile(const string& fileName)
{
    // build list containing the test data
	vector<string> v;

	ifstream in(fileName, ios::in);
	if (!in.is_open()) {
	    cerr << "failed to open " << fileName << endl;
	}

	for(string line; getline(in, line); )
	{
	    v.push_back(line);
	}

    return v;
}

int main()
{
	auto words = extractLinesFromFile("/usr/share/dict/words");
	auto stemCounts = determineStems(words);
	auto popularStems = processStems(stemCounts);

	for(int i = 2; i < 20; i++)
	{
		auto t = popularStems[i];
		cout << i << ": " << get<0>(t) << " -> " << get<1>(t) << endl;
	}
}
