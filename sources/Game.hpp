#include <iostream>
#include <vector>
#pragma once
namespace coup{
    class Game{
    private:
        std::vector<std::string> participants;
        std::vector<std::string> turns;
        unsigned int count=0;

    public:
        bool started;
        Game();
        std::vector<std::string>& players();
        std::string turn();
        std::string winner();
        void add(const std::string &name);
        void end_turn(){count++;};
        unsigned int remove(const std::string &name);
        bool contains(const std::string &name);
    };
}