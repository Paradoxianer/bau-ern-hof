#ifndef FENSTER_H
#define FENSTER_H
#include "SpielElement.h"

class Fenster : public SpielElement
{
	public:
	Fenster(char *name);
	bool offen;
	virtual void	AufZu(){offen=!offen;};
	virtual bool	IstOffen(){return offen;};
};

#endif
