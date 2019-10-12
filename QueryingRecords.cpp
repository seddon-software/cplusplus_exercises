/********************************************************************
 *
 *		Querying Records from Files
 *
 *******************************************************************/

#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <list>
#include <sstream>

using namespace std;

list<string> extractLinesFromFile(const string& fileName)
{
	list<string> lines;

	ifstream in(fileName, ios::in);
	if (!in.is_open()) {
	    cerr << "failed to open " << fileName << endl;
	}

	for(string line; getline(in, line); )
	{
	    lines.push_back(line);
	}

    return lines;
}

class Record
{
public:
	static void defineColumns(const string& titles)
	{
		istringstream titleStream(titles);
		string column;
		char delimiter = ',';
		while (getline(titleStream, column, delimiter)) {
			columns.push_back(column);
		}
	}

	Record(const vector<string>& tokens)
	{
		for(unsigned i = 0; i < columns.size(); i++)
		{
			fields[columns[i]] = tokens[i];
		}
	}

	bool query(const string& field, const string& value) const
	{
		// note operator[] is not const, so have to use find
		auto items = *fields.find(field);
		auto objectValue = get<1>(items);
		return objectValue == value;
	}

	friend ostream& operator<<(ostream& out, const Record& r);
private:
	static vector<string> columns;
	unordered_map<string, string> fields;
};

// define static variables
vector<string> Record::columns;

ostream& operator<<(ostream& out, const Record& r)
{
	for(auto it = r.fields.begin(); it != r.fields.end(); ++it)
	{
		out << it->first << "=" << it->second << " ";
	}
	return out;
}

list<Record> convertLinesToRecords(const list<string>& lines)
{
	list<Record> records;
	for (auto& line : lines) {
		vector<string> tokens;
		string token;
		istringstream tokenStream(line);
		char delimiter = ',';
		while (std::getline(tokenStream, token, delimiter)) {
			tokens.push_back(token);
		}
		Record record(tokens);
		records.push_back(record);
	}
	return records;
}

void query(const list<Record>& records, const string& field, const string& value) {
	cout << "Query:" << field << " = " << value << endl;
	for (const auto& r : records)
	{
		if (r.query(field, value))
			cout << r << endl;
	}
	cout << endl;
}

void setupTitles(list<string>& lines)
{
	// read column titles
	string titles = lines.front();
	lines.pop_front(); // remove Title line
	Record::defineColumns(titles);
}

int main()
{
	auto lines = extractLinesFromFile("C++/sales.csv");
	setupTitles(lines);
	list<Record> records = convertLinesToRecords(lines);

	// perform queries
	query(records, "Status", "presented");
	query(records, "Product", "CPU");
}
