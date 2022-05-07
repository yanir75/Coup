#include "Duke.hpp"

std::string coup::Duke::role() {return "Duke";}

constexpr int magic_nine =9;
void coup::Duke::tax() {
    coins();

    if(money >magic_nine){
        throw std::runtime_error("need to coup");
    }
    if(game.turn()!=Name){
        throw std::runtime_error("not the right turn");
    }
    money+=3;
    game.end_turn();
}
