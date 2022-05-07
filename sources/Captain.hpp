#include "Player.hpp"
#pragma once
namespace coup{
    class Captain : public Player{
    public:
        std::string role() override;
        Captain(Game &game,std::string name): Player(game,name){};
        void steal(Player &player);
        void block(Player player) override;
        int stole = 0;
         int *from = &stole;
         void giveback();
    };
}