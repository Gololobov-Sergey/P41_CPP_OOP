#pragma once
#include<iostream>

#include"String.h"
#include"List.h"


using namespace std;

class Warrior;

class Skill
{
public:
	virtual void execute(Warrior * w) = 0;
};

class Poison : public Skill
{
public:
	virtual void execute(Warrior* w) override;
};


class Warrior
{
	int hp;
	int damage;

	List<Skill*> skills;
	//Skill* skill;

public:
	Warrior(int hp, int damage, Skill* skill = nullptr) : hp(hp), damage(damage) 
	{
		if (skill)
			skills.push_back(skill);
	}

	Skill* getSkill()
	{
		if (skills.length() > 0)
			return skills[rand() % skills.length()];
		return nullptr;
	}

	int getHP()
	{
		return hp;
	}

	/// <summary>
	/// ;lei f'weiofqpoweifpqoweif [powiefwef
	/// </summary>
	/// <returns>wqe rqwe rwer</returns>
	int getDamage()
	{
		return damage;
	}

	void setHP(int hp)
	{
		this->hp = hp;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="damage"></param>
	void setDamage(int damage)
	{
		this->damage = damage;
	}

	virtual void skill(Warrior* w) = 0;

	virtual ostream& print(ostream& out) const
	{
		out << "HP : " << hp << ", Damage : " << damage << endl;
		return out;
	}

	friend ostream& operator<<(ostream& out, const Warrior* w);

};

ostream& operator<<(ostream& out, const Warrior* w)
{
	return w->print(out);
}

void Poison::execute(Warrior* w)
{
	cout << "Poison!!!!!!";
	w->setHP(0);
}

class Light : public Warrior
{

public:
	Light(int hp, int damage, Skill* skill) : Warrior(hp, damage, skill) { }
};


class Dark : public Warrior
{

public:
	Dark(int hp, int damage) : Warrior(hp, damage) {}
};


class Swordsman : public Light
{

public:
	Swordsman(int hp, int damage) : Light(hp, damage, nullptr) {}

	virtual void skill(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const
	{
		cout << setw(15) << left << "Swordsman -> ";
		return Warrior::print(out);
	}
};


class Rider : public Light
{

public:
	Rider(int hp, int damage, Skill* skill = nullptr) : Light(hp, damage, skill) {}

	virtual void skill(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const
	{
		cout << setw(15) << left << "Rider -> ";
		return Warrior::print(out);
	}
};

class Archer : public Light
{

public:
	Archer(int hp, int damage) : Light(hp, damage, nullptr) {}

	virtual void skill(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const
	{
		cout << setw(15) << left << "Archer -> ";
		return Warrior::print(out);
	}
};

class Zombi : public Dark
{

public:
	Zombi(int hp, int damage) : Dark(hp, damage) {}

	virtual void skill(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const
	{
		cout << setw(15) << left << "Zombi -> ";
		return Warrior::print(out);
	}
};

class Ork : public Dark
{

public:
	Ork(int hp, int damage) : Dark(hp, damage) {}

	virtual void skill(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const
	{
		cout << setw(15) << left << "Ork -> ";
		return Warrior::print(out);
	}
};

class Skeleton : public Dark
{

public:
	Skeleton(int hp, int damage) : Dark(hp, damage) {}

	virtual void skill(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const
	{
		cout << setw(15) << left << "Skeleton -> ";
		return Warrior::print(out);
	}
};


class WarOfWorld
{
	List<Light*> lightes;
	List<Dark*> darkes;

public:
	WarOfWorld(int count)
	{
		for (size_t i = 0; i < count; i++)
		{
			int r = rand() % 3;
			Light* l = nullptr;
			switch (r)
			{
			case 0: l = new Swordsman(rand() % 30 + 50, rand() % 10 + 20); break;
			case 1: l = new Rider(rand() % 30 + 50, rand() % 10 + 20, new Poison()); break;
			case 2: l = new Archer(rand() % 30 + 50, rand() % 10 + 20); break;
			}
			lightes.push_back(l);
		}

		for (size_t i = 0; i < count; i++)
		{
			int r = rand() % 3;
			Dark* d = nullptr;
			switch (r)
			{
			case 0: d = new Ork(rand() % 30 + 50, rand() % 10 + 20); break;
			case 1: d = new Skeleton(rand() % 30 + 50, rand() % 10 + 20); break;
			case 2: d = new Zombi(rand() % 30 + 50, rand() % 10 + 20); break;
			}
			darkes.push_back(d);
		}
	}

	Warrior* fight(Warrior* war1, Warrior* war2)
	{
		if (true)
		{
			//
			//war1->skill(war2);
			Skill* skill = war1->getSkill();
			if(skill)
				skill->execute(war2);

			war1->getDamage();

			return war1;
		}
		else if (true)
		{
			//
			return war2;
		}
		else
		{
			return nullptr;
		}
	}

	void game()
	{
		while (true)
		{
			system("cls");
			cout << "        ------ LIGHT ------" << endl;
			lightes.print();

			gotoxy(50, 0);
			cout << "        ------ DARK ------";
			darkes.print(50, 1);

			int ind_l = rand() % lightes.length();
			int ind_d = rand() % darkes.length();

			Warrior* lose = fight(lightes[ind_l], darkes[ind_d]);

			if (lightes[ind_l] == lose)
			{
				lightes.remove(ind_l);
			}
			else if (darkes[ind_d] == lose)
			{
				darkes.remove(ind_d);
			}

			gotoxy(0, 10);
			system("pause");
		}
		
	}
};