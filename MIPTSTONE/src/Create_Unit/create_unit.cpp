#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

void CRunit() {
	std::ofstream fout;
	fout.open("prepods.txt", std::ios::app);

	fout << '\n';
	
	std::cout << "Enter the name of a new fucker" << '\n';
	std::string name_;
	std::cin >> name_;
	fout << name_ << '\n';

	std::cout << "Enter the department of your fucker" << '\n';
	std::string department_;
	std::cin >> department_;
	fout << department_ << '\n';

	std::cout << "Enter the knowledge of your fucker" << '\n';
	double knowledge_;
	std::cin >> knowledge_;
	fout << knowledge_ << '\n';

	std::cout << "Enter the teaching level of your fucker" << '\n';
	double teaching_;
	std::cin >> teaching_;
	fout << teaching_ << '\n';
	std::cout << "Enter the communication level of your fucker" << '\n';
	double communication_;
	std::cin >> communication_;
	fout << communication_ << '\n';

	std::cout << "Enter the khaluavnost of your fucker" << '\n';
	double khaluavnost_;
	std::cin >> khaluavnost_;
	fout << khaluavnost_ << '\n';
	
	fout.close();
}