#include "Player_data.h"
#include "general.h"
#include "Dicee.h"
#include "exceptions.h"
#include<iostream>
#include<iostream>
using namespace std;



Player::Player(string xname, int xpoints)
	: name(xname)
	, points(xpoints)
{
}
Player::Player()
{
	name = "wakat";
	points = 0;
}
void Player::get_name()
{
	cout << "Enter name: ";
	string odp_imie;
	cin >> odp_imie;
	Player::name = odp_imie;
	int odp_points = 0;
	players_tab.push_back(Player(odp_imie, odp_points));
}

void Player::throw_dices(int number_player)
{
		try
		{
			for (int x = 1; x <6; x++)
			{
				int tmp_dice = (rand() % 6) + 1;// to daæ do koœci
				if (tmp_dice < 1 || tmp_dice > 6)
				{
					throw  err_number_dice();
				}
				dices_tab.push_back(tmp_dice);
			}
			cout << endl;
			cout << "===============  Player: " << players_tab[number_player].name << " Points: " << players_tab[number_player].points << "  ===============" << endl;
			my_dice.show_dices();
		}//try
		catch (const exception_generator& de)
		{
			cout << de.err_template() << endl;
		}
		catch (bad_alloc())
		{
			cout << "Error in allocate dices table" << endl;
			exit(2);
		}
}

