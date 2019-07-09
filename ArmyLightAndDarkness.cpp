#include "stdafx.h"
#include <iostream>
#include <vector>
#include <thread>
#include <functional>

class IWarior
{
public:
	virtual void Cut() = 0;
	virtual ~IWarior() {}
};

class IBowman
{
public:
	virtual void Shut() = 0;
	virtual ~IBowman() {}
};

class IHeal
{
public:
	virtual void TreatAndHack() = 0;
	virtual ~IHeal() {}
};

class ICavaler
{
public:
	virtual void Beat() = 0;
	virtual ~ICavaler() {}
};

class Sword
{
public:
	void Cut()
	{
		std::cout << "----Cut----" << std::endl;
	}
};

class Bow
{
public:
	void Shut()
	{
		std::cout << "----Shut----" << std::endl;
	}
};

class Aye
{
public:
	void Hack()
	{
		std::cout << "----Hack----" << std::endl;
	}
};

class Horse
{
public:
	void Go()
	{
		std::cout << "----GO----" << std::endl;
	}
};

class Vitamine
{
public:
	void Treat()
	{
		std::cout << "----Treat----" << std::endl;
	}
};

class Spear
{
public:
	void Beat()
	{
		std::cout << "----Beat----" << std::endl;
	}
};

class Warior : public IWarior
{
	Sword sword;
public:
	virtual void Cut() override
	{
		sword.Cut();
	}
	virtual ~Warior() {}
};

class Bowman : public IBowman
{
	Bow bow;
public:
	virtual void Shut() override
	{
		bow.Shut();
	}
	virtual ~Bowman() {}
};

class Heal : public IHeal
{
	Aye aye;
	Vitamine vitamine;
public:
	virtual void TreatAndHack() override
	{
		aye.Hack();
		vitamine.Treat();
	}
	virtual ~Heal() {}
};

class Cavaler : public ICavaler
{
	Horse horse;
	Spear spear;
public:
	virtual void Beat() override
	{
		horse.Go();
		spear.Beat();
	}
	virtual ~Cavaler() {}
};

class Legolas : virtual public Heal, virtual public Bowman
{
	
	Bow bow;
	Heal heal;
public:
	static int num;
	void Number()
	{
		num++;
		(num < 2) ? std::cout << "Legolas " << std::endl : std::cout << "enemyLegolas " << std::endl;
	}
	virtual void Shut()override
	{
		Number();
		bow.Shut();
	}

	virtual void TreatAndHack()override
	{
		Number();
		heal.TreatAndHack();
	}
	virtual ~Legolas() {}
};

int Legolas::num = 0;
class Aragorn : virtual public Warior, virtual public Bowman, virtual public Cavaler
{
	Sword sword;
	Bow bow;
	Horse horse;
	Spear spear;
public:
	  static int num;
	  void Number()
	  {
		  num++;
		  (num < 2) ? std::cout << "Aragorn " << std::endl : std::cout << "enemyAragorn " << std::endl;
	  }
	virtual void Cut() override
	{ 
		Number();
		sword.Cut();
	}
	virtual void Shut()override
	{
		Number();
		bow.Shut();

	}
	virtual void Beat() override
	{
		Number();
		horse.Go();
		spear.Beat();
	}
	virtual ~Aragorn() {}
};

int Aragorn::num = 0;
class Gendolf : virtual public Heal, virtual public Cavaler
{
	
	Aye aye;
	Vitamine vitamine;
	Horse horse;
	Spear spear;
public:
	static int num;
	void Number()
	{
		num++;
		(num < 3) ? (std::cout << "Gendolf " <<  std::endl) : std::cout << "enemyGendolf " << std::endl;
	}
	virtual void TreatAndHack() override
	{
		Number();
		aye.Hack();
		vitamine.Treat();
	}
	virtual void Beat() override
	{
		Number();
		horse.Go();
		spear.Beat();
	}
	virtual ~Gendolf() {}
};
int Gendolf::num = 0;
//
//class enemyLegolas : virtual public Heal, virtual public Bowman
//{
//	Bow bow;
//	Heal heal;
//public:
//	virtual void Shut()override
//	{
//		std::cout << "enemyLegolas" << std::endl;
//		bow.Shut();
//	}
//
//	virtual void TreatAndHack()override
//	{
//		std::cout << "enemyLegolas" << std::endl;
//		heal.TreatAndHack();
//	}
//	virtual ~enemyLegolas() {}
//};
//
//class enemyAragorn : virtual public Warior, virtual public Bowman, virtual public Cavaler
//{
//	Sword sword;
//	Bow bow;
//	Horse horse;
//	Spear spear;
//public:
//	virtual void Cut() override
//	{
//		std::cout << "enemyAragorn" << std::endl;
//		sword.Cut();
//	}
//	virtual void Shut()override
//	{
//		std::cout << "enemyAragorn" << std::endl;
//		bow.Shut();
//
//	}
//	virtual void Beat() override
//	{
//		std::cout << "enemyAragorn" << std::endl;
//		horse.Go();
//		spear.Beat();
//	}
//	virtual ~enemyAragorn() {}
//};
//
//class enemyGendolf : virtual public Heal, virtual public Cavaler
//{
//	Aye aye;
//	Vitamine vitamine;
//	Horse horse;
//	Spear spear;
//public:
//	virtual void TreatAndHack() override
//	{
//		std::cout << "enemyGendolf" << std::endl;
//		aye.Hack();
//		vitamine.Treat();
//	}
//	virtual void Beat() override
//	{
//		std::cout << "enemyGendolf" << std::endl;
//		horse.Go();
//		spear.Beat();
//	}
//	virtual ~enemyGendolf() {}
//};

