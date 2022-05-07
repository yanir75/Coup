//
// Created by yanir on 4/25/2022.
//
#include "Contessa.hpp"

std::string coup::Contessa::role() {return "Contessa";}

void coup::Contessa::block(coup::Assassin player) {
    this->role();
    if(player.last_action=="coup") {
        player.revive();
    }
    else{
        throw std::runtime_error("can't revive");
    }
}
