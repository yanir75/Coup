//
// Created by yanir on 4/24/2022.
//

#include "Player.hpp"
#include <stdexcept>
coup::Player::Player(Game start_game, std::string name) {
    Name = name;
    game = start_game;
    money = 0;
    not_blocked = true;
    dead = false;
    fore_aid = false;
}

void coup::Player::income() {
    coins();
    money+=1;
    fore_aid = false;
}

int coup::Player::coins() {
    if(not_blocked == false && fore_aid){
        money-=2;
    }
    return money;
}

void coup::Player::block(Player player) {
    coins();
    player.not_blocked = false;
}

void coup::Player::coup(Player player) {
    coins();
    if(money >=7) {
        player.dead = true;
        money -= 7;
    }
    else{
        //throw std::invalid_argument("not enough coins");
    }
    fore_aid = false;
}

void coup::Player::foreign_aid() {
    coins();
    money += 2;
    fore_aid = true;
}

std::string coup::Player::role() {return "Player";}