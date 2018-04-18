#ifndef exceptions
#define exceptions
#include<string>

using namespace std;
class exception_generator
{
private:
	int error_code;
	string message;
public:
	exception_generator(int error_code, const string& message)
	
		:error_code(error_code),
		message(message)
	{}
	int err_template()//error template always close programm
		const {
		cout << this->message;
		cout << endl;
		system("pause");
		exit(this->error_code);
	}
	string war_template()//warning template only shows info
		const {
		cout << "Warning: " << this->error_code;
		return this->message;
	}
};


	class err_number_dice : public exception_generator
	{
	public:
		err_number_dice() : exception_generator(1, "Error.Bad random number of dice") {};

	};
	class err_numbers_to_random : public exception_generator
	{
	public:
		err_numbers_to_random() : exception_generator(3, "You can't change more numbers than 5, because You have only 5 dices.") {};

	};

	class err_bad_option : public exception_generator
	{
	public:
		err_bad_option() : exception_generator(4, "Select '1' or '2'") {};

	};
	class err_randomize_changes: public exception_generator
	{
	public:
		err_randomize_changes() : exception_generator(5, "You haven't chances to randomize again in  this round.\n\n") {};

	};
	
#endif