#include "Player.hpp"
namespace coup{
    class Contessa : public Player{
    public:
        std::string role();
        Contessa(Game game,std::string name): Player(game,name){};
    };
}