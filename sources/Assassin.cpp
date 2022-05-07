#include "Assassin.hpp"

std::string coup::Assassin::role() {return "Assassin";}


constexpr int seven_magic =7;
void coup::Assassin::coup(coup::Player player) {
    coins();
    if(!game.contains(player.Name)){
        throw std::runtime_error("not in game");
    }
    if(game.turn()!=Name){
        throw std::runtime_error("not the right turn");
    }
    if(money >=seven_magic) {
        player.dead = true;
        money -= seven_magic;
        fore_aid = false;
        game.remove(player.Name);
        game.end_turn();
        last_action = "coup1";
    }
    else if(money >=3) {
        player.dead = true;
        money -= 3;
        fore_aid = false;
        ind = game.remove(player.Name);
        killed = player.Name;
        game.end_turn();
        last_action = "coup";
    }
    else{
        throw std::invalid_argument("not enough coins");
    }

}

void coup::Assassin::revive() {
    game.players().insert(game.players().begin()+ind,killed);
}
