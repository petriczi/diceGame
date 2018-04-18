#include<iostream>
#include<string>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include<fstream>
#include "Player_data.h"
#include "general.h"
#include "Dicee.h"
#include "exceptions.h"
vector<vector<int>> player_table_flags;
vector < Player > players_tab;
vector < int > dices_tab;

void winner(int round)
{
	if (round == 13)
	{
		cout << "Player: " << players_tab[0].name << ", " << "Points: " << players_tab[0].points << endl;
		cout << "Player: " << players_tab[1].name << ", " << "Points: " << players_tab[1].points << endl;
		if (players_tab[0].points > players_tab[1].points)
		{
			cout << "Player: " << players_tab[0].name << "Won !" << endl;
		}
		else
		{
			cout << "Player: " << players_tab[1].name << "Won !" << endl;
		}
	}//if
}//end winner

int main()
{
	srand(time(NULL));
	Player p1;
	p1.get_name();
	Player p2;
	p2.get_name();
	int round = 1;
	while (round <= 13)
	{
		p1.throw_dices(0);
		p1.throw_again(0, 0);
		p1.select_table(0, 0);
		dices_tab.clear();
		system("cls");
		p2.throw_dices(1);
		p2.throw_again(1, 1);
		p2.select_table(1, 1);
		dices_tab.clear();
		system("cls");
		winner(round);
		round++;
	}
	system("pause");
	return 0;
}