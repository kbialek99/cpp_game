#include "../inc/game/Vector2D.hpp"

Vector2D::Vector2D() : x(0.0f), y(0.0f)
{
}

Vector2D::Vector2D(int x, int y) : x(x), y(y)
{
}

Vector2D &Vector2D::Add(const Vector2D &vec)
{
    this->x += vec.x;
    this->y += vec.y;

    return *this;
}
Vector2D &Vector2D::Subtract(const Vector2D &vec)
{
    this->x -= vec.x;
    this->y -= vec.y;
    return *this;
}
Vector2D &Vector2D::Multiply(const Vector2D &vec)
{
    this->x *= vec.x;
    this->y *= vec.y;
    return *this;
}
Vector2D &Vector2D::Divide(const Vector2D &vec)
{
    this->x /= vec.x;
    this->y /= vec.y;
    return *this;
}

Vector2D &operator+(Vector2D &v1, const Vector2D &v2)
{
    return v1.Add(v2);
}
Vector2D &operator-(Vector2D &v1, const Vector2D &v2)
{
    return v1.Subtract(v2);
}
Vector2D &operator*(Vector2D &v1, const Vector2D &v2)
{
    return v1.Multiply(v2);
}
Vector2D &operator/(Vector2D &v1, const Vector2D &v2)
{
    return v1.Divide(v2);
}

Vector2D& Vector2D::operator+=(const Vector2D& v)
{
    return this->Add(v);
}
Vector2D& Vector2D::operator-=(const Vector2D& v)
{
    return this->Subtract(v);
}
Vector2D& Vector2D::operator*=(const Vector2D& v)
{
    return this->Multiply(v);
}
Vector2D& Vector2D::operator/=(const Vector2D& v)
{
    return this->Divide(v);
}

Vector2D& Vector2D::operator*(const int& i)
{
    this->x *= i;
    this->y *= i;

    return *this;
}
Vector2D& Vector2D::Zero()
{
    this->x = 0;
    this->y = 0;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& vec)
{
    stream << "(" << vec.x << "," << vec.y << ")";
    return stream;
}