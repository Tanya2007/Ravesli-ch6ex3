#include "AIRLINE_TICKETS_H.h"

int AirlineTickets::m_number = 1;

std::istream& operator>>(std::istream &in, Date &obj)
{
	std::cout << _TBA("\nГод: ");
	while(true)
	{
		obj.m_year = inputValue();
		if(obj.m_year >= 2000 && obj.m_day <= 3000)
		{
			break;
		}

		std::cout << _TBA("\nНеверно введен год. Повторите снова: ");
	}

	std::cout << _TBA("\nМесяц: ");
	while(true)
	{	
		obj.m_month = inputValue();
		if(obj.m_month >= 1 && obj.m_month <= 12)
		{
			break;
		}

		std::cout << _TBA("\nНеверно введен месяц. Повторите снова: ");
	}

	std::cout << _TBA("\nДень: ");
	while(true)
	{
		obj.m_day = inputValue();
		switch(obj.m_month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if(obj.m_day >= 1 && obj.m_day <= 31)
				{
					return in;
				}
				break;
				
			case 2:
				if(obj.m_year % 4 == 0)
				{
					if(obj.m_day >= 1 && obj.m_day <= 29)
					{
						return in;
					}
				}
				else
				{
					if(obj.m_day >= 1 && obj.m_day <= 28)
					{
						return in;
					}
				}
				break;
				
			case 4:
			case 6:
			case 9:
			case 11:
				if(obj.m_day >= 1 && obj.m_day <= 30)
				{
					return in;
				}
				break;
		}

		std::cout << _TBA("\nНеверно введен день. Повторите снова: ");
	}
	
	return in;
}

std::istream& operator>>(std::istream &in, AirlineTickets &obj)
{
	std::cout << _TBA("Введите пункт назначения: ");
	std::getline(in, obj.m_destination);
	std::cout << "\n";

	std::cout << _TBA("Введите номер рейса: ");
	obj.m_flightNumber = inputValue();
	std::cout << "\n";

	std::cout << _TBA("Введите фамилию пассажира: ");
	std::getline(in, obj.m_passengerName.m_surname);
	std::cout << "\n";

	std::cout << _TBA("Введите имя пассажира: ");
	std::getline(in, obj.m_passengerName.m_name);
	std::cout << "\n";

	std::cout << _TBA("Введите отчество пассажира: ");
	std::getline(in, obj.m_passengerName.m_patronymic);
	std::cout << "\n";

	std::cout << _TBA("Введите желаемую дату вылета");
	in >> obj.m_date;
	std::cout << "\n";
	
	return in;
}

std::ostream& operator<<(std::ostream &out, const Date &obj)
{
	out << ((obj.m_day < 10) ? "0" : "") << obj.m_day << ".";
	out << ((obj.m_month < 10) ? "0" : "") << obj.m_month << "." << obj.m_year;
	
	return out;
}

std::ostream& operator<<(std::ostream &out, const AirlineTickets &obj)
{
	out << std::setw(20) << std::left << _TBA("Номер заявки: ");
	out << obj.m_numberData << "\n";
	out << std::setw(20) << std::left << _TBA("Пункт назначения: ");
	out << obj.m_destination << "\n";
	out << std::setw(20) << std::left << _TBA("Номер рейса: ");
	out << obj.m_flightNumber << "\n";
	out << std::setw(20) << std::left << _TBA("ФИО пассажира: ");
	out << obj.m_passengerName.m_surname << " " << obj.m_passengerName.m_name;
	out << " " << obj.m_passengerName.m_patronymic << "\n";
	out << std::setw(20) << std::left << _TBA("Дата вылета: ");
	out << obj.m_date << "\n";

	return out;
}

int AirlineTickets::getNumberData() const
{
	return m_numberData;
}