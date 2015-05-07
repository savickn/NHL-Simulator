#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>
#include "Team.h"

//Function declarations

void PlayGame (Team& a, Team& b)
{
    a.SetGoalsScored(a.nGetShots(), b.dGetSvPer(), b.dGetBlockPer(), a.dGetAccuracy(), a.nGetGoalsScored());
    std::cout << /*a.sGetTeamName*/ a.sGetName() << " scored " << a.nGetGoalsScored() << " goals." << std::endl;
    b.SetGoalsScored(b.nGetShots(), a.dGetSvPer(), a.dGetBlockPer(), b.dGetAccuracy(), b.nGetGoalsScored());
    std::cout << /*b.sGetTeamName*/ b.sGetName() << " scored " << b.nGetGoalsScored() << " goals." << std::endl;

    if (a.nGetGoalsScored() > b.nGetGoalsScored())
    {
        std::cout << /*a.sGetTeamName*/ a.sGetName() << " won the game" << '\n';
        a.SetWins(a.nGetWins());
        b.SetLosses(b.nGetLosses());
    }
    else if (a.nGetGoalsScored() == b.nGetGoalsScored())
    {
        std::cout << "The game ended in a tie." << '\n';
        a.SetTies(a.nGetTies());
        b.SetTies(b.nGetTies());
    }
    else if (a.nGetGoalsScored() < b.nGetGoalsScored())
    {
        std::cout << /*b.sGetTeamName*/ b.sGetName() << " won the game" << '\n';
        a.SetLosses(a.nGetLosses());
        b.SetWins(b.nGetWins());
    }
    std::cout << '\n';
}

std::vector<std::pair<double, Team>> MakeLeagueStandings(Team& a, Team& b, Team& c, Team& d, Team& e, Team& f, Team& g, Team& h)
{
    a.SetPoints(a.nGetWins(), a.nGetLosses(), a.nGetTies(), a.nGetPoints());
    b.SetPoints(b.nGetWins(), b.nGetLosses(), b.nGetTies(), b.nGetPoints());
    c.SetPoints(c.nGetWins(), c.nGetLosses(), c.nGetTies(), c.nGetPoints());
    d.SetPoints(d.nGetWins(), d.nGetLosses(), d.nGetTies(), d.nGetPoints());
    e.SetPoints(e.nGetWins(), e.nGetLosses(), e.nGetTies(), e.nGetPoints());
    f.SetPoints(f.nGetWins(), f.nGetLosses(), f.nGetTies(), f.nGetPoints());
    g.SetPoints(g.nGetWins(), g.nGetLosses(), g.nGetTies(), g.nGetPoints());
    h.SetPoints(h.nGetWins(), h.nGetLosses(), h.nGetTies(), h.nGetPoints());

    std::vector<std::pair<double,Team>> vTeamStandings (8);
    vTeamStandings [0] = std::make_pair(a.nGetPoints(),a);
    vTeamStandings [1] = std::make_pair(b.nGetPoints(),b);
    vTeamStandings [2] = std::make_pair(c.nGetPoints(),c);
    vTeamStandings [3] = std::make_pair(d.nGetPoints(),d);
    vTeamStandings [4] = std::make_pair(e.nGetPoints(),e);
    vTeamStandings [5] = std::make_pair(f.nGetPoints(),f);
    vTeamStandings [6] = std::make_pair(g.nGetPoints(),g);
    vTeamStandings [7] = std::make_pair(h.nGetPoints(),h);

    bool pairCompare(const std::pair<double,Team> firstElem, const std::pair<double,Team> secondElem);

    std::sort(vTeamStandings.begin(), vTeamStandings.end(), pairCompare);

    std::cout << '\n' << "League Table" << '\n' << "Pts Team  SOG  SV%  Blk%  Acc%" << '\n';

    for(int i = 0; i < vTeamStandings.size(); i++)
    {
        std::cout << vTeamStandings[i].first << ", " << vTeamStandings[i].second << '\n';
    }

    int nValue=0;
    while (nValue != 1)
    {
        std::cout << '\n' << "Press 1 to simulate the playoffs" << '\n';
        std::cin >> nValue;
    }
    std::cout << '\n';

    return vTeamStandings;
}

bool pairCompare (const std::pair<double,Team> firstElem, const std::pair<double,Team> secondElem)
{
    return firstElem.first > secondElem.first;
}

