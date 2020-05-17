/* Пользователь вводит натуральное четырёхзначное число. Выяснить, является ли оно
палиндромом (читается одинаково как слева направо, так и справа налево). */

#include <iostream>
using std::cout; using std::cin; using std::endl;

// получаем от пользователя положительное целое четырёхзначное число
const unsigned short get_4_signes_number()
{
	cout << "Введите положительное целое четырёхзначное число: ";
	int number{ 0 };
	cin >> number;
	while (cin.fail() || (number < 1000) || (number > 9999))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Вы ввели что-то не то, введите положительное целое четырёхзначное число: ";
		cin >> number;
	}
	return static_cast<unsigned short>(number);
}

// проверяем четырёхзначное число на "палиндромность"
bool check_number_is_palindrom(const unsigned short number)
{
	const unsigned short thousands = number / 1000;
	const unsigned short hundreds = (number / 100) % 10;
	const unsigned short tens = (number / 10) % 10;
	const unsigned short last_sign = number % 10;
	if ((thousands == last_sign) && (hundreds == tens))
		return true;
	else return false;
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	while (true)
	{
		unsigned short number_to_check{ get_4_signes_number() };
		if (check_number_is_palindrom(number_to_check))
			cout << number_to_check << " является палиндромом" << endl << endl;
		else 
			cout << number_to_check << " не является палиндромом" << endl << endl;
	}
	return 0;
}