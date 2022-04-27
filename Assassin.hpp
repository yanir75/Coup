#include "Player.hpp"
namespace coup{
    class Assassin : public Player{
    public:
        std::string role();
        Assassin(Game game,std::string name) : Player(game,name){};
    };
}
