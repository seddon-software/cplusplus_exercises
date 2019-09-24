#ifndef LADDER_H
#define LADDER_H

#include <iostream>
#include <string>
#include <vector>

#include "Team.h"
using namespace std;

class Team;

class Ladder
{
public:
	Ladder() {}
	void add(const Team& team);
	void print() const;
private:
	vector<const Team*> pTeams;
};

#endif
