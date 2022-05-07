//
// Created by yanir on 4/24/2022.
//

#include "Player.hpp"
#include <stdexcept>
constexpr int seven = 7;
constexpr int nine = 9;
constexpr int two = 2;
coup::Player::Player(Game &game, const std::string &name): game(game) {
    Name = name;
    money = 0;
    not_blocked = true;
    dead = false;
    fore_aid = false;
    game.add(name);
    blockable = true;
    last_action= "";
}

void coup::Player::income() {
    coins();
    if(money >nine){
        throw std::runtime_error("need to coup");
    }

    if(game.turn()!=Name){
        throw std::runtime_error("not the right turn");
    }
    money+=1;
    fore_aid = false;
    blockable = false;
    game.end_turn();
    game.started = true;
    last_action = "income";
}

int coup::Player::coins() {
    if(game.players().size()==1){
        throw  std::runtime_error("can't do it");
    }
    if(!not_blocked && fore_aid){
        money-=two;
    }
    if(money < 0)
    {money=0;}
    return money;
}

void coup::Player::block(Player player) {
    if(!player.blockable){
        throw std::runtime_error("not blockable");
    }
    coins();
    player.not_blocked = false;
}

void coup::Player::coup(Player player) {
    coins();
    if(!game.contains(player.Name)){
        throw std::runtime_error("not in game");
    }
    if(game.turn()!=Name){
        throw std::runtime_error("not the right turn");
    }
    if(money >=seven) {
        player.dead = true;
        money -= seven;
    }
    else{
        throw std::invalid_argument("not enough coins");
    }
    game.remove(player.Name);
    fore_aid = false;
    game.end_turn();
}

void coup::Player::foreign_aid() {

    if(money >nine){
        throw std::runtime_error("need to coup");
    }
    if(game.turn()!=Name){
        throw std::runtime_error("not the right turn");
    }
    coins();
    money += two;
    fore_aid = true;
    blockable = true;
    game.end_turn();
    last_action = "foreign_aid";
}

std::string coup::Player::role() {return "Player";}

