#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include "SNServeurTcpMonoClient.h"
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	SNServeurTcpMonoClient   myServeur;
	string                   IPServeur;
	char                     message[1500];

		myServeur.Initialisation();
		myServeur.MettreEnEcouteSurLePort(1066);

		cout << "En ecoute..." << endl;

		while(true)
		{
			myServeur.AttendreUnNouveauClient();
			myServeur.RecevoirUnMessage(message, 1500);

			cout << "Message : ";
			cout << message << endl;
		}

	cin.get();
   	cin.get();
	return 0;
}
