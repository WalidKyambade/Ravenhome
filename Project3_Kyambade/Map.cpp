#include <iostream>
#include <vector>
#include "Map.h"
using namespace std;

Map::Map()
{   
    //constric the map
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 17; j++)
        {
            if(j == 0 || j == 16)
            {
                map[i][j] = '|';
            }
            else if(i == 0 || i == 9)
            {
                map[i][j] = '-';
            }
            else
            {
                map[i][j] = ' ';
            }
        }
    }
}

void Map::PlacePlayer()
{
    //places the player
    map[2][8] = '0';
}

void Map::PrintMap()
{
    //prints the entire map
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 17; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void Map::MovePlayer(char input)
{
    //moves the player on the map
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 17; j++)
        {
            if(map[i][j] == '0')
            {
                if(input == 'w')
                {
                    //makes it so the player can't walk through walls and already places items
                    if(map[i-1][j] != '|' && map[i-1][j] != '-' && map[i-1][j] != 'x')
                    {
                        map[i-1][j] = '0';
                        map[i][j] = ' ';
                        return;
                    }
                    
                }
                
                if(input == 's')
                {
                    if(map[i+1][j] != '|' && map[i+1][j] != '-' && map[i+1][j] != 'x')
                    {
                        map[i+1][j] = '0';
                        map[i][j] = ' ';
                        return;
                    }   
                }

                if(input == 'a')
                {
                    if(map[i][j-1] != '|' && map[i][j-1] != '-' && map[i][j-1] != 'x')
                    {
                        map[i][j-1] = '0';
                        map[i][j] = ' ';
                        return;
                    }
                    
                }

                if(input == 'd')
                {
                    if(map[i][j+1] != '|' && map[i][j+1] != '-' && map[i][j+1] != 'x')
                    {
                        map[i][j+1] = '0';
                        map[i][j] = ' ';
                        return;
                    }
                }
            }
        }
    }
}

void Map::PlaceItem()
{
    //makes the playrs current spot the spot with the item
    for(int i = 0; i < 10; i++)
    {
        int j = 0;
        while(j < 17)
        {
            cout << map[i][j]; 
            if(map[i][j] == '0')
            {
                map[i][j] = 'x';
            }
            j++;
        }
        cout << endl;
    }
}