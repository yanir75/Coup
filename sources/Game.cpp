#include "Game.hpp"
constexpr int five = 5;
constexpr unsigned int seven_magic=7;
std::vector<std::string> &coup::Game::players() {return participants;}

std::string coup::Game::turn() {
    while (!this->contains(turns[count%turns.size()])) {
        end_turn();
    }
    return turns[count % turns.size()];
}

std::string coup::Game::winner() {
    if(participants.size()==1 && started) {
        return participants[0];
    }
    throw std::runtime_error("no winner yet");

}

void coup::Game::add(const std::string &name) {
    if(started){
        throw std::runtime_error("already started");
    }
    if(turns.size()>five){
        throw std::runtime_error("too many players");
    }
    participants.push_back(name);
    turns.push_back(name);
    //std::cout << participants.size();
}

coup::Game::Game(){
    started = false;
}

unsigned int coup::Game::remove(const std::string &name) {
for(unsigned int i=0;i<participants.size();i++){
    if(name == participants[i]){
        participants.erase(participants.begin()+i);
        return i;
    }
}
return seven_magic;
}

bool coup::Game::contains(const std::string &name) {
    for(unsigned int i=0;i<participants.size();i++){
        if(name == participants[i]){
          return true;
        }
    }
    return false;
}
