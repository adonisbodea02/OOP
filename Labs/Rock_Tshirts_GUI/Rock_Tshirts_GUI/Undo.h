#pragma once
#include "Domain.h"
#include "File_Repo.h"
#include "Repository.h"

class Undo
{
public:
	Undo(){}
	virtual void do_undo() = 0;
	virtual void do_redo() = 0;
};

class Undo_Add : public Undo
{
	Repository& repo;
	Rock_Tshirt rt;

public:
	Undo_Add(Repository& r, const Rock_Tshirt& rt) : repo{r}, rt{rt} {}
	void do_undo() override
	{
		repo.delete_rock_thsirt(rt.get_ID());
	}
	void do_redo() override
	{
		repo.add_rock_tshirt(rt);
	}
};

class Undo_Remove : public Undo
{
	Repository& repo;
	Rock_Tshirt rt;

public:
	Undo_Remove(Repository& r, const Rock_Tshirt& rt) : repo{ r }, rt{ rt } {}
	void do_undo() override
	{
		repo.add_rock_tshirt(rt);
	}
	void do_redo() override
	{
		repo.delete_rock_thsirt(rt.get_ID());
	}
};

class Undo_Update : public Undo
{
	Repository& repo;
	Rock_Tshirt rt;
	int old_price;
	int new_price;

public:
	Undo_Update(Repository& r, int op, int np, const Rock_Tshirt& rock) : repo{ r }, old_price{ op }, new_price{ np }, rt{ rock } {}
	void do_undo() override
	{
		repo.update_rock_thsirt_price(rt.get_ID(), old_price);
	}
	void do_redo() override
	{
		repo.update_rock_thsirt_price(rt.get_ID(), new_price);
	}
};

