#include "SpielElement.h"
#include <File.h>
#include <BitmapStream.h>
#include <TranslatorRoster.h>


SpielElement::SpielElement(char *neuerName): BRect(0,0,2,2)
{
	name			= new BString(neuerName);
	meinBild		= HoleBild();
	unterElemente 	= new BList();
}

void SpielElement::FuegeHinzu(void * neuesElement)
{
	unterElemente->AddItem(neuesElement);
}

void SpielElement::NimmsWeg(void * altesElement)
{
	unterElemente->RemoveItem(altesElement);
}

void SpielElement::Zeige(BView *leinwand)
{
	int i = 0;
	if ((meinBild!=NULL) && (meinBild->IsValid()))
			leinwand->DrawBitmap(meinBild,*this);
	SpielElement *element =NULL;
	for (i=0;(element=(SpielElement *)unterElemente->ItemAt(i));i++)
	{
		element->Zeige(leinwand);
	}
}


BBitmap *SpielElement::HoleBild()
{
	BString path("/Haiku_Daten/dev/Bauernhof/art/");
	path.Append(*name);
	BFile file(path.String(),B_READ_ONLY);
	BTranslatorRoster *roster = BTranslatorRoster::Default();
	BBitmapStream stream;
	BBitmap *result = NULL;
	if (roster->Translate(&file, NULL, NULL, &stream,B_TRANSLATOR_BITMAP) < B_OK)
		return NULL;
	stream.DetachBitmap(&result);
	if (result->IsValid())
		Set(0,0,result->Bounds().Width(),result->Bounds().Height());
	return result;
}
