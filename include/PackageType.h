#ifndef OOP_PACKAGETYPE_H
#define OOP_PACKAGETYPE_H

#include <iostream>

enum class PackageType{Family, AllInclusive, BeachResort, CityBreak, Adventure, Affordable};

std::ostream& operator<<(std::ostream& os, const PackageType& pkg);

#endif //OOP_PACKAGETYPE_H