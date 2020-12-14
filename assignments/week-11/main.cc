#include <iostream>
#include <vector>
#include <unordered_map>

#include "college.h"
#include "user.h"
#include "building.h"


int main() {
    int n;
    size_t id, id2, size;
    std::string type, name, college_name;

    std::unordered_map<std::string, College*> colleges;
    std::unordered_map<size_t, Building*> buildings;
    std::unordered_map<size_t, User*> users;

    { // initialize colleges
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            std::cin >> college_name;

            auto college = colleges.find(college_name);
            if (college == colleges.end()) {
                colleges.insert({ college_name, new College(college_name) });
            } else {
                std::cout << "Name duplicated error" << std::endl;
            }
        }
    }

    { // initialize buildings
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            std::cin >> name >> id >> college_name >> size;
            auto college = colleges.find(college_name);
            if (college != colleges.end()) {
                if (buildings.find(id) == buildings.end()) {
                    buildings.insert({id, new Building(name, id, *(college->second), size)});
                } else {
                    std::cout << "Id duplicated error" << std::endl;
                }
            } else {
                std::cout << "College not exist error" << std::endl;
            }
        }
    }

    { // initialize users
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            std::cin >> type >> name >> id >> college_name;
            auto college = colleges.find(college_name);
            if (college != colleges.end()) {
                User* user;
                if (users.find(id) == users.end()) {
                    if (type == "student") {
                        user = new Student(name, id, (*college->second));
                    } else if (type == "professor") {
                        user = new Professor(name, id, (*college->second));
                    } else if (type == "employee") {
                        user = new Employee(name, id, (*college->second));
                    }
                    users.insert({id, user});
                } else {
                    std::cout << "Id duplicated error" << std::endl;
                }
            } else {
                std::cout << "College not exist error" << std::endl;
            }
        }
    }

    { // command handle
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            std::cin >> type >> id;
            
            if (type == "enter") {
                std::cin >> id2;
                auto user = users.find(id);
                if (user != users.end()) {
                    bool flag = false;
                    for (const auto& building : buildings) {
                        flag |= building.second->contains(user->second);
                    }

                    auto building = buildings.find(id2);
                    if (flag || building == buildings.end()) {
                        std::cout << "Not enter error" << std::endl;
                    } else {
                        if (building->second->enter(user->second)) {
                            for (size_t index = 0; index < building->second->size(); index++) {
                                building->second->apply([&index, &user](User* u) {
                                    if (user->second == u) {
                                        std::cout << index + 1 << std::endl;
                                    }
                                }, index);
                            }
                        } else {
                            std::cout << "Not enter error" << std::endl;
                        }
                    }
                } else {
                    std::cout << "Invalid id" << std::endl;
                }
            } else if (type == "exit") {
                std::cin >> id2;
                auto user = users.find(id);
                auto building = buildings.find(id2);
                if (user == users.end() || building == buildings.end() || !building->second->contains(user->second)) {
                    // std::cout << "Invalid exit" << std::endl;
                } else {
                    building->second->exit(user->second);
                }
            } else if (type == "total") {
                auto building = buildings.find(id);
                if (building != buildings.end()) {
                    std::cout << building->second->total() << std::endl;
                } else {
                    std::cout << "Invalid id" << std::endl;
                }
            } else if (type == "clean") {
                auto user = users.find(id);
                if (user != users.end()) {
                    if (dynamic_cast<Employee*>(user->second) != nullptr) {
                        Building* build = nullptr;
                        for (const auto& building : buildings) {
                            if (building.second->contains(user->second)) {
                                build = building.second;
                            }
                        }

                        if (build != nullptr) {
                            build->clean(user->second);
                        } else {
                            std::cout << "Nothing to clean error" << std::endl;
                        }
                    } else {
                        std::cout << "Permission error" << std::endl;
                    }
                } else {
                    std::cout << "Invalid id" << std::endl;
                }
            } else if (type == "attendance") {
                auto user = users.find(id);
                if (user != users.end()) {
                    if (dynamic_cast<Professor*>(user->second) != nullptr) {
                        Building* build = nullptr;
                        size_t count = 0, room = -1;

                        for (const auto& building : buildings) {
                            for (size_t index = 0; index < building.second->size(); index++) {
                                bool flag = false;
                                size_t counter = 0;
                                building.second->apply([&flag, &counter, &user](User* u) {
                                    if (user->second == u) {
                                        flag = true;
                                    }

                                    if (dynamic_cast<Student*>(u) != nullptr) {
                                        counter += 1;
                                    }
                                }, index);

                                if (flag) {
                                    build = building.second;
                                    room = index;
                                    count = counter;
                                    break;
                                }
                            }
                        }

                        if (build != nullptr && room != -1 && count > 1) {
                            build->apply([](User* u) {
                                if (dynamic_cast<Student*>(u) != nullptr) {
                                    std::cout << u->getId() << std::endl;
                                }
                            }, room);
                        } else {
                            std::cout << "No students error" << std::endl;
                        }

                    } else {
                        std::cout << "Permission error" << std::endl;
                    }
                } else {
                    std::cout << "Invalid id" << std::endl;
                }
            } else if (type == "where") {
                auto user = users.find(id);
                if (user != users.end()) {
                    for (const auto& building : buildings) {
                        if (building.second->contains(user->second)) {
                            std::cout << building.first << std::endl;
                            break;
                        }
                    }
                } else {
                    std::cout << "Invalid id" << std::endl;
                }
            } else if (type == "all") {
                auto building = buildings.find(id);
                if (building != buildings.end()) {
                    building->second->apply([](User* user) {
                        std::cout << user->getName() << std::endl;
                    });
                } else {
                    std::cout << "Invalid id" << std::endl;
                }
            }
        }
    }

    return 0;
}
