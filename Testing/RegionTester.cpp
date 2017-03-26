//
// Created by Stephen Clyde on 3/13/17.
//

#include "RegionTester.h"

#include "../Region.h"

#include <iostream>
#include <fstream>

void RegionTester::testCreateFromStream()
{
    std::cout << "RegionTester::testCreateFromStream" << std::endl;

    // Load a file with just the world in it
    {
        std::string inputFile = "SampleData/sampleData-1.txt";
        std::ifstream inputStream(inputFile);
        Region* region = Region::create(inputStream);
        if (region==nullptr)
        {
            std::cout << "Failed to create a region from " << inputFile << std::endl;
            return;
        }

        if (region->getType()!=Region::RegionType::WorldType)
        {
            std::cout << "Failed to create correct type of region from " << inputFile << std::endl;
            std::cout << "\tExpected World region type, but created a " << region->getRegionLabel() << std::endl;
            return;
        }
    }

    // Load a file with the and four nations
    {
        std::string inputFile = "SampleData/sampleData-2.txt";
        std::ifstream inputStream(inputFile);
        Region* world = Region::create(inputStream);
        if (world==nullptr)
        {
            std::cout << "Failed to create a region from " << inputFile << std::endl;
            return;
        }

        if (world->getType()!=Region::RegionType::WorldType)
        {
            std::cout << "Failed to create correct type of region from " << inputFile << std::endl;
            std::cout << "\tExpected World region type, but created a " << world->getRegionLabel() << std::endl;
            return;
        }

        if (world->getSubRegionCount()!=4)
        {
            std::cout << "Failed to load the four expected nations from " << inputFile << std::endl;
            std::cout << "\tExpected 4 nations, but loaded a " << world->getSubRegionCount() << std::endl;
            return;
        }

        for (unsigned int nationIndex=0; nationIndex < world->getSubRegionCount(); nationIndex++)
        {
            Region* nation = world->findSubRegionByIndex(nationIndex);
            if (nation->getType()!=Region::RegionType::NationType)
            {
                std::cout << "Failed to create correct type of sub-region in the world from " << inputFile << std::endl;
                std::cout << "\tExpected nation sub-region type, but created a " << nation->getRegionLabel() << std::endl;
                return;
            }
        }
    }

}

void RegionTester::testCreateFromString()
{
    std::cout << "RegionTester::testCreateFromString" << std::endl;

    {
        std::string inputString = "2,Tiny Country,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::NationType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected Country region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny Country") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny Country\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "3,Tiny State,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::StateType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected State region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny State") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny State\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "4,Tiny County,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CountyType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected County region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny County") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "5,Tiny City,30,20";
        Region *region = Region::create(inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CityType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected City region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny City") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny City\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny Country,30,20";
        Region *region = Region::create(inputString);
        if (region != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString << std::endl;
            return;
        }
    }

    {
        std::string inputString = "2,30,20";
        Region *region = Region::create(inputString);
        if (region != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString << std::endl;
            return;
        }
    }

}

