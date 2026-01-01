#include <iostream>
#include <cmath>


inline void LOG(float vb) 
{
	std::cout << vb << std::endl;
}

class Vector2D
{
private:
	float m_PosX, m_PosY;
public:
	Vector2D() :m_PosX(0.f), m_PosY(0.f) {};
	Vector2D(float PosX, float PosY) :m_PosX(PosX), m_PosY(PosY) {};

public:
	void Normalise()
	{
			float Magnitude = std::sqrt(m_PosX * m_PosX + m_PosY * m_PosY);
			if(Magnitude != 0){
				m_PosX /= Magnitude;
				m_PosY /= Magnitude;
			}
	}
	void MultByConst(float a)
	{
		m_PosX *= a;
		m_PosY *= a;
	}
	void Print() const
	{
		std::cout << "X Position: " << m_PosX << "\n" << "Y Position: " << m_PosY << std::endl;
	}

	static Vector2D Add(const Vector2D& v1,const Vector2D& v2)
	{
		Vector2D temp;
		temp.m_PosX = v1.m_PosX + v2.m_PosX;
		temp.m_PosY = v1.m_PosY + v2.m_PosY;
		return temp;
	}
	static float Cross(const Vector2D& v1,const Vector2D& v2)
	{
		return v1.m_PosX * v2.m_PosY - v1.m_PosY * v2.m_PosX;
	}
	static float Dot(const Vector2D& v1, const Vector2D& v2)
	{
		return v1.m_PosX * v2.m_PosX + v1.m_PosY * v2.m_PosY;
		
	}

};

