//
// Author: JakubSzwedowicz
// Date: 12.10.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef LIST_1_TABLE_HPP
#define LIST_1_TABLE_HPP

#include <string>

class Table
{
public:
    // CTOR/DTOR
    explicit Table();

    Table(std::string a_name, int a_size);

    Table(Table& a_other);

    Table(Table&& a_other);

    Table& operator=(const Table& a_other);

    Table& operator=(Table&& a_other);

    ~Table();

    // GETTERY
    const std::string& get_name() const;

    int get_size() const;

    const int* get_array() const;

    // SETTERY
    void set_name(std::string a_name);

    bool set_new_size(int a_new_size);

    void set_value_at(int a_offset, int a_new_value);

    // Methods
    Table* clone();

    void print() const;

    // Overloads
    Table operator+(const Table& a_other);

    friend std::ostream& operator<<(std::ostream& a_out, const Table& a_table);


private:
    std::string m_name;
    int m_size;
    int* m_array;
};

#endif //LIST_1_TABLE_HPP
