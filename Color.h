#pragma once
class Color {
public:
	//Constructeur
	Color(float red, float green, float blue);
	Color(float red, float green, float blue, float alpha);

	//Getters
	float Red() const;
	float Green() const;
	float Blue() const;
	float Alpha() const;

	//Setters
	void Red(float value);
	void Green(float value);
	void Blue(float value);
	void Alpha(float value);
	void Set(float r, float g, float b);
	void Set(float r, float g, float b, float a);

private:
	float red;
	float green;
	float blue;
	float alpha;
};