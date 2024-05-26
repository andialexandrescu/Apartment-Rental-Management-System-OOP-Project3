#include "PackageType.h"

std::ostream &operator<<(std::ostream &os, const PackageType &pkg) {
    switch(pkg)
    {
        case PackageType::Family:
            os<<"Family";
            break;
        case PackageType::AllInclusive:
            os<<"All-Inclusive";
            break;
        case PackageType::BeachResort:
            os<<"Beach Resort";
            break;
        case PackageType::CityBreak:
            os<<"City Break";
            break;
        case PackageType::Adventure:
            os<<"Adventure";
            break;
        case PackageType::Affordable:
            os<<"Affordable";
            break;
    }
    return os;
}