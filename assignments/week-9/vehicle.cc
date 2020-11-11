#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Person {
public:
    std::string name;
    int assets;

    Person(std::string name, int assets)
    : name(name), assets(assets) {
    }
};

bool operator==(const Person& lhs, const Person& rhs) {
    return &lhs == &rhs;
}


class Vehicle {
public:
    float max_speed, cur_speed;
    int max_passengers;
    std::vector<Person *> passengers;

    Vehicle(float max_speed, int max_passengers)
    : max_speed(max_speed), cur_speed(0), max_passengers(max_passengers) {
    }

    void start() {
        cur_speed = max_speed;
    }

    void stop() {
        cur_speed = 0.f;
    }

    int size() {
        return passengers.size();
    }

    virtual void get_in(Person& person) { }
    virtual void get_off(Person& person) { }
};

class Car : public Vehicle {
public:
    Person& owner;

    Car(float max_speed, int max_passengers, Person& owner)
    : Vehicle(max_speed, max_passengers), owner(owner) {
    }

    void get_in(Person& person) {
        if ((size() == 0 && max_passengers > 0 && person == owner)
            || (0 < size() && size() < max_passengers)){
            passengers.push_back(&person);
        }
    }
    
    void get_off(Person& person) {
        if (person == owner) {
            passengers.clear();
        } else if (auto it = std::find(passengers.begin(), passengers.end(), &person);
                   it != passengers.end()) {
            passengers.erase(it);
        }
    }
};

class Bus : public Vehicle {
public:
    int charge;

    Bus(float max_speed, int max_passengers, int charge)
    : Vehicle(max_speed, max_passengers), charge(charge) {
    }

    void start() {
        cur_speed = max_speed / 2.f;
    }

    void get_in(Person& person) {
        if (size() < max_passengers && person.assets >= charge) {
            person.assets -= charge;
            passengers.push_back(&person);
        }
    }
    void get_in(const std::vector<Person *>& people) {
        for (auto person : people) {
            if (size() >= max_passengers) {
                break;
            }

            if (person->assets >= charge) {
                person->assets -= charge;
                passengers.push_back(person);
            }
        }
    }
    void get_off(Person& person) {
        auto it = std::find(passengers.begin(), passengers.end(), &person);
        if (it != passengers.end()) {
            passengers.erase(it);
        }
    }
    void get_off(const std::vector<Person *>& people) {
        for (auto person : people) {
            get_off(*person);
        }
    }
};

class Taxi : public Vehicle {
public:
    int charge;
    bool payed;

    Taxi(float max_speed, int max_passengers, int charge)
        : Vehicle(max_speed, max_passengers), charge(charge) {
    }

    void get_in(Person& person) {
        if (!size() && person.assets >= charge) {
            passengers.push_back(&person);
            payed = false;
        }
    }
    void get_in(const std::vector<Person *>& people) {
        if (!size() && people.size() <= max_passengers
            && std::any_of(people.begin(), people.end(), [this](Person* person) {
            return person->assets >= this->charge;
        })) {
            passengers.insert(passengers.end(), people.begin(), people.end());
            payed = false;
        }

    }
    void get_off(Person& person) {
        auto it = std::find(passengers.begin(), passengers.end(), &person);
        if (it != passengers.end()) {
            if (payed == false && (*it)->assets >= charge) {
                (*it)->assets -= charge;
                payed = true;
            }
            passengers.erase(it);
        }
        
    }
    void get_off(const std::vector<Person *>& people) {
        for (auto person : people) {
            get_off(*person);
        }
    }
};

