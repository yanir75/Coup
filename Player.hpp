#include <iostream>
#include <vector>
#include "Game.hpp"
#pragma once
namespace coup{
    class Player{
    private:
        int money;
        std::string Name;
        Game game;
        bool not_blocked;
        bool dead;
        bool fore_aid;
    protected:
        Player(Game start_game, std::string name);
    public:
        void income();
        void foreign_aid();
        virtual void coup(Player player);
        virtual std::string role();
        int coins();
        void block(Player player);
    };
}