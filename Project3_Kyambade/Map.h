#include <iostream>
#include <vector>
using namespace std;

class Map
{
    private:
        char map[10][17];
    public:
        Map();

        void PlacePlayer();

        void PrintMap();

        void MovePlayer(char input);

        void PlaceItem();
};