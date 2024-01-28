// Name: Meetpal Singh
// Seneca Student ID: 125926212
// Seneca email: msingh683@myseneca.ca
// Date of completion: 2023/4/8
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"

namespace sdds {

    std::deque<CustomerOrder> g_pending{};
    std::deque<CustomerOrder> g_completed{};
    std::deque<CustomerOrder> g_incomplete{};



    Workstation::Workstation(const std::string& record) : Station(record) {
    }

    void Workstation::fill(std::ostream& os) {
        if (m_orders.size() > 0) {
            m_orders.front().fillItem(*this, os);
        }
    }

    bool Workstation::attemptToMoveOrder() {
        bool val = false;
        if (m_orders.size() > 0) {
            if (m_orders.front().isItemFilled(getItemName()) || getQuantity() == 0) {
                if (getNextStation()) {
                    *getNextStation() += std::move(m_orders.front());
                }
                else {
                    if (m_orders.front().isOrderFilled()) {
                        g_completed.push_back(std::move(m_orders.front()));
                    }
                    else {
                        g_incomplete.push_back(std::move(m_orders.front()));
                    }
                }
                m_orders.pop_front();
                val = true;
            }
        }
        return val;
    }

    void Workstation::setNextStation(Workstation* station) {
        m_pnextStation = station;
    }

    Workstation* Workstation::getNextStation()const {
        return m_pnextStation;
    }

    void Workstation::display(std::ostream& os)const {
        os << getItemName() << " --> ";
        if (getNextStation()) {
            os << getNextStation()->getItemName();
        }
        else {
            os << "End of Line";
        }
        os << std::endl;
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(std::move(newOrder));
        return *this;
    }
}