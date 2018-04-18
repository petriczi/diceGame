#ifndef Player_data
#define Player_data

#include<iostream>
#include<string>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include<fstream>
#include "Dicee.h"
extern 	vector < int > dices_tab;
using namespace std;
class Player
{

public:
	int points;
	string name;
	Player(string xname, int xpoints);
	Player();
	void get_name();
	void throw_dices(int number_player);
	void throw_again(int number_player,int x); // da sie przeladowanie zrobic.
	void select_table(int player_points, int x);
private:
	Dice my_dice;
};
#endif