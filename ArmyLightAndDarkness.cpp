// ArmyLightAndDarkness.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

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
	virtual void Shut()override
	{
		std::cout << "Legolas" << std::endl;
		bow.Shut();
	}

	virtual void TreatAndHack()override
	{
		std::cout << "Legolas" << std::endl;
		heal.TreatAndHack();
	}
	virtual ~Legolas() {}
};

class Aragorn : virtual public Warior, virtual public Bowman, virtual public Cavaler
{
	Sword sword;
	Bow bow;
	Horse horse;
	Spear spear;
public:
	virtual void Cut() override
	{
		std::cout << "Aragorn" << std::endl;
		sword.Cut();
	}
	virtual void Shut()override
	{
		std::cout << "Aragorn" << std::endl;
		bow.Shut();

	}
	virtual void Beat() override
	{
		std::cout << "Aragorn" << std::endl;
		horse.Go();
		spear.Beat();
	}
	virtual ~Aragorn() {}
};

class Gendolf : virtual public Heal, virtual public Cavaler
{
	Aye aye;
	Vitamine vitamine;
	Horse horse;
	Spear spear;
public:
	virtual void TreatAndHack() override
	{
		std::cout << "Gendolf" << std::endl;
		aye.Hack();
		vitamine.Treat();
	}
	virtual void Beat() override
	{
		std::cout << "Gendolf" << std::endl;
		horse.Go();
		spear.Beat();
	}
	virtual ~Gendolf() {}
};

class enemyLegolas : virtual public Heal, virtual public Bowman
{
	Bow bow;
	Heal heal;
public:
	virtual void Shut()override
	{
		std::cout << "enemyLegolas" << std::endl;
		bow.Shut();
	}

	virtual void TreatAndHack()override
	{
		std::cout << "enemyLegolas" << std::endl;
		heal.TreatAndHack();
	}
	virtual ~enemyLegolas() {}
};

class enemyAragorn : virtual public Warior, virtual public Bowman, virtual public Cavaler
{
	Sword sword;
	Bow bow;
	Horse horse;
	Spear spear;
public:
	virtual void Cut() override
	{
		std::cout << "enemyAragorn" << std::endl;
		sword.Cut();
	}
	virtual void Shut()override
	{
		std::cout << "enemyAragorn" << std::endl;
		bow.Shut();

	}
	virtual void Beat() override
	{
		std::cout << "enemyAragorn" << std::endl;
		horse.Go();
		spear.Beat();
	}
	virtual ~enemyAragorn() {}
};

class enemyGendolf : virtual public Heal, virtual public Cavaler
{
	Aye aye;
	Vitamine vitamine;
	Horse horse;
	Spear spear;
public:
	virtual void TreatAndHack() override
	{
		std::cout << "enemyGendolf" << std::endl;
		aye.Hack();
		vitamine.Treat();
	}
	virtual void Beat() override
	{
		std::cout << "enemyGendolf" << std::endl;
		horse.Go();
		spear.Beat();
	}
	virtual ~enemyGendolf() {}
};

class ArmyFactory
{
public:
	virtual IWarior* createWarior() = 0;
	virtual IBowman* createBowman() = 0;
	virtual ICavaler* createCavaler() = 0;
	virtual IHeal* createHeal() = 0;
	virtual ~ArmyFactory() {}
};

class ALightArmyFactory : public ArmyFactory
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

class ADarknesstArmyFactory : public ArmyFactory
{
public:
	IWarior* createWarior() override
	{
		return new enemyAragorn;
	}

	IBowman* createBowman() override
	{
		return new enemyLegolas;
	}

	ICavaler* createCavaler() override
	{
		return new enemyGendolf;
	}

	IHeal* createHeal() override
	{
		return new enemyGendolf;
	}
};

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

	void info()
	{
		int i;
		for (i = 0; i < m_w.size(); ++i)  m_w[i]->Cut;
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
	Army* createArmy(ArmyFactory& factory)
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
	ALightArmyFactory al_factory;
	ADarknesstArmyFactory ad_factory;
	/*Aragorn aragorn;
	enemyAragorn enemy;
	Army * A = game.createArmy(aragorn);*/

	Army* al = game.createArmy(al_factory);
	Army* ad = game.createArmy(ad_factory);
	std::cout << "Army Light: " << std::endl;
	al->info();
	std::cout << "\nArmy Darkness: " << std::endl;
	ad->info();
	system("pause");
	return 0;
}

