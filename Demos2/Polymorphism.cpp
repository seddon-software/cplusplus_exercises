#include <iostream>
#include <vector>

using namespace std;

class Shape
{
public:
	virtual void show() { cout << "default impl of show()" << endl; }
	virtual void hide() = 0;
	virtual void draw() = 0;
};

class Ellipse: public Shape
{
public:
	virtual void show() { cout << "Ellipse::show()" << endl; }
	virtual void hide() { cout << "Ellipse::hide()" << endl; }
	virtual void draw() { cout << "Ellipse::draw()" << endl; }
	virtual ~Ellipse() { cout << "Ellipse::DTOR" << endl; }
};

class Rectangle: public Shape
{
public:
	virtual void show()
	{
		//Shape::show();
		cout << "Rectangle::show()" << endl;
	}
	virtual void hide() { cout << "Rectangle::hide()" << endl; }
	virtual void draw() { cout << "Rectangle::draw()" << endl; }
	virtual ~Rectangle() { cout << "Rectangle::DTOR" << endl; }
};

class Polygon: public Shape
{
public:
	virtual void show() { cout << "Polygon::show()" << endl; }
	virtual void hide() { cout << "Polygon::hide()" << endl; }
	virtual void draw() { cout << "Polygon::draw()" << endl; }
	virtual ~Polygon() { cout << "Polygon::DTOR" << endl; }
};

void show(Shape& s)
{
	s.show();
}

int main()
{
	// Shape s;
	Ellipse e1, e2;
	Rectangle r1, r2;
	Polygon p1, p2;
	show(e1);
	show(r1);
	show(p1);
	vector<Shape*> group = { &e1, &e2, &r1, &r2, &p1, &p2 };
	for(auto s:group)
	{
		show(*s);
	}
}
