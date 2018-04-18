#include "Player_data.h"
#include "general.h"
#include "Dicee.h"
#include "exceptions.h"
#include<iostream>

	void Dice::show_dices()
	{
		cout << "\n\nYour currently dices: ";
		for (int x = 0; x < 5; x++)
		{
			cout << dices_tab[x] << " ";
		}
		cout << "\n\n";
	}



	void Dice::random_again(int number_player, int x)//2 values for 2 players. 0 -first player, 1 -second
	{
		try
		{
			cout << "How meny numbers do You want to change ?: ";
			int how_numbers = 0;
			cin >> how_numbers;
			if (how_numbers > 5)
			{
				throw err_numbers_to_random();
			}
			else
			{
				int number_to_randomize = 0;
				for (int x = 1; x <= how_numbers; x++)
				{
					cout << "Select number to randomize: ";
					cin >> number_to_randomize;
					for (int y = 0; y < 5; y++)
					{
						if (number_to_randomize == dices_tab[y])
						{
							int tmp_dice = (rand() % 6) + 1;
							dices_tab[y] = tmp_dice;
						}
					}
				}
				system("cls");
				Dice::show_dices();
			}
		}

		catch (const err_randomize_changes& de)
		{
			cout << de.war_template() << endl;
			system("pause");
		}
	}
	int Dice::number_repetitions(int number)
	{
		int x, how = 0;
		for (x = 0; x <dices_tab.size(); x++)
			if (dices_tab[x] == number)
				how++;
		return how;
	}
	int Dice::points_tab1(int number, int repetitions)
	{
		int temp = 0;
		temp = number*repetitions;
		return temp;
	}

	int Dice::identical(int number)// this parameter must adopt volues: 3 or 4.
	{
		int temp = 0;
		if (number_repetitions(1) == number || number_repetitions(2) == number || number_repetitions(3) == number || number_repetitions(4) == number || number_repetitions(5) == number || number_repetitions(6) == number)
		{
			int one = number_repetitions(1);
			int two = number_repetitions(2);
			int three = number_repetitions(3);
			int four = number_repetitions(4);
			int five = number_repetitions(5);
			int six = number_repetitions(6);
			temp = points_tab1(1, one) + points_tab1(2, two) + points_tab1(3, three) + points_tab1(4, four) + points_tab1(5, five) + points_tab1(6, six);
		}
		return temp;

	}
	int Dice::full(int number, int number2)//// this parameter must adopt volues: 3 or 2.
	{
		int temp = 0;
		if ((number_repetitions(1) == number || number_repetitions(2) == number || number_repetitions(3) == number || number_repetitions(4) == number || number_repetitions(5) == number || number_repetitions(6) == number) && (number_repetitions(1) == number2 || number_repetitions(2) == number2 || number_repetitions(3) == number2 || number_repetitions(4) == number2 || number_repetitions(5) == number2 || number_repetitions(6) == number2))
		{
			temp = 25;
		}
		return temp;
	}
	int Dice::small_strit()
	{
		int temp = 0;
		if (dices_tab[0] == 1 && dices_tab[1] == 2 && dices_tab[2] == 3 && dices_tab[3] == 4)
		{
			temp = 30;
		}
		else if (dices_tab[0] == 2 && dices_tab[1] == 3 && dices_tab[2] == 4 && dices_tab[3] == 5)
		{
			temp = 30;
		}
		else if (dices_tab[1] == 1 && dices_tab[2] == 2 && dices_tab[3] == 3 && dices_tab[4] == 4)
		{
			temp = 30;
		}
		else if (dices_tab[1] == 2 && dices_tab[2] == 3 && dices_tab[3] == 4 && dices_tab[4] == 5)
		{
			temp = 30;
		}
		return temp;
	}
	int Dice::big_strit()
	{
		int temp = 0;
		if (dices_tab[0] < dices_tab[1] && dices_tab[1] < dices_tab[2] && dices_tab[2] < dices_tab[3] && dices_tab[3] < dices_tab[4])
		{
			temp = 40;
		}
		return temp;
	}
	int Dice::generall()
	{
		int temp = 0;
		if ((dices_tab[0] == dices_tab[1]) && (dices_tab[1] == dices_tab[2]) && (dices_tab[2] == dices_tab[3]) && (dices_tab[3] == dices_tab[4]))
		{
			temp = 50;
		}
		return temp;

	}
	int Dice::chance()
	{
		int temp = 0;
		temp = dices_tab[0] + dices_tab[1] + dices_tab[2] + dices_tab[3] + dices_tab[4];
		return temp;
	}



