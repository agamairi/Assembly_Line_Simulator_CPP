//Name: Agam Airi
//Student Number: 116731217
//Date: December 3, 2022
//Email: aairi@myseneca.ca

#ifndef WORKSTATION_H
#define WORKSTATION_H

#include <deque>
#include <iostream>

#include "CustomerOrder.h"
#include "Station.h"

namespace sdds {

    extern std::deque<sdds::CustomerOrder> g_pending;
    extern std::deque<sdds::CustomerOrder> g_completed;
    extern std::deque<sdds::CustomerOrder> g_incomplete;

    class Workstation : public Station {
        std::deque<CustomerOrder> m_orders;
        Workstation* m_pNextStation = nullptr;

    public:
        Workstation(const Workstation& a) = delete;
        Workstation(Workstation&& a) = delete;
        Workstation& operator=(const Workstation& a) = delete;
        Workstation& operator=(Workstation& a) = delete;

        Workstation(const std::string& data);

        void fill(std::ostream& ostr);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* workStation = nullptr);
        Workstation* getNextStation() const { return m_pNextStation; };
        void display(std::ostream& ostr) const;
        Workstation& operator+=(CustomerOrder&& newOrder);
        bool empty() const { return m_orders.empty(); };
    };
};
#endif // !WORKSTATION_H