void RegionTester::testCreateFromTypeAndString()
{
    std::cout << "RegionTester::testCreateFromTypeAndString" << std::endl;

    {
        std::string inputString = "Tiny Country,30,20";
        Region *region = Region::create(Region::NationType,inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::NationType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected Nation region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny Country") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny State,30,20";
        Region *region = Region::create(Region::RegionType::StateType, inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::StateType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected State region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny State") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny State\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny County,30,20";
        Region *region = Region::create(Region::RegionType::CountyType, inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CountyType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected County region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny County") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny City,30,20";
        Region *region = Region::create(Region::RegionType::CityType, inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::CityType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected City region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny City") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny City\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }
    }

    {
        std::string inputString = "Tiny Country,30";
        Region *r1 = Region::create(Region::NationType,inputString);
        if (r1 != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString << std::endl;
            return;
        }
    }

    {
        std::string inputString = "2";
        Region *r1 = Region::create(Region::NationType, inputString);
        if (r1 != nullptr) {
            std::cout << "Failed to recognize a bad data string in create method, inputString=" << inputString << std::endl;
            return;
        }
    }

}

void RegionTester::testGettersAndSetters()
{
    std::cout << "RegionTester::testGettersAndSetters" << std::endl;

    {
        std::string inputString = "Tiny Country,30,20";
        Region *region = Region::create(Region::NationType,inputString);
        if (region == nullptr) {
            std::cout << "Failed to create a region from " << inputString << std::endl;
            return;
        }

        if (region->getType() != Region::RegionType::NationType) {
            std::cout << "Failed to create correct type of region from " << inputString << std::endl;
            std::cout << "\tExpected Nation region type, but got " << region->getRegionLabel() << std::endl;
            return;
        }

        if (region->getName() != "Tiny Country") {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Tiny County\", but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        if (region->getPopulation() != 30) {
            std::cout << "Failed to initialize the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 30, but created a " << region->getPopulation() << std::endl;
            return;
        }

        if (region->getArea() != 20) {
            std::cout << "Failed to initialize the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 20, but created a " << region->getArea() << std::endl;
            return;
        }

        region->setName("Really Tiny County");
        if (region->getName() != "Really Tiny County") {
            std::cout << "Failed to set the name for region from " << inputString << std::endl;
            std::cout << "\tExpected \"Really Tiny County\", but got \"" << region->getName() << "\"" << std::endl;
            return;
        }

        region->setPopulation(5);
        if (region->getPopulation()!=5) {
            std::cout << "Failed to set the population for region from " << inputString << std::endl;
            std::cout << "\tExpected 5, but got \"" << region->getPopulation() << "\"" << std::endl;
            return;
        }

        region->setArea(2);
        if (region->getArea()!=2) {
            std::cout << "Failed to set the area for region from " << inputString << std::endl;
            std::cout << "\tExpected 2, but got \"" << region->getArea() << "\"" << std::endl;
            return;
        }
    }
}

void RegionTester::testSubRegions()
{
    std::cout << "RegionTester::testSubRegions" << std::endl;

    // TODO: Add test cases for managing sub-regions
    /*These methods are difficult or impossible to test without relying on Region::appendSubRegion,
     *so I've assumed that Region::appendSubRegion is functional.
     *It's functionality is trivial, and easy to test manually.*/

    Region* region = Region::create(Region::RegionType::WorldType, "Test Region 0,7,6");

    Region* region1 = Region::create(Region::RegionType::NationType, "Test Region 1,10,15");
    Region* region2 = Region::create(Region::RegionType::StateType, "Test Region 2,15,25");
    Region* region3 = Region::create(Region::RegionType::CountyType, "Test Region 3,1,1");

    region->appendSubRegion(region1);
    region1->appendSubRegion(region2);
    region2->appendSubRegion(region3);

    if (region->findId(region->getId()) != region)
    {
        std::cout << "Failed to find the pointer to the region with id " << region->getId() << "." << std::endl;
        std::cout << "\tReturned " << (region->findId(region->getId()) ? "the wrong pointer" : "a null pointer") << "." << std::endl;
        return;
    }

    if (region->findId(region1->getId()) != region1)
    {
        std::cout << "Failed to find the pointer to the region with id " << region1->getId() << "." << std::endl;
        std::cout << "\tReturned " << (region->findId(region1->getId()) ? "the wrong pointer" : "a null pointer") << "." << std::endl;
        return;
    }

    if (region->findId(region2->getId()) != region2)
    {
        std::cout << "Failed to find the pointer to the region with id " << region2->getId() << "." << std::endl;
        std::cout << "\tReturned " << (region->findId(region2->getId()) ? "the wrong pointer" : "a null pointer") << "." << std::endl;
        return;
    }

    if (region->findId(region3->getId()) != region3)
    {
        std::cout << "Failed to find the pointer to the region with id " << region3->getId() << "." << std::endl;
        std::cout << "\tReturned " << (region->findId(region3->getId()) ? "the wrong pointer" : "a null pointer") << "." << std::endl;
        return;
    }

    if (region->findParentByChildId(region1->getId()) != region)
    {
        std::cout << "Failed to find the pointer to the parent of the region with id " << region1->getId() << "." << std::endl;
        std::cout << "\tReturned " << (region->findParentByChildId(region1->getId()) ? "the wrong pointer" : "a null pointer") << "." << std::endl;
        return;
    }

    if (region->findParentByChildId(region2->getId()) != region1)
    {
        std::cout << "Failed to find the pointer to the parent of the region with id " << region2->getId() << "." << std::endl;
        std::cout << "\tReturned " << (region->findParentByChildId(2) ? "the wrong pointer" : "a null pointer") << "." << std::endl;
        return;
    }

    if (region->findParentByChildId(region3->getId()) != region2)
    {
        std::cout << "Failed to find the pointer to the parent of the region with id " << region3->getId() << "." << std::endl;
        std::cout << "\tReturned " << (region->findParentByChildId(region3->getId()) ? "the wrong pointer" : "a null pointer") << "." << std::endl;
        return;
    }

    unsigned int region3Id = region3->getId();
    region2->removeSubRegion(region3);

    if (region->findId(region3Id) != nullptr)
    {
        std::cout << "Failed to remove subregion." << std::endl;
        return;
    }

    delete region;
    region = Region::create(Region::RegionType::WorldType, "Test Region,7,6");

    if (region->getSubRegionCount() != 0)
    {
        std::cout << "Failed to return the proper number of subregions." <<std::endl;
        std::cout << "\tExpected 0, but got \"" << region->getSubRegionCount() << "\"" << std::endl;
        return;
    }

    region1 = Region::create(Region::RegionType::NationType, "Test SubRegion1,8,7");
    region2 = Region::create(Region::RegionType::NationType, "Test SubRegion2,9,8");
    region3 = Region::create(Region::RegionType::NationType, "Test SubRegion3,10,9");

    region->appendSubRegion(region1);
    region->appendSubRegion(region2);
    region->appendSubRegion(region3);

    if (region->findSubRegionByIndex(0) != region1)
    {
        std::cout << "Failed to return subregion by index." << std::endl;
        std:: cout << "Returned " << (region->findSubRegionByIndex(0) ? "the wrong pointer" : "the null pointer") << "." << std::endl;
        return;
    }

    if (region->getSubRegionCount() != 3)
    {
        std::cout << "Failed to return the proper number of subregions." << std::endl;
        std::cout << "\tExpected 3, but got \"" << region->getSubRegionCount() << "\"" << std::endl;
        return;
    }

    //End of To Do
}

void RegionTester::testComputeTotalPopulation()
{
    std::cout << "RegionTester::testComputeTotalPopulation" << std::endl;

    //TODO: Add test cases for computeTotalPopulation
    //Done

    Region* region = Region::create(Region::RegionType::WorldType, "Test Region,100,200");
    region->setPopulation(100);

    if (region->computeTotalPopulation() != 100)
    {
        std::cout << "Failed to return the correct population for a lone region." << std::endl;
        std::cout << "\tExpected 100, but got \"" << region->computeTotalPopulation() << "\"" << std::endl;
        return;
    }

    Region* subRegion = Region::create(Region::RegionType::NationType, "Test SubRegion,50,25");
    region->appendSubRegion(subRegion);

    if (region->computeTotalPopulation() != 150)
    {
        std::cout << "Failed to return the correct population for a region and subregion." <<std::endl;
        std::cout << "\tExpected 150, but got \"" << region->computeTotalPopulation() << "\"" << std::endl;
        return;
    }

    Region* subSubRegion = Region::create(Region::RegionType::StateType, "Test SubSubRegion,25,12");
    subRegion->appendSubRegion(subSubRegion);

    if (region->computeTotalPopulation() != 175)
    {
        std::cout << "Failed to return the correct population for a region, subregion, and subsubregion." <<std::endl;
        std::cout << "\tExpected 175, but got \"" << region->computeTotalPopulation() << "\"" << std::endl;
        return;
    }

    subRegion->removeSubRegion(subSubRegion);
    delete subSubRegion;
    subSubRegion = nullptr;

    Region* subRegion2 = Region::create(Region::RegionType::NationType, "Test SubRegion 2,37,25");
    region->appendSubRegion(subRegion2);

    if (region->computeTotalPopulation() != 187)
    {
        std::cout << "Failed to return the correct population for a region and two subregions." << std::endl;
        std::cout << "\tExpected 187, but got \"" << region->computeTotalPopulation() << "\"" << std::endl;
        return;
    }

    delete region;

    region = nullptr;
    subRegion = nullptr;
    subRegion2 = nullptr;

    //End of To Do
}
