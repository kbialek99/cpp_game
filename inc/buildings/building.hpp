#ifndef BUILDINGCLASS_H
#define BUILDINGCLASS_H


#include <string>
#include <iostream>

#include "../dataDefinition.hpp"

//#include "../characters/npc.hpp"

//class NPC;
class Building
{

    protected:
        short height;
        short width; // buildings are two dimensional. Values defined by building type
    public:

        std::string buildingName;

        int posX, posY; // right lower corner

        

        Building();

        Building(std::string buildingName, int posX, int posY);

        virtual ~Building();

        virtual void assignCharacter(const std::string characterName)const;

        // virtual void getInfo() const{
        //     std::cout << this->buildingName << " has resident named " << this->residents[0].name << "." << std::endl;
        // }

        virtual void interact(int *arg);



};

#endif
