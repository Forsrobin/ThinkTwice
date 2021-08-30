#ifndef B36F3391_3B53_4DB5_921B_D0E563EF52A6
#define B36F3391_3B53_4DB5_921B_D0E563EF52A6

class Vector2D
{
public:
  float x;
  float y;

  Vector2D();
  Vector2D(float x, float y);

  Vector2D &Add(const Vector2D &vec);
  Vector2D &Subtract(const Vector2D &vec);
  Vector2D &Multiply(const Vector2D &vec);
  Vector2D &Divide(const Vector2D &vec);

  friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
  friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
  friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
  friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

  Vector2D& operator+=(const Vector2D& vec);
  Vector2D& operator-=(const Vector2D& vec);
  Vector2D& operator*=(const Vector2D& vec);
  Vector2D& operator/=(const Vector2D& vec);

};

#endif /* B36F3391_3B53_4DB5_921B_D0E563EF52A6 */
