/*
 Define and implement a Ladder class that represents a squash league in which
 teams play each other. Create a Team class to hold each team's results
 (number of games won, drawn and lost). The Ladder class will hold a list of
 all the teams.
Create a test harness that defines the results of several games and prints
out the current standings of the table.

 */
#include <iostream>
#include <sstream>

#include "Team.h"


int main()
{

	Team spurs("Spurs");
	Team rangers("Rangers");
	Team rockets("Rockets");
	Team stingray("Stingray");
	spurs >> rangers;
	rockets >> spurs;
	rockets >> stingray;
	stingray >> spurs;
	Team::printTable();
}

