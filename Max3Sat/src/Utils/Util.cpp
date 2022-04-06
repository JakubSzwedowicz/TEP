// Brian Goldman

// Collection of utilities not better suited for placement
// in other files

#include "Util.hpp"

// Creates a new vector containing "length" number of random bits
std::vector<bool> rand_vector(Random& a_rand, const size_t a_length)
{
    std::uniform_int_distribution<int> rbit(0, 1);
    std::vector<bool> vect(a_length, 0);
    for (size_t i = 0; i < vect.size(); i++)
    {
        vect[i] = rbit(a_rand);
    }
    return vect;
}

// Outputs the vector to the stream as 0 and 1 characters
void print(const std::vector<bool>& a_vect, std::ostream& a_out)
{
    for (const auto& bit: a_vect)
    {
        a_out << bit;
    }
    a_out << std::endl;
}

// Counts how many bits are different between "a" and "b".
size_t hamming_distance(const std::vector<bool>& a, const std::vector<bool>& b)
{
    size_t difference = 0;
    for (size_t i = 0; i < a.size(); i++)
    {
        difference += a[i] != b[i];
    }
    return difference;
}

// Rounds the number to the desired precision
float float_round(float value, int precision)
{
    return std::round(value * precision) / precision;
}

// Constructs the conversion tool for gray coded bits to floats
// on a given range of numbers
Binary_To_Float::Binary_To_Float(size_t _bits, float min, float max,
                                 int precision) noexcept
{
    bits = _bits;
    size_t length = 1 << bits;
    size_t gray;
    // all get_values gray coded values
    values.resize(length);
    float span = max - min;
    for (size_t i = 0; i < length; i++)
    {
        // magical conversion of an integer to a gray code
        gray = (i >> 1) ^ i;
        values[gray] = i / static_cast<float>(length) * span + min;
    }
}
