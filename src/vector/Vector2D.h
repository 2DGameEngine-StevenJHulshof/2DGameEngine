#pragma once

class Vector2D {

private:

public:
    explicit Vector2D(float x = 0.0f,  float y = 0.0f);
    ~Vector2D();

    float x;
    float y;

    Vector2D& Add(const Vector2D& vector2D);
    Vector2D& Subtract(const Vector2D& vector2D);
    Vector2D& Multiply(const Vector2D& vector2D);
    Vector2D& Divide(const Vector2D& vector2D);

    friend Vector2D& operator+(Vector2D& vector2D1, const Vector2D& vector2D2);
    friend Vector2D& operator-(Vector2D& vector2D1, const Vector2D& vector2D2);
    friend Vector2D& operator*(Vector2D& vector2D1, const Vector2D& vector2D2);
    friend Vector2D& operator/(Vector2D& vector2D1, const Vector2D& vector2D2);

    Vector2D& operator+=(const Vector2D& vector2D);
    Vector2D& operator-=(const Vector2D& vector2D);
    Vector2D& operator*=(const Vector2D& vector2D);
    Vector2D& operator/=(const Vector2D& vector2D);

};