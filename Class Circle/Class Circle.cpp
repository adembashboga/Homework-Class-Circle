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
        std::cout << "���: " << type
            << ", ������� ���������: " << passengers
            << ", ������������ ���������: " << maxPassengers << std::endl;
    }
};

int main() {
    Airplane plane1(1, 180);
    Airplane plane2(2, 160);

    if (plane1 == plane2)
        std::cout << "�������� ������ ����.\n";
    else
        std::cout << "�������� ������� ����.\n";

    if (plane1 > plane2)
        std::cout << "������� 1 ����� �������� ������ ����������, ��� ������� 2.\n";
    else
        std::cout << "������� 2 ����� �������� ������ ����������, ��� ������� 1.\n";

    ++plane1;
    plane1.print();

    --plane1;
    plane1.print();
}