void Player::select_table(int player_points, int x)
{
	int one = my_dice.number_repetitions(1);
	int two = my_dice.number_repetitions(2);
	int three = my_dice.number_repetitions(3);
	int four = my_dice.number_repetitions(4);
	int five = my_dice.number_repetitions(5);
	int six = my_dice.number_repetitions(6);
	int choice = 0;
	try
	{
		for (int i = 0; i < 13; i++)
		{
			int y = 0;
			player_table_flags.push_back(vector<int>());
			player_table_flags[x].push_back(y);


		}
	}//try
	catch (bad_alloc())
	{
		cout << "Error. Failed table flags allocation" << endl;
		exit(2);
	}

	cout << "Table 1:" << endl;
	if (player_table_flags[x][0] == 0)
	{
		cout << "1. One" << "             (" << my_dice.points_tab1(1, one) << ")" << endl;
	}
	if (player_table_flags[x][1] == 0)
	{
		cout << "2. Two" << "             (" << my_dice.points_tab1(2, two) << ")" << endl;
	}
	if (player_table_flags[x][2] == 0)
	{
		cout << "3. Three" << "             (" << my_dice.points_tab1(3, three) << ")" << endl;
	}
	if (player_table_flags[x][3] == 0)
	{
		cout << "4. Four" << "             (" << my_dice.points_tab1(4, four) << ")" << endl;
	}
	if (player_table_flags[x][4] == 0)
	{
		cout << "5. Five" << "             (" << my_dice.points_tab1(5, five) << ")" << endl;
	}
	if (player_table_flags[x][5] == 0)
	{
		cout << "6. Six" << "             (" << my_dice.points_tab1(6, six) << ")" << endl;
	}
	cout << "\n\n Table 2:" << endl;
	if (player_table_flags[x][6] == 0)
	{
		cout << "7. Three identical" << "             (" << my_dice.identical(3) << ")" << endl;
	}
	if (player_table_flags[x][7] == 0)
	{
		cout << "8. Four identical" << "             (" << my_dice.identical(4) << ")" << endl;
	}
	if (player_table_flags[x][8] == 0)
	{
		cout << "9. Full" << "             (" << my_dice.full(3, 2) << ")" << endl;
	}
	if (player_table_flags[x][9] == 0)
	{
		cout << "10. Small strit" << "             (" << my_dice.small_strit() << ")" << endl;
	}
	if (player_table_flags[x][10] == 0)
	{
		cout << "11. Big strit" << "             (" << my_dice.big_strit() << ")" << endl;
	}
	if (player_table_flags[x][11] == 0)
	{
		cout << "12. General" << "             (" << my_dice.generall() << ")" << endl;
	}
	if (player_table_flags[x][12] == 0)
	{
		cout << "13. Chance" << "             (" << my_dice.chance() << ")" << endl;
	}

	cout << "Select option: ";
	do
	{
		cin >> choice;
		int tab_points_iterator = 0;  //0 mean first player in vector
		switch (choice)
		{
		case 1:
		{
			if (player_table_flags[x][0] == 0)
			{
				players_tab[player_points].points = players_tab[player_points].points + my_dice.points_tab1(1, one);
				player_table_flags[x][0] = 1;
			}
			break;
		}
		case 2:
		{
			if (player_table_flags[x][1] == 0)
			{
				players_tab[player_points].points = players_tab[player_points].points + my_dice.points_tab1(2, two);
				player_table_flags[x][1] = 1;
			}
			break;
		}
		case 3:
		{
			if (player_table_flags[x][2] == 0)
			{
				players_tab[player_points].points = players_tab[player_points].points + my_dice.points_tab1(3, three);
				player_table_flags[x][2] = 1;
			}
			break;
		}
		case 4:
		{
			if (player_table_flags[x][3] == 0)
			{
				players_tab[player_points].points = players_tab[player_points].points + my_dice.points_tab1(4, four);
				player_table_flags[x][3] = 1;
			}
			break;
		}
		case 5:
		{
			if (player_table_flags[x][4] == 0)
			{
				players_tab[player_points].points = players_tab[player_points].points + my_dice.points_tab1(5, five);
				player_table_flags[x][4] = 1;
			}
			break;
		}
		case 6:
		{
			if (player_table_flags[x][5] == 0)
			{
				players_tab[player_points].points = players_tab[player_points].points + my_dice.points_tab1(6, six);
				player_table_flags[x][5] = 1;
			}
			break;
		}
		case 7:
		{
			if (player_table_flags[x][6] == 0)
			{
				players_tab[player_points].points = players_tab[player_points].points + my_dice.identical(3);
				player_table_flags[x][6] = 1;
			}
			break;
		}
		case 8:
		{
			if (player_table_flags[x][7] == 0)
			{
				players_tab[player_points].points = players_tab[player_points].points + my_dice.identical(4);
				player_table_flags[x][7] = 1;
			}
			break;
		}
		case 9:
		{
			if (player_table_flags[x][8] == 0)
			{
				players_tab[player_points].points = players_tab[player_points].points + my_dice.full(3, 2);
				player_table_flags[x][8] = 1;
				break;
			}
		}
		case 10:
		{
			if (player_table_flags[x][9] == 0)
			{
				players_tab[player_points].points = players_tab[player_points].points + my_dice.small_strit();
				player_table_flags[x][9] = 1;
			}
			break;
		}
		case 11:
		{
			if (player_table_flags[x][10] == 0)
			{
				players_tab[player_points].points = players_tab[player_points].points + my_dice.big_strit();
				player_table_flags[x][10] = 1;
			}
			break;
		}
		case 12:
		{
			if (player_table_flags[x][11] == 0)
			{
				players_tab[player_points].points = players_tab[player_points].points + my_dice.generall();
				player_table_flags[x][11] = 1;
			}
			break;
		}
		case 13:
		{
			if (player_table_flags[x][12] == 0)
			{
				players_tab[player_points].points = players_tab[player_points].points + my_dice.chance();
				player_table_flags[x][12] = 1;
			}
			break;
		}
		default:
		{
			cout << "\n Selected option is incorrect." << endl;
			break;
		}

		}//end switch (choice)
	} while (choice > 13 || choice == 0);
	
	//dices_tab.clear();

}//end void select_table()

void Player::throw_again(int number_player,int x)
{
	int flag = 2;
	try
	{
	int choice;//for switch
	do
	{
		cout << "\n\n Do You want to randomize again  ?" << endl;
		cout << "1.Yes" << endl;
		cout << "2.No" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			if (flag <= 3)
			{
				my_dice.random_again(number_player, x);
				flag++;
			}
			else
			{
				choice = 2;//for exit with loop  while (choice != 2);
				throw err_randomize_changes();
				break;
			}
			break;
		}//end case 1
		case 2:
		{
			//Player::select_table(number_player,x);
			break;
		}
		default:
		{
			throw err_bad_option();
			break;
			//cout << "Select '1' or '2'" << endl;
		}
		}//end switch
	} while (choice != 2);

		}//try
		catch (const err_numbers_to_random& de)
		{
			cout << de.err_template() << endl;
		}
		catch (const err_bad_option& de)
		{
			cout << de.war_template() << endl;
			Player::throw_again(number_player, x);
		}
		catch (const err_randomize_changes& de)
		{
			cout << de.war_template() << endl;
		}
	}

