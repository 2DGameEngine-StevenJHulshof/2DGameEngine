#include "Vector2D.h"

Vector2D::Vector2D(float x, float y) :
    x(x),
    y(y) {

}

Vector2D::~Vector2D() = default;

Vector2D& Vector2D::Add(const Vector2D &vector2D) {

    this->x += vector2D.x;
    this->y += vector2D.y;

    return *this;
}

Vector2D& Vector2D::Subtract(const Vector2D &vector2D) {

    this->x -= vector2D.x;
    this->y -= vector2D.y;

    return *this;
}

Vector2D& Vector2D::Multiply(const Vector2D &vector2D) {

    this->x *= vector2D.x;
    this->y *= vector2D.y;

    return *this;
}

Vector2D& Vector2D::Divide(const Vector2D &vector2D) {

    this->x /= vector2D.x;
    this->y /= vector2D.y;

    return *this;
}

Vector2D& operator+(Vector2D& vector2D1, const Vector2D& vector2D2) {

    return vector2D1.Add(vector2D2);
}

Vector2D& operator-(Vector2D& vector2D1, const Vector2D& vector2D2) {

    return vector2D1.Subtract(vector2D2);
}

Vector2D& operator*(Vector2D& vector2D1, const Vector2D& vector2D2) {

    return vector2D1.Multiply(vector2D2);
}

Vector2D& operator/(Vector2D& vector2D1, const Vector2D& vector2D2) {

    return vector2D1.Divide(vector2D2);
}

Vector2D& Vector2D::operator+=(const Vector2D& vector2D) {

    return this->Add(vector2D);
}

Vector2D& Vector2D::operator-=(const Vector2D& vector2D) {

    return this->Subtract(vector2D);
}

Vector2D& Vector2D::operator*=(const Vector2D& vector2D) {

    return this->Multiply(vector2D);
}

Vector2D& Vector2D::operator/=(const Vector2D& vector2D) {

    return this->Divide(vector2D);
}