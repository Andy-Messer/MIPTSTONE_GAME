#ifndef TP_GAME_PROJECT_CARD_H
#include <string>

class Card {
public:
    Card();
    Card(std::string& name, std::string& dept,  double& exp, double& inst, double& comm, double& free);
    std::string GetName();
    std::string GetDepartment();
    double GetExpert();
    double GetInstructor();
    double GetCommunication();
    double GetFreebie();
    int GetAttack();
    int GetHp();
    int GetCost();
private:
    std::string name_;
    std::string department_;
    double expert_level_;
    double instructor_level_;
    double communication_level_;
    double freebie_level_;
    int attack_;
    int hp_;
    int cost_;
};

#define TP_GAME_PROJECT_CARD_H

#endif //TP_GAME_PROJECT_CARD_H