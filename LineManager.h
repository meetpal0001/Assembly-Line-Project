// Name: Meetpal Singh
// Seneca Student ID: 125926212
// Seneca email: msingh683@myseneca.ca
// Date of completion: 2023/4/8
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef LINEMANAGER_H

#define LINEMANAGER_H

#include <vector>
#include "Workstation.h"
#include <fstream>
#include <string>
#include "Utilities.h"
#include <algorithm>

namespace sdds {

	class LineManager
	{
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void reorderStations();

		bool run(std::ostream& os);
		void display(std::ostream& os) const;

	private:
		std::vector<Workstation*> m_activeLine;
		size_t m_cntCustomerOrder{};
		Workstation* m_firstStation{};
	};



}
#endif // !LINEMANAGER_H

