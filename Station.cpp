// Name: Agam Airi
// Seneca Student ID: 116731217
// Seneca email: aairi@myseneca.ca
// Date of completion: 17 Nov 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"

namespace sdds {
    size_t Station::m_widthField = 0;
    int Station::id_generator = 0;

    Station::Station(const std::string& str) {
        size_t position = 0;
        bool flag = true;
        Utilities utilObj;
        m_stationId = ++id_generator;
        try {
            m_itemName = utilObj.extractToken(str, position, flag);
            m_nextSerial = stoi(utilObj.extractToken(str, position, flag));
            m_itemCount = stoi(utilObj.extractToken(str, position, flag));
            Station::m_widthField = Station::m_widthField > utilObj.getFieldWidth() ? Station::m_widthField : utilObj.getFieldWidth();
            m_description = utilObj.extractToken(str, position, flag);
        }
        catch (std::invalid_argument& e) {
            throw e;
        }
    }

    void Station::updateQuantity() {
        if (m_itemCount >= 1) {
            m_itemCount--;
        }
            
    }

    void Station::display(std::ostream& ostr, bool full) const {
        ostr << std::setw(3) << std::setfill('0') << std::right << m_stationId
            << " | " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_itemName << "  | "
            << std::setw(6) << std::right << std::setfill('0') << m_nextSerial << " | ";
        if (full)
        {
            ostr << std::setw(4) << std::setfill(' ') << std::right << m_itemCount << " | "
                << m_description;
        }
        ostr << std::endl;
    }
}