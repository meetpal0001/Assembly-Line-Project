// Name: Meetpal Singh
// Seneca Student ID: 125926212
// Seneca email: msingh683@myseneca.ca
// Date of completion: 2023/4/8
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include "Station.h"
#include <string>

namespace sdds {
	class CustomerOrder {
			struct Item
			{
				std::string m_itemName;
				size_t m_serialNumber{ 0 };
				bool m_isFilled{ false };
				bool m_handled{ false };
				Item(const std::string& src) : m_itemName(src) {};
			};

			std::string m_name;
			std::string m_product; 
			size_t m_cntItem;
			Item** m_lstItem; 
			static size_t m_widthField;

		public:
			CustomerOrder();
			CustomerOrder(const std::string&);
			CustomerOrder(CustomerOrder const&);
			CustomerOrder& operator=(CustomerOrder const&) = delete;
			CustomerOrder(CustomerOrder&&) noexcept;
			CustomerOrder& operator=(CustomerOrder&& other) noexcept;
			~CustomerOrder();
			bool isOrderFilled() const;
			bool isItemFilled(const std::string& itemName) const;
			void fillItem(Station& station, std::ostream& os);
			void display(std::ostream& os) const;
	};
}

#endif //SDDS_CUSTOMERORDER_H
