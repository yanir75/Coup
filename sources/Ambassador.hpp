#include "Player.hpp"
#include "Captain.hpp"
namespace coup{
    class Ambassador : public Player{
    public:
        std::string role() override;
        Ambassador(Game &game,std::string name) : Player(game,name){};
        void transfer(Player &player1 , Player &player2);
        void block(coup::Captain &player);
    };
}