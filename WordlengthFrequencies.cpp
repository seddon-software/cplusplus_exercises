/********************************************************************
 *
 * Word lengths from /usr/share/dict/words
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

/*
 import matplotlib.pyplot as plt

def displayPlot():
    plt.title('Frequency of word lengths in /usr/share/dict/words')
    plt.xlabel('word length', fontsize=16)
    plt.ylabel('frequency', fontsize=16)
    plt.show()

def generateStepPlot(occurances):
    keys = occurances.keys()
    keys = [key+0.5 for key in keys] # adjust x axis legend by 0.5
    values = occurances.values()
    plt.step(keys, values, color='red')
    old_key = keys[0]
    for key, value in zip(keys, values):
        plt.fill_between([old_key, key], [value, value], [0, 0])
        # this generates a warning although it shouldn't (its a bug in matplotlib)
        old_key = key

def calculateOccurancesOfWords(words):
    occurances = {}
    for word in words:
        length = len(word)
        if length in occurances:
            occurances[length] += 1
        else:
            occurances[length] = 1
    return occurances

def readInputFile(fileName):
    try:
        with open(fileName, "r") as f:
            allLines = f.readlines()
            return allLines
    except IOError,e:
        print e


words = readInputFile("/usr/share/dict/words")
occurances = calculateOccurancesOfWords(words)
generateStepPlot(occurances)
displayPlot()


 */


#include <iostream>

using namespace std;

vector<string> readFile(const string& fileName)
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

map<int,int> calculateFrequencies(const vector<string>& words)
{
    map<int,int> frequencies;

    for (auto word : words)
    {
    	frequencies[word.size()]++;
    }
    return frequencies;
}

int main()
{
	auto words = readFile("/usr/share/dict/words");
	auto results = calculateFrequencies(words);

	for(auto t : results)
	{
		cout << get<0>(t) << ": " << get<1>(t) << endl;
	}
	cout << endl;
}
