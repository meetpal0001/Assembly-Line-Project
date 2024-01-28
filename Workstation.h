// Name: Meetpal Singh
// Seneca Student ID: 125926212
// Seneca email: msingh683@myseneca.ca
// Date of completion: 2023/4/8
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef WORKSTATION_H

#define WORKSTATION_H

#include <deque>
#include "CustomerOrder.h"
#include "Station.h"
#include <iomanip>

namespace sdds {

	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete;

	class Workstation: public Station
	{
	public:
		Workstation(const std::string& record);

		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);

	private:
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pnextStation{};
	};



	
}
#endif // !WORKSTATION_H

