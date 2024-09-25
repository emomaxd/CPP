#include <iostream>

class GameManager {
private:
	GameManager(){}
	static GameManager s_Instance;
public:
	GameManager(GameManager& g) = delete;
	static GameManager& GetInstance() {
		return s_Instance;
	}
	void ReloadScene() {
		std::cout << "Scene reloading...\n";
	}
};
GameManager GameManager::s_Instance;

int main() {

	GameManager& gm = GameManager::GetInstance();

	gm.ReloadScene();
	


	return 0;
}