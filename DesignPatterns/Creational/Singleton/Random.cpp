#include <iostream>

class Random {
private:
	Random(){}

	

	float random = 0.05f;

	float IFloat() {
		return random;
	}

public:
	static float Float() { return GetInstance().IFloat(); }
	Random(Random& g) = delete;

	static Random& GetInstance() {
		static Random s_Instance;
		return s_Instance;
	}
	
};


int main() {

	 float f = Random::GetInstance().Float();
	 std::cout << f;
	
	



	return 0;
}