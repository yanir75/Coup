#include <iostream>
#include <vector>
#pragma once
namespace coup{
    class Game{
    private:
        std::vector<std::string> participants;
    public:
        std::vector<std::string> players();
        std::string turn();
        std::string winner();
    };
}