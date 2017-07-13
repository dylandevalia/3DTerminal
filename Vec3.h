
#ifndef INC_3DTERMINAL_VEC3_H
#define INC_3DTERMINAL_VEC3_H

#include <vector>
#include <cmath>
#include <cassert>

template <typename T>
struct Vec3 {

    T x, y, z;

    Vec3() : Vec3(T(), T(), T()) {};
    Vec3(T _x,T _y,T _z) : x{_x}, y{_y}, z{_z} {};

    /* Operators */
    Vec3<T>& operator+=(Vec3<T> const& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    Vec3<T>& operator-=(Vec3<T> const& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    Vec3<T>& operator*=(T const& rhs) {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        return *this;
    }
    Vec3<T>& operator/=(T const& rhs) {
        x /= rhs;
        y /= rhs;
        z /= rhs;
        return *this;
    }

    friend Vec3<T> operator-(Vec3<T> const& lhs, Vec3<T> const& rhs) {
        return (Vec3<T>(lhs) -= rhs);
    }
    friend Vec3<T> operator+(Vec3<T> const& lhs, Vec3<T> const& rhs) {
        return (Vec3<T>(lhs) += rhs);
    }

    friend Vec3<T> operator*(Vec3<T> const& lhs, T const& rhs) {
        return (Vec3<T>(lhs) *= rhs);
    }
    friend Vec3<T> operator/(Vec3<T> const& lhs, T const& rhs) {
        return (Vec3<T>(lhs) /= rhs);
    }

    // Vector's xyz gettable using []
    T operator[](int i) const {
        assert(i < 3 && i >= 0);
        switch (i) {
            case 0 : return x;
            case 1 : return y;
            case 2 : return z;
        }
    }

    T magnitude() { return sqrt(x^2 + y^2 + z^2); }

};

typedef Vec3<float> Vec3f;

#endif //INC_3DTERMINAL_VEC3_H