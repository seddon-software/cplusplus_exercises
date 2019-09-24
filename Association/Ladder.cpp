#include "Ladder.h"

#include <iostream>
#include <sstream>

class Team;

void Ladder::add(const Team& team)
{
	pTeams.push_back(&team);
}

void Ladder::print() const
{
	for(const auto* pTeam : pTeams)
	{
		cout << pTeam->status();
	}
}


