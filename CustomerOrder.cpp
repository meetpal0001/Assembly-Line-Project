// Name: Meetpal Singh
// Seneca Student ID: 125926212
// Seneca email: msingh683@myseneca.ca
// Date of completion: 2023/4/8
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>

#include <iomanip>

#include <vector>

#include "Utilities.h"

#include "Station.h"

#include "CustomerOrder.h"

#include <algorithm>

namespace sdds {
  size_t CustomerOrder::m_widthField = 12;

  CustomerOrder::CustomerOrder() {}

  CustomerOrder::CustomerOrder(const std::string & input): CustomerOrder() {
    if (input.length() > 0) {
      size_t pos = 0;
      bool more = true;
      Utilities ut;
      try {
        m_name = ut.extractToken(input, pos, more);
        m_product = ut.extractToken(input, pos, more);
        m_cntItem = std::count(input.begin(), input.end(), ut.getDelimiter()) - 1;
        this -> m_lstItem = new Item * [m_cntItem];
        for (size_t i = 0; i < m_cntItem; i++) {
          Item * temp = new Item(ut.extractToken(input, pos, more));
          m_lstItem[i] = std::move(temp);
          temp = nullptr;
        };

        if (CustomerOrder::m_widthField < ut.getFieldWidth()) {
          CustomerOrder::m_widthField = ut.getFieldWidth();
        }
      } catch (const std::string error) {
        std::cout << error;
      }
    }
  }

  CustomerOrder::CustomerOrder(CustomerOrder
    const & ) {
    throw std::string("Cannot make copies.");
  }
  CustomerOrder::CustomerOrder(CustomerOrder && other) noexcept {
    this -> m_cntItem = other.m_cntItem;
    this -> m_lstItem = other.m_lstItem;
    this -> m_name = other.m_name;
    this -> m_product = other.m_product;

    other.m_cntItem = 0;
    other.m_lstItem = nullptr;
    other.m_name = "";
    other.m_product = "";
  }
  CustomerOrder & CustomerOrder::operator = (CustomerOrder && other) noexcept {
    if (this != & other) {

      if (this -> m_lstItem) {
        for (size_t i = 0; i < this -> m_cntItem; i++) {
          delete this -> m_lstItem[i];
        }
        delete[] m_lstItem;
      }
      this -> m_lstItem = nullptr;

      this -> m_cntItem = other.m_cntItem;
      this -> m_lstItem = other.m_lstItem;
      this -> m_name = other.m_name;
      this -> m_product = other.m_product;

      other.m_cntItem = 0;
      other.m_lstItem = nullptr;
      other.m_name = "";
      other.m_product = "";
    }

    return *this;
  }
  CustomerOrder::~CustomerOrder() {
    if (this -> m_lstItem) {
      for (size_t i = 0; i < this -> m_cntItem; i++) {
        delete this -> m_lstItem[i];
      }
      delete[] m_lstItem;
    }
    this -> m_lstItem = nullptr;
  }
  bool CustomerOrder::isOrderFilled() const {
    bool filled = true;
    for (size_t i = 0; i < m_cntItem && filled; i++) {
      if (!m_lstItem[i] -> m_isFilled) filled = false;
    }
    return filled;
  }
  bool CustomerOrder::isItemFilled(const std::string & itemName) const {
    bool found = false;
    bool val = true;
    std::vector < Item * > matchedItems;
    for (size_t i = 0; i < m_cntItem; i++) {
      if (m_lstItem[i] -> m_itemName == itemName) {
        found = true;
        matchedItems.push_back(m_lstItem[i]);
      }
    }

    if (found) {
      val = std::all_of(matchedItems.begin(), matchedItems.end(), [](const Item * ptr) {
        return ptr -> m_handled == true;
      });
    }

    return val;
  }
  void CustomerOrder::fillItem(Station & station, std::ostream & os) {
    bool flag = true;
    for (size_t i = 0; i < m_cntItem && flag; i++) {

      if (m_lstItem[i] -> m_itemName == station.getItemName() && !m_lstItem[i] -> m_handled) {
        flag = false;
        if (station.getQuantity() > 0) {
          station.updateQuantity();
          m_lstItem[i] -> m_isFilled = true;
          m_lstItem[i] -> m_handled = true;
          m_lstItem[i] -> m_serialNumber = station.getNextSerialNumber();
          os << "    Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std::endl;
        } else {
          for (size_t k = 0; k < m_cntItem; k++) {
            if (m_lstItem[k] -> m_itemName == station.getItemName() && !m_lstItem[k] -> m_handled) {
              m_lstItem[k] -> m_handled = true;
              os << "    Unable to fill " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std::endl;
            }
          }
        }
      }
    }
  }
  void CustomerOrder::display(std::ostream & os) const {
    os << this -> m_name << " - " << this -> m_product << std::endl;

    for (size_t i = 0; i < this -> m_cntItem; i++) {
      os << "[" << std::setw(6)<<std::right<<std::setfill('0') << this -> m_lstItem[i] -> m_serialNumber << "] ";
      os << std::setfill(' ') << std::left << std::setw(m_widthField) << this -> m_lstItem[i] -> m_itemName;
      if (this -> m_lstItem[i] -> m_isFilled) {
        os << "   - " << "FILLED";
      } else {
        os << "   - " << "TO BE FILLED";
      }
      os << std::endl;
    }
  }
}
