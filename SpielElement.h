#ifndef SPIELELEMENT_H
#define SPIELELEMENT_H
#include <String.h>
#include <List.h>
#include <Bitmap.h>
#include <Rect.h>
#include <View.h>

class SpielElement: public BRect
{
public:
	SpielElement (char *neuerName);
	virtual void	FuegeHinzu(void *neuesElement);
	virtual void	NimmsWeg(void *altesElement);
	virtual void	Zeige(BView *leinwand);
	BBitmap	*meinBild;

protected:
	BString	*name;
	BList	*unterElemente;
	BBitmap *HoleBild();
};
#endif
