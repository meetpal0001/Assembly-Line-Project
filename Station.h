// Name: Meetpal Singh
// Seneca Student ID: 125926212
// Seneca email: msingh683@myseneca.ca
// Date of completion: 2023/4/8
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <string>

namespace sdds {
    class Station {
        int m_id;
        std::string m_name;
        std::string m_desc;
        int m_nextSerial;
        int m_stockQty;

        static size_t m_widthField;
        static size_t id_generator;

    public:
        Station();
        virtual ~Station();
        Station(const std::string& record);

        const std::string& getItemName() const;

        size_t getNextSerialNumber();

        size_t getQuantity() const;

        void updateQuantity();

        void display(std::ostream& os, bool full) const;

    };
}


#endif //SDDS_STATION_H