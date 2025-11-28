#include <iostream>

// Declare an enum class for colors
enum class Color:char {
    Red='B',    
    Green,  // Implicitly assigned 'C'i.e 67 
    Blue=2,    
    White    // Implicitly assigned 3 
};

// Declare another enum class for directions
enum class Direction {
    North,
    South,
    East,
    West
};

int main() {
    Color myColor = Color::Red;
    Direction myDirection = Direction::North;

    // Type-safe comparison:
   // if (1 == static_cast<int>(Color::Red)) {
   //     std::cout << "My color is Red." << std::endl;
   // }

    // This would be a compile-time error due to strong type safety:
    // if (myColor == myDirection) { ... }

    // Explicit conversion to underlying type:

    std::cout << "Red's underlying value: " << static_cast<char>(Color::Red) << std::endl;
    std::cout << "Green's underlying value: " << static_cast<int>(Color::Green) << std::endl;
    std::cout << "Blue's underlying value: " << static_cast<int>(Color::Blue) << std::endl;
    std::cout << "Blue's underlying value: " << static_cast<int>(Color::White) << std::endl;
    std::cout << "Color underlying size: " << sizeof(Color::Green) << std::endl;
    std::cout << "Direction underlying size: " << sizeof(Direction::North) << std::endl;


    return 0;
}
