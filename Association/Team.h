#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
#include <vector>

#include "Ladder.h"
using namespace std;

class Ladder;

class Team
{
public:
	Team(const string& name);
	friend void operator>>(Team& lhs, Team& rhs);
	string status() const;
	static void printTable();
private:
	static Ladder ladder;
	string name;
	int won;
	int lost;
};

#endif
