//
// Created by yanir on 4/25/2022.
//

#include "Ambassador.hpp"
constexpr int nine_magic = 9;
std::string coup::Ambassador::role() {return "Ambassador";}

void coup::Ambassador::transfer(Player &player1, Player &player2) {
    coins();

    if(money >nine_magic){
        throw std::runtime_error("need to coup");
    }
    if(game.turn()!=Name){
        throw std::runtime_error("not the right turn");
    }
    if(player1.coins() > 0){
        player1.money-=1;
        player2.money+=1;
    }
    else{
        throw std::runtime_error("can't transfer 0 coins");
    }

    game.end_turn();}

void coup::Ambassador::block(coup::Captain &player) {
    this->role();
player.giveback();
}
