// Name: Agam Airi
// Seneca Student ID: 116731217
// Seneca email: aairi@myseneca.ca
// Date of completion: 17 Nov 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

namespace sdds {
    char Utilities::m_delimiter{};


    // Hwlpwe
    void trim(std::string& str) {
        if (str.length() > 0) 
        {
            int begin = str.find_first_not_of(' ');
            int end = str.find_last_not_of(' ');

            if (begin == -1) {
                str = "";
            }
            else {
                str = str.substr(begin, end - begin + 1);
            }
        }
    }


    std::string sdds::Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        
        int tempDel;
        std::string tempStr;


        if (str[next_pos] == m_delimiter) {
            more = false;
            throw - 1;
        }
        else {
            std::string temp = str.substr(next_pos);
            if ((tempDel = temp.find_first_of(m_delimiter)) != -1) {
                tempStr = temp.substr(0, tempDel);
                trim(tempStr);
                next_pos += tempDel + 1;
                more = true;
            }
            else {
                tempStr = temp;
                trim(tempStr);
                more = false;
            }
        }


        if (m_widthField < tempStr.length()) {
            m_widthField = tempStr.length();
        }
            

        return tempStr;
    }


    // setters
    void sdds::Utilities::setFieldWidth(size_t newWidth) {
        m_widthField = newWidth;
    }

    void sdds::Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }


}