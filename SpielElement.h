#ifndef SPIELELEMENT_H
#define SPIELELEMENT_H
#include <String.h>
#include <List.h>
#include <Bitmap.h>
#include <Rect.h>
#include <View.h>

class SpielElement: public BRect, public BArchivable
{
public:
							SpielElement (char *neuerName);
	static	BArchivable*	Instantiate(BMessage* data);
	virtual	status_t		Archive(BMessage* data, bool deep = true);
	virtual void			FuegeHinzu(SpielElement *neuesElement);
	virtual void			NimmsWeg(SpielElement *altesElement);
	virtual void			Zeige(BView *leinwand);
	BBitmap					*meinBild;

protected:
	BString		*name;
	BList		*unterElemente;
	BList		*aktionen;
	BList		*sensoren;
	BBitmap		*HoleBild();
};
#endif
