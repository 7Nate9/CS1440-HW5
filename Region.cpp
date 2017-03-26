//
// Created by Stephen Clyde on 3/4/17.
//

#include "Region.h"
#include "Utils.h"
#include "World.h"
#include "Nation.h"
#include "State.h"
#include "County.h"
#include "City.h"

#include <iomanip>

const std::string regionDelimiter = "^^^";
const int TAB_SIZE = 4;
unsigned int Region::m_nextId = 0;

Region* Region::create(std::istream &in)
{
    Region* region = nullptr;
    std::string line;
    std::getline(in, line);
    if (line!="")
    {
        region = create(line);
        if (region!= nullptr)
            region->loadChildren(in);
    }
    return region;
}
Region* Region::create(const std::string& data)
{
    Region* region = nullptr;
    std::string regionData;
    unsigned long commaPos = (int) data.find(",");
    if (commaPos != std::string::npos)
    {
        std::string regionTypeStr = data.substr(0,commaPos);
        regionData = data.substr(commaPos+1);

        bool isValid;
        RegionType regionType = (RegionType) convertStringToInt(regionTypeStr, &isValid);

        if (isValid)
        {
            region = create(regionType, regionData);
        }

    }

    return region;
}

Region* Region::create(RegionType regionType, const std::string& data)
{
    Region* region = nullptr;
    std::string fields[3];
    if (split(data, ',', fields, 3)) {

        // Create the region based on type
        switch (regionType) {
            case WorldType:
                region = new World();
                break;
            case NationType:
                region = new Nation(fields);
                break;
       // TODO: Add cases for State, County, and City
       //Done
            case StateType:
                region = new State(fields);
                break;
            case CountyType:
                region = new County(fields);
                break;
            case CityType:
                region = new City(fields);
                break;
       // End of To Do
            default:
                break;
        }

        // If the region isn't valid, git ride of it
        if (region != nullptr && !region->getIsValid()) {
            delete region;
            region = nullptr;
        }
    }

    return region;
}

std::string Region::regionLabel(RegionType regionType)
{
    std::string label = "Unknown";
    switch (regionType)
    {
        case Region::WorldType:
            label = "World";
            break;
        case Region::NationType:
            label = "Nation";
            break;
        case Region::StateType:
            label = "State";
            break;
        case Region::CountyType:
            label = "County";
            break;
        case Region::CityType:
            label = "City";
            break;
        default:
            break;
    }
    return label;
}

Region::Region() { }

Region::Region(RegionType type, const std::string data[]) :
        m_id(getNextId()), m_regionType(type), m_isValid(true)
{
    m_name = data[0];
    m_population = convertStringToUnsignedInt(data[1], &m_isValid);
    if (m_isValid)
        m_area = convertStringToDouble(data[2], &m_isValid);
}

Region::~Region()
{
    // TODO: cleanup any dynamically allocated objects

    for (Region* child : m_children)
    {
        delete child;
        child = nullptr;
    }

    //End of To Do
}

std::string Region::getRegionLabel() const
{
    return regionLabel(getType());
}

//Methods for managing subregions
void Region::appendSubRegion(Region* subRegion)
{
    m_children.push_back(subRegion);
}

Region* Region::findId(unsigned int id)
{
    if (m_id != id)
    {
        Region* foundRegion = nullptr;

        for (Region* child : m_children)
        {
            foundRegion = child->findId(id);
            if (foundRegion != nullptr)
                break;
        }

        return foundRegion;
    }
    else
    {
        return this;
    }
}

Region* Region::findSubRegionByIndex(unsigned int index)
{
    if (index >= 0 && index < m_children.size())
        return m_children[index];
    else
        return nullptr;
}

Region* Region::findParentByChildId(unsigned int id)
{
    Region* parent = nullptr;

    for (Region* child : m_children)
    {
        if (child->getId() == id)
            parent = this;
    }

    if (!parent)
    {
        for (Region* child : m_children)
        {
            parent = child->findParentByChildId(id);
        }
    }

    return parent;
}

void Region::removeSubRegion(Region *subRegion)
{
    std::vector<Region*> childrenPostDelete;

    for (Region* child : m_children)
    {
        if (child != subRegion)
        {
            childrenPostDelete.push_back(child);
        }
        else
        {
            delete child;
        }
    }

    m_children = childrenPostDelete;
}

int Region::getSubRegionCount()
{
    return m_children.size();
}
//End

unsigned int Region::computeTotalPopulation()
{
    // TODO: implement computeTotalPopulation, such that the result is m_population + the total population for all sub-regions
    //Done
    unsigned int population = m_population;

    for (Region* child : m_children)
    {
        population += child->computeTotalPopulation();
    }

    return population;

    //End of To Do
}

void Region::list(std::ostream& out)
{
    out << std::endl;
    out << getName() << ":" << std::endl;

    // TODO: implement the loop in the list method
    //Done
    // foreach subregion, print out
    //      id    name

    for (Region* child : m_children)
    {
        out << child->getId() << " : " << child->getName() << std::endl;
    }

    //End of To Do
}

void Region::display(std::ostream& out, unsigned int displayLevel, bool showChild)
{
    if (displayLevel>0)
    {
        out << std::setw(displayLevel * TAB_SIZE) << " ";
    }

    unsigned totalPopulation = computeTotalPopulation();
    double area = getArea();
    double density = (double) totalPopulation / area;

    // TODO: compute the totalPopulation using a method
    //Done

    out << std::setw(6) << getId() << "  "
        << getName() << ", population="
        << totalPopulation
        << ", area=" << area
        << ", density=" << density << std::endl;

    if (showChild)
    {
        // TODO: implement loop in display method
        // foreach subregion
        //      display that subregion at displayLevel+1 with the same showChild value

        //Done
        for (Region* child : m_children)
        {
            child->display(out, displayLevel + 1, showChild);
        }

        //End of To Do
    }
}

void Region::save(std::ostream& out)
{
    out << getType()
        << "," << getName()
        << "," << getPopulation()
        << "," << getArea()
        << std::endl;

    // TODO: implement loop in save method to save each sub-region
    // foreach subregion,
    //      save that region

    //Done
    for (Region* child : m_children)
    {
        child->save(out);
    }

    //End of To Do

    out << regionDelimiter << std::endl;
}

void Region::validate()
{
    //m_isValid = (m_area!=UnknownRegionType && m_name!="" && m_area>=0);
    m_isValid = (m_regionType!=UnknownRegionType && m_name!="" && m_area>=0);
}

void Region::loadChildren(std::istream& in)
{
    std::string line;
    bool done = false;
    while (!in.eof() && !done)
    {
        std::getline(in, line);
        if (line==regionDelimiter)
        {
            done = true;
        }
        else
        {
            Region* child = create(line);
            if (child!= nullptr)
            {
                // TODO: Add the new sub-region to this region
                //Done
                m_children.push_back(child);

                //End of To Do
                child->loadChildren(in);
            }
        }
    }
}

unsigned int Region::getNextId()
{
    if (m_nextId==UINT32_MAX)
        m_nextId=1;

    return m_nextId++;
}