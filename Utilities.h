// Name: Agam Airi
// Seneca Student ID: 116731217
// Seneca email: aairi@myseneca.ca
// Date of completion: 17 Nov 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
namespace sdds {

    class Utilities
    {
        // data members
        size_t m_widthField = 1;
        static char m_delimiter;

    public:
        // getters
        size_t getFieldWidth() const { return m_widthField; };
        static char getDelimiter() { return m_delimiter; };
        
        std::string extractToken(const std::string&, size_t&, bool&);

        // setters
        void setFieldWidth(size_t);
        static void setDelimiter(char);
    };
    // Helper function
    void trim(std::string& str);
}

#endif // !UTILITIES_H
