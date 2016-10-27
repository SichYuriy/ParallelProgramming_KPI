class Vector {
private:
	int size;
	int *vector;

	~Vector();

public:

	Vector(int size);

	int& operator[](int index);

	int getSize();

	Vector* operator*(int val);

	int operator*(Vector& vector);

	Vector* sort();
	
	int min_val();

	int max_val();

	Vector* operator+(Vector& vector);

};