class IArmyFactory
{
public:
	virtual IWarior* createWarior() = 0;
	virtual IBowman* createBowman() = 0;
	virtual ICavaler* createCavaler() = 0;
	virtual IHeal* createHeal() = 0;
	virtual ~IArmyFactory() {}
};

class ArmyFactory : public IArmyFactory
{
public:
	IWarior* createWarior() override
	{
		return new Aragorn;
	}

	IBowman* createBowman() override
	{
		return new Legolas;
	}

	ICavaler* createCavaler() override
	{
		return new Gendolf;
	}

	IHeal* createHeal() override
	{
		return new Gendolf;
	}
};

//class ADarknesstArmyFactory : public IArmyFactory
//{
//public:
//	IWarior* createWarior() override
//	{
//		return new enemyAragorn;
//	}
//
//	IBowman* createBowman() override
//	{
//		return new enemyLegolas;
//	}
//
//	ICavaler* createCavaler() override
//	{
//		return new enemyGendolf;
//	}
//
//	IHeal* createHeal() override
//	{
//		return new enemyGendolf;
//	}
//};

class Army
{
public:
	~Army()
	{
		int i;
		for (i = 0; i<m_w.size(); ++i)  delete m_w[i];
		for (i = 0; i<m_b.size(); ++i)  delete m_b[i];
		for (i = 0; i<m_h.size(); ++i)  delete m_h[i];
		for (i = 0; i<m_c.size(); ++i)  delete m_c[i];
	}

	void infoLight()
	{
		int i;
		for (i = 0; i < m_w.size(); ++i)  m_w[i]->Cut();
		for (i = 0; i < m_b.size(); ++i)  m_b[i]->Shut();
		for (i = 0; i < m_h.size(); ++i)  m_h[i]->TreatAndHack();
		for (i = 0; i < m_c.size(); ++i)  m_c[i]->Beat();
	}

	void infoDarkness()
	{
		int i;
		for (i = 0; i < m_w.size(); ++i)  m_w[i]->Cut();
		for (i = 0; i < m_b.size(); ++i)  m_b[i]->Shut();
		for (i = 0; i < m_h.size(); ++i)  m_h[i]->TreatAndHack();
		for (i = 0; i < m_c.size(); ++i)  m_c[i]->Beat();
	}

	std::vector<IWarior*> m_w;
	std::vector<IBowman*> m_b;
	std::vector<IHeal*> m_h;
	std::vector<ICavaler*> m_c;
};

class Game
{
public:
	Army* createArmy(IArmyFactory& factory)
	{
		Army *army = new Army;
		army->m_w.push_back(factory.createWarior());
		army->m_b.push_back(factory.createBowman());
		army->m_c.push_back(factory.createCavaler());
		army->m_h.push_back(factory.createHeal());
		return army;
	}
};


int main()
{
	Game game;
	ArmyFactory al_factory;
	ArmyFactory ad_factory;
	//ADarknesstArmyFactory ad_factory;
	/*Aragorn aragorn;
	enemyAragorn enemy;
	Army * A = game.createArmy(aragorn);*/

	Army* al = game.createArmy(al_factory);
	Army* ad = game.createArmy(ad_factory);
	
	std::thread t1([&al]() {
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
		std::cout << "Army Light: " << std::endl;
	al->infoLight(); });

	std::thread t2([&ad]() {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		std::cout << "\nArmy Darkness: " << std::endl;
	ad->infoDarkness();});
	
	t1.join();
	t2.join();
	system("pause");
	return 0;
}

