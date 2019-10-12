#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

class Query
{
public:
	Query(int salary):salary(salary) {}
	bool operator() (const pair<string, int>& i)
	{
		return get<1>(i) < salary;
	}
private:
	int salary;
};


bool LessThan24K(const pair<string, int>& i)
{
	//cout << get<0>(i) << ", " << get<1>(i) << endl;
	return get<1>(i) < 24000;
}

int main()
{
    map<string, int> salary;
    salary["John"]  = 45000;
    salary["Mary"]  = 55000;
    salary["Peter"] = 21000;
    salary["Ali"]   = 27000;
    salary["Zahir"] = 53000;

    map<string, int>::iterator i;
    Query q(25000);
    int s = 25000;
    i = find_if(
    		salary.begin(),
    		salary.end(),
    		[&](const pair<string, int>& i)
    		{
    			return get<1>(i) < s;
    		});
    if(i != salary.end())
    {
    	cout << get<0>(*i) << ", " << get<1>(*i) << endl;
    }
    else
    {
    	cout << "not found" << endl;
    }




    for(i = salary.begin(); i != salary.end(); ++i)
    {
    	//const auto& entry = *i;
    	cout << get<0>(*i) << ", " << get<1>(*i) << endl;
    }
}
