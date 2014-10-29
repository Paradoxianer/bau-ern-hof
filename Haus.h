#ifndef HAUS_H
#define HAUS_H
#include "SpielElement.h"

class Haus : public SpielElement
{
public:
	int		laenge;
	int		breite;
	int		hoehe;
	bool	tuer_auf;
	bool	fenster_auf;

					Haus(char *haus_name);

	virtual void	MachFensterAuf();
	virtual void	MachFensterZu();
	virtual void	MachTuerAuf();
	virtual void	MachTuerZu();
	virtual void	Zeige();
	
private:
};

#endif
