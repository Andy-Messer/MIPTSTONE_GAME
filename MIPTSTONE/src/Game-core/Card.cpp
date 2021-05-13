#include <string>
#include "Card.h"
#include <math.h>

Card::Card() {
    expert_level_ = 0;
    instructor_level_ = 0;
    communication_level_ = 0;
    freebie_level_ = 0;
    attack_ = 0;
    hp_ = 0;
    cost_ = 0;
}

Card::Card(std::string &name,
           std::string &dept,
           double &exp,
           double &inst,
           double &comm,
           double &free)
        :
        name_(name),
        department_(dept),
        expert_level_(exp),
        instructor_level_(inst),
        communication_level_(comm),
        freebie_level_(free),
        attack_(ceil((exp / free) * 10)),
        hp_(ceil((inst * 2 + comm) / 2) * 10),
        cost_(ceil(hp_ * 0.2 + attack_ * 0.8)) {};
