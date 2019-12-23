//
// Created by ward on 12/2/19.
//

#include <cmath>

#include "vector.h"

utils::Vector::Vector() : Vector(0, 0) {}

utils::Vector::Vector(float x, float y) : x(x), y(y) {}

utils::Vector::operator bool() { return static_cast<bool>(x) || static_cast<bool>(y); }

float utils::Vector::length() const { return std::sqrt(std::pow(x, 2.0f) + std::pow(y, 2.0f)); }

utils::Vector utils::Vector::normalize() const
{
        if (length() == 0)
                return *this;
        return *this / length();
}

utils::Vector utils::Vector::rotate(const float angle) const
{
        float radians = angle * static_cast<float>(M_PI) / 180.0f;
        return {x * std::cos(radians) - y * std::sin(radians), x * std::sin(x) + y * std::cos(radians)};
}

float utils::Vector::dot(utils::Vector vector) const { return x * vector.x + y * vector.y; }

utils::Vector utils::Vector::operator-() const { return {-x, -y}; }

utils::Vector& utils::Vector::operator+=(const Vector vector)
{
        x += vector.x;
        y += vector.y;
        return *this;
}

utils::Vector& utils::Vector::operator-=(utils::Vector vector)
{
        x -= vector.x;
        y -= vector.y;
        return *this;
}

utils::Vector& utils::Vector::operator*=(float amount)
{
        x *= amount;
        y *= amount;
        return *this;
}

utils::Vector& utils::Vector::operator/=(float amount)
{
        x /= amount;
        y /= amount;
        return *this;
}

utils::Vector utils::Vector::operator+(const utils::Vector vector) const { return {x + vector.x, y + vector.y}; }

utils::Vector utils::Vector::operator-(utils::Vector vector) const { return {x - vector.x, y - vector.y}; }

utils::Vector utils::Vector::operator/(utils::Vector vector) const { return {x / vector.x, y / vector.y}; }

utils::Vector utils::Vector::operator*(utils::Vector vector) const { return {x * vector.x, y * vector.y}; }

utils::Vector utils::Vector::operator*(float amount) const { return {x * amount, y * amount}; }

utils::Vector utils::Vector::operator/(float amount) const { return {x / amount, y / amount}; }

utils::Vector utils::Vector::operator+(float amount) const { return {x + amount, y + amount}; }

float utils::getSign(const float f) { return std::signbit(f) ? -1 : 1; }

int utils::positiveModulo(const int value, const int m) { return (value % m + m) % m; }