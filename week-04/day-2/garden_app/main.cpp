#include <iostream>
#include "Plant.h"
#include "Tree.h"
#include "Flower.h"
#include "Garden.h"

int main() {
    Garden garden("My garden");

    Flower flower1(FLOWER, "yellow");
    Flower flower2(FLOWER, "blue");
    Tree tree1(TREE, "purple");
    Tree tree2(TREE, "orange");

    garden.addPlant(&flower1);
    garden.addPlant(&flower2);
    garden.addPlant(&tree1);
    garden.addPlant(&tree2);

    garden.status();

    garden.watering(40);

    garden.status();

    return 0;
}