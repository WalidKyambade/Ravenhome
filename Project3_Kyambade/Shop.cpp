#include <iostream>
#include <fstream>
#include <vector>
#include "Shop.h"
using namespace std;

Shop::Shop()
{
    decor_level = 1;
    magic_rocks = 0;
    selling_multiplier = 0;
}

int Shop::GetDecorLevel()
{
    return decor_level;
}

void Shop::SetDecorLevel(int decor_level_in)
{
    decor_level = decor_level_in;
}

int Shop::CalculateDecorPrice()
{
    //returns price of decor upgrade based on the decor level of the shop
    if(decor_level == 1)
    {
        return 600;
    }
    if(decor_level == 2)
    {
        return 1500;
    }
    return 0;
}

int Shop::GetMagicRocks()
{
    return magic_rocks;
}

void Shop::SetMagicRocks(int magic_rocks_in)
{
    magic_rocks = magic_rocks_in;
}

int Shop::CalculateMagicRockPrice()
{
    //returns price of rocks upgrade based on the amount of rocks the player has
    if(magic_rocks == 0)
    {
        return 500;
    }

    if(magic_rocks == 1)
    {
        return 1500;
    }
    
    if(magic_rocks == 2)
    {
        return 7000;
    }

    if(magic_rocks == 3)
    {
        return -1;
    }
    return 0;
    
}

void Shop::DecorUp()
{
    decor_level++;
}

void Shop::AddRock()
{
    magic_rocks++;
}


vector<Item> Shop::GetItems()
{
    return items;
}

Item Shop::GetItemsAt(int index)
{
    return items.at(index);
}

int Shop::GetItemsSize()
{
    return items.size();
}

Customer Shop::GetCustomerAt(int index)
{
    return customers.at(index);
}

double Shop::GetSellingMultiplier()
{
    return selling_multiplier;
}

void Shop::SetSellingMultiplier(double selling_multiplier_in)
{
    selling_multiplier = selling_multiplier_in;
}

void Shop::MagicRocksToSellingMultiplier()
{
    //calculates the selling multiplier based on how many magic rocks you have
    if(magic_rocks == 0)
    {
        selling_multiplier = 1.4;
    }
    
    if(magic_rocks == 1)
    {
        selling_multiplier = 1.6;
    }

    if(magic_rocks == 2)
    {
        selling_multiplier = 1.8;
    }
    
    if(magic_rocks == 3)
    {
        selling_multiplier = 2.4;
    }

}

int Shop::DecorLevelToAmtCustomers()
{
    if(decor_level == 1)
    {
        return 10; //based on how many lvl 1 characters there are
    }
    else if(decor_level == 2)
    {
        return 20; //based on how many lvl 2 characters there are
    }
    else if(decor_level == 3)
    {
        return 30; //based on how many lvl 3 characters there are
    }
    
    return 0;
}


int split(string input_string, char seperator, string string_arr[], int arr_size)
{
    // declare number of splits initially to be 1
    int num_splits = 0;
    bool exit_loop = true;
    string curr_substring;
    int master_index = 0;

    //k incraments the place in the array
    int k = 0;
        
    //first loop is to go beween the comma sepearated parts of string
    for(int i = 0; i < input_string.length(); i = i + curr_substring.length() + 1)
    {

        exit_loop = true;
        //second loop checks each letter of the string to see if it's a comma
        for(int j = 0; exit_loop == true; j++)
        {
            //master index goes through and checks every letter in string
            char current_char = input_string[master_index];
            if(current_char == seperator || master_index > input_string.length())
            {
                curr_substring = input_string.substr(i,j);
                string_arr[k] = {curr_substring};
                num_splits++;
                exit_loop = false;
            }
            master_index++;
        }
        k++;
    }
    
    if(num_splits > arr_size)
    {
        num_splits = -1;
    }


    return num_splits;
}

void Shop::FillItems(string file_name)
{
    //declare varibles
    string curr_line;
    ifstream input;
    int arr_size = 4;
    string holding_arr[4];

    input.open(file_name);

    //fills up the itmes vector will all the possible itmes in the game
    for(int i = 0; getline(input, curr_line); i++)
    {
        split(curr_line, '|', holding_arr, arr_size);
        items.push_back(Item(holding_arr[0], stod(holding_arr[1]), stoi(holding_arr[2]), stod(holding_arr[3])));
    }

    input.close();
}

void Shop::FillCustomers(string file_name)
{
    //declare varibles
    string curr_line;
    ifstream input;
    int arr_size = 5;
    string holding_arr[5];

    input.open(file_name);

    //fills up the customers vector with all the possible cuustomers in the game
    for(int i = 0; getline(input, curr_line); i++)
    {
        split(curr_line, '|', holding_arr, arr_size);
        customers.push_back(Customer(holding_arr[0], holding_arr[1], holding_arr[2], stoi(holding_arr[3]), stoi(holding_arr[4])));
    }

    input.close();

}