//
//  main.cpp
//  Middle2
//
//  Created by Юрий Филиппов on 01.04.2021.
//

#include <iostream>

class MyClass
{
public:
    MyClass()
    {
        std::cout << "constructor\n";

        createArray();
        
        m_text = new std::string("что-то");
    }
    MyClass(const MyClass& other)
    {
        std::cout << "copy constructor\n";
        m_array = NULL;
        m_text = NULL;
        
        copy(other);
    }
    MyClass& operator=(const MyClass& other)
    {
        std::cout << "copy operator\n";
        copy(other);
        return *this;
    }
    ~MyClass()
    {
        cleanArray();
        cleanText();
    }
private:
    int** m_array;
    std::string* m_text;
    void createArray()
    {
        m_array = new int*[10];
        for (int i = 0; i < 10; i++)
            m_array[i] = new int[10];
    }
    void cleanArray()
    {
        if (!m_array)
            return;
        
        for (int i = 0; i < 10; i++)
            delete[] m_array[i];

        delete[] m_array;
        m_array = NULL;
    }
    void cleanText()
    {
        if (!m_text)
            return;
        
        delete m_text;
        m_text = NULL;
    }
    void copy(const MyClass& other)
    {
        if (!other.m_array)
        {
            if (m_array)
                cleanArray();
        }
        else
        {
            if (!m_array)
                createArray();
            
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 10; j++)
                    m_array[i][j] = other.m_array[i][j];
        }
        
        if (!other.m_text)
        {
            if (m_text)
                cleanText();
        }
        else
        {
            if (!m_text)
                m_text = new std::string();
            
            *m_text = *other.m_text;
        }
    }
};

int main() {
    MyClass m1;
    MyClass m2(m1);
    MyClass m3;
    m3 = m2;
    return 0;
}
