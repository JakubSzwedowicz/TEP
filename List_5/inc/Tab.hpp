//
// Author: jakubszwedowicz
// Date: 16.12.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef LIST_5_TAB_HPP
#define LIST_5_TAB_HPP

namespace tep
{
    class Tab
    {
    public:
        Tab()
        {
            std::cout << "[CTOR]" << std::endl;

            m_array = new int[DEFAULT_SIZE];
            m_size = DEFAULT_SIZE;
        }

        Tab(const Tab& a_other);

        Tab(Tab&& a_other);

        Tab& operator=(const Tab& a_other);

        Tab& operator=(Tab&& a_other);

        ~Tab();

        bool set_size(int a_new_size);

        int get_size()
        { return (m_size); }

        static void test_class();

    private:
        const static int DEFAULT_SIZE = 10;

        void copy(const Tab& a_other);

        int* m_array;
        int m_size;
    };
}

#endif //LIST_5_TAB_HPP
