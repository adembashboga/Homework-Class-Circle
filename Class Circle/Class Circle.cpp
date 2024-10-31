#include <iostream>

class Airplane {
private:
    int type;       
    int passengers;
    int maxPassengers;

public:
    Airplane(int type, int maxPassengers)
        : type(type), passengers(0), maxPassengers(maxPassengers) {}

    bool operator==(const Airplane& other) const {
        return type == other.type;
    }

    bool operator>(const Airplane& other) const {
        return maxPassengers > other.maxPassengers;
    }

    Airplane& operator++() {
        if (passengers < maxPassengers) ++passengers;
        return *this;
    }

    Airplane& operator--() {
        if (passengers > 0) --passengers;
        return *this;
    }

    void print() const {
        std::cout << "Тип: " << type
            << ", Текущие пассажиры: " << passengers
            << ", Максимальные пассажиры: " << maxPassengers << std::endl;
    }
};

int main() {
    Airplane plane1(1, 180);
    Airplane plane2(2, 160);

    if (plane1 == plane2)
        std::cout << "Самолеты одного типа.\n";
    else
        std::cout << "Самолеты разного типа.\n";

    if (plane1 > plane2)
        std::cout << "Самолет 1 может вместить больше пассажиров, чем самолет 2.\n";
    else
        std::cout << "Самолет 2 может вместить больше пассажиров, чем самолет 1.\n";

    ++plane1;
    plane1.print();

    --plane1;
    plane1.print();
}