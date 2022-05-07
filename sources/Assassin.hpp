#include <utility>
#pragma once
#include "Player.hpp"
namespace coup{
    class Assassin : public Player{
        std::string killed;
    public:
        unsigned int ind = 0;
        std::string role() override;
        Assassin(Game &game,std::string name):Player(game,name){
            killed = "";
        };
        void coup(Player player) override;
        void revive();
    };
}
