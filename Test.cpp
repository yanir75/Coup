
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

#include "doctest.h"

TEST_CASE("good input"){
    coup::Game game;
    coup::Assassin as(game,"test");
    coup::Duke du(game,"tester");
    CHECK(game.players().size()==2);
    CHECK(game.turn()=="test");
    for(int i=1;i<5;i++){
        as.foreign_aid();
        CHECK(as.coins()==i*2);
        du.foreign_aid();
        CHECK(du.coins()==i*2);
    }
    as.foreign_aid();
    du.block(du);
    as.coup(du);
    CHECK(game.players().size()==2);
    du.foreign_aid();
    as.coup(du);
    CHECK(game.players().size()==1);
    CHECK(game.winner()=="test");
}

TEST_CASE("bad input"){

    coup::Game game;
    coup::Assassin as(game,"test");
    coup::Duke du(game,"tester");
    for(int i=0;i<5;i++){
        as.foreign_aid();
        du.foreign_aid();
    }
        CHECK_THROWS(as.block(du));
        CHECK_THROWS(as.income());
        CHECK_THROWS(as.foreign_aid());
        CHECK_THROWS(du.block(as));
        CHECK_THROWS(du.income());
        CHECK_THROWS(du.foreign_aid());
        CHECK_THROWS(game.winner());
}