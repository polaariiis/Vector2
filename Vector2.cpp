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
			float Magnitude = sqrt(m_PosX * m_PosX + m_PosY * m_PosY);
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


int main()
{
	Vector2D v1 = { 3.1,4.2 };
	Vector2D v2 = { 5.4 , 6.9 };
	v1.Print(); v2.Print();
	
	
	float dotproduct = Vector2D::Dot(v1, v2);
	LOG(dotproduct);
	float crossproduct = Vector2D::Cross(v1, v2);
	LOG(crossproduct);


	Vector2D temp = Vector2D::Add(v1, v2);
	temp.Print();

	v1.Normalise();
	v1.Print();

	v1.MultByConst(4);
	v1.Print();
}