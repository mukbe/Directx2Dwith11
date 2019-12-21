#pragma once
//ȸ����ȯ�� ���������ʰ� ���� ȸ���� ����� ��ü��� �������� �ٿ���� �� ��



class FloatRect;
class GameObject;
class Bounding
{
public:
	enum class Figure
	{
		Box,Circle
	};
	Bounding(Figure f);
	virtual~Bounding();

	//Pivot�� ����
	void SetGameObject(GameObject* obj, D3DXVECTOR2 offset );
	
	void Update();
	void Render();
	void SetOffset(D3DXVECTOR2 offset);
	FloatRect GetRect();

protected:
	Figure figure;
	GameObject* obj;
	FloatRect rc;
	FloatRect renderRc;
	D3DXVECTOR2 offset;
};

class BoundingBox : public Bounding
{
public:
	BoundingBox(GameObject* obj, D3DXVECTOR2 offset = D3DXVECTOR2(0.f, 0.f)) : Bounding(Figure::Box)
	{
		SetGameObject(obj, offset);
	}
	~BoundingBox() {}
};

class BoundingCircle : public Bounding
{
public:
	BoundingCircle(GameObject* obj, D3DXVECTOR2 offset = D3DXVECTOR2(0.f, 0.f)) : Bounding(Figure::Circle)
	{
		SetGameObject(obj, offset);
	}
	~BoundingCircle() {}
	
};