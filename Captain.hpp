#include "Player.hpp"
namespace coup{
    class Captain : public Player{
    public:
        std::string role();
        Captain(Game game,std::string name): Player(game,name){};
        void steal(Player player);
    };
}