#include "Player.hpp"
namespace coup{
    class Ambassador : public Player{
    public:
        std::string role();
        Ambassador(Game game,std::string name) : Player(game,name){};
        void transfer(Player player1 , Player player2);
    };
}