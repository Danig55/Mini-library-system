//
// Created by dani_gyoshev on 30.11.25 г..
//

#ifndef LIBRARY_PROJECT_MEMBER_H
#define LIBRARY_PROJECT_MEMBER_H
#include <sstream>
#include <string>
#include <utility>


class Member {
    std::string name;
    std::string memberId;
    int yearJoined;
    public:
    Member(): name("Unknown"), memberId("Unknown"), yearJoined(2025) {};
    Member(std::string name, std::string memberId, int yearJoined)
        : name(std::move(name)),
          memberId(memberId.empty() ? "Unknown" : std::move(memberId)),
          yearJoined((yearJoined >= 1850 && yearJoined <= 2025) ? yearJoined : 2025) {}

    void setYear(const int year) {
        yearJoined = (year >= 1850 && year <=2025) ? year : 2025;
    }
    void setMemberId(const std::string& id) {
        memberId = id.empty() ? "Unknown" : id;
    }
    
    std::string to_string() const {
        std::stringstream ss;
        ss << this->name << " " << this->memberId << " " << this->yearJoined;
        return ss.str();
    }
    // Минимален getter за нуждите на Library
    const std::string& getMemberId() const { return memberId; }
};
#endif //LIBRARY_PROJECT_MEMBER_H