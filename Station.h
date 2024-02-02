// Name: Agam Airi
// Seneca Student ID: 116731217
// Seneca email: aairi@myseneca.ca
// Date of completion: 17 Nov 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef STATION_H
#define STATION_H

#include <string>
#include <iostream>
#include <iomanip>

#include "Utilities.h"

namespace sdds {
    class Station {
        int m_stationId{};
        std::string m_itemName{};
        std::string m_description{};
        size_t m_nextSerial{};
        size_t m_itemCount{};
        static size_t m_widthField;
        static int id_generator;

    public:
        // constructor
        Station(const std::string& str);
        
        /// Getters
        const std::string& getItemName() const { return m_itemName; };
        size_t getNextSerialNumber() { return m_nextSerial++; };
        size_t getQuantity() const { return m_itemCount; };

        // setter
        void updateQuantity();

        //display
        void display(std::ostream& ostr, bool full) const;
    };
}

#endif // !STATION_H