Team PlayoffSeries(Team& a, Team& b)
{
    a.ResetPlayoffWins(a.nGetPlayoffWins());
    b.ResetPlayoffWins(a.nGetPlayoffWins());
    for (int nGamesPlayed = 1;  nGamesPlayed < 8; nGamesPlayed++)
    {
        if (a.nGetPlayoffWins() == 4 || b.nGetPlayoffWins() == 4)
        {
            break;
        }
        else
        {
            a.SetGoalsScored(a.nGetShots(), b.dGetSvPer(), b.dGetBlockPer(), a.dGetAccuracy(), a.nGetGoalsScored());
            std::cout << a.sGetName() << " scored " << a.nGetGoalsScored() << " goals." << std::endl;
            b.SetGoalsScored(b.nGetShots(), a.dGetSvPer(), a.dGetBlockPer(), b.dGetAccuracy(), b.nGetGoalsScored());
            std::cout << b.sGetName() << " scored " << b.nGetGoalsScored() << " goals." << std::endl;

            int nOvertime = 1;
            while (a.nGetGoalsScored() == b.nGetGoalsScored())
            {
                std::cout << "This game is going into overtime #" << nOvertime << "!!" << '\n';
                a.SetGoalsScored(a.nGetShots(), b.dGetSvPer(), b.dGetBlockPer(), a.dGetAccuracy(), a.nGetGoalsScored());
                std::cout << a.sGetName() << " scored " << a.nGetGoalsScored() << " goals in overtime #"
                << nOvertime << "." << '\n';
                b.SetGoalsScored(b.nGetShots(), a.dGetSvPer(), a.dGetBlockPer(), b.dGetAccuracy(), b.nGetGoalsScored());
                std::cout << b.sGetName() << " scored " << b.nGetGoalsScored() << " goals in overtime #"
                << nOvertime << "." << '\n';
                nOvertime++;
            }
            if (a.nGetGoalsScored() > b.nGetGoalsScored())
            {
                std::cout << a.sGetName() << " won the game" << '\n';
                a.SetPlayoffWins(a.nGetPlayoffWins());
            }
            else if (a.nGetGoalsScored() < b.nGetGoalsScored())
            {
                std::cout << b.sGetName() << " won the game" << '\n';
                b.SetPlayoffWins(b.nGetPlayoffWins());
            }
            std::cout << '\n';
        }
    }
    if (a.nGetPlayoffWins() > b.nGetPlayoffWins())
    {
        std::cout << a.sGetName() << " won the series against " << b.sGetName() << " and advances to the Stanley Cup Finals." << '\n' << '\n';
        Team temp;
        temp = a;
        return temp;
    }
    else if (a.nGetPlayoffWins() < b.nGetPlayoffWins())
    {
        std::cout << b.sGetName() << " won the series against " << a.sGetName() << " and advances to the Stanley Cup Finals." << '\n' << '\n';
        Team temp;
        temp = b;
        return temp;
    }
}

void StanleyCupFinals (Team& a, Team& b)
{
    a.ResetPlayoffWins(a.nGetPlayoffWins());
    b.ResetPlayoffWins(a.nGetPlayoffWins());
    for (int nGamesPlayed = 1;  nGamesPlayed < 8; nGamesPlayed++)
    {
        if (a.nGetPlayoffWins() == 4)
        {
            std::cout << a.sGetName() << " won the Stanley Cup Finals against " << b.sGetName() << " and took home the Stanley Cup." << '\n';
            break;
        }
        else if (b.nGetPlayoffWins() == 4)
        {
            std::cout << b.sGetName() << " won the Stanley Cup Finals against " << a.sGetName() << " and took home the Stanley Cup." << '\n';
            break;
        }
        else
        {
            a.SetGoalsScored(a.nGetShots(), a.dGetSvPer(), b.dGetBlockPer(), b.dGetAccuracy(), a.nGetGoalsScored());
            std::cout << a.sGetName() << " scored " << a.nGetGoalsScored() << " goals." << std::endl;
            b.SetGoalsScored(b.nGetShots(), a.dGetSvPer(), a.dGetBlockPer(), b.dGetAccuracy(), b.nGetGoalsScored());
            std::cout << b.sGetName() << " scored " << b.nGetGoalsScored() << " goals." << std::endl;

            int nOvertime = 1;
            while (a.nGetGoalsScored() == b.nGetGoalsScored())
            {
                std::cout << "This game is going into overtime #" << nOvertime << "!!" << '\n';
                a.SetGoalsScored(a.nGetShots(), b.dGetSvPer(), b.dGetBlockPer(), a.dGetAccuracy(), a.nGetGoalsScored());
                std::cout << a.sGetName() << " scored " << a.nGetGoalsScored() << " goals in overtime #"
                << nOvertime << "." << '\n';
                b.SetGoalsScored(b.nGetShots(), a.dGetSvPer(), a.dGetBlockPer(), b.dGetAccuracy(), b.nGetGoalsScored());
                std::cout << b.sGetName() << " scored " << b.nGetGoalsScored() << " goals in overtime #"
                << nOvertime << "." << '\n';
                nOvertime++;
            }
            if (a.nGetGoalsScored() > b.nGetGoalsScored())
            {
                std::cout << a.sGetName() << " won the game" << '\n';
                a.SetPlayoffWins(a.nGetPlayoffWins()); 
            }
            else if (a.nGetGoalsScored() < b.nGetGoalsScored())
            {
                std::cout << b.sGetName() << " won the game" << '\n';
                b.SetPlayoffWins(b.nGetPlayoffWins());
            }
                std::cout << '\n';
        }
    }
}

