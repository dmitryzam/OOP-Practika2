#include<iostream>
#include<string>
#include"Map.hpp"

int main() {
	setlocale(LC_ALL, "RU");
	std::cout << "Создадим первую коллекцию:\n";
	Map<std::string, int> mp1;
	std::cout << "Размер коллекции 1 - " << mp1.size() << " до добавления элементов.\n";

	mp1.setItem("Russia", 7);
	mp1.setItem("USA", 1);
	mp1.setItem("France", 33);
	mp1.setItem("Japan", 81);
	mp1.setItem("Japan", 81);
	std::cout << "Размер коллекции 1 - " << mp1.size() << " после добавления элементов.\n";
			
	std::cout << "Телефонный код Japan - +" << mp1["Japan"] << '\n';
	std::cout << "Телефонный код France - +" << mp1["France"] << '\n';
	std::cout << "Телефонный код Russia - +" << mp1["Russia"] << '\n';

	std::cout << "\nСоздадим новую коллекцию на основе первой коллекции:\n";
	Map<std::string, int> mp2(mp1);
	std::cout << "Размер коллекции 2 - " << mp2.size() << '\n';
	std::cout << "Телефонный код Japan - +" << mp2["Japan"] << '\n';
	std::cout << "Телефонный код France - +" << mp2["France"] << '\n';
	std::cout << "Телефонный код Russia - +" << mp2["Russia"] << '\n';

	//std::cout << "\nСоздадим третью коллекцию с помощью списка инициализации:\n";

	//Map<std::string, int> mp3(("India", 91), ("Belarussia", 375), ("Avstralia", 61));
	//Map<std::string, int> mp3("India", 91);



	
	




	return 0;
}