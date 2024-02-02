//Name: Agam Airi
//Student Number: 116731217
//Date: December 3, 2022
//Email: aairi@myseneca.ca

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "Utilities.h"
#include "Workstation.h"

namespace sdds {
    class LineManager
    {
        std::vector<Workstation*> m_activeLine;
        size_t m_cntCustomerOrder;
        Workstation* m_firstStation;

    public:
        LineManager(const std::string& filename, const std::vector<Workstation*>& workStations);
        void reorderStations();
        bool run(std::ostream& ostr);
        void display(std::ostream& ostr) const;
    };
};
#endif // !LINEMANAGER_H
