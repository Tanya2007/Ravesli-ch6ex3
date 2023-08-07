#ifndef AIRLINE_TICKETS_H
#define AIRLINE_TICKETS_H

#include <iostream>
#include <string>
#include <utility>
#include <iomanip>

#include "INPUT_VALUE_H.h"
#include "_TBA_H.h"

struct PassengersFullName
{
	std::string m_surname;
	std::string m_name;
	std::string m_patronymic;
};

class Date
{
		int m_day;
		int m_month;
		int m_year;

	public:
		Date()
			: m_day{}, m_month{}, m_year{}
		{
		}
		
		friend std::istream& operator>>(std::istream &in, Date &obj);
		friend std::ostream& operator<<(std::ostream &out, const Date &obj);
};

class AirlineTickets
{
		static int m_number;
		int m_numberData;
		std::string m_destination;
		int m_flightNumber;
		PassengersFullName m_passengerName;
		Date m_date;

	public:
		AirlineTickets()
			: m_numberData{m_number}, m_destination{}, m_flightNumber{}, m_passengerName{}, m_date{}
		{
			++m_number;
		}
		
		int getNumberData() const;
			
		friend std::istream& operator>>(std::istream &in, AirlineTickets &obj);
		friend std::ostream& operator<<(std::ostream &out, const AirlineTickets &obj);
};

#endif