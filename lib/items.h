#ifndef __items_h_
#define __items_h_
#include "pkmn.h"

class Item {
    public:
    Item();
    private:
    string ItemName;
    string desc;
    string pocketType;
};
class HealItem : public Item {
    public:
    HealItem();
    void Use(Individual &pokemon);

    private:
    int healAmount;
    vector<Status> canCure;
};
class TM : public Item {
    public:
    TM();

    private:
    Move move;
    int moveNo;
};
class Bag {
    public:
    void insertItem(Item item);
    void useItem(string pocketName, Item item);
    void destroyItem(string pocketName, Item item);
    vector<Item> viewPocket(string pocketName);

    private:
    vector<HealItem> healingItems;
    vector<Item> KeyItems;
    vector<Item> TMs;
    vector<Item> HeldItems;
    vector<Item> Pokeballs;
    vector<Item> Berries;
};
#endif
