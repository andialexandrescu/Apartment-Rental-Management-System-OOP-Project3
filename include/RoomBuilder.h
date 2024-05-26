#ifndef OOP_ROOMBUILDER_H
#define OOP_ROOMBUILDER_H

#include "RoomLayout.h"

class RoomBuilder{ // since RoomBuilder is a friend class of RoomLayout, all the methods in RoomBuilder will have access to all protected members contained in RoomLayout
private:
    RoomLayout room; // composition, meaning RoomBuilder solely depends on the existence of RoomLayout
public:
    RoomBuilder() = default;

    RoomBuilder& length(const float &length);
    RoomBuilder& width(const float &width);
    RoomBuilder& room_type(const std::string &room_type);
    RoomBuilder& name(const std::string &name);
    RoomBuilder& bed_capacity(const int &bed_capacity);
    RoomBuilder& l_amenities(std::vector<std::string> &l);

    RoomLayout build();
};

#endif //OOP_ROOMBUILDER_H