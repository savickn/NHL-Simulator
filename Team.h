#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED
#include <iostream>

class Team
{
private:
    std::string m_sName;
    int m_nShotAttempts;
    double m_dSavePercentage;
    double m_dBlockRate;
    double m_dShotAccuracy;
    int m_nWins;
    int m_nLosses;
    int m_nTies;
    int m_nGoals;
    int m_nPoints;
    int m_nPlayoffWins;
    int m_nPlayoffLosses;

public:

    Team () {}

    Team (std::string sName,int nShots, double dSvPer, double dBlockPer, double dAccuracy, int nWins, int nLosses, int nTies, int nGoals, int nPoints, int nPlayoffWins, int nPlayoffLosses);

    Team (const Team &cSource);

    std::string sGetName () const;

    void SetGoalsScored(int nShots, double dSvPer, double dBlockPer, double dAccuracy, int nGoals);
    int nGetGoalsScored () const;
    int nGetShots () const;
    double dGetSvPer () const;
    double dGetBlockPer () const;
    double dGetAccuracy () const;
    void SetWins (int nWins);
    int nGetWins ()const;
    void SetPlayoffWins (int nPlayoffWins);
    int nGetPlayoffWins ()const;
    void ResetPlayoffWins (int nPlayoffWins);
    void SetLosses (int nLosses);
    int nGetLosses () const;
    void SetTies (int nTies);
    int nGetTies () const;
    void SetPoints (int nWins, int nLosses, int nTies, int nPoints);
    int nGetPoints () const;

    friend std::ostream& operator<< (std::ostream &out, const Team &a);

    Team& operator= (const Team &cSource);

    ~Team() {};
};

#endif // TEAM_H_INCLUDED