int main() {
    const float max_speed = 30.f;
    const int max_passengers = 3;
    const int charge = 100;

    Person p1{"p1", 300};
    Person p2{"p2", 0};
    Person p3{"p3", 0};
    Person p4{"p4", 0};
    Person p5{"p5", 300};
    Person p6{"p6", 300};
    Person p7{"p7", 300};

    Car car{max_speed, max_passengers, p1};
    Bus bus{max_speed, max_passengers, charge};
    Taxi taxi{max_speed, max_passengers, charge};

    std::cout << "Check: Car: get_in block if owner not ride" << std::endl;
    car.get_in(p2);
    assert(car.passengers.size() == 0);

    std::cout << "Check: Car: get_in owner" << std::endl;
    car.get_in(p1);
    assert(car.passengers.size() == 1
           && *car.passengers[0] == p1);

    std::cout << "Check: Car: get_in after owner ride" << std::endl;
    car.get_in(p2);
    car.get_in(p3);
    assert(car.passengers.size() == 3
           && *car.passengers[1] == p2
           && *car.passengers[2] == p3);

    std::cout << "Check: Car: get_in block exceed max_passengers" << std::endl;
    car.get_in(p4);
    assert(car.passengers.size() == 3);

    std::cout << "Check: Car: get_off passenger" << std::endl;
    car.get_off(p2);
    assert(car.passengers.size() == 2
           && *car.passengers[2] == p3);

    std::cout << "Check: Car: get_off owner" << std::endl;
    car.get_off(p1);
    assert(car.passengers.size() == 0);

    std::cout << "Check: Bus: start half of max_speed" << std::endl;
    bus.start();
    assert(bus.cur_speed == (bus.max_speed / 2.f));

    std::cout << "Check: Bus: get_in person with charge" << std::endl;
    auto bus_possible_assets = p1.assets;
    bus.get_in(p1);
    assert(bus.passengers.size() == 1
           && *bus.passengers[0] == p1
           && bus.passengers[0]->assets == bus_possible_assets - bus.charge);

    std::cout << "Check: Bus: get_in person w/o charge" << std::endl;
    auto bus_impossible_assets = p2.assets;
    bus.get_in(p2);
    assert(bus.passengers.size() == 1
           && p2.assets == bus_impossible_assets);
    
    std::cout << "Check: Bus: get_in people" << std::endl;
    std::vector<Person*> people_get_in_bus{&p2, &p3, &p4, &p5, &p6, &p7};
    std::vector<int> people_get_in_assets(people_get_in_bus.size());

    std::transform(people_get_in_bus.begin(), people_get_in_bus.end(),
                   people_get_in_assets.begin(), [](Person* person) {
        return person->assets;
    });

    bus.get_in(people_get_in_bus);
    assert(bus.passengers.size() == 3
           && *bus.passengers[1] == p5
           && p5.assets == people_get_in_assets[3] - bus.charge
           && *bus.passengers[2] == p6
           && p6.assets == people_get_in_assets[4] - bus.charge
           && p7.assets == people_get_in_assets[5]);

    std::cout << "Check: Bus: get_off person" << std::endl;
    auto bus_off_assets = p5.assets;
    bus.get_off(p5);
    assert(bus.passengers.size() == 2
           && *bus.passengers[1] == p6
           && p5.assets == bus_off_assets);
           
    bus.get_off(p5);
    assert(bus.passengers.size() == 2
           && *bus.passengers[1] == p6
           && p5.assets == bus_off_assets);

    std::cout << "Check: Bus: get_off people" << std::endl;
    std::vector<Person*> people_get_off_bus{&p1, &p6, &p7, &p4};
    std::vector<int> people_get_off_assets(people_get_off_bus.size());

    std::transform(people_get_off_bus.begin(), people_get_off_bus.end(),
                   people_get_off_assets.begin(), [](Person* person) {
        return person->assets;
    });

    bus.get_off(people_get_off_bus);
    assert(bus.passengers.size() == 0
           && p1.assets == people_get_off_assets[0]
           && p6.assets == people_get_off_assets[1]
           && p7.assets == people_get_off_assets[2]
           && p4.assets == people_get_off_assets[3]);

    std::cout << "Check: Taxi: get_in person w/o charge" << std::endl;
    auto taxi_impossible_assets = p2.assets;
    taxi.get_in(p2);
    assert(taxi.passengers.size() == 0
           && p2.assets == taxi_impossible_assets);

    std::cout << "Check: Taxi: get_in person with charge" << std::endl;
    auto taxi_possible_get_in_assets = p1.assets;
    taxi.get_in(p1);
    assert(taxi.passengers.size() == 1
           && *taxi.passengers[0] == p1
           && taxi.passengers[0]->assets == taxi_possible_get_in_assets);

    std::cout << "Check: Taxi: get_in block person if not empty" << std::endl;
    auto taxi_block_assets = p6.assets;
    taxi.get_in(p6);
    assert(taxi.passengers.size() == 1
           && p6.assets == taxi_block_assets);

    std::cout << "Check: Taxi: get_off person with charge" << std::endl;
    auto taxi_possible_get_off_assets = p1.assets;
    taxi.get_off(p1);
    assert(taxi.passengers.size() == 0
           && p1.assets == taxi_possible_get_off_assets - taxi.charge);


    std::cout << "Check: Taxi: get_in people w/o charge" << std::endl;
    std::vector<Person*> people_block_assets_taxi{&p2, &p3, &p4};
    std::vector<int> people_block_assets_taxi_assets(people_block_assets_taxi.size());

    std::transform(people_block_assets_taxi.begin(), people_block_assets_taxi.end(),
                   people_block_assets_taxi_assets.begin(), [](Person *person) {
        return person->assets;
    });

    taxi.get_in(people_block_assets_taxi);
    assert(taxi.passengers.size() == 0
           && p2.assets == people_block_assets_taxi_assets[0]
           && p3.assets == people_block_assets_taxi_assets[1]
           && p4.assets == people_block_assets_taxi_assets[2]);

    std::cout << "Check: Taxi: get_in people block exceed" << std::endl;
    std::vector<Person*> people_block_exceed_taxi{&p1, &p5, &p6, &p7};
    std::vector<int> people_block_exceed_taxi_assets(people_block_exceed_taxi.size());

    std::transform(people_block_exceed_taxi.begin(), people_block_exceed_taxi.end(),
                   people_block_exceed_taxi_assets.begin(), [](Person *person) {
        return person->assets;
    });

    taxi.get_in(people_block_exceed_taxi);
    assert(taxi.passengers.size() == 0
           && p1.assets == people_block_exceed_taxi_assets[0]
           && p5.assets == people_block_exceed_taxi_assets[1]
           && p6.assets == people_block_exceed_taxi_assets[2]
           && p7.assets == people_block_exceed_taxi_assets[3]);
    

    std::cout << "Check: Taxi: get_in people" << std::endl;
    std::vector<Person*> people_taxi{&p5, &p6, &p7};
    std::vector<int> people_taxi_assets(people_taxi.size());

    std::transform(people_taxi.begin(), people_taxi.end(),
                   people_taxi_assets.begin(), [](Person *person) {
        return person->assets;
    });

    taxi.get_in(people_taxi);
    assert(taxi.passengers.size() == 3
           && p5.assets == people_taxi_assets[0]
           && p6.assets == people_taxi_assets[1]
           && p7.assets == people_taxi_assets[2]);

    
    std::cout << "Check: Taxi: get_off people" << std::endl;
    taxi.get_off(people_taxi);
    assert(taxi.passengers.size() == 0);
}
