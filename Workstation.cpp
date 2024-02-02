//Name: Agam Airi
//Student Number: 116731217
//Date: December 3, 2022
//Email: aairi@myseneca.ca

#include "Workstation.h"

namespace sdds
{
    std::deque<CustomerOrder> g_pending{};
    std::deque<CustomerOrder> g_completed{};
    std::deque<CustomerOrder> g_incomplete{};

    Workstation::Workstation(const std::string& data) : Station{ data } {}

    void Workstation::fill(std::ostream& ostr) {
        if (!m_orders.empty()) {
            m_orders.front().fillItem(*this, ostr);
        }
    }

    bool Workstation::attemptToMoveOrder() {
        if (m_orders.empty()) {
            return true;
        }
        else {
            if (m_orders.front().isItemFilled(getItemName()) || this->getQuantity() == 0) {
                if (m_pNextStation == nullptr) {
                    if (m_orders.front().isOrderFilled()) {
                        g_completed.emplace_back(std::move(m_orders.front()));
                    }
                    else {
                        g_incomplete.emplace_back(std::move(m_orders.front()));
                    }
                }
                else {
                    (*m_pNextStation) += std::move(m_orders.front());
                }
                m_orders.pop_front();
                return true;
            }
            return false;
        }
    }

    void Workstation::setNextStation(Workstation* workStation) {
        m_pNextStation = workStation;
    }
    
    void Workstation::display(std::ostream& ostr) const {
        ostr << getItemName();
        ostr << " --> ";

        if (m_pNextStation == nullptr) {
            ostr << "End of Line" << std::endl;
        }
        else {
            ostr << m_pNextStation->getItemName() << std::endl;
        }
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.emplace_back(std::move(newOrder));
        return *this;
    }
}