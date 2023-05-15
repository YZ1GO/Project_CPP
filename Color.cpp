#include "Color.hpp"
#include <sstream> // to use "stoi" function
#include <iomanip> // to use "setfill" and "setw"

namespace prog {
    Color::Color() {
        // default constructor with color = black
        r = 0;
        g = 0;
        b = 0;
    }
    Color::Color(const Color& other) {
        // copy constructor
        r = other.r; 
        g = other.g;
        b = other.b;
    }
    Color::Color(rgb_value red, rgb_value green, rgb_value blue) {
        // constructor supplied (r, g, b) values
        this->r = red;
        this->g = green;
        this->b = blue;
    }
    rgb_value Color::red() const {
        return r;   //get red component
    }
    rgb_value Color::green() const {
        return g;   //get green component
    }
    rgb_value Color::blue() const {
        return b;   //get blue component
    }

    // TODO: remove this DUMMY variable once you have appropriate fields for representing colors.
    // rgb_value DUMMY_rgb_value = 0; 

    rgb_value& Color::red()  {
        // mutator for red component
        rgb_value& red_mutator = r;
        return red_mutator;
    }
    rgb_value& Color::green()  {
        // mutator for green component
        rgb_value& green_mutator = g;
        return green_mutator;
    }
    rgb_value& Color::blue()  {
        // mutator for blue component
        rgb_value& blue_mutator = b;
        return blue_mutator;
    }
    Color::Color(const string& hexcode) {
        // use "stoi" to turn hexcode string to integer values rgb
        // pass "nullptr" because we don't need to store the values, we'll just use them temporarily
        // 16 indicates the base for interpreting the string as a hexadecimal number
        this->r = stoi(hexcode.substr(1, 2), nullptr, 16);
        this->g = stoi(hexcode.substr(3, 2), nullptr, 16);
        this->b = stoi(hexcode.substr(5, 2), nullptr, 16);
    }
    string Color::rgb_to_hexcode(const Color& c) {
        // stringstream to build hexcode by converting the rgb values to a string
        stringstream hexcode;
        // perform bitwise & operation between the rgb value and "0xFF"(11111111) to get 8 bits that represent a rgb value
        hexcode << "#" << setfill('0') << setw(2) << hex << uppercase << (c.red() & 0xFF) 
                << setfill('0') << setw(2) << hex << uppercase << (c.green() & 0xFF) 
                << setfill('0') << setw(2) << hex << uppercase << (c.blue() & 0xFF);
        return hexcode.str();
    }
    // implement function "operator<" to be able to use map<Color, string>
    bool Color::operator<(const Color& other) const {
    if (r < other.r)
        return true;
    else if (r == other.r && g < other.g)
        return true;
    else if (r == other.r && g == other.g && b < other.b)
        return true;
    return false;
    }
}
