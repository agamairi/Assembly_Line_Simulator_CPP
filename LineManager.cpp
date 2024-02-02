//Name: Agam Airi
//Student Number: 116731217
//Date: December 3, 2022
//Email: aairi@myseneca.ca

#include "LineManager.h"

namespace sdds {

    LineManager::LineManager(const std::string& filename, const std::vector<Workstation*>& workStations) {
        Utilities utility;

        std::ifstream input(filename);

        if (!input.is_open()) {
            throw std::string("Cannot open file");
        }

        std::string tempData;
        while (!input.eof()) {
            getline(input, tempData);
            size_t position = 0;
            bool flag = true;
            std::string currentStation, nextStation;

            currentStation = utility.extractToken(tempData, position, flag);

            if (flag) {
                nextStation = utility.extractToken(tempData, position, flag);
            }

            Workstation* currentWorkStation = nullptr;
            Workstation* nextWorkStation = nullptr;

            for_each(workStations.begin(), workStations.end(), [&currentWorkStation, &nextWorkStation, currentStation, nextStation](Workstation* ws) {
                    if (ws->getItemName() == currentStation) {
                        currentWorkStation = ws;
                    }
                    else if (ws->getItemName() == nextStation) {
                        nextWorkStation = ws;
                    } 
            });

            if (m_activeLine.size() == 0) {
                m_firstStation = currentWorkStation;
            }

            currentWorkStation->setNextStation(nextWorkStation);
            m_activeLine.push_back(currentWorkStation);
        }
        input.close();
    }

    void LineManager::reorderStations()
    {
        std::vector<Workstation*> newWorkStation;
        Workstation* prevWorkStation = nullptr;
        unsigned int cnt = 0;
        while (cnt < m_activeLine.size()) {
            for (unsigned int i = 0; i < m_activeLine.size(); i++) {
                if (m_activeLine[i]->getNextStation() == prevWorkStation) {
                    newWorkStation.push_back(m_activeLine[i]);
                    prevWorkStation = m_activeLine[i];
                    cnt++;
                    break;
                }
            }
        }
        reverse(newWorkStation.begin(), newWorkStation.end());
        m_firstStation = newWorkStation[0];
        m_activeLine = newWorkStation;
    }

    bool LineManager::run(std::ostream& ostr) {
        static int cnt = 0;
        cnt++;
        ostr << "Line Manager Iteration: " << cnt << std::endl;
        if (!g_pending.empty()) {
            (*m_firstStation) += std::move(g_pending.front());
            g_pending.pop_front();
        }
        for (unsigned int i = 0; i < m_activeLine.size(); i++) {
            m_activeLine[i]->fill(ostr);
        }
        for (unsigned int i = 0; i < m_activeLine.size(); i++) {
            m_activeLine[i]->attemptToMoveOrder();
        }
        bool isEmpty = true;
        for (unsigned int i = 0; i < m_activeLine.size(); i++) {
            if (!m_activeLine[i]->empty()) {
                isEmpty = false;
                break;
            }
        }
        return isEmpty;
    }

    void LineManager::display(std::ostream& ostr) const {
        for (unsigned int i = 0; i < m_activeLine.size(); i++) {
            m_activeLine[i]->display(ostr);
        }
    }
}