/*
akil bhuiyan
prof. cong chen
cs211-HW3
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Team
{
private:
    int totalScore;
    string letter;
    float numRunners;

public:
    Team(string letter, int totalScore)
    {
        this->letter = letter;
        this->totalScore = totalScore;
        numRunners = 1;
    }

    void addToScore(int n)
    {
        numRunners++;
        totalScore += n;
    }

    int getScore()
    {
        return totalScore;
    }

    float getNumRunners()
    {
        return numRunners;
    }

    string getLetter()
    {
        return letter;
    }
};

bool isNewTeam(string t, vector<Team> v);
int findTeamIndex(string t, vector<Team> v);

int main()
{
    while (true)
    {
        string raceRes = "";
        cout << "What were the race results? Or type \"done\" if you want to exit\n";
        cin >> raceRes;
        
        //a vector to store the teams 
        vector<Team> teams;

        //if user types done, exit
        if (raceRes.compare("done") == 0 || raceRes.compare("DONE") == 0)
            break;

        //this loop will check each letter of the race result string and either add to the existing teams score, or create a new team and set its score
        for (int i = 0; i < raceRes.size(); i++)
        {
            if (isNewTeam(raceRes.substr(i, 1), teams))
            {
                //add a new object of type Team at the end of the vector along with its letter and score
                teams.push_back(Team(raceRes.substr(i, 1), i + 1));
            }
            else
                //if team exists, add to its score
                teams.at(findTeamIndex(raceRes.substr(i, 1), teams)).addToScore(i + 1);
        }

        int winnerIndex = 0;
        //check that the number of teams(teams.size()) times the number of runners at the winning team is equal to the number of total runners i.e if there were 4 teams and the winning team had 4 runners then the total number of runners should be 16. This because the amount of runners will always be a factor of the number of teams, if there is 3 teams, then the number of runners should be 3 6 9 12 15 etc.
        if (teams.size() * teams.at(winnerIndex).getNumRunners() == raceRes.size())
        {
            for (int i = 1; i < teams.size(); i++)
            {
                //compare the teams to see which has the lowest score
                if (teams.at(winnerIndex).getScore() > teams.at(i).getScore())
                    winnerIndex = i;
            }
            cout << "The winning team is team " << teams.at(winnerIndex).getLetter() << " with a score of: " << teams.at(winnerIndex).getScore() / teams.at(winnerIndex).getNumRunners() << endl;
        }
        else
            cout << "Please enter the same number of runners for each team!\n";
    }
    return 0;
}

//this method/function checks if there is already an existing Team that corresponds 
//to the letter that we are checking for, if a team with that letter exists, 
//return false since that is not a new team
bool isNewTeam(string t, vector<Team> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if(t.compare(v.at(i).getLetter()) == 0)
            return false;
    }
    return true;
}

//this method finds at which index of the teams vector is the team corresponding to parameter "t" and returns it as an int
int findTeamIndex(string t, vector<Team> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (t.compare(v.at(i).getLetter()) == 0)
            return i;
    }
}