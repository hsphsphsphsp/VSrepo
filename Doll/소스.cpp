#include <iostream>

using namespace std;

#if 0
class Doll {
public:
	virtual void push() = 0;
};

class BlueDoll : public Doll {
public:
	void push() {
		cout << "BlueBlue" << endl;
	}

	static Doll* create() {
		return new BlueDoll();
	}
};

class RedDoll : public Doll {
public:
	void push() {
		cout << "RedRed" << endl;
	}

	static Doll* create() {
		return new RedDoll();
	}
};

class Factory {
public:
	Doll* makeDoll(string kind) {
		if (kind == "Red") {
			return new RedDoll();
		}
		else if (kind == "Blue") {
			return new BlueDoll();
		}
	}
};

class Cut {
public:
	class Builder {
	public:
		Builder& setFront(int ml) {
			frontHair = ml;
			return *this;
		}

		Builder& setBack(int ml) {
			backHair = ml;
			return *this;
		}

		Builder& setSide(int ml) {
			sideHair = ml;
			return *this;
		}

		Builder& setStyleName(string name) {
			style = name;
			return *this;
		}

		Cut build() {
			return Cut(style, frontHair, backHair, sideHair);
		}

	private:
		string style;
		int frontHair;
		int backHair;
		int sideHair;
	};
	
	void showInfo() {
		cout << "style: " << style << endl;
		cout << "frontHair: " << frontHair << endl;
		cout << "backHair: " << backHair << endl;
		cout << "sideHair: " << sideHair << endl;
	}

private:
	Cut(string style, int frontHair, int backHair, int sideHair)
		: style{ style },
		frontHair{ frontHair },
		backHair{ backHair },
		sideHair{ sideHair }
	{}

	string style;
	int frontHair;
	int backHair;
	int sideHair;
};
#endif

#define MAKESINGLE(classname)									\
public:															\
	static classname& getInstance() {							\
		static classname instance{}; 		  \
		return instance;										\
	}															\
																\
private:														\
	classname() { } 					 \
										   \
	classname& operator=(const classname& other) = delete;		\
	classname(const classname& other) = delete;					\
/*
class Singleton {
	MAKESINGLE(Singleton)
};

class Logger {
	MAKESINGLE(Logger);

public:
	void write(string str) {
		cout << str << endl;
	}
};
*/
class Product {
public:
	virtual void showInfo() = 0;
};

class Gold : public Product {
public:
	virtual void showInfo() {
		cout << "Gold, 100" << endl;
	}

	static Product* create() {
		return new Gold();
	}
};

class Ruby : public Product {
public:
	virtual void showInfo() {
		cout << "Ruby, 50" << endl;
	}

	static Product* create() {
		return new Ruby();
	}
};

class Diamond : public Product {
public:
	virtual void showInfo() {
		cout << "Diamond, 10" << endl;
	}

	static Product* create() {
		return new Diamond();
	}
};

#include <map>

class Factory {
	MAKESINGLE(Factory);
public:

	Product* create(string name) {
		return m[name]();
	}
	void registerProduct(string name, Product* (*create)()) {
		m[name] = create;
	}

private:
	map<string, Product* (*)()> m;
};
/*
class Register {
public:
	Register() {
		Factory::registerProduct("Gold", Gold::create);
		Factory::registerProduct("Ruby", Ruby::create);
		Factory::registerProduct("DIamond", Diamond::create);
	}
	static Register t;
};

Register Register::t{};
*/
int main() {
#if 0
	Factory f{};
	Doll* redDoll = 0;
	Doll* blueDoll = 0;

	redDoll = f.makeDoll("Red");
	blueDoll = f.makeDoll("Blue");

	redDoll->push();
	blueDoll->push();


	Cut cut = Cut::Builder().setStyleName("Sports").setFront(3).setBack(2).setSide(1).build();

	cut.showInfo();
	Singleton &s = Singleton::getInstance();

	Logger& log = Logger::getInstance();

	log.write("Hi");
#endif
	Factory::getInstance().registerProduct("Gold", Gold::create);
	Factory::getInstance().create("Gold")->showInfo();


	

	return 0;
}