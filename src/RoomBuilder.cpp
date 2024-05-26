#include "RoomBuilder.h"

RoomBuilder &RoomBuilder::length(const float &length) {
    room.setLength(length); // length is a private data member of Layout, therefore it can be modified only through a setter
    return *this;
}

RoomBuilder &RoomBuilder::width(const float &width) {
    room.setWidth(width);
    return *this;
}

RoomBuilder &RoomBuilder::room_type(const std::string &room_type) {
    room.room_type = room_type;
    return *this;
}

RoomBuilder &RoomBuilder::name(const std::string &name) {
    room.name = name;
    return *this;
}

RoomBuilder &RoomBuilder::bed_capacity(const int &bed_capacity) {
    room.bed_capacity = bed_capacity;
    return *this;
}

RoomBuilder &RoomBuilder::l_amenities(std::vector<std::string> &l) {
    for(auto& t : l)
    {
        room.l_amenities.push_back(t);
    }
    return *this;
}

RoomLayout RoomBuilder::build() {
    return room;
}

