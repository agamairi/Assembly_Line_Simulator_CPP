// Name: Agam Airi
// Seneca Student ID: 116731217
// Seneca email: aairi@myseneca.ca
// Date of completion: 23 Nov 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H


#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "Utilities.h"
#include "Station.h"

namespace sdds
{
    struct Item
    {
        std::string m_itemName;
        size_t m_serialNumber{ 0 };
        bool m_isFilled{ false };

        Item(const std::string& source) : m_itemName(source) {};
    };
    class CustomerOrder
    {
        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{};
        Item** m_lstItem{};

        static size_t m_widthField;

    public:
        CustomerOrder() {};
        CustomerOrder(const std::string& str);
        CustomerOrder(const CustomerOrder& customerOrderObj);
        CustomerOrder(CustomerOrder&& obj) noexcept;
        CustomerOrder& operator=(CustomerOrder&& obj) noexcept;
        ~CustomerOrder();
        bool isOrderFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& stationObj, std::ostream& ostr);
        void display(std::ostream& ostr) const;
    };
}

#endif // !CUSTOMERORDER_H
