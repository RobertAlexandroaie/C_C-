#include "Lista_Agende.h"
#include <fstream>


AgendeSingleton::AgendeSingleton()
{

}

bool AgendeSingleton::salveaza()
{
	std::ofstream fout("Proprietari.txt");
	if(!fout.is_open())
		return false;

	std::list<ModelAgenda*>::iterator i;
	for(i=Agende.begin();i!=Agende.end();++i)
	{
		if((*i)->toCStringnp()!=_T("")&&(*i)->toCStringnp()!=_T(" "))
			fout<<(*i)->nume_proprietar<<"|"<<(*i)->prenume_proprietar<<"\n";
	}

	fout.close();
	return true;
}

bool AgendeSingleton::incarca()
{
	std::ifstream fin("Proprietari.txt");

	if(!fin.is_open())
		return false;

	char linie[100];
	while(fin.getline(linie,100))
	{
		CString text;
		text=linie;

		CString rezToken[3];
		int curPos = 0;
		rezToken[0]= text.Tokenize(_T("|"),curPos);
		int i=0;
		while (rezToken[i] != _T(""))
		{
			++i;
			rezToken[i] = text.Tokenize(_T("|"), curPos);
		}

		CString fisier;
		fisier=rezToken[0]+_T("!")+rezToken[1]+_T(".txt");
		ModelAgenda *ag=new ModelAgenda(fisier);
		Agende.push_back(ag);
	}

	return true;
}

