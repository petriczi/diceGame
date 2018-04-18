#ifndef Dicee
#define Dicee
#include <vector>

using namespace std;
class Dice
{

public:
	void show_dices();
	void random_again(int number_player, int x);//2 values for 2 players. 0 -first player, 1 -second
	int number_repetitions(int number);
	int points_tab1(int number, int repetitions);
	int identical(int number);// this parameter must adopt volues: 3 or 4.
	int full(int number, int number2);//// this parameter must adopt volues: 3 or 2.
	int small_strit();
	int big_strit();
	int generall();
	int chance();
};


#endif
