//---------------------------------------------------------------------------
#if defined (WIN32)
	#include <winsock2.h>
	typedef int socklen_t;
#endif
#include <stdio.h>
#include <vector>
 #include "Windows.h"
#include "windows.h"
#include <stdlib.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vcl.h>
#pragma hdrstop
#include "fonctions.h"
#include "cloche.h"
#define BUFFERSIZE 25
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	cloche1->Visible=false;
	cloche2->Visible=false;
	cloche3->Visible=false;
	cloche4->Visible=false;
	melodie->Visible=false;
	fichier->Visible=false;
	Edit1->Visible=false;
	close->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::connexionClick(TObject *Sender)
{
	#if defined (WIN32)
		WSADATA WSAData;
		int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
	#else
		int erreur = 0;
	#endif

	SOCKADDR_IN sin;
	if(!erreur)
	{
		/* Création de la socket */
		sock = socket(AF_INET, SOCK_STREAM, 0);

		/* Configuration de la connexion */
		sin.sin_addr.s_addr = inet_addr("192.168.64.124");
		sin.sin_family = AF_INET;
		sin.sin_port = htons(502);

		/* Si le client arrive à se connecter */
		if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
		{
            // affichage des boutons d'envoi de trame
			connexion->Visible=false;
			cloche1->Visible=true;
			cloche2->Visible=true;
			cloche3->Visible=true;
			cloche4->Visible=true;
			melodie->Visible=true;
			fichier->Visible=true;
			close->Visible=true;
			Edit1->Visible=true;
            Form1->Color = clGradientActiveCaption;
			ding = new cloche(sock);
		}
		else
		{
		 // connexion non valide
		}

	}
}
//---------------------------------------------------------------------------
// activation cloche 1
void __fastcall TForm1::cloche1Click(TObject *Sender)
{
	ding->cloche1();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::closeClick(TObject *Sender)
{
  /* On ferme la socket précédemment ouverte */
	closesocket(sock);
	delete ding;
	#if defined (WIN32)
		WSACleanup();
	#endif
	Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cloche2Click(TObject *Sender)
{
	ding->cloche2();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cloche3Click(TObject *Sender)
{
	ding->cloche3();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cloche4Click(TObject *Sender)
{
	ding->cloche4();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
  if (Key==VK_F1) {
		ding->cloche1();
  }
  if (Key==VK_F2) {
	   ding->cloche2();
  }
  if (Key==VK_F3) {
	   ding->cloche3();
  }
  if (Key==VK_F4) {
		ding->cloche4();
  }
  if (Key==VK_F5) {
		ding->toutCloche();
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::melodieClick(TObject *Sender)
{

	ding->cloche2();
	ding->cloche4();
	ding->cloche1();
	ding->cloche2();
	ding->cloche1();
	ding->cloche2();
	ding->cloche3();
	ding->cloche4();
	ding->toutCloche();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::fichierClick(TObject *Sender)
{
	std::ifstream ifs ("E:/TP Systèmes/TP5 Cloches/C++/melodie.txt", std::ifstream::in);

	char c = ifs.get();
	UnicodeString str ="";
	char buf[5] ;
	int i=0;
	while (ifs.good()) {
		buf[i]=c;
		str += c;
		c = ifs.get();
		i++;
	}
	wcstombs(buf,str.c_str(),5);
	for (int a = 0; a < 5; a++) {
		if (buf[a]==1) {
			ding->cloche1();
		}
		if (buf[a]==2) {
			ding->cloche2();
		}
		if (buf[a]==3) {
			ding->cloche3();
		}
		if (buf[a]==4) {
			ding->cloche4();
		}
		if (buf[a]==5) {
			ding->toutCloche();
		}
	}
	ifs.close();


}
//---------------------------------------------------------------------------




