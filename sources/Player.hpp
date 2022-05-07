#include <iostream>
#include <vector>
#include "Game.hpp"
#pragma once
namespace coup{
    class Player{
    private:
        bool not_blocked;
    protected:
        Player(Game &start_game, const std::string &name);

        bool fore_aid;
    public:

        std::string last_action;
        void income();
        void foreign_aid();
        virtual void coup(Player player);
        virtual std::string role();
        int coins();
        virtual void block(Player player);
        Game &game;
        bool dead;
        std::string Name;
        int money;
        bool blockable;
    };
}