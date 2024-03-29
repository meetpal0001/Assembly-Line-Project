// Name: Meetpal Singh
// Seneca Student ID: 125926212
// Seneca email: msingh683@myseneca.ca
// Date of completion: 2023/4/8
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include "Utilities.h"
#include "Station.h"

namespace sdds {
    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 1;
    Station::Station() {}
    Station::~Station() {}

    Station::Station(const std::string& record)
    {
        m_id = id_generator++;

        Utilities utils;
        size_t npos = 0;
        bool more;

        try {
            m_name = utils.extractToken(record, npos, more);
            m_nextSerial = std::stoi(utils.extractToken(record, npos, more));
            m_stockQty = std::stoi(utils.extractToken(record, npos, more));

            m_widthField = std::max(utils.getFieldWidth(), m_widthField);

            m_desc = utils.extractToken(record, npos, more);
        }
        catch (std::string& err) {
            std::cout << err;
        }
    }

    const std::string& Station::getItemName() const
    {
        return m_name;
    }

    size_t Station::getNextSerialNumber()
    {
        return m_nextSerial++;
    }

    size_t Station::getQuantity() const
    {
        return m_stockQty;
    }

    void Station::updateQuantity()
    {
        if (0 > --m_stockQty) m_stockQty = 0;
    }

    void Station::display(std::ostream& os, bool full) const
    {
        os << std::setfill('0') << std::setw(3) << std::right << m_id << " | ";
        os << std::setw(m_widthField) << std::setfill(' ') << std::left << m_name << "  | ";
        os << std::setfill('0') << std::setw(6) << std::right << m_nextSerial << " | ";

        if (full) {
            os << std::setw(4) << std::setfill(' ') << std::right << m_stockQty << " | ";
            os << m_desc << std::endl;
        }
        else os << std::endl;
    }
}



