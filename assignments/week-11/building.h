#ifndef __BUILDING_H__
#define __BUILDING_H__

#include <vector>
#include <set>
#include <functional>

#include "college.h"
#include "user.h"
#include "utility.h"

class Building {
public:
    Building(const std::string& name, size_t id, College& college, size_t size)
    : name(name), id(id), college(college), rooms(size) {
    }

    std::string getName() const {
        return name;
    }

    size_t getId() const {
        return id;
    }

    College& getCollege() const {
        return college;
    }

    size_t size() const {
        return rooms.size();
    }

    bool enter(User* user) {
        if (dynamic_cast<Employee*>(user) != nullptr) {
            bool flag = true;
            for (auto& room: rooms) {
                for (auto person : room) {
                    if (dynamic_cast<Employee*>(person) != nullptr) {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) {
                util::select_randomly(rooms.begin(), rooms.end())->insert(user);
                return true;
            }
        } else if (dynamic_cast<Professor*>(user) != nullptr) {

            size_t count = 0;
            for (auto& room : rooms) {
                for (auto person : room) {
                    if (dynamic_cast<Professor *>(person) != nullptr) {
                        count += 1;
                        break;
                    }
                }
            }

            if (count < rooms.size()) {
                while (true) {
                    auto room = util::select_randomly(rooms.begin(), rooms.end());
                    bool flag = true;
                    for (auto person : *room) {
                        if (dynamic_cast<Professor *>(person) != nullptr) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        room->insert(user);
                        return true;
                    }
                }
            }

        } else if (dynamic_cast<Student*>(user) != nullptr) {
            auto student = dynamic_cast<Student*>(user);
            if (student->getCollege() == college) {
                util::select_randomly(rooms.begin(), rooms.end())->insert(user);
            }
            return true;
        }
        

        return false;
    }

    bool exit(User* user) {
        bool result = false;

        for (auto& room : rooms) {
            auto it = room.find(user);
            if (it != room.end()) {
                room.erase(it);
                result = true;
                break;
            }
        }

        return result;
    }

    size_t total() const {
        size_t sum = 0;
        
        for (const auto& room : rooms) {
            sum += room.size();
        }

        return sum;
    }

    void clean(User* user) {
        for (auto& room : rooms) {
            bool flag = room.find(user) != room.end();
            room.clear();
            if (flag) {
                room.insert(user);
            }
        }
    }

    bool contains(User* user) const {
        bool flag = false;

        apply([&flag, &user](User* u) {
            if (user == u) {
                flag = true;
            }
        });

        return flag;
    };

    void apply(const std::function<void(User*)>& f, size_t index) const {
        for (const auto& user : rooms[index]) {
            f(user);
        }
    }

    void apply(const std::function<void(User*)>& f) const {
        for (size_t index = 0; index < rooms.size(); index++) {
            apply(f, index);
        }
    }

private:
    std::string name;
    size_t id;
    College& college;

    std::vector<std::set<User*>> rooms;
};

#endif