void Playoffs (const std::vector<std::pair<double,Team>>& vTeamStandings)
{
    Team FirstPlace;
    Team SecondPlace;
    Team ThirdPlace;
    Team FourthPlace;

    FirstPlace = vTeamStandings[0].second;
    SecondPlace = vTeamStandings[1].second;
    ThirdPlace = vTeamStandings[2].second;
    FourthPlace = vTeamStandings[3].second;

    Team NHLFinalsOne = PlayoffSeries(FirstPlace, FourthPlace);
    Team NHLFinalsTwo = PlayoffSeries(SecondPlace, ThirdPlace);

    int nValue=0;
    while (nValue != 1)
    {
        std::cout << '\n' << "Press 1 to continue to the Stanley Cup Finals" << '\n';
        std::cin >> nValue;
    }
    std::cout << '\n';

    StanleyCupFinals(NHLFinalsOne, NHLFinalsTwo);
}

void TeamStats (const Team& a)
{
    std::cout << a << '\n';
}

int main()
{
    srand(time(0));

    Team cTor("Tor",28, 0.915, 0.50, 0.50, 0, 0, 0, 0, 0, 0, 0);
    Team cMon("Mon",30, 0.935, 0.35, 0.52, 0, 0, 0, 0, 0, 0, 0);
    Team cDet("Det",36, 0.905, 0.35, 0.52, 0, 0, 0, 0, 0, 0, 0);
    Team cBos("Bos",33, 0.925, 0.65, 0.45, 0, 0, 0, 0, 0, 0, 0);
    Team cNyr("Nyr",40, 0.930, 0.55, 0.52, 0, 0, 0, 0, 0, 0, 0);
    Team cChi("Chi",39, 0.915, 0.35, 0.60, 0, 0, 0, 0, 0, 0, 0);
    Team cCal("Cal",29, 0.910, 0.40, 0.48, 0, 0, 0, 0, 0, 0, 0);
    Team cWpg("Wpg",35, 0.920, 0.60, 0.45, 0, 0, 0, 0, 0, 0, 0);

    std::cout << "Team Statistics" << '\n';
    TeamStats(cWpg);
    TeamStats(cTor);
    TeamStats(cMon);
    TeamStats(cChi);
    TeamStats(cNyr);
    TeamStats(cBos);
    TeamStats(cDet);
    TeamStats(cCal);

    std::cout << '\n' << "Regular Season Games" << '\n';
    PlayGame(cWpg,cMon);
    PlayGame(cTor,cMon);
    PlayGame(cChi,cMon);
    PlayGame(cBos,cMon);
    PlayGame(cNyr,cMon);
    PlayGame(cCal,cMon);
    PlayGame(cDet,cMon);
    PlayGame(cDet,cTor);
    PlayGame(cBos,cTor);
    PlayGame(cNyr,cTor);
    PlayGame(cCal,cTor);
    PlayGame(cChi,cTor);
    PlayGame(cWpg,cTor);
    PlayGame(cDet,cBos);
    PlayGame(cDet,cChi);
    PlayGame(cDet,cWpg);
    PlayGame(cDet,cNyr);
    PlayGame(cDet,cCal);
    PlayGame(cWpg,cChi);
    PlayGame(cWpg,cBos);
    PlayGame(cWpg,cNyr);
    PlayGame(cWpg,cCal);
    PlayGame(cChi,cNyr);
    PlayGame(cCal,cNyr);
    PlayGame(cBos,cNyr);
    PlayGame(cCal,cChi);
    PlayGame(cCal,cBos);
    PlayGame(cBos,cChi);

    std::cout << "Team Records" << '\n';
    std::vector<std::pair<double,Team>> vPlayoffStandings = MakeLeagueStandings(cTor,cMon,cWpg,cChi,cNyr,cBos,cCal,cDet);

    Playoffs(vPlayoffStandings);
}
