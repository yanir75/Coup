#include "Player.hpp"
#include "Assassin.hpp"
namespace coup{
    class Contessa : public Player{
    public:
        std::string role() override;
        Contessa(Game &game,std::string name): Player(game,name){};
        void block(coup::Assassin player);
    };
}