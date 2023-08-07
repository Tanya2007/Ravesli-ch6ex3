#include <iostream>
#include <string>
#include <list>

#include "INPUT_VALUE_H.h"
#include "_TBA_H.h"
#include "AIRLINE_TICKETS_H.h"

void addData(std::list<AirlineTickets> &listAir);
void deleteData(std::list<AirlineTickets> &listAir);
void outputData(const std::list<AirlineTickets> &listAir);

int main()
{
#if defined (_WIN32)
	std::system("chcp 1251 > NUL");
#endif

	std::list<AirlineTickets> listAir;
	bool exitAir(false);

	while(!exitAir)
	{
		std::cout << "//////////////////////////////////////////////////////////////////////////\n";
		std::cout << _TBA("Выберите действие (1 - добавить заявки, 2 - удалить заявку, 3 - вывести все заявки на экран, 0 - выход из программы): ");
		int action(inputValue());

		switch(action)
		{
			case 1:
				addData(listAir);
				break;

			case 2:
				deleteData(listAir);
				break;

			case 3:
				outputData(listAir);
				break;

			case 0:
				exitAir = true;
				break;

			default:
				std::cout << _TBA("Не верно выбрано действие.\n");
				break;
		}
	}

	return 0;
}

void addData(std::list<AirlineTickets> &listAir)
{
	std::cout << "//////////////////////////////////////////////////////////////////////////\n";
	std::cout << _TBA("Введите количество бронируемых билетов: ");
	int count(inputValue());

	for(std::size_t i{}; i < static_cast<std::size_t>(count); ++i)
	{
		AirlineTickets obj;
		std::cin >> obj;

		listAir.push_back(std::move(obj));
	}
}

void deleteData(std::list<AirlineTickets> &listAir)
{
	std::cout << "//////////////////////////////////////////////////////////////////////////\n";
	std::cout << _TBA("Введите номер удаляемой заявки: ");
	int numb(inputValue());

	for(auto iter = listAir.begin(); iter != listAir.end(); ++iter)
	{
		if(numb == iter -> getNumberData())
		{
			listAir.erase(iter);
			std::cout << _TBA("Заявка удалена!\n");
			return;
		}
	}
	
	std::cout << _TBA("Заявка с таким номером отсутствует!\n");
}

void outputData(const std::list<AirlineTickets> &listAir)
{
	std::cout << "//////////////////////////////////////////////////////////////////////////\n";
	for(const auto &elem : listAir)
	{
		std::cout << elem << "\n";
	}
}