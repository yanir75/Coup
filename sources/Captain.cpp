//
// Created by yanir on 4/25/2022.
//

#include "Captain.hpp"
constexpr int nine_magic = 9;
void coup::Captain::steal(Player &player) {
    coins();

    if(money >nine_magic){
        throw std::runtime_error("need to coup");
    }
    if(game.turn()!=Name){
        throw std::runtime_error("not the right turn");
    }
    if(player.coins() > 1){
        player.money-=2;
        money+=2;
        stole = 2;
        from = &player.money;
    }
    else if(player.coins() >0){
        player.money-=1;
        money+=1;
        stole = 1;
        from = &player.money;
    }

game.end_turn();
}

std::string coup::Captain::role() {return "Captain";}

void coup::Captain::block(coup::Player player) {
    Player::block(player);
}

void coup::Captain::giveback() {
    *from+=stole;
    money-=stole;
}
