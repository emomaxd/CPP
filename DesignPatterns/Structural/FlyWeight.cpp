#include <iostream>
#include <unordered_map>

struct SharedState {
	std::string brand_;
	std::string model_;
	std::string color_;

	SharedState(const std::string& brand, const std::string& model, const std::string& color) 
		: brand_(brand), model_(model), color_(color) {

	}
	friend std::ostream& operator<<(std::ostream& os, const SharedState& ss) {
		return os << "[" << ss.brand_ << "," << ss.model_ << "," << ss.color_ << "]";
	}
};

struct UniqueState {
	std::string owner_;
	std::string plates_;

	UniqueState(const std::string& owner, const std::string& plates)
		: owner_(owner), plates_(plates)
	{

	}
	friend std::ostream& operator<<(std::ostream& os, const UniqueState& us) {
		return os << "[" << us.owner_ << "," << us.plates_ << "]";
	}
	
};

/**
 * The Flyweight stores a common portion of the state (also called intrinsic
 * state) that belongs to multiple real business entities. The Flyweight accepts
 * the rest of the state (extrinsic state, unique for each entity) via its
 * method parameters.
 */

class FlyWeight {
private:
	SharedState* shared_state_;

public:
	FlyWeight(const SharedState* shared_state) : shared_state_(new SharedState(* shared_state)) {
			
	}
	FlyWeight(const FlyWeight& other) : shared_state_(new SharedState(*other.shared_state_)) {

	}
	~FlyWeight() {
		delete shared_state_;
	}
	SharedState* shared_state() const {
		return shared_state_;
	}
	void Operation(const UniqueState& unique_state) const {
		std::cout << "Flyweight: Displaying shared (" << *shared_state_ << ")and unique(" << unique_state << ") state.\n";
	}
};

/**
 * The Flyweight Factory creates and manages the Flyweight objects. It ensures
 * that flyweights are shared correctly. When the client requests a flyweight,
 * the factory either returns an existing instance or creates a new one, if it
 * doesn't exist yet.
 */

class FlyWeightFactory {
private:
	std::unordered_map<std::string, FlyWeight> flyweights_;

	std::string GetKey(const SharedState& ss) const {
		return ss.brand_ + "_" + ss.model_ + "_"+ss.color_;
	}
public:
	FlyWeightFactory(std::initializer_list<SharedState> share_states) {
		for (const SharedState& ss : share_states) {
			this->flyweights_.insert(std::make_pair<std::string, FlyWeight>(this->GetKey(ss), FlyWeight(&ss)));
		}
		
	}
	FlyWeight GetFlyWeight(const SharedState& shared_state) {
		std::string key = this->GetKey(shared_state);
		if (this->flyweights_.find(key) == this->flyweights_.end()) {
			std::cout << "FlyweightFactory: Can't find a flyweight, creating new one\n";
			this->flyweights_.insert(std::make_pair( key, FlyWeight(&shared_state)));

		}
		else {
			std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
		}
		return this->flyweights_.at(key);
	}
	void ListFlyWeights() const {
		size_t count = this->flyweights_.size();
		std::cout << "\nFlyweightFactory: I have " << count << " flyweights:\n";
		for (std::pair<std::string, FlyWeight> pair : this->flyweights_)
			std::cout << pair.first << "\n";
	}
};

void AddCarToPoliceDatabase(
	FlyWeightFactory& ff, const std::string& plates, const std::string& owner,
	const std::string& brand, const std::string& model, const std::string& color
) {
	std::cout << "\nClient: Adding a car to database.\n";
	const FlyWeight& flyweight = ff.GetFlyWeight({ brand,model,color });

	flyweight.Operation({ owner,plates });

	
}

int main()
{
	FlyWeightFactory* factory = new FlyWeightFactory({ {"Chevrolet", "Camaro2018", "pink"}, {"Mercedes Benz", "C300", "black"}, {"Mercedes Benz", "C500", "red"}, {"BMW", "M5", "red"}, {"BMW", "X6", "white"} });
	factory->ListFlyWeights();

	AddCarToPoliceDatabase(*factory,
		"CL234IR",
		"James Doe",
		"BMW",
		"M5",
		"red");

	AddCarToPoliceDatabase(*factory,
		"CL234IR",
		"James Doe",
		"BMW",
		"X1",
		"red");
	factory->ListFlyWeights();
	delete factory;

	return 0;
}