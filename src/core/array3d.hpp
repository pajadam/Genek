/**
  ********************************************
  * Copyright (C) @pajadam
  ********************************************
  * Generator 3D array class
  ********************************************
  */
#ifndef ARRAY3D_HPP
#define ARRAY3D_HPP

typedef short vox;

class Array3D
{
    size_t m_width, m_height;
    std::vector<vox> m_data;
public:
    Array3D(size_t x, size_t y, size_t z, unsigned int init = 0):
        m_width(x), m_height(y), m_data(x*y*z, init)
    {}
    vox& get(size_t x, size_t y, size_t z)
    {
        return m_data.at(x + y * m_width + z * m_width * m_height);
    }
};

#endif // ARRAY3D_HPP
