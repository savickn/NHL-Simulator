#include <iostream>
#include <random>
#include "Team.h"

Team::Team (std::string sName,int nShots, double dSvPer, double dBlockPer, double dAccuracy, int nWins, int nLosses, int nTies, int nGoals, int nPoints, int nPlayoffWins, int nPlayoffLosses)
{
    m_sName = sName;
    m_nShotAttempts = nShots;
    m_dSavePercentage = dSvPer;
    m_dBlockRate = dBlockPer;
    m_dShotAccuracy = dAccuracy;
    m_nWins = nWins;
    m_nLosses = nLosses;
    m_nTies = nTies;
    m_nGoals = nGoals;
    m_nPoints = nPoints;
    m_nPlayoffWins = nPlayoffWins;
    m_nPlayoffLosses = nPlayoffLosses;
}

//copy constructor
Team::Team (const Team &cSource)
{
    m_sName = cSource.m_sName;
    m_nShotAttempts = cSource.m_nShotAttempts;
    m_dSavePercentage = cSource.m_dSavePercentage;
    m_dBlockRate = cSource.m_dBlockRate;
    m_dShotAccuracy = cSource.m_dShotAccuracy;
    m_nWins = cSource.m_nWins;
    m_nLosses = cSource.m_nLosses;
    m_nTies = cSource.m_nTies;
    m_nGoals = cSource.m_nGoals;
    m_nPoints = cSource.m_nPoints;
    m_nPlayoffWins = cSource.m_nPlayoffWins;
    m_nPlayoffLosses = cSource.m_nPlayoffLosses;
}

std::string Team::sGetName () const
{
    return m_sName;
}

void Team::SetGoalsScored(int nShots, double dSvPer, double dBlockPer, double dAccuracy, int nGoals)
{
    m_nGoals = 0;

    double dAccuracyRand;
    double dBlocksRand;
    double dSavesRand;
    for(int i=0; i<nShots; i++)
    {
        dAccuracyRand = rand()%1000+1;
        //std::cout << dAccuracyRand << '\n';
        dBlocksRand = rand()%1000+1;
        //std::cout << dBlocksRand << '\n';
        dSavesRand = rand()%1000+1;
        //std::cout << dSavesRand << '\n';

        if (dAccuracyRand <= (dAccuracy*1000))
        {
            if (dBlocksRand > (dBlockPer*1000))
            {
                if (dSavesRand > (dSvPer*1000))
                {
                m_nGoals++;
                //std::cout << "Goal!!" << '\n';
                continue;
                }
                else
                {
                continue;
                }
            }
            else
            {
            continue;
            }
        }
        else
        {
        continue;
        }
    }
}

int Team::nGetGoalsScored () const
{
    return m_nGoals;
}

int Team::nGetShots () const
{
    return m_nShotAttempts;
}

double Team::dGetSvPer () const
{
    return m_dSavePercentage;
}

double Team::dGetBlockPer () const
{
    return m_dBlockRate;
}

double Team::dGetAccuracy () const
{
    return m_dShotAccuracy;
}

void Team::SetWins (int nWins)
{
    m_nWins = nWins;
    m_nWins++;
}

int Team::nGetWins ()const
{
    return m_nWins;
}

void Team::SetPlayoffWins (int nPlayoffWins)
{
    m_nPlayoffWins = nPlayoffWins;
    m_nPlayoffWins++;
}

int Team::nGetPlayoffWins () const
{
    return m_nPlayoffWins;
}

void Team::ResetPlayoffWins (int nPlayoffWins)
{
    m_nPlayoffWins = nPlayoffWins;
    m_nPlayoffWins = 0;
}

void Team::SetLosses (int nLosses)
{
    m_nLosses = nLosses;
    m_nLosses++;
}

int Team::nGetLosses () const
{
    return m_nLosses;
}

void Team::SetTies (int nTies)
{
    m_nTies = nTies;
    m_nTies++;
}

int Team::nGetTies () const
{
   return m_nTies;
}

void Team::SetPoints (int nWins, int nLosses, int nTies, int nPoints)
{
    m_nWins = nWins;
    m_nLosses = nLosses;
    m_nTies = nTies;
    m_nPoints = nPoints;
    m_nPoints = 2*nWins + 1*nTies + 0*nLosses;
    std::cout << m_sName << " ended the season with " << m_nPoints << " points." << '\n';
}

int Team::nGetPoints() const
{
    return m_nPoints;
}

Team& Team::operator= (const Team &cSource)
{
    m_sName = cSource.m_sName;
    m_nShotAttempts = cSource.m_nShotAttempts;
    m_dSavePercentage = cSource.m_dSavePercentage;
    m_dBlockRate = cSource.m_dBlockRate;
    m_dShotAccuracy = cSource.m_dShotAccuracy;
    m_nWins = cSource.m_nWins;
    m_nLosses = cSource.m_nLosses;
    m_nTies = cSource.m_nTies;
    m_nGoals = cSource.m_nGoals;
    m_nPoints = cSource.m_nPoints;
    return *this;
}

std::ostream& operator<< (std::ostream &out, const Team &cTeam)
{
    out << "(" << cTeam.m_sName << ", " << cTeam.m_nShotAttempts << ", " <<
        cTeam.m_dSavePercentage << ", " <<
        cTeam.m_dBlockRate << ", " << cTeam.m_dShotAccuracy << ")";
    return out;
}
