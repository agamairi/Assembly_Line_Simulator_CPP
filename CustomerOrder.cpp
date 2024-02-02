// Name: Agam Airi
// Seneca Student ID: 116731217
// Seneca email: aairi@myseneca.ca
// Date of completion: 23 Nov 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"

namespace sdds
{
    size_t CustomerOrder::m_widthField = 0;

    CustomerOrder::CustomerOrder(const std::string& str) {
        Utilities utilObj;
        size_t position = 0;
        bool flag = true;

        std::vector<Item*> vecItem;
        Item* tempItem;

        m_name = utilObj.extractToken(str, position, flag);
        m_product = utilObj.extractToken(str, position, flag);
     
        while (flag == true) {
            tempItem = new Item(utilObj.extractToken(str, position, flag));
            vecItem.push_back(tempItem);
        }
        m_cntItem = vecItem.size();
        m_lstItem = new Item * [m_cntItem];

        for (size_t i = 0; i < m_cntItem; i++) {
            m_lstItem[i] = vecItem[i];
        }

        if (CustomerOrder::m_widthField < utilObj.getFieldWidth()) {
            CustomerOrder::m_widthField = utilObj.getFieldWidth();
        }
        else {
            CustomerOrder::m_widthField = CustomerOrder::m_widthField;
        }
    }

    CustomerOrder::CustomerOrder(const CustomerOrder& customerOrderObj) {
        throw "NO COPY OPERATION";
    }

    CustomerOrder::CustomerOrder(CustomerOrder&& obj) noexcept
    {
        *this = std::move(obj);
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& obj) noexcept {
        if (this != &obj) {
            for (size_t i = 0; i < m_cntItem; i++) {
                delete m_lstItem[i];
            }
            delete[] m_lstItem;
            
            m_name = obj.m_name;
            m_product = obj.m_product;
            m_cntItem = obj.m_cntItem;
            m_lstItem = obj.m_lstItem;
            
            obj.m_lstItem = nullptr;
            obj.m_cntItem = 0;
        }
        return *this;
    }

    CustomerOrder::~CustomerOrder() {
        for (size_t i = 0; i < m_cntItem; i++) {
            delete m_lstItem[i];
        }
        delete[] m_lstItem;
    }

    bool CustomerOrder::isOrderFilled() const {
        bool isOrderFilled = true;
        for (size_t i = 0; i < m_cntItem && isOrderFilled; i++) {
            if (m_lstItem[i]->m_isFilled == false) {
                isOrderFilled = false;
            }
        }
        return isOrderFilled;
    }

    bool CustomerOrder::isItemFilled(const std::string& str) const {
        bool isItemFilled = true;
        for (size_t i = 0; i < m_cntItem && isItemFilled; i++) {
            if (m_lstItem[i]->m_itemName == str && m_lstItem[i]->m_isFilled == false) {
                isItemFilled = false;
            }    
        }
        return isItemFilled;
    }

    void CustomerOrder::fillItem(Station& stationObj, std::ostream& ostr) {
        for (size_t i = 0; i < m_cntItem; i++) {
            if (m_lstItem[i]->m_itemName == stationObj.getItemName() && !m_lstItem[i]->m_isFilled) {
                if (stationObj.getQuantity() >= 1) {
                    stationObj.updateQuantity();
                    m_lstItem[i]->m_serialNumber = stationObj.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    ostr << "    Filled " << m_name << ", "
                        << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                    break;
                }
                else {
                    ostr << "    Unable to fill " << m_name << ", " << m_product
                        << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                }
            }
        }
    }

    void CustomerOrder::display(std::ostream& ostr) const {
        ostr << m_name << " - " << m_product << std::endl;
        for (size_t i = 0; i < m_cntItem; i++)
        {
            ostr << "[" << std::setw(6) << std::right << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] "
                << std::setw(m_widthField) << std::left << std::setfill(' ') << m_lstItem[i]->m_itemName
                << "   - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
        }
    }
}