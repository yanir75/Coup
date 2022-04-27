#include "Player.hpp"
namespace coup{
    class Duke : public Player{
    public:
        std::string role();
        Duke(Game game,std::string name) : Player(game,name){};
        void tax();
    };
